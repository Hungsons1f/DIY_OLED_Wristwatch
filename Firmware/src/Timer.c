/**
  ******************************************************************************
  * @file    Global.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    14/09/2019
  * @brief   General display function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "..\inc\Timer.h"

/* Global Variables ----------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
void TimerInit ()
{
    TIM2_TimeBaseInit(TIM2_PRESCALER_16,50000);
    TIM2_ITConfig(TIM2_IT_UPDATE,ENABLE);
    TIM2_ClearFlag(TIM2_FLAG_UPDATE);
    TIM2_Cmd(ENABLE);

    TIM3_TimeBaseInit(TIM2_PRESCALER_16,50000);
    TIM3_ITConfig(TIM2_IT_UPDATE,ENABLE);
    TIM3_ClearFlag(TIM2_FLAG_UPDATE);
}

void TimerRun50us (uint8_t state)
{
	TIM3_Cmd(state);
}
