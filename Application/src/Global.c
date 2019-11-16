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
#include "..\inc\Global.h"
#include "..\inc\Buffer.h"
#include "..\inc\TypeStruct.h"
#include "..\Firmware\inc\rtc_ds3231_i2c.h"

/* Global Variables ----------------------------------------------------------*/

/* Global Structs ------------------------------------------------------------*/


/* Private functions ---------------------------------------------------------*/
void Icon(uint8_t* Gicon)
{
	uint8_t Icon1 = *Gicon;
	uint8_t NumofIcon = 0, i = 0, space = 0;
	for (i = 0; i <5 ; i++)
	{
		if ( ((Icon1 >> i) & 0x01) )
			NumofIcon ++;
	}
	for (i = 0; i< NumofIcon; i++)
	{
		if (Icon1 & IBattery)
		{
			space += 10;
			GotoXP(128-space,0);
			DrawIcon(IconBattery,8);
			Icon1 &=~ IBattery;
			continue;
		}
		if (Icon1 & ICharge)
		{
			space += 8;
			GotoXP(128-space,0);
			DrawIcon(IconCharge,6);
			Icon1 &=~ ICharge;
			continue;
		}
		if (Icon1 & IAlarm)
		{
			space += 8;
			GotoXP(128-space,0);
			DrawIcon(IconAlarm,6);
			Icon1 &=~ IAlarm;
			continue;
		}
		if (Icon1 & ISound)
		{
			space += 9;
			GotoXP(128-space,0);
			DrawIcon(IconSound,8);
			Icon1 &=~ ISound;
			continue;
		}
		if (Icon1 & ICount)
		{
			space += 10;
			GotoXP(128-space,0);
			DrawIcon(IconCount,8);
			Icon1 &=~ ICount;
			continue;
		}
	}
}

void DisTime(volatile struct Rtctime *time, uint8_t State)
{
	GotoXP(0,7);
	switch (State)
	{
	case 1:
		WriteChar(time->hour10 + 48);
		WriteChar(time->hour + 48);
		WriteChar(':');
		WriteChar(time->min10 + 48);
		WriteChar(time->min + 48);
		break;
	default:
		GotoXP(30,7);
		break;
	}

	WriteString("   ");
    uint8_t i = time->date;
	WriteString((uint8_t*)(Datetype+i-1));
	WriteChar(time->day10 + 48);
	WriteChar(time->day + 48);
	WriteChar('/');
	WriteChar(time->mon10 + 48);
	WriteChar(time->mon + 48);
	WriteChar('/');
	WriteChar(time->year10 + 48);
	WriteChar(time->year + 48);
}

void GetTime (volatile struct Rtctime *time)
{
	uint8_t *timetemp;
	//RtcInit();
	timetemp = RtcGet();
	time->sec10 = *timetemp >> 4;
	time->sec = *timetemp & 0x0F;
	time->min10 = *(timetemp+1) >> 4;
	time->min = *(timetemp+1) & 0x0F;
	time->hour10 = *(timetemp+2) >> 4;
	time->hour = *(timetemp+2) & 0x0F;
	time->date = *(timetemp+3) & 0x0F;
	time->day10 = *(timetemp+4) >> 4;
	time->day = *(timetemp+4) & 0x0F;
	time->mon10 = *(timetemp+5) >> 4;
	time->mon = *(timetemp+5) & 0x0F;
	time->year10 = *(timetemp+6) >> 4;
	time->year = *(timetemp+6) & 0x0F;
}

void SendTime (volatile struct Rtctime *time)
{
	uint8_t timetemp[7];
	//RtcInit();
	timetemp[0] = time->sec10 << 4;
	timetemp[0] += time->sec & 0x0F;
	timetemp[1] = time->min10 << 4;
	timetemp[1] += time->min & 0x0F;
	timetemp[2] = time->hour10 << 4;
	timetemp[2] += time->hour & 0x0F;
	timetemp[3] = time->date & 0x0F;
	timetemp[4] = time->day10 << 4;
	timetemp[4] += time->day & 0x0F;
	timetemp[5] = time->mon10 << 4;
	timetemp[5] += time->mon & 0x0F;
	timetemp[6] = time->year10 << 4;
	timetemp[6] += time->year & 0x0F;
	RtcSend(timetemp);
}


void Delay(uint32_t delayms)
{
	uint32_t x = delayms * 160;
	while (x--);
}

