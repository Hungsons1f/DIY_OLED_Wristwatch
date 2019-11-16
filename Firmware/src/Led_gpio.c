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
#include "..\inc\Led_gpio.h"

/* Private functions ---------------------------------------------------------*/
void Led1ON ()
{
	GPIO_WriteLow(Led1Port, Led1Pin);
}

void Led2ON ()
{
	GPIO_WriteLow(Led2Port, Led1Pin);
}

void Led1OFF ()
{
	GPIO_WriteHigh(Led1Port, Led1Pin);
}

void Led2OFF ()
{
	GPIO_WriteHigh(Led1Port, Led1Pin);
}

void LedInit ()
{
	GPIO_Init(Led1Port, Led1Pin, GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(Led2Port, Led2Pin, GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_WriteHigh(Led1Port, Led1Pin);
	GPIO_WriteHigh(Led2Port, Led1Pin);
}
