#ifndef _spi_led_h
#define _spi_led_h
#include <Arduino.h>
#include "delare.h"
//******************************
class led_function {
public:
  void export_led(uint8_t digit, uint8_t point1, uint8_t point2);
  void shiftOutWithDelay(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
};
extern led_function disp;
#endif
