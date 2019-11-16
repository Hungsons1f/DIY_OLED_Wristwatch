/**
  ******************************************************************************
  * @file    Global.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    14/09/2019
  * @brief   Idling screen function
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "TypeStruct.h"

/* Private defines -----------------------------------------------------------*/
#define h10os					6		//0
#define hos						26		//20
#define dos						47		//40
#define m10os					58		//48
#define mos						78		//68
#define s10os					102		//88
#define sos						113		//113

/* Private function prototypes -----------------------------------------------*/
void DisMainTime (volatile struct Rtctime *time);
