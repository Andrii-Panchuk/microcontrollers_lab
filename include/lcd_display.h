#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Arduino.h>

void lcd_init(void);
void lcd_set_digit(uint8_t digit);
void lcd_show_main_text(void);
void lcd_clear(void);

#endif // LCD_DISPLAY_H