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
#include "..\inc\Buffer.h"
#include "..\Firmware\inc\oled_i2c.h"
#include "..\inc\fonts.h"

/* Global Variables ----------------------------------------------------------*/
uint8_t Buffer[1024];

/* Global Structs ------------------------------------------------------------*/
struct Position
{
	uint8_t x;
	uint8_t p;
} Pos;

/* Private functions ---------------------------------------------------------*/
void GotoXP (uint8_t x, uint8_t p)
{
	Pos.x = x;
	Pos.p = p;
}

void NextPosition (uint8_t xpos, uint8_t ppos)
{
	Pos.x = xpos + 1;
	if (Pos.x >127)
	{
		Pos.p = ppos + 1;
		if (Pos.p > 7)
		{
			Pos.p = 7;
			Pos.x = 127;
		}
		else Pos.x = 0;
	}
}

void WriteCol (uint8_t Col)
{
	*(Buffer + (128* Pos.p + Pos.x)) = Col;					//equation: pos = 128*y + x
	NextPosition (Pos.x,Pos.p);
}

void WriteChar (uint8_t Char)
{
	uint8_t i;
	for (i = 0; i <= 5; i++)
		WriteCol(fonta[Char - 32][i]);
}

void WriteString (uint8_t String[])
{
	uint8_t i = 0;
	while (String[i])
	{
		WriteChar(String[i]);
		i++;
	}
}

void SolidFill (uint8_t Fill)
{
	GotoXP(0,0);
	uint8_t i = 0;
	uint8_t j = 0;
	for (j = 0; j<= 7; j++)
		for (i = 0; i<= 127; i++)
		{
			WriteCol(Fill);
		}
}

void DrawBitmap (const uint8_t *bmp)
{
	GotoXP(0,0);
	uint8_t i = 0;
	uint8_t j = 0;
	uint16_t x = 0;
	for (j = 0; j<= 7; j++)
		for (i = 0; i<= 127; i++)
		{
			WriteCol((bmp[x++]^0xFF));
		}
}

void DrawIcon (const uint8_t *Icon, uint8_t Size)
{
	uint8_t i;
	for (i = 0; i < Size ; i++)
		WriteCol(*(Icon + i));
}

void DrawImage (const uint8_t *bmp, uint8_t xbegin, uint8_t xend, uint8_t pbegin, uint8_t pend)
{
	uint8_t i = xbegin;
	uint8_t j = pbegin;
	uint16_t x = 0;
	for (j = pbegin; j<= pend; j++)
	{
		GotoXP(xbegin,j);
		for (i = xbegin; i<= xend; i++)
		{
			WriteCol(bmp[x++]);
		}
	}
}

void InverseImage (uint8_t xbegin, uint8_t xend, uint8_t pbegin, uint8_t pend)
{
	uint8_t i = xbegin;
	uint8_t j = pbegin;
	for (j = pbegin; j<= pend; j++)
	{
		GotoXP(xbegin,j);
		for (i = xbegin; i<= xend; i++)
		{
			WriteCol(*(Buffer + (128* j + i)) ^ 0xFF);
		}
	}
}

void UpdateScreen (uint8_t inverse)
{
	OledUpdate(Buffer, inverse);
}
