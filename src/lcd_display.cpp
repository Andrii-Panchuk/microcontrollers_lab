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

void lcd_clear(void){
    lcd.clear();
}
