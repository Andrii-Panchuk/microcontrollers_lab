#include "seven_segment.h"
#include "config.h"

static const uint8_t DIGITS[10][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0},  /* 0 */
    {0, 1, 1, 0, 0, 0, 0, 0},  /* 1 */
    {1, 1, 0, 1, 1, 0, 1, 0},  /* 2 */
    {1, 1, 1, 1, 0, 0, 1, 0},  /* 3 */
    {0, 1, 1, 0, 0, 1, 1, 0},  /* 4 */
    {1, 0, 1, 1, 0, 1, 1, 0},  /* 5 */
    {1, 0, 1, 1, 1, 1, 1, 0},  /* 6 */
    {1, 1, 1, 0, 0, 0, 0, 0},  /* 7 */
    {1, 1, 1, 1, 1, 1, 1, 0},  /* 8 */
    {1, 1, 1, 1, 0, 1, 1, 0}   /* 9 */
};

void seg_init(void)
{
    for (uint8_t i = 0; i < 8; i++) {
        pinMode(SEG_PINS[i], OUTPUT);
    }
    seg_show_digit(0);
}

void seg_show_digit(int digit)
{
    if (digit < 0 || digit > 9) {
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (DIGITS[digit][i] == 1) {
            digitalWrite(SEG_PINS[i], LOW);   
        } else {
            digitalWrite(SEG_PINS[i], HIGH);  
        }
    }
}