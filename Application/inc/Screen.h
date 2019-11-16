/**
  ******************************************************************************
  * @file    oled_i2c.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    28/06/2019
  * @brief   Oled defines, function headers, running with I2C communication
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "TypeStruct.h"

/* Private defines -----------------------------------------------------------*/
/* Level ---------*/
#define IdlingLevel 					0
#define MenuLevel						1
#define FunctionLevel					2
#define LowerLevel						3
#define OutStateAlarmLevel				4

/* Function ------*/
#define AlarmFunc						1
#define CounterFunc						2
#define FlashFunc						3
#define SettingFunc						4
#define CreditFunc 						5
#define BackFunc						6

/* Button Done?---*/
#define done							0
#define nyet							1

/* Alarm Date-----*/
#define Monday							0x40
#define Tuesday							0x20
#define Wednesday						0x10
#define Thursday						0x08
#define Friday							0x04
#define Saturday						0x02
#define Sunday							0x01

/* Alarm Line-----*/
#define AlarmLine1						1
#define AlarmLine2						2
#define AlarmLine3						3
#define AlarmLine4						4
#define AlarmLine5						5
#define AlarmBack						6

/* Alarm Position Cursors----*/
#define APNull							0
#define APEnable						1
#define APHour							2
#define APMin10							3
#define APMin							4
#define APMon							5
#define APTue							6
#define APWed							7
#define APThu							8
#define APFri							9
#define APSat							10
#define APSun							11

/* Flash Lines---------------*/
#define FlashLine1						1
#define FlashLine2						2
#define FlashLine3						3
#define FlashBack						4

/* Counter Lines---------------*/
#define CounterLine1					1
#define CounterLine2					2
#define CounterBack						3

/* Setting Lines-----*/
#define SetLine1						1
#define SetLine2						2
#define SetSave							3
#define SetBack							4

/* Setting Position Cursors----*/
#define SPNull							0
#define SPHour							1
#define SPMin10							2
#define SPMin							3
#define	SPDate							4
#define SPDay							8
#define SPMonth							7
#define SPYear10						5
#define SPYear							6

/* Credit Picture Number--------*/
#define CreditNull						4
#define Cydeus							1
#define LMCuong							2
#define Payitforward					3

/* Private functions ---------------------------------------------------------*/
void IdlingState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime );
void MenuState (uint8_t *NumberOfIcon, uint8_t Function, volatile struct Rtctime *Realtime);
void AlarmFuncState(volatile struct AlarmStruct *AlarmData, uint8_t *AlarmLine, uint8_t *AlarmPos);
void FlashFuncState (uint8_t *FlashLine);
void CounterFuncState (uint8_t *CounterLine);
uint8_t CounterLowerState (volatile struct CounterStruct *counter, volatile struct Rtctime *time, uint8_t *numberoficon, uint8_t *run);
void AlarmRingState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime);
void SettingFuncState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime );
void SettingClockState (uint8_t *NumberOfIcon, volatile struct Rtctime *Realtime, uint8_t *SettingLine, uint8_t *SettingPos );
void CreditFuncState(uint8_t *numpicture);
