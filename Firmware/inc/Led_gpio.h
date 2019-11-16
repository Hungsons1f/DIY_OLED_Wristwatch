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
/* Firmware defines -----------*/
#define Led1Port										GPIOB
#define Led2Port										GPIOB
#define Led1Pin											GPIO_PIN_1
#define Led2Pin 										GPIO_PIN_2


/* Private function prototypes -----------------------------------------------*/
void Led1ON ();
void Led2ON ();
void Led1OFF ();
void Led2OFF ();
void LedInit ();
