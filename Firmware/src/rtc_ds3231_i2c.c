/**
  ******************************************************************************
  * @file    rtc_ds3232_i2c.c 
  * @author  Nguyen Hung Son
  * @version V2.0
  * @date    03/07/199
  * @brief   Realtime Clock function running with I2C
   ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "..\inc\rtc_ds3231_i2c.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
//void UART1_SendString(uint8_t data[20]);
//void sendbcd(uint8_t bcd);

/* Global Variables ----------------------------------------------------------*/
//uint8_t data[20] = "THOI GIAN: ", ngay[6] = " Ngay ";
//uint8_t homnay[7]= {0x00,0x33,0x11,0x05,0x04,0x07,0x19};

/* Private functions ---------------------------------------------------------*/
void RtcSend(uint8_t *time)
{
	while (I2C_GetFlagStatus(I2C_FLAG_BUSBUSY));
	I2C_GenerateSTART(ENABLE);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(RTCAdd,I2C_DIRECTION_TX);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(0x00);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    uint8_t i = 0;
	for (i = 0; i<=6;i++ )
	{
		I2C_SendData(*(time+i));
		while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}
	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}

void RtcSendByte(uint8_t address, uint8_t bytedata)
{
	while (I2C_GetFlagStatus(I2C_FLAG_BUSBUSY));
	I2C_GenerateSTART(ENABLE);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(RTCAdd,I2C_DIRECTION_TX);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(address);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	I2C_SendData(bytedata);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	I2C_GenerateSTOP(ENABLE);
	I2C->SR1; I2C->SR3;
}

uint8_t* RtcGet(void)
{
    while (I2C_GetFlagStatus(I2C_FLAG_BUSBUSY));
	I2C_GenerateSTART(ENABLE);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(RTCAdd,I2C_DIRECTION_TX);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_SendData(0x00);
	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));

 	I2C_GenerateSTART(ENABLE);
 	while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
 	I2C_Send7bitAddress(RTCAdd,I2C_DIRECTION_RX);
 	while (!I2C_CheckEvent(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

    static uint8_t time[7];
    uint8_t i;
 	for (i = 0; i<=5;i++ )
 	{
 		while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_RECEIVED));
 		time[i] = I2C_ReceiveData();
 	}

  	I2C_AcknowledgeConfig(I2C_ACK_NONE);
  	while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_RECEIVED));
  	time[6] = I2C_ReceiveData();
  	I2C_GenerateSTOP(ENABLE);
  	I2C->SR1; I2C->SR3;
  	I2C_AcknowledgeConfig(I2C_ACK_CURR);
    return time;
}

	  	/*UART1_SendString(data);
	  	for (i = 2; i>=0; i--)
	  	{
	  		sendbcd(buffer[i]);
	  		if (i)
	  			{
	  				while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	  				UART1_SendData8(':');
	  			}
	  	}
	  	while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	  	UART1_SendData8(' ');
	  	while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	  	UART1_SendData8('T');
	  	sendbcd(buffer[3]);
	  	while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	  	UART1_SendString(ngay);
	  	for (i = 4; i<=6; i++)
	  		  	{
	  		  		sendbcd(buffer[i]);
	  		  		if (i!=6)
	  		  			{
	  		  		while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	  		  				UART1_SendData8('/');
	  		  			}
	  		  	}
	  	while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	  	UART1_SendData8('\n');

       time = 20000;
       while (time --);

  }
  
}*/

/* Private function  ---------------------------------------------------------*/
/*void UART1_SendString(uint8_t data[20])
{
	i = 0;
	while (data[i])
	{
		while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
		UART1_SendData8(data[i]);
		i++;
	}
}

void sendbcd(uint8_t bcd)
{
	uint8_t temp = 0;
	temp = bcd>>4;
	while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	UART1_SendData8((temp+48));
	temp = (bcd & 0x0F);
	while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
	UART1_SendData8((temp+48));*/
