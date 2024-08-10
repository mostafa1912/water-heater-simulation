/*
 * HAL_Led_prog.c
 *
 *  Created on: Apr 24, 2024
 *      Author: msaeed
 */
#include "../../03_Service/STD_TYPES.h"
#include "../../03_Service/BIT_MATH.h"
#include "../../00_MCAL/DIO/DIO_priv.h"
#include "../../00_MCAL/DIO/DIO_int.h"
#include "HAL_Led_int.h"

u8 LED_u8ON(const LED_t * Copy_psled){

	u8 Local_u8ErrorState = OK;


	if(Copy_psled -> LED_connection == LED_FORWARD){
		DIO_voidSetPinValue(Copy_psled->LED_port, Copy_psled -> LED_pin, DIO_HIGH);
	}
	else if(Copy_psled -> LED_connection == LED_REVERSED){
		DIO_voidSetPinValue(Copy_psled->LED_port, Copy_psled -> LED_pin, DIO_LOW);
	}
	else{
		// Error
//		#warning "Error: Connection not valid"
		Local_u8ErrorState = WRONG_CONNECTION;
	}

	return Local_u8ErrorState;
}

u8 LED_u8OFF(const LED_t * Copy_psled){
	u8 Local_u8ErrorState = OK;

	if(Copy_psled -> LED_connection == LED_FORWARD){
		DIO_voidSetPinValue(Copy_psled->LED_port, Copy_psled -> LED_pin, DIO_LOW);
	}
	else if(Copy_psled -> LED_connection == LED_REVERSED){
		DIO_voidSetPinValue(Copy_psled->LED_port, Copy_psled -> LED_pin, DIO_HIGH);
	}
	else{
		// Error
//		#warning "Error: Connection not valid"
		Local_u8ErrorState = WRONG_CONNECTION;
	}

	return Local_u8ErrorState;
}

void LED_voidTOG(const LED_t * Copy_psled){
	DIO_voidTogglePin(Copy_psled->LED_port, Copy_psled -> LED_pin);
}
