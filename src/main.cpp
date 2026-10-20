#include <Arduino.h>
#include "config.h"
#include "algoritms.h"
#include "sensors.h"
//#include "seven_segment.h"
#include "lcd_display.h"
#include "show_sensors_stats.h"

static unsigned long last_sensor_time = 0;

static SensorData sensor_data;

static uint32_t lastSwitch = 0;
static bool showSensors = true;

void setup() {
  sensors_init();
  lcd_init();
  //seg_init();
  algoritm_peripherals_init();
  show_init();
}

void loop() {
  if(button_1_pressed()){
    algoritm_digit_countdown();
  }
  if(button_2_pressed()){
    algoritm_blink_led();
  }

  unsigned long now = millis();

  if (now - lastSwitch >= PAGE_MS) {
    lastSwitch = now;
    showSensors = !showSensors;
    if (showSensors) lcd_show_sensors(&sensor_data);
    else             lcd_show_main_text();
  }

  if (millis() - last_sensor_time >= SENSOR_INTERVAL_MS) {
    last_sensor_time = millis();

    sensor_data = read_all_sensors();
    algoritm_servo(sensor_data.temperature);
    show_sensor_data(sensor_data);
  }
}