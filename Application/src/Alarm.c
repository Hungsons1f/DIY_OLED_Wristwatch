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
#include "..\inc\Alarm.h"

/* Global Variables ----------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
uint8_t CheckAlarm (volatile struct AlarmStruct *alarmstruct1, volatile struct Rtctime *rtctime1 )
{
	uint8_t alarmon = 0;

	uint8_t alarmtemp = 0;
	uint8_t timetemp = 0;

	uint8_t i = 0;
	uint8_t date = 0x80;
	for (i = 1; i<= 7; i++)
	{
		date >>= 1;
		alarmtemp = alarmstruct1->date;
		timetemp = rtctime1->date;
		if ((alarmtemp&date) == (timetemp&date))
		{
			alarmtemp = alarmstruct1->hour10 * 10 + alarmstruct1->hour;
			timetemp = rtctime1->hour10 * 10 + rtctime1->hour;
			if (alarmtemp == timetemp)
			{
				alarmtemp = alarmstruct1->min10 * 10 + alarmstruct1->min;
				timetemp = rtctime1->min10 * 10 + rtctime1->min;
				if (alarmtemp == timetemp)
				{
					alarmon = 1;
				}
			}
		}
	}
	return alarmon;
}
