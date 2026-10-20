#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Arduino.h>
#include "config.h"

void lcd_init(void);
void lcd_set_digit(uint8_t digit);
void lcd_show_main_text(void);
void lcd_show_sensors(const SensorData *data);
void lcd_clear(void);

#endif // LCD_DISPLAY_H