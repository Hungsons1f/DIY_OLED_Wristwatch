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
#include "..\inc\Number.h"
#include "..\inc\Buffer.h"
#include "..\inc\Counter.h"
#include "..\inc\TypeStruct.h"

/* Global Variables ----------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void DisCount (volatile struct CounterStruct *count)
{
	DrawImage(Dots,0+dos,7+dos,2,5);
	switch (count->min10)
	{
	case 0:
		DrawImage(Zero,0+h10os,17+h10os,2,5);
		break;
	case 1:
		DrawImage(One,0+h10os,17+h10os,2,5);
		break;
	case 2:
		DrawImage(Two,0+h10os,17+h10os,2,5);
		break;
	case 3:
		DrawImage(Three,0+h10os,17+h10os,2,5);
		break;
	case 4:
		DrawImage(Four,0+h10os,17+h10os,2,5);
		break;
	case 5:
		DrawImage(Five,0+h10os,17+h10os,2,5);
		break;
	case 6:
		DrawImage(Six,0+h10os,17+h10os,2,5);
		break;
	case 7:
		DrawImage(Seven,0+h10os,17+h10os,2,5);
		break;
	case 8:
		DrawImage(Eight,0+h10os,17+h10os,2,5);
		break;
	case 9:
		DrawImage(Nine,0+h10os,17+h10os,2,5);
		break;
	}

	switch (count->min)
	{
	case 0:
		DrawImage(Zero,0+hos,17+hos,2,5);
		break;
	case 1:
		DrawImage(One,0+hos,17+hos,2,5);
		break;
	case 2:
		DrawImage(Two,0+hos,17+hos,2,5);
		break;
	case 3:
		DrawImage(Three,0+hos,17+hos,2,5);
		break;
	case 4:
		DrawImage(Four,0+hos,17+hos,2,5);
		break;
	case 5:
		DrawImage(Five,0+hos,17+hos,2,5);
		break;
	case 6:
		DrawImage(Six,0+hos,17+hos,2,5);
		break;
	case 7:
		DrawImage(Seven,0+hos,17+hos,2,5);
		break;
	case 8:
		DrawImage(Eight,0+hos,17+hos,2,5);
		break;
	case 9:
		DrawImage(Nine,0+hos,17+hos,2,5);
		break;
	}

	switch (count->sec10)
	{
	case 0:
		DrawImage(Zero,0+m10os,17+m10os,2,5);
		break;
	case 1:
		DrawImage(One,0+m10os,17+m10os,2,5);
		break;
	case 2:
		DrawImage(Two,0+m10os,17+m10os,2,5);
		break;
	case 3:
		DrawImage(Three,0+m10os,17+m10os,2,5);
		break;
	case 4:
		DrawImage(Four,0+m10os,17+m10os,2,5);
		break;
	case 5:
		DrawImage(Five,0+m10os,17+m10os,2,5);
		break;
	case 6:
		DrawImage(Six,0+m10os,17+m10os,2,5);
		break;
	case 7:
		DrawImage(Seven,0+m10os,17+m10os,2,5);
		break;
	case 8:
		DrawImage(Eight,0+m10os,17+m10os,2,5);
		break;
	case 9:
		DrawImage(Nine,0+m10os,17+m10os,2,5);
		break;
	}

	switch (count->sec)
	{
	case 0:
		DrawImage(Zero,0+mos,17+mos,2,5);
		break;
	case 1:
		DrawImage(One,0+mos,17+mos,2,5);
		break;
	case 2:
		DrawImage(Two,0+mos,17+mos,2,5);
		break;
	case 3:
		DrawImage(Three,0+mos,17+mos,2,5);
		break;
	case 4:
		DrawImage(Four,0+mos,17+mos,2,5);
		break;
	case 5:
		DrawImage(Five,0+mos,17+mos,2,5);
		break;
	case 6:
		DrawImage(Six,0+mos,17+mos,2,5);
		break;
	case 7:
		DrawImage(Seven,0+mos,17+mos,2,5);
		break;
	case 8:
		DrawImage(Eight,0+mos,17+mos,2,5);
		break;
	case 9:
		DrawImage(Nine,0+mos,17+mos,2,5);
		break;
	}

	switch (count->decisec)
	{
	case 0:
		DrawImage(Zeros,0+s10os,8+s10os,3,5);
		break;
	case 1:
		DrawImage(Ones,0+s10os,8+s10os,3,5);
		break;
	case 2:
		DrawImage(Twos,0+s10os,8+s10os,3,5);
		break;
	case 3:
		DrawImage(Threes,0+s10os,8+s10os,3,5);
		break;
	case 4:
		DrawImage(Fours,0+s10os,8+s10os,3,5);
		break;
	case 5:
		DrawImage(Fives,0+s10os,8+s10os,3,5);
		break;
	case 6:
		DrawImage(Sixs,0+s10os,8+s10os,3,5);
		break;
	case 7:
		DrawImage(Sevens,0+s10os,8+s10os,3,5);
		break;
	case 8:
		DrawImage(Eights,0+s10os,8+s10os,3,5);
		break;
	case 9:
		DrawImage(Nines,0+s10os,8+s10os,3,5);
		break;
	}

	switch (count->centisec)
	{
	case 0:
		DrawImage(Zeros,0+sos,8+sos,3,5);
		break;
	case 1:
		DrawImage(Ones,0+sos,8+sos,3,5);
		break;
	case 2:
		DrawImage(Twos,0+sos,8+sos,3,5);
		break;
	case 3:
		DrawImage(Threes,0+sos,8+sos,3,5);
		break;
	case 4:
		DrawImage(Fours,0+sos,8+sos,3,5);
		break;
	case 5:
		DrawImage(Fives,0+sos,8+sos,3,5);
		break;
	case 6:
		DrawImage(Sixs,0+sos,8+sos,3,5);
		break;
	case 7:
		DrawImage(Sevens,0+sos,8+sos,3,5);
		break;
	case 8:
		DrawImage(Eights,0+sos,8+sos,3,5);
		break;
	case 9:
		DrawImage(Nines,0+sos,8+sos,3,5);
		break;
	}
}
