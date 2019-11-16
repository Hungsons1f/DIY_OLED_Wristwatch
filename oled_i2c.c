/**
  ******************************************************************************
  * @file    oled_i2c.c 
  * @author  Nguyen Hung Son 
  * @version V1.0
  * @date    28/06/2019
  * @brief   Oled main function running with I2C
   ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "..\inc\oled_i2c.h"
#include "..\inc\fonts.h"

/* Private functions ---------------------------------------------------------*/
void OledPreWrite (uint8_t FirstByte)
{
	while (I2C_GetFlagStatus(I2C_FLAG_BUSBUSY));
	I2C_GenerateSTART(ENABLE);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(OledAdd,I2C_DIRECTION_TX);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(FirstByte);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

void OledWriteCmd (uint8_t Command, uint8_t NumberOfPara, uint8_t Para1, uint8_t Para2)
{
	OledPreWrite(ctrl);

	I2C_SendData(Command);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if (NumberOfPara >=1)
	{
		I2C_SendData(Para1);
		while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}
	if (NumberOfPara >=2)
	{
		I2C_SendData(Para2);
		while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}
	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}

void OledInit (void)
{
	CLK_DeInit();
	CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
	CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);

	I2C_Init(100000, OledAdd, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, 2);
	I2C_Cmd(ENABLE);
	GPIO_Init(GPIOB,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5),GPIO_MODE_OUT_OD_HIZ_FAST);

	OledWriteCmd((DisplayOn|DISABLE), 0, 0 ,0);

	OledWriteCmd(MuxRatio, 1 , 0x3F, 0);
	OledWriteCmd(DisplayOffset, 1 , 0x00, 0);
	OledWriteCmd(DisplayStartLine, 0,0,0);
	OledWriteCmd(SegmentRemap, 0,0,0);
	OledWriteCmd(COMOutScanDir063, 0 , 0 ,0);
	OledWriteCmd(COMPinHWConf, 1 ,0x12, 0);
	OledWriteCmd(DisplayOscFreq, 1, 0xF0, 0);
       	OledWriteCmd(ChargePump, 1, 0x14, 0);

	OledWriteCmd(Contrast, 1, 0xFF, 0);
	OledWriteCmd(AddressMode, 1, 0x00, 0);
	OledWriteCmd((DisplayOn|ENABLE), 0,0,0);
	OledWriteCmd((EntireDisplay|DISABLE), 0,0,0);
}
  
void OledGotoXY (uint8_t xStart, uint8_t xEnd, uint8_t PageStart, uint8_t PageEnd)
{
	OledWriteCmd(PageAddress, 2, PageStart, PageEnd);
	OledWriteCmd(ColumnAddress, 2, xStart, xEnd);
}

void OledWriteCol (uint8_t Col)
{
	OledPreWrite(data);
	I2C_SendData(Col);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}

void OledWriteChar (uint8_t Char)
{
	uint8_t i;
	for (i = 0; i <= 6; i++)
		OledWriteCol(fonta[Char - 32][i]);
}

void OledWriteString (uint8_t String[])
{
	uint8_t i = 0;
	while (String[i])
	{
		OledWriteChar(String[i]);
		i++;
	}
}

void OledSolidFill (uint8_t Fill)
{
	OledGotoXY(0,127,0,7);
	OledPreWrite(data);
	uint8_t i = 0;
	uint8_t j = 0;
	for (j = 0; j<= 7; j++)
		for (i = 0; i<= 127; i++)
		{
			I2C_SendData(Fill);
			while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		}
	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}

void OledDrawBitmap (const uint8_t *bmp)
{
	OledGotoXY(0,127,0,7);
	OledPreWrite(data);
	uint8_t i = 0;
	uint8_t j = 0;
	uint16_t x = 0;
	for (j = 0; j<= 7; j++)
		for (i = 0; i<= 127; i++)
		{
			I2C_SendData((bmp[x++]^0xFF));
			while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));

		}
	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}

void OledDrawIcon (const uint8_t *Icon, uint8_t Size)
{
	uint8_t i;
	for (i = 0; i < Size ; i++)
		OledWriteCol(*(Icon + i));
}

void OledDrawImage (const uint8_t *bmp, uint8_t xbegin, uint8_t xend, uint8_t ybegin, uint8_t yend)
{
	OledGotoXY(xbegin,xend,ybegin,yend);
	OledPreWrite(data);
	uint8_t i = xbegin;
	uint8_t j = ybegin;
	uint16_t x = 0;
	for (j = ybegin; j<= yend; j++)
		for (i = xbegin; i<= xend; i++)
		{
			I2C_SendData(bmp[x++]);
			while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		}
	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}