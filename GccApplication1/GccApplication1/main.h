#ifndef main_h__
#define main_h__
#include "HAL/Button.h"
#include <avr/builtins.h>
#include <avr/interrupt.h>

#define MinTemp 35
#define MaxTemp 75

#define ADC_MAX 1023 
#define V_REF 5

Button_t TemperatureUpButton;
Button_t TemperatureDownButton;
volatile float CurrentTemp;
void init()
{
	// Set up Timer1 for temperature check
	TCCR1A = 0; // Normal operation mode for Timer1
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10); // CTC mode, prescaler = 64
	OCR1A = 24999; // Set the compare match value for 100 ms
	TIMSK = (1 << OCIE1A); // Enable Timer1 compare match interrupt
		
	initADC();
	
	//buttons
	DDRB &= ~((1<<PINB0) | (1<<PINB1)) | (1<<PINB2); //set PB0,1,2 as input
	PORTB = 0b00000111; //enabling pull-up resistors
	
	DDRA |= 1<<PINA7 ; //setting a7 to output
	

	TemperatureUpButton.port = &PORTB;
	TemperatureUpButton.pin = PINB0;
	
	TemperatureDownButton.port = &PORTB;
	TemperatureDownButton.pin = PINB1;
	
	
	sei();
	
}

void initADC()
{
	// Set ADC prescaler to 64 (for 16 MHz / 64 = 250 kHz)
	// This sets the ADC clock to an appropriate value
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

	// Set ADC reference voltage to AVCC (AVCC pin or VCC)
	ADMUX = (1 << REFS0);
}


uint16_t readADC(uint8_t channel) {
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07); // Select ADC channel
	ADCSRA |= (1 << ADSC); // Start conversion
	while (ADCSRA & (1 << ADSC)); // Wait for conversion to complete....ADSC is 1 as long as conversion is running
	return ADC; // Return ADC result
}


float ADC_to_Temperature(uint16_t adc_value) {
	float v_out = ((float)adc_value / ADC_MAX) * V_REF; // Convert ADC value to voltage
	float temperature = v_out * 100.0;           // Convert voltage to temperature
	return temperature;
}


#endif // main_h__
