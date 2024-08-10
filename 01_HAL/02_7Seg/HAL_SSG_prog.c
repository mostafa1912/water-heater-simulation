/*
 * HAL_SSG_prog.c
 *
 *  Created on: Apr 26, 2024
 *      Author: msaeed
 */
#include "../../03_Service/STD_TYPES.h"
#include "../../03_Service/BIT_MATH.h"
#include "../../00_MCAL/DIO/DIO_priv.h"
#include "../../00_MCAL/DIO/DIO_int.h"
#include "HAL_SSG_int.h"

void SSG_voidEnable(const SSG_t * copy_SSG){
	if(copy_SSG != NULL){
		u8 enablePin = copy_SSG -> SSG_enablePin;
		u8 enablePort = copy_SSG -> SSG_enablePort;


		DIO_voidSetPinDirection(enablePort, enablePin, DIO_OUTPUT);
		DIO_voidSetPinValue(enablePort, enablePin, DIO_HIGH);

	}
	else{
		// Error
	}
}


void SSG_voidDisable(const SSG_t * copy_SSG){
	u8 enablePin = copy_SSG -> SSG_enablePin;
	u8 enablePort = copy_SSG -> SSG_enablePort;

	DIO_voidSetPinDirection(enablePort, enablePin, DIO_OUTPUT);
	DIO_voidSetPinValue(enablePort, enablePin, DIO_LOW);
}

void SSG_voidWriteNumber(const SSG_t * copy_SSG, u8 Copy_u8Num){
	u8 pin0 = 0b00000001;
	u8 pin1 = 0b00000010;
	u8 pin2 = 0b00000100;
	u8 pin3 = 0b00001000;

//	Copy_u8Num = 0b00000011;

	DIO_voidSetPinDirection(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[0], DIO_OUTPUT);
	DIO_voidSetPinDirection(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[1], DIO_OUTPUT);
	DIO_voidSetPinDirection(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[2], DIO_OUTPUT);
	DIO_voidSetPinDirection(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[3], DIO_OUTPUT);

	if( (Copy_u8Num & pin0) > 0){
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[0], DIO_HIGH);
	}
	else{
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[0], DIO_LOW);
	}

	if( (Copy_u8Num & pin1) > 0){
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[1], DIO_HIGH);
	}
	else{
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[1], DIO_LOW);
	}

	if( (Copy_u8Num & pin2) > 0){
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[2], DIO_HIGH);
	}
	else{
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[2], DIO_LOW);
	}

	if( (Copy_u8Num & pin3) > 0){
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[3], DIO_HIGH);
	}
	else{
		DIO_voidSetPinValue(copy_SSG->SSG_dataPort, copy_SSG->SSG_dataPin[3], DIO_LOW);
	}

//	DIO_voidSetPortValue(copy_SSG -> SSG_dataPort, Copy_u8Num << 4);


}

void SSG_voidWriteTwoNumber(const SSG_t * SSG_1, const SSG_t *SSG_2, u8 Copy_u8Num1, u8 Copy_u8Num2){
		_delay_ms(10);
		SSG_voidDisable(SSG_2);
		SSG_voidWriteNumber(SSG_1, Copy_u8Num1);
		SSG_voidEnable(SSG_1);

		_delay_ms(10);
		SSG_voidDisable(SSG_1);
		SSG_voidWriteNumber(SSG_2, Copy_u8Num2);
		SSG_voidEnable(SSG_2);

	}
