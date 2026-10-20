#include <Arduino.h>
#include "algoritms.h"
#include "config.h"
//#include "seven_segment.h"
#include "lcd_display.h"
#include <Servo.h>

static Servo servo;

void algoritm_peripherals_init(void) {
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  servo.attach(PIN_SERVO);
}

void algoritm_digit_countdown(void) {
  lcd_clear();
    for(int digit = START_DIGIT; digit <= 9; digit++){
        //seg_show_digit(digit);
        lcd_set_digit(digit);
        if(digit == 9){
            tone(PIN_BUZZER, BUZZER_FREQ_HZ, BEEP_LONG_MS);
            delay(4000);
        }else{
          tone(PIN_BUZZER, BUZZER_FREQ_HZ, BEEP_SHORT_MS);
          delay(500);
        }
    }
    lcd_clear();
    //seg_show_digit(0);
}

void algoritm_blink_led(void) {
  for (int i = 0; i < LED_BLINK_COUNT; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(LED_HALF_PERIOD_MS);
    digitalWrite(PIN_LED, LOW);
    delay(LED_HALF_PERIOD_MS);
  }
}

void algoritm_servo(int16_t temp){
    if(temp >= 36){
        servo.write(10);
      }else{
        servo.write(45);
      }
}