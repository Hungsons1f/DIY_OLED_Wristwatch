/**
  ******************************************************************************
  * @file    rtc_ds3231_i2c.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    28/06/2019
  * @brief   Realtime Clock defines, function headers, running with I2C communication
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
#define RTCAdd                                  0xD0

/* Private function Prototypes -----------------------------------------------*/
void RtcSend(uint8_t *time);
void RtcSendByte(uint8_t address, uint8_t bytedata);
uint8_t* RtcGet(void);
