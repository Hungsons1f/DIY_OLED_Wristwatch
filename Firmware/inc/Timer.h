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
void TimerInit ();
void TimerRun50us (uint8_t state);
