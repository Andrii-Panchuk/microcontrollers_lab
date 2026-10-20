#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>

struct SensorData {
    float temperature;
    float humidity;
    bool dht_status_ok;
    int soil_moisture; 
    int gas_level;     
};


#define PIN_BUTTON_1        4
#define PIN_BUTTON_2        A3
#define PIN_BUZZER          12
#define PIN_LED             A0
#define PIN_DHT11           2
#define PIN_SERVO           9
#define PIN_SOIL_MOISTURE   A1 
#define PIN_MQ2             A2

#define DHTTYPE             DHT11

#define ADC_MAX_VALUE       1023.0f

static const uint8_t SEG_PINS[8] = {7, 6, 5, 10, 11, 8, 3, 4};

#define SEG_ACTIVE_LOW      1      

#define GROUP               1
#define VARIANT             14      
#define BUZZER_FREQ_HZ      500
#define COUNT_STEP_MS       500
#define BEEP_SHORT_MS       150
#define BEEP_LONG_MS        4000   

#define LED_BLINK_COUNT     14     
#define LED_HALF_PERIOD_MS  250

#define TEMP_THRESHOLD_C    36
#define SERVO_ANGLE_HOT     10
#define SERVO_ANGLE_NORMAL  45

#define SENSOR_INTERVAL_MS  2000
#define SERIAL_BAUD         9600

#define START_DIGIT         1

#define LCD_ADDR            0x27
#define DIGIT_COL           7    
#define DIGIT_ROW           0  

#endif /* CONFIG_H */