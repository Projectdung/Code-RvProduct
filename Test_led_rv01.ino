//Process Display LED.
#include <Arduino.h>
#include "delare.h"
#include "spi_led.h"

var_all var;
led_function disp;


int inc = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(SDA, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(LAT, OUTPUT);
  digitalWrite(SDA, LOW);
  digitalWrite(SCK, LOW);
  digitalWrite(LAT, LOW);

  //event.Write_Color(Code_Color::RED);
  for (inc = 0; inc <= 9; inc++) {

    //shiftOut(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    disp.shiftOutWithDelay(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    //shiftOut(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    disp.shiftOutWithDelay(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    //shiftOut(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    disp.shiftOutWithDelay(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    //shiftOut(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    disp.shiftOutWithDelay(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    //shiftOut(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    disp.shiftOutWithDelay(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    //shiftOut(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);
    disp.shiftOutWithDelay(SDA, SCK, LSBFIRST, var.led.digit_code[inc]);

    digitalWrite(LAT, HIGH);
    delay(50);
    digitalWrite(LAT, LOW);
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
