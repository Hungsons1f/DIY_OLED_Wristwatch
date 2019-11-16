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
#include "..\inc\Power_adc.h"

/* Private functions ---------------------------------------------------------*/
void EnableReading()
{
	GPIO_WriteHigh(ADCEnPort, ADCEnPin);
}

void WaitForAWhile()
{
	ADC1_StartConversion();
}

void ADCInit(void)
{
	GPIO_Init(ADCBatPort, ADCBatPin, GPIO_MODE_IN_FL_IT);
	ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D2, ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL3, DISABLE);
	ADC1_ITConfig(ADC1_IT_EOCIE,ENABLE);
}

volatile uint16_t ReadingPow()
{
	volatile uint16_t read = 0;
	read = ADC1_GetConversionValue();
	ADC1_ClearITPendingBit(ADC1_IT_EOC);
	//GPIO_WriteLow(GPIOC, GPIO_PIN_5);
	return read;
}

void PWSenseInit (void)
{
	GPIO_Init(PwsensePort, PwsensePin, GPIO_MODE_IN_FL_IT);
	GPIO_WriteLow(PwsensePort, PwsensePin);
	GPIO_Init(StatPort, StatPin, GPIO_MODE_IN_FL_IT);
	GPIO_WriteLow(StatPort, StatPin);
}
