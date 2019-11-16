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
#define IBattery				0x01
#define ICharge					0x02
#define IAlarm					0x04
#define ISound					0x08
#define ICount					0x10

/* Global Variables ----------------------------------------------------------*/
static const unsigned char IconBattery[] = {0x3E,0x22,0x22,0x22,0x22,0x22,0x1C,0x00};
static const unsigned char IconCharge[] = {0x0C,0x4E,0x6F,0x39,0x18,0x00};
static const unsigned char IconAlarm[] = {0x10,0x1E,0x5F,0x1E,0x10,0x00};
static const unsigned char IconSound[] = {0x1C,0x3E,0x7F,0x00,0x14,0x08,0x14,0x00};
static const unsigned char IconCount[] = {0x1C,0x22,0x41,0x4F,0x49,0x22,0x1C,0x00};

static const uint8_t Datetype[][6] = {"Sun, ","Mon, ", "Tue, ", "Wed, ", "Thu, ", "Fri, ", "Sat, "};

/* Private function prototypes -----------------------------------------------*/
void Icon(uint8_t* Gicon);
void DisTime(volatile struct Rtctime *time, uint8_t State);
void GetTime (volatile struct Rtctime *time);
void SendTime (volatile struct Rtctime *time);
void Delay(uint32_t delayms);
