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
#include "..\inc\Screen.h"
#include "..\inc\Global.h"
#include "..\inc\Idling.h"
#include "..\inc\Menu.h"
#include "..\inc\Buffer.h"
#include "..\inc\Counter.h"
#include "..\inc\TypeStruct.h"
#include "..\inc\Menuicon.h"
#include "..\inc\sonx.h"
#include "..\inc\LMC.h"
#include "..\inc\pif.h"

/* Global Variables ----------------------------------------------------------*/
//const uint8_t Pointing[6] = {0x00, 0x7F, 0x7F, 0x3D, 0x1C, 0x08};
//const uint8_t EnableDot[6] = {0x00, 0x3D, 0x36, 0x2A, 0x36, 0x3D};

/* Private functions ---------------------------------------------------------*/
/* Idling State ------------------------*/
void IdlingState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime )
{
	Icon(NumberOfIcon);
    DisTime(Realtime,IdlingLevel);
    DisMainTime(Realtime);
}

/* Menu State --------------------------*/
void MenuState (uint8_t *NumberOfIcon, uint8_t Function, volatile struct Rtctime *Realtime)
{
	Icon(NumberOfIcon);
	MenuName(Function);
	DisMenuIcon(Function);
	DisTime(Realtime,MenuLevel);
}

