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
#include "..\inc\Beep.h"

/* Private functions ---------------------------------------------------------*/
void BeepInit(void)
{
	GPIO_Init(GPIOD,GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);                 //Config Beep GPIO
	BEEP_DeInit();
	BEEP_LSICalibrationConfig(128000);
}

void RunBeepDelay(uint16_t delayms, uint8_t freqkhz)
{
	if (freqkhz == 1)
	{
		BEEP_Init(BEEP_FREQUENCY_1KHZ);
	}
	if (freqkhz == 2)
	{
		BEEP_Init(BEEP_FREQUENCY_2KHZ);
	}
	if (freqkhz == 4)
	{
		BEEP_Init(BEEP_FREQUENCY_4KHZ);
	}

	uint32_t x = delayms * 16000*50;
    //while (x--);
    BEEP_Cmd(ENABLE);
    //x = delayms * 16000*50;
	while (x--);
	BEEP_Cmd(DISABLE);
}

void RunBeep(uint8_t freqkhz)
{
	if (freqkhz == 1)
	{
		BEEP_Init(BEEP_FREQUENCY_1KHZ);
	}
	if (freqkhz == 2)
	{
		BEEP_Init(BEEP_FREQUENCY_2KHZ);
	}
	if (freqkhz == 4)
	{
		BEEP_Init(BEEP_FREQUENCY_4KHZ);
	}

    BEEP_Cmd(ENABLE);
}

void StopBeep()
{
	BEEP_Cmd(DISABLE);
}
