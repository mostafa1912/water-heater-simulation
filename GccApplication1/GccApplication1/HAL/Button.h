/********************************************************************
		created:	2024/08/12
		created:	12:8:2024   3:21
		filename: 	c:\users\mosta\Documents\Atmel Studio\7.0\GccApplication1\GccApplication1\HAL\Button.h
		file path:	c:\users\mosta\Documents\Atmel Studio\7.0\GccApplication1\GccApplication1\HAL
		file base:	Button
		file ext:	h
		author:		mostafa elshafie
		
		purpose:	
	*********************************************************************/
#ifndef BUTTON_H
#define BUTTON_H
#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct   
{
	uint8_t volatile* port ;
	uint8_t pin;
}Button_t;

bool pressed(Button_t* button); //checks the state of a button


#endif /* BUTTON_H */