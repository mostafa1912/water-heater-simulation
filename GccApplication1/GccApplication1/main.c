/*
 * GccApplication1.c
 *
 * Created: 12/08/2024 02:32:48 AM
 * Author : mostafa
 */ 

#include <avr/io.h>
#include <avr/common.h>
#include "HAL/Button.h"
#include "main.h"


int main(void)
{
	init();
	
    while (1) 
    {
		
		//if(pressed(&TemperatureUpButton))
		//{
			//PORTA &= ~(1<<PINA0);
		//}
		//else
		//{
			//PORTA |= (1<<PINA0);
				//
		//}
		
		if (CurrentTemp < 25)
		{
			PORTA |= 1<<PINA7 ;
		}
		else
		{
			PORTA &= ~(1<<PINA7);
		}
		
		
		
	}
	


	
	
	return 0;
}
	

	ISR(TIMER1_COMPA_vect)
	{
		CurrentTemp = ADC_to_Temperature(readADC(0));
	}
	
