
#include "spi_led.h"

const unsigned long bitDelayMicros = 1000;  // Độ trễ giữa các bit (10 microseconds)

void led_function::export_led(uint8_t digit, uint8_t point1, uint8_t point2) {
  uint8_t in = 0;
  //var.counter.product = var.led.counter / var.counter.sample;
  //  var.data.fTemp = int(var.lora.fTemp * 10);
  //  var.data.fHumi = int(var.lora.fHumi * 10);
  var.led.digit[0] = var.led.Data1 % 10;
  var.led.digit[1] = (var.led.Data1 / 10) % 10;
  var.led.digit[2] = (var.led.Data1 / 100) % 10;

  var.led.digit[3] = var.led.Data2 % 10;
  var.led.digit[4] = (var.led.Data2 / 10) % 10;
  var.led.digit[5] = (var.led.Data2 / 100) % 10;

  for (in = 0; in < digit; in++) {
    var.led.code = var.led.digit_code[var.led.digit[in]];
    if (((point1 == in) || (point2 == in)) & ((point1 != 0) || point2 != 3)) var.led.code = var.led.code + 1;
    //shiftOut(SDA, SCK, LSBFIRST, var.led.code);
    led_function::shiftOutWithDelay(SDA, SCL, LSBFIRST, var.led.code);
  }
  digitalWrite(LAT, HIGH);
  delay(50);
  digitalWrite(LAT, LOW);
}
/**********************************************************/
void led_function::shiftOutWithDelay(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {
  for (int i = 0; i < 8; i++) {
    if (bitOrder == MSBFIRST) {
      digitalWrite(dataPin, (val & (1 << (7 - i))) ? HIGH : LOW);
    } else {
      digitalWrite(dataPin, (val & (1 << i)) ? HIGH : LOW);
    }
    delayMicroseconds(bitDelayMicros);  // Đợi để giảm tốc độ xung clock
    digitalWrite(clockPin, HIGH);
    delayMicroseconds(bitDelayMicros);  // Đợi để giảm tốc độ xung clock
    digitalWrite(clockPin, LOW);
  }

  //Trong ví dụ này, hàm shiftOutWithDelay() được sử dụng thay vì shiftOut(). Hàm này thêm một độ trễ (delay) giữa mỗi bit trước khi nó được truyền đi, giúp giảm tốc độ xung clock xuống. Điều này cho phép bạn kiểm soát tốc độ truyền dữ liệu theo mong muốn. Hãy thay đổi giá trị bitDelayMicros để điều chỉnh tốc độ truyền dữ liệu theo ý muốn của bạn.
}