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


/* Private Function Prototypes -----------------------------------------------*/
void GotoXP (uint8_t x, uint8_t p);
void NextPosition (uint8_t xpos, uint8_t ppos);
void WriteCol (uint8_t Col);
void WriteChar (uint8_t Char);
void WriteString (uint8_t String[]);
void SolidFill (uint8_t Fill);
void DrawBitmap (const uint8_t *bmp);
void DrawIcon (const uint8_t *Icon, uint8_t Size);
void DrawImage (const uint8_t *bmp, uint8_t xbegin, uint8_t xend, uint8_t pbegin, uint8_t pend);
void InverseImage (uint8_t xbegin, uint8_t xend, uint8_t pbegin, uint8_t pend);
void UpdateScreen (uint8_t inverse);
