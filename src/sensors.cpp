#include <Arduino.h>
#include <DHT.h>
#include "sensors.h"
#include "config.h"

static DHT dht(PIN_DHT11, DHTTYPE);

void sensors_init(void)
{
    pinMode(PIN_BUTTON_1, INPUT_PULLUP);
    pinMode(PIN_BUTTON_2, INPUT_PULLUP);
    
    dht.begin();
}

int button_1_pressed(void)
{
    return digitalRead(PIN_BUTTON_1) == LOW;
}

int button_2_pressed(void)
{
    return digitalRead(PIN_BUTTON_2) == LOW;
}

SensorData read_all_sensors(void)
{
    SensorData data;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        data.dht_status_ok = false;
        data.temperature = 0.0;
        data.humidity = 0.0;
    } else {
        data.dht_status_ok = true;
        data.temperature = t;
        data.humidity = h;
    }

    data.soil_moisture = (int)((analogRead(PIN_SOIL_MOISTURE) / ADC_MAX_VALUE ) * 100.f);
    data.gas_level = (int)((analogRead(PIN_MQ2) / ADC_MAX_VALUE ) * 100.f);

    return data;
}