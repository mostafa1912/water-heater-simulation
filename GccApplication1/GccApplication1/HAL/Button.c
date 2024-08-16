/*
 * CFile1.c
 *
 * Created: 12/08/2024 03:14:56 AM
 *  Author: mostafa
 */ 

#include "Button.h"
#include <avr/io.h>


bool pressed(Button_t* button){
	
	if (PINB&(1<<button->pin))
	{
		return false;
	}
	return true;
	
}


