/* Global Structs ------------------------------------------------------------*/
#ifndef REALTIMESTRUCT_H_
#define REALTIMESTRUCT_H_

struct Rtctime
{
	uint8_t hour10;
	uint8_t hour;
	uint8_t min10;
	uint8_t min;
	uint8_t sec10;
	uint8_t sec;
	uint8_t date;
	uint8_t day10;
	uint8_t day;
	uint8_t mon10;
	uint8_t mon;
	uint8_t year10;
	uint8_t year;
};

#endif

#ifndef ALARMSTRUCT_H_
#define ALARMSTRUCT_H_

struct AlarmStruct
{
	uint8_t hour10;
	uint8_t hour;
	uint8_t min10;
	uint8_t min;
	uint8_t date;
	uint8_t enable;
};

#endif

#ifndef COUNTERSTRUCT_H_
#define COUNTERSTRUCT_H_

struct CounterStruct
{
	uint8_t min10;
	uint8_t min;
	uint8_t sec10;
	uint8_t sec;
	uint8_t decisec;
	uint8_t centisec;
	uint8_t enable;
};

#endif
