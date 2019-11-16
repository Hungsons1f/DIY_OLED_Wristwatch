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

/* Private defines -----------------------------------------------------------*/
#define OledAdd				0x78

#define ctrl				0x00
#define data				0x40
#define ColumnMax				127
#define PageMax				7

#define Contrast 				0x81
#define ChargePump 			0x8D
#define AddressMode 			0x20
#define EntireDisplay				0xA4
#define Inverse				0xA6
#define DisplayOn				0xAE
#define ColumnAddress			0x21
#define PageAddress 			0x22
#define MuxRatio				0xA8
#define DisplayOffset			0xD3
#define DisplayStartLine			0x40
#define SegmentRemap			0xA0
#define COMOutScanDir063			0xC0
#define COMOutScanDir630			0xC8
#define COMPinHWConf			0xDA
#define DisplayOscFreq			0xD5
#define Precharge 				0xD9
#define SetVcomDetect			0xDB

#define LowColStartAdd                  0x00
#define HighColStartAdd                 0x10
#define PageStartAdd                    0xB0


/* Private function prototypes -----------------------------------------------*/
void OledPreWrite (uint8_t FirstByte);
void OledWriteCmd (uint8_t Command, uint8_t NumberOfPara, uint8_t Para1, uint8_t Para2);
void OledInit (void);
void OledUpdate (uint8_t *screen, uint8_t inverse);
void OledEnable (uint8_t on);
