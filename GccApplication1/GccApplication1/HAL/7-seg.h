#ifndef 7-seg_h__
#define 7-seg_h__
//this file is for a 7-segment display connected with a BCD display driver
#include <avr/io.h>

#define DISPLAY_1_SELECT_PIN PORTC6  // Pin to select the first display
#define DISPLAY_2_SELECT_PIN PORTGC7  // Pin to select the second display
#define BCD_VALUE_MASK 0x0F       // Mask for the lower 4 bits (PC0-PC3)

void initSevenSegmentDisplay();
void displayDigit(uint8_t digit, uint8_t displayNumber);
void displayNumber(uint8_t number);


#endif // 7-seg_h__
