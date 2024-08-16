/*
 * CFile1.c
 *
 * Created: 16/08/2024 08:01:32 PM
 *  Author: mosta
 */ 
#include "7-seg.h"

void initSevenSegmentDisplay() {
	DDRC |= (1 << DISPLAY_1_SELECT_PIN) | (1 << DISPLAY_2_SELECT_PIN); // Set selector pins as output
	DDRC |= BCD_VALUE_MASK; // Set PC0-PC3 as output for BCD value
	PORTC &= ~(1 << DISPLAY_1_SELECT_PIN) & ~(1 << DISPLAY_2_SELECT_PIN); // Initialize with both displays off
}

void displayDigit(uint8_t digit, uint8_t displayNumber) {
	// Ensure digit is in the 0-9 range
	if (digit > 9) {
		return;
	}

	// Clear the previous BCD value
	PORTC &= ~BCD_VALUE_MASK;

	// Set the new BCD value
	PORTC |= (digit & BCD_VALUE_MASK);

	// Select the appropriate display
	if (displayNumber == 1) {
		PORTC |= (1 << DISPLAY_1_SELECT_PIN);
		PORTC &= ~(1 << DISPLAY_2_SELECT_PIN);
		} else if (displayNumber == 2) {
		PORTC |= (1 << DISPLAY_2_SELECT_PIN);
		PORTC &= ~(1 << DISPLAY_1_SELECT_PIN);
	}
}

void displayNumber(uint8_t number) {
	if (number > 99) {
		return; // Only supports two digits
	}

	// Display tens digit on the first display
	displayDigit(number / 10, 1);

	// Small delay (optional, depends on your setup)
	_delay_ms(5);

	// Display units digit on the second display
	displayDigit(number % 10, 2);
}