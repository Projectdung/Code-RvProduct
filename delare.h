#ifndef _delare_h
#define _delare_h
#include <Arduino.h>
#include <SPI.h>
/**********define PIN IO************************/


#define SDA 4   //D3
#define SCK 5   //D1
#define LAT 6  //D4


//*******************************************
typedef struct data_led {
  uint8_t digit_code[11] = { 0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe0, 0xfe, 0xf6, 0x00 };
  uint8_t char_code[4] = { 0xb6, 0x9e, 0xc0, 0x1c };
  uint8_t sign_code = 0xFD;
  uint8_t code;
  uint8_t digit[6];
  uint16_t Data1 = 0, Data2 = 0;
} data_led;
//*******************************************

//*******************************************
typedef struct
{
  struct data_led led;
} var_all;
extern var_all var;
#endif
