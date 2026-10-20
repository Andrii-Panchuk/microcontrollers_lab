#include "show_sensors_stats.h"

void show_init(void){
    Serial.begin(SERIAL_BAUD);
}

void show_sensor_data(SensorData data){
    Serial.print("==========================\n");
    
    if (data.dht_status_ok) {
        Serial.print("Температура: ");
        Serial.print(data.temperature, 1);
        Serial.println(" °C");

        Serial.print("Вологість:    ");
        Serial.print(data.humidity, 1);
        Serial.println(" %");
    } else {
        Serial.println("Помилка DHT11: Не вдалося зчитати дані!");
    }

    Serial.print("Вологість ґрунту:  ");
    Serial.print(data.soil_moisture);
    Serial.println(" %");

    Serial.print("Рівень газу MQ-2:   ");
    Serial.print(data.gas_level);
    Serial.println(" %");

    Serial.println("==========================\n");
}