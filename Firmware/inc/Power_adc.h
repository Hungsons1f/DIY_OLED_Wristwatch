/**
  ******************************************************************************
  * @file    oled_i2c.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    28/06/2019
  * @brief   Oled defines, function headers, running with I2C communication
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
/* Firmware defines ------------------*/
#define PwsensePort									GPIOA
#define PwsensePin									GPIO_PIN_1
#define StatPort									GPIOA
#define StatPin										GPIO_PIN_2
#define ADCEnPort									GPIOF
#define ADCEnPin									GPIO_PIN_4
#define ADCBatPort									GPIOB
#define ADCBatPin									GPIO_PIN_3


/* Private function prototypes -----------------------------------------------*/
void EnableReading();
void ADCInit(void);
volatile uint16_t ReadingPow();
void WaitForAWhile();
void PWSenseInit (void);
