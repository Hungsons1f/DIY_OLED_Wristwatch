/**
  ******************************************************************************
  * @file    Menu.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    28/06/2019
  * @brief   Functions for main menu screen
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "..\inc\Menu.h"
#include "..\inc\Buffer.h"
#include "..\inc\fonts.h"
#include "..\inc\Menuicon.h"

/* Global Variables ----------------------------------------------------------*/
void MenuName (uint8_t status)
{
	uint8_t i;
	GotoXP(14,2);
	WriteString("-MENU-");
	switch (status)
	{
	case 6:
		GotoXP(5,5);
		for (i = 5; i<=13; i++)
			WriteCol(0x00);
		GotoXP(14,5);
		WriteString("<Back>   ");
		break;
	case 1:
		GotoXP(5,5);
		for (i = 5; i<=10; i++)
			WriteCol(0x00);
		GotoXP(11,5);
		WriteString("<Alarm>  ");
		break;
	case 2:
		GotoXP(5,5);
		WriteString("<Counter>");
		break;
	case 3:
		GotoXP(5,5);
		for (i = 5; i<=10; i++)
			WriteCol(0x00);
		GotoXP(11,5);
		WriteString("<Flash>  ");
		break;
	case 4:
		GotoXP(5,5);
		WriteString("<Setting>");
		break;
	case 5:
		GotoXP(5,5);
		WriteCol(0x00);
		WriteCol(0x00);
		WriteCol(0x00);
		GotoXP(8,5);
		WriteString("<Credit> ");
		break;
	default:
		break;
	}
}

void DisMenuIcon (uint8_t Status)
{
	switch (Status)
	{
	case 6:
		DrawImage(BackMenu, 82,113,2,5);
		break;
	case 1:
		DrawImage(AlarmMenu, 82,113,2,5);
		break;
	case 2:
		DrawImage(CounterMenu, 82,113,2,5);
		break;
	case 3:
		DrawImage(FlashMenu, 82,113,2,5);
		break;
	case 4:
		DrawImage(SettingMenu, 82,113,2,5);
		break;
	case 5:
		DrawImage(CreditMenu, 82,113,2,5);
		break;
	default:
	}
	GotoXP(78,1);
	WriteCol(0xF0);
	uint8_t i;
	for (i = 80; i<= 116; i++)
		WriteCol(0x10);
	WriteCol(0xF0);
	GotoXP(78,6);
	WriteCol(0x0F);
	for (i = 80; i<= 116; i++)
		WriteCol(0x08);
	WriteCol(0x0F);
}
