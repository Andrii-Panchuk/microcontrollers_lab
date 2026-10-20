#include "lcd_display.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "config.h"

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void lcd_init(void) {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void lcd_set_digit(uint8_t digit) {
    if (digit > 9) return;
    lcd.setCursor(DIGIT_COL, DIGIT_ROW);
    lcd.print(digit);
}

void lcd_show_main_text(void) {
    lcd.setCursor(0, 0);
    lcd.print("Gr:");
    lcd.print(GROUP);
    lcd.print(" Var:");
    lcd.print(VARIANT);
    lcd.print("  ");            
  
    lcd.setCursor(0, 1);
    lcd.print("PANCHUK ANDRII");
}

void lcd_show_sensors(const SensorData *data){
    lcd.clear();
    lcd.setCursor(0, 0);
    if (data->dht_status_ok) {
        lcd.print("T:");
        lcd.print(data->temperature, 1);
        lcd.print("C H:");
        lcd.print(data->humidity, 0);
        lcd.print("%  ");
    } else {
        lcd.print("DHT error      ");
    }

    lcd.setCursor(0, 1);
    lcd.print("G:");
    lcd.print(data->gas_level);
    lcd.print("% S:");
    lcd.print(data->soil_moisture);
    lcd.print("%  ");
}

void lcd_clear(void){
    lcd.clear();
}
