/**
  ******************************************************************************
  * @file    main.c
  * @author  Hung Son Nguyen
  * @version V1.0
  * @date    14/08/2019
  * @brief   Main program body
  ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "..\Application\inc\sonx.h"
#include "..\Application\inc\LMC.h"
#include "..\Application\inc\Number.h"
#include "..\Application\inc\pif.h"
#include "..\Application\inc\Menu.h"
#include "..\Application\inc\Buffer.h"
#include "..\Application\inc\Idling.h"
#include "..\Application\inc\TypeStruct.h"
#include "..\Application\inc\Screen.h"
#include "..\Application\inc\Global.h"
#include "..\Application\inc\Alarm.h"
#include "..\Application\inc\Counter.h"

#include "..\Firmware\inc\oled_i2c.h"
#include "..\Firmware\inc\Beep.h"
#include "..\Firmware\inc\rtc_ds3231_i2c.h"
#include "..\Firmware\inc\Power_adc.h"
#include "..\Firmware\inc\Led_gpio.h"
#include "..\Firmware\inc\Timer.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/
uint32_t timex =80000;
uint8_t clk;
uint8_t string[30] = "Nguyen Hung Son";

uint8_t numicon = 1;
volatile uint16_t Power = 0;
volatile uint8_t plug = 0;
uint8_t sound = ENABLE;
uint8_t light = ENABLE;
volatile uint8_t screen = ENABLE;
volatile uint8_t chkalarm = DISABLE;
volatile uint8_t alarmrhythm = 0;
uint8_t inversescreen = 0x00;
uint8_t settime = DISABLE;

volatile struct Rtctime time1 = {0,0,0,0,0,0,1,0,1,0,1,0,0};					/* Realtime got from RTC */
volatile uint8_t Up;
volatile uint8_t Down;
volatile uint8_t Push;

uint8_t StateLevel = IdlingLevel;
uint8_t PreviousState = 0;
uint8_t Func = AlarmFunc;
volatile uint8_t Changing = done;

struct AlarmStruct Alarm1[5] = {				/* Struct store alarms information, including 5 alarms */
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0
};

uint8_t homnay[7]= {0x00,0x00,0x00,0x01,0x00,0x00,0x00};



void main(void)
{

	GPIO_Init(GPIOC,GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);                 //Config ADC Power Reading GPIO
        
	ADCInit();
	PWSenseInit();
	BeepInit();
	OledInit();
    LedInit();
    TimerInit();

    GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_PU_IT);
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_PU_IT);
    GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_IN_PU_IT);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);

    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_IN_PU_IT);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOB, EXTI_SENSITIVITY_RISE_FALL);

    enableInterrupts();

    //RtcSend(homnay);
    SendTime(&time1);
    RtcSendByte(0x0E, 0x00);

    SolidFill(0x00);
    IdlingState(&numicon,&time1);
    Led1ON();
    
    clk = CLK_GetClockFreq();



    /* UpdateScreen();
        TIM2_Cmd(DISABLE);
        clk = TIM2_GetCounter();*/



    
  /* Infinite loop */


  while (1)
  {
	  /* Precomputing and enable screen --------*/
	  /* Turn off screen after 5 secs --------*/
	  static uint8_t prescreen = ENABLE;
	  if (prescreen != screen)
	  {
		  OledEnable(screen);
		  prescreen = screen;
	  }

	  /* If charger is connected -------------*/
	  if (plug)
	  {
		  numicon |= ICharge;
		  Led1ON();
	  }
	  else
	  {
		  numicon &=~ ICharge;
		  Led1OFF();
	  }

	  /* Alarms ring -------------------------*/
	  if (chkalarm)
	  {
		  chkalarm = DISABLE;
		  uint8_t i1 = 0;
		  for (i1 = 0;i1 <=4;i1++)
		  {
			  if (CheckAlarm((Alarm1+i1), &time1))
			  {
				  if (StateLevel != OutStateAlarmLevel)
				  {
					  PreviousState = StateLevel;
				  }
				  screen = ENABLE;
				  StateLevel = OutStateAlarmLevel;
				  SolidFill(0x00);
			  }
		  }
	  }



	  /*Alarm Ring - OutState level ------------*/
	  if (StateLevel == OutStateAlarmLevel)
	  {
		  TimerRun50us(ENABLE);
          if (alarmrhythm > 20)
        	  alarmrhythm = 20;
		  switch (alarmrhythm)
		  {
		  case 0:
			  alarmrhythm = 20;
			  break;
		  case 20:
			  Led1ON();
			  //Led2OFF();
			  RunBeep(1);
			  inversescreen = 0xFF;
			  break;
		  case 18:
			  StopBeep();
			  break;
		  case 16:
			  RunBeep(2);
			  break;
		  case 15:
			  Led1OFF();
			  Led2ON();
			  break;
		  case 14:
			  StopBeep();
			  break;
		  case 12:
			  RunBeep(4);
			  break;
		  case 10:
			  Led1ON();
			  //Led2OFF();
			  StopBeep();
			  inversescreen = 0x00;
			  break;
		  case 5:
			  Led1OFF();
			  Led2ON();
			  break;
		  }

		  AlarmRingState(&numicon, &time1);
		  screen = ENABLE;
		  if (Push || Up || Down)
		  {
			  Push = 0;
			  Up = 0;
			  Down = 0;
			  alarmrhythm = 0;
			  StateLevel = PreviousState;
			  SolidFill(0x00);
			  TimerRun50us(DISABLE);
			  Led1OFF();
			  Led2OFF();
			  StopBeep();
			  inversescreen = 0x00;
		  }
	  }

	  /*Idling Sreen - Top level ---------------*/
	  if (StateLevel == IdlingLevel)
	  {
		  IdlingState(&numicon,&time1);  //tat ngat up, down
		  if (Push)
		  {
			  Push = 0;
			  StateLevel = MenuLevel;
			  SolidFill(0x00);
		  }
	  }

	  if (StateLevel == MenuLevel)
	  {
		  MenuState(&numicon, Func, &time1);
		  if (Down)
		  {
              Down = 0;
			  Func++;
			  if (Func > BackFunc)	Func = AlarmFunc;
		  }
		  if (Up)
		  {
			  Up = 0;
              Func--;
			  if (Func < AlarmFunc)	Func = BackFunc;
		  }
		  if (Push)
		  {
			  Push = 0;
			  if (Func == BackFunc)
			  {
				  StateLevel = IdlingLevel;
				  Func = AlarmFunc;
			  }
			  else
			  {
				  StateLevel = FunctionLevel;
			  }
			  SolidFill(0x00);
		  }
	  }

	  if (StateLevel == FunctionLevel)
	  {
		  switch (Func)
		  {
		  case AlarmFunc:
			  static uint8_t Alarmline = AlarmLine1;
			  static uint8_t AlarmPos = APNull;
			  AlarmFuncState(Alarm1,&Alarmline,&AlarmPos);
			  uint8_t ii = 0, on = 0;
			  for (ii = 0; ii< 4; ii++)
			  {
				  if (Alarm1[ii].enable) on++;
			  }
			  if (on) numicon |= IAlarm;
			  else numicon &=~ IAlarm;

			  if (Down && !AlarmPos)
			  {
	              Down = 0;
				  Alarmline++;
				  if (Alarmline > AlarmBack)	Alarmline = AlarmLine1;
			  }
			  if (Up && !AlarmPos)
			  {
				  Up = 0;
	              Alarmline--;
				  if (Alarmline < AlarmLine1)	Alarmline = AlarmBack;
			  }

			  if (Push || AlarmPos)
			  {
				  //Push = 0;
				  if (Alarmline == AlarmBack)
				  {
					  StateLevel = MenuLevel;
					  Alarmline = AlarmLine1;
					  SolidFill(0x00);
				  }
				  else
				  {
					  if (Push) AlarmPos++;
					  if (AlarmPos > APSun) AlarmPos = APNull;

					  switch (AlarmPos)
					  {
					  case APEnable:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].enable ^= 0x01;
						  }
						  break;
					  case APHour:
						  uint8_t AlarmHour = Alarm1[Alarmline-1].hour10 * 10 + Alarm1[Alarmline-1].hour;
						  if (Up)
						  {
							  Up = 0;
							  AlarmHour ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  AlarmHour --;
						  }
						  if (AlarmHour > 23) AlarmHour = 0;
						  if (AlarmHour == 0xFF) AlarmHour = 23;
						  Alarm1[Alarmline-1].hour10 = AlarmHour/10;
						  Alarm1[Alarmline-1].hour = AlarmHour - Alarm1[Alarmline-1].hour10*10;
						  break;
					  case APMin10:
						  if (Up)
						  {
							  Up = 0;
							  Alarm1[Alarmline-1].min10 ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Alarm1[Alarmline-1].min10 --;
						  }
						  if (Alarm1[Alarmline-1].min10 > 5) Alarm1[Alarmline-1].min10 = 0;
						  if (Alarm1[Alarmline-1].min10 == 0xFF) 
                                                    Alarm1[Alarmline-1].min10 = 5;
						  break;
					  case APMin:
						  if (Up)
						  {
							  Up = 0;
							  Alarm1[Alarmline-1].min ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Alarm1[Alarmline-1].min --;
						  }
						  if (Alarm1[Alarmline-1].min > 9) Alarm1[Alarmline-1].min = 0;
						  if (Alarm1[Alarmline-1].min == 0xFF) Alarm1[Alarmline-1].min = 9;
						  break;
					  case APMon:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Monday;
						  }
						  break;
					  case APTue:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Tuesday;
						  }
						  break;
					  case APWed:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Wednesday;
						  }
						  break;
					  case APThu:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Thursday;
						  }
						  break;
					  case APFri:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Friday;
						  }
						  break;
					  case APSat:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Saturday;
						  }
						  break;
					  case APSun:
						  if (Up || Down)
						  {
							  Up = 0;
							  Down = 0;
							  Alarm1[Alarmline-1].date ^= Sunday;
						  }
						  break;
					  }

				  }
				  Push = 0;
			  }
			  break;

		  case FlashFunc:
			  static uint8_t Flashline = FlashLine1;
			  FlashFuncState(&Flashline);
			  if (Down)
			  {
	              Down = 0;
				  Flashline++;
				  if (Flashline > FlashBack)	Flashline = FlashLine1;
			  }
			  if (Up)
			  {
				  Up = 0;
	              Flashline--;
				  if (Flashline < FlashLine1)	Flashline = FlashBack;
			  }

			  if (Push)
			  {
				  Push = 0;
				  if (Flashline == FlashBack)
				  {
					  StateLevel = MenuLevel;
					  Flashline = FlashLine1;
					  SolidFill(0x00);
				  }
			  }
			  break;

		  case CounterFunc:
			  static uint8_t Counterline = CounterLine1;
			  CounterFuncState(&Counterline);
			  if (Down)
			  {
	              Down = 0;
				  Counterline++;
				  if (Counterline > CounterBack)	Counterline = CounterLine1;
			  }
			  if (Up)
			  {
				  Up = 0;
	              Counterline--;
				  if (Counterline < CounterLine1)	Counterline = CounterBack;
			  }

			  if (Push)
			  {
				  Push = 0;
				  if (Counterline == CounterBack)
				  {
					  StateLevel = MenuLevel;
					  Counterline = CounterLine1;
					  SolidFill(0x00);
				  }
			  }
			  break;

		  case SettingFunc:
			  static uint8_t Setpos = SPNull;
			  static uint8_t Setline = SetLine1;
              //static struct Rtctime time1 = {0,0,0,0,0,0,1,0,0,0,0,0,0};
			  //SettingFuncState();
			  SettingClockState(&numicon, &time1, &Setline, &Setpos);

			  settime = ENABLE;
			  if (Down && !Setpos)
			  {
	              Down = 0;
				  Setline++;
				  if (Setline > SetBack)	Setline = SetLine1;
			  }
			  if (Up && !Setpos)
			  {
				  Up = 0;
	              Setline--;
				  if (Setline < SetLine1)	Setline = SetBack;
			  }

			  if (Push || Setpos)
			  {
				  switch (Setline)
				  {
				  case SetBack:
					  settime = DISABLE;
					  StateLevel = MenuLevel;
					  Setline = SetLine1;
					  SolidFill(0x00);
					  break;
				  case SetSave:
					  SendTime(&time1);


					  break;
				  default:
					  if (Setline == SetLine1)
					  {
						  if (Push) Setpos ++;
						  if (Setpos > SPMin)   Setpos = SPNull;
					  }
					  if (Setline == SetLine2)
					  {
						  if (Setpos == SPNull) Setpos = SPMin;
						  if (Push) Setpos ++;
						  if (Setpos > SPDay)   Setpos = SPNull;
					  }
					 
					  switch (Setpos)
					  {
					  case SPHour:
						  int8_t Sethour = time1.hour10 * 10 + time1.hour;
						  if (Up)
						  {
							  Up = 0;
							  Sethour ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Sethour --;
						  }
						  if (Sethour > 23) Sethour = 0;
						  if (Sethour < 0) Sethour = 23;
						  time1.hour10 = (uint8_t)Sethour/10;
						  time1.hour = (uint8_t)Sethour - time1.hour10*10;
						  break;
					  case SPMin10:
						  int8_t Setmin10 = time1.min10;
						  if (Up)
						  {
							  Up = 0;
							  Setmin10 ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setmin10 --;
						  }
						  if (Setmin10 > 5) Setmin10 = 0;
						  if (Setmin10 < 0) Setmin10 = 5;
                          time1.min10 = (uint8_t) Setmin10;
						  break;
					  case SPMin:
						  int8_t Setmin = time1.min;
						  if (Up)
						  {
							  Up = 0;
							  Setmin ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setmin --;
						  }
						  if (Setmin > 9) Setmin = 0;
						  if (Setmin < 0) Setmin = 9;
                          time1.min = (uint8_t)Setmin;
						  break;

					  case SPDate:
						  int8_t Setdate = time1.date;
						  if (Up)
						  {
							  Up = 0;
							  Setdate ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setdate --;
						  }
						  if (Setdate > 7) Setdate = 1;
						  if (Setdate < 1) Setdate = 7;
                          time1.date = (uint8_t)Setdate;
						  break;
					  case SPYear10:
						  int8_t Setyear10 = time1.year10;
						  if (Up)
						  {
							  Up = 0;
							  Setyear10 ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setyear10 --;
						  }
						  if (Setyear10 > 9) Setyear10 = 0;
						  if (Setyear10 < 0) Setyear10 = 9;
                          time1.year10 = (uint8_t)Setyear10;
						  break;
					  case SPYear:
						  int8_t Setyear = time1.year;
						  if (Up)
						  {
							  Up = 0;
							  Setyear ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setyear --;
						  }
						  if (Setyear > 9) Setyear = 0;
						  if (Setyear < 0) Setyear = 9;
                          time1.year = (uint8_t)Setyear;
						  break;
					  case SPMonth:
						  int8_t Setmonth = time1.mon10 *10 + time1.mon;
						  if (Up)
						  {
							  Up = 0;
							  Setmonth ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setmonth --;
						  }
						  if (Setmonth > 12) Setmonth = 0;
						  if (Setmonth < 0) Setmonth = 12;
						  time1.mon10 = (uint8_t)Setmonth/10;
						  time1.mon = (uint8_t)Setmonth - time1.mon10*10;
						  break;

					  case SPDay:
						  int8_t Setday = time1.day10*10+time1.day;
						  if (Up)
						  {
							  Up = 0;
							  Setday ++;
						  }
						  if (Down)
						  {
							  Down = 0;
							  Setday --;
						  }
						  uint8_t  Setmonthd = time1.mon10*10 + time1.mon;
						  uint8_t  Setyeard = time1.year10*10 + time1.year;
						  switch (Setmonthd)
						  {
						  case 2:
							  if (((Setyeard%4 == 0 && Setyeard%100 !=0) || Setyeard % 400 == 0))
							  {
								  if (Setday > 29) Setday = 0;
								  if (Setday < 0) Setday = 29;
							  }
							  else
							  {
								  if (Setday > 28) Setday = 0;
								  if (Setday < 0) Setday = 28;
							  }
							  break;
						  case 4:
						  case 6:
						  case 9:
						  case 11:
							  if (Setday > 30) Setday = 0;
							  if (Setday < 0) Setday = 30;
							  break;
						  default:
							  if (Setday > 31) Setday = 0;
							  if (Setday < 0) Setday = 31;
						  }
						  time1.day10 = (uint8_t)Setday/10;
						  time1.day = (uint8_t)Setday - time1.day10*10;
						  break;
					  }
				  }
				  Push = 0;
			  }
			  break;

		  case CreditFunc:
			  static uint8_t CreditState = Cydeus;
			  CreditFuncState(&CreditState);
			  if (Push)
			  {
				  CreditState ++;
				  if (CreditState >= CreditNull)
				  {
					  StateLevel = MenuLevel;
					  CreditState = Cydeus;
					  SolidFill(0x00);
				  }
			  }
			  Push = 0;
			  Up = 0;
			  Down = 0;
			  break;
		  }
	  }

	  static uint8_t haltstart = 15;
	  if (!(haltstart--))
	  {
		if (StateLevel != OutStateAlarmLevel) 
                  halt();
		  haltstart = 15;
	  }
  }
  
}


/*GotoXP(20,3);
uint8_t loading[] = "Loading...   ";
int8_t i = -1;
while (loading[i++])
{
	WriteChar(loading[i]);
	Delay(3000);
}
i = -1;
while (i++ <99)
{
	GotoXP(100,3);
	uint8_t ii = (i/10);
	WriteChar(ii+48);
	WriteChar(i - ii*10 +48);
	WriteChar('%');
	Delay((uint32_t)(3000+  i*180));
}
SolidFill(0x00);
GotoXP(20,3);
WriteString("SYSTEM HACKED!");
Delay(200000);
GotoXP(20,4);
WriteString("DATA LOOTING...");
Delay(200000);
uint8_t j;
TIM2_Cmd(DISABLE);
for (j = 255; j>0; j-=3)
{
    OledWriteCmd(Contrast,1,j,0);
    Delay(500);
    UpdateScreen();
}
OledWriteCmd(Contrast,1,0x00,0);
DrawBitmap(pif);

for (j = 0; j<254; j+=3)
{

	OledWriteCmd(Contrast,1,j,0);
    Delay(500);
    UpdateScreen();
}*/


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
