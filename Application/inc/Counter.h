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
#include "TypeStruct.h"

/* Private defines -----------------------------------------------------------*/
#ifndef COUNTER_H_
#define COUNTER_H_

#define h10os					6		//0
#define hos						26		//20
#define dos						47		//40
#define m10os					58		//48
#define mos						78		//68
#define s10os					102		//88
#define sos						113		//113

#endif

/* Private function prototypes------------------------------------------------*/
void DisCount (volatile struct CounterStruct *count);