/* Function State ----------------------*/
void AlarmFuncState(volatile struct AlarmStruct *AlarmData, uint8_t *AlarmLine, uint8_t *AlarmPos)
{
	GotoXP(39,0);
	WriteString("<ALARMS>");
	
	uint8_t i;
	for (i = 2; i<= 6; i++)
	{
		GotoXP(0,i);
		if (*AlarmLine == (i-1))
		{
			WriteChar(92+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}

		if (((AlarmData+i-2)->enable) )
		{
			WriteChar(93+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}

		WriteChar(((AlarmData+i-2)->hour10)+48);
		WriteChar(((AlarmData+i-2)->hour)+48);
		WriteChar(':');
		WriteChar(((AlarmData+i-2)->min10)+48);
		WriteChar(((AlarmData+i-2)->min)+48);
		WriteChar(' ');

		if (((AlarmData+i-2)->date) & Monday)
		{
			WriteChar('M');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Tuesday)
		{
			WriteChar('T');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Wednesday)
		{
			WriteChar('W');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Thursday)
		{
			WriteChar('T');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Friday)
		{
			WriteChar('F');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Saturday)
		{
			WriteChar('S');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Sunday)
		{
			WriteChar('S');
		}
		else
		{
			WriteChar('-');
		}

		if (*AlarmLine == (i-1))
		{
			switch (*AlarmPos)
			{
			case APEnable:
				InverseImage(12,17,i,i);
				break;
			case APHour:
				InverseImage(24,35,i,i);
				break;
			case APMin10:
				InverseImage(42,47,i,i);
				break;
			case APMin:
				InverseImage(48,53,i,i);
				break;
			case APMon:
				InverseImage(60,65,i,i);
				break;
			case APTue:
				InverseImage(66,71,i,i);
				break;
			case APWed:
				InverseImage(72,77,i,i);
				break;
			case APThu:
				InverseImage(78,83,i,i);
				break;
			case APFri:
				InverseImage(84,89,i,i);
				break;
			case APSat:
				InverseImage(90,95,i,i);
				break;
			case APSun:
				InverseImage(96,101,i,i);
				break;
			}
		}
	}

	GotoXP(0,7);
	if (*AlarmLine == 6)
	{
		WriteChar(92+32);
		WriteChar(' ');
	}
	else
	{
		WriteString("  ");
	}
	WriteString("Back");
}

void FlashFuncState (uint8_t *FlashLine)
{
	GotoXP(42,0);
	WriteString("<FLASH>");

	uint8_t i;
	for (i = 2; i<= 4; i++)
	{
		GotoXP(0,i);
		if (*FlashLine == (i-1))
		{
			WriteChar(92+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}
		switch (i-1)
		{
		case 1:
			WriteString("Flash Light");
			break;
		case 2:
			WriteString("Blinking");
			break;
		case 3:
			WriteString("S.O.S");
			break;
		}
	}

	GotoXP(0,7);
	if (*FlashLine == 4)
	{
		WriteChar(92+32);
		WriteChar(' ');
	}
	else
	{
		WriteString("  ");
	}
	WriteString("Back");
}

void CounterFuncState (uint8_t *CounterLine)
{
	GotoXP(36,0);
	WriteString("<COUNTER>");

	uint8_t i;
	for (i = 2; i<= 3; i++)
	{
		GotoXP(0,i);
		if (*CounterLine == (i-1))
		{
			WriteChar(92+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}
		switch (i-1)
		{
		case 1:
			WriteString("Counting Up");
			break;
		case 2:
			WriteString("Counting Down");
			break;
		}
	}

	GotoXP(0,7);
	if (*CounterLine == 3)
	{
		WriteChar(92+32);
		WriteChar(' ');
	}
	else
	{
		WriteString("  ");
	}
	WriteString("Back");
}

uint8_t CounterLowerState (volatile struct CounterStruct *counter, volatile struct Rtctime *time, uint8_t *numberoficon, uint8_t *run)
{
	uint8_t on = 0;
	DisMenuIcon(*numberoficon);
	DisTime(time, LowerLevel);

	if (!run)
	{
		GotoXP(0,7);
		WriteString("STOPPED");
	}
	else
	{
		GotoXP(0,7);
		WriteString( "RUNNING");
	}

	DisCount(counter);

	return 0;
}

void SettingFuncState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime )
{

}

void CreditFuncState(uint8_t *numpicture)
{
	switch (*numpicture)
	{
	case Cydeus:
		DrawBitmap(hero);
		break;
	case LMCuong:
		DrawBitmap(LMC);
		break;
	case Payitforward:
		DrawBitmap(pif);
		break;
	}
}
/* Out State ----------------------------*/
void AlarmRingState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime)
{
	Icon(NumberOfIcon);
	DrawImage(AlarmMenu, 48,79,2,5);
	DisTime(Realtime,MenuLevel);
}

/* Setting Lower State ------------------*/
void SettingClockState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime, uint8_t *SettingLine, uint8_t *SettingPos )
{
	Icon(NumberOfIcon);

	GotoXP(33,0);
	WriteString("<SETTINGS>");

	uint8_t i;
	for (i = 2; i<= 3; i++)
	{
		GotoXP(0,2*(i-1));
		if (*SettingLine == (i-1))
		{
			WriteChar(92+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}

		if (i ==2)
		{
			WriteChar((Realtime->hour10)+48);
			WriteChar((Realtime->hour)+48);
			WriteChar(':');
			WriteChar((Realtime->min10)+48);
			WriteChar((Realtime->min)+48);
		}
		else
		{
		    uint8_t ii = Realtime->date;
			WriteString((uint8_t*)(Datetype+ii-1));
			WriteChar((Realtime->year10)+48);
			WriteChar((Realtime->year)+48);
			WriteChar('/');
			WriteChar((Realtime->mon10)+48);
			WriteChar((Realtime->mon)+48);
			WriteChar('/');
			WriteChar((Realtime->day10)+48);
			WriteChar((Realtime->day)+48);
		}

		if (*SettingLine == 1)
		{
			switch (*SettingPos)
			{
			case SPHour:
				InverseImage(12,23,2,2);
				break;
			case SPMin10:
				InverseImage(30,35,2,2);
				break;
			case SPMin:
				InverseImage(36,41,2,2);
				break;
			}
		}
		else
		{
			switch (*SettingPos)
			{
			case SPDate:
				InverseImage(12,29,4,4);
				break;
			case SPYear10:
				InverseImage(42,47,4,4);
				break;
			case SPYear:
				InverseImage(48,53,4,4);
				break;
			case SPMonth:
				InverseImage(60,71,4,4);
				break;
			case SPDay:
				InverseImage(78,89,4,4);
				break;
			}
		}
	}

	GotoXP(0,3);
	WriteString("  HH:MM");
	GotoXP(0,5);
	WriteString("  DATE YY/MM/DD");

	GotoXP(0,6);
	if (*SettingLine == 3)
	{
		WriteChar(92+32);
		WriteChar(' ');
	}
	else
	{
		WriteString("  ");
	}
	WriteString("Save");

	GotoXP(0,7);
	if (*SettingLine == 4)
	{
		WriteChar(92+32);
		WriteChar(' ');
	}
	else
	{
		WriteString("  ");
	}
	WriteString("Back");
}
