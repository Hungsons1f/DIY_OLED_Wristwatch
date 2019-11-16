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
void BeepInit(void);
void RunBeepDelay(uint16_t delayms, uint8_t freqkhz);
void RunBeep(uint8_t freqkhz);
void StopBeep();
