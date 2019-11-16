/**
  ******************************************************************************
  * @file    Buffer.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    28/06/2019
  * @brief   Functions that transfer data between buffer and hardware
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "..\inc\TypeStruct.h"


/* Private Function Prototypes -----------------------------------------------*/
uint8_t CheckAlarm (volatile struct AlarmStruct *alarmstruct1, volatile struct Rtctime *rtctime1 );
