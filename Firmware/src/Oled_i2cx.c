/**
  ******************************************************************************
  * @file    oled_i2cx.c 
  * @author  Nguyen Hung Son 
  * @version V1.0
  * @date    28/06/2019
  * @brief   Oled main function running with I2C
   ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "..\inc\oled_i2c.h"

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

	GPIO_Init(GPIOD,GPIO_PIN_7,GPIO_MODE_OUT_PP_LOW_FAST);					//Config OLED GPIO
	GPIO_WriteHigh(GPIOD, GPIO_PIN_7);
        
	GPIO_Init(GPIOB,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5),GPIO_MODE_OUT_OD_HIZ_FAST);
	I2C_Init(50000, 0x01, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, 2);
	I2C_Cmd(ENABLE);

	OledWriteCmd((DisplayOn|DISABLE), 0, 0 ,0);

	OledWriteCmd(MuxRatio, 1 , 0x3F, 0);
	OledWriteCmd(DisplayOffset, 1 , 0x00, 0);
	OledWriteCmd(DisplayStartLine, 0,0,0);
	OledWriteCmd((SegmentRemap|ENABLE), 0,0,0);
	OledWriteCmd(COMOutScanDir630, 0 , 0 ,0);
	OledWriteCmd(COMPinHWConf, 1 ,0x12, 0);
	OledWriteCmd(DisplayOscFreq, 1, 0xF0, 0);
	OledWriteCmd(Precharge, 1, 0x22, 0);
    OledWriteCmd(ChargePump, 1, 0x14, 0);
    OledWriteCmd(SetVcomDetect, 1 , 0x20, 0);

	OledWriteCmd(Contrast, 1, 0xFF, 0);
	OledWriteCmd((Inverse|DISABLE), 0,0,0);
	OledWriteCmd(AddressMode, 1, 0x10, 0);

	OledWriteCmd((PageStartAdd + 0), 0, 0, 0 );
	OledWriteCmd((LowColStartAdd + 0), 0,0,0);
	OledWriteCmd((HighColStartAdd + 0), 0, 0 ,0);

	OledWriteCmd((DisplayOn|ENABLE), 0,0,0);
	OledWriteCmd((EntireDisplay|DISABLE), 0,0,0);
}
  
void OledUpdate (uint8_t *screen, uint8_t inverse)
{
	//OledWriteCmd(PageAddress, 2, 0, 7);
	//OledWriteCmd(ColumnAddress, 2, 0, 127);

	uint8_t i = 0;
	uint8_t j = 0;
	uint16_t x = 0;
	for (j = 0; j<= 7; j++)
	{
	    OledWriteCmd((PageStartAdd + j), 0, 0, 0 );
	    OledWriteCmd((LowColStartAdd + ((0+2)&0x0F)), 0,0,0);
	    OledWriteCmd((HighColStartAdd + ((0+2)>>4)), 0, 0 ,0);

		OledPreWrite(data);
		for (i = 0; i<= 127; i++)
		{
			I2C_SendData(((screen[x++])^inverse));
			while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));

		}
		I2C_GenerateSTOP(ENABLE);
		I2C->SR1; I2C->SR3;
	}
}

void OledEnable (uint8_t on)
{
	OledWriteCmd((DisplayOn|on), 0, 0 ,0);
}
