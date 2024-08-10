/*
 * HAL_CLCD_prog.c
 *
 *  Created on: Apr 26, 2024
 *      Author: msaeed
 */
#define F_CPU 16000000UL
#include "util/delay.h"

#include "../../03_Service/STD_TYPES.h"
#include "../../03_Service/BIT_MATH.h"
#include "../../00_MCAL/DIO/DIO_int.h"
#include "HAL_CLCD_priv.h"
#include "HAL_CLCD_config.h"
#include "HAL_CLCD_int.h"

#if CLCD_u8_MODE == CLCD_4BIT
static void CLCD_voidSetHalfPort(u8 Copy_u8data){

	DIO_voidSetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_DATA_PIN_0, GET_BIT( Copy_u8data,0) );
	DIO_voidSetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_DATA_PIN_1, GET_BIT( Copy_u8data,1) );
	DIO_voidSetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_DATA_PIN_2, GET_BIT( Copy_u8data,2) );
	DIO_voidSetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_DATA_PIN_3, GET_BIT( Copy_u8data,3) );
}
#endif

static void CLCD_sendEnablePulse(void){
	DIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN, DIO_HIGH);
	_delay_ms(10);
	DIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN, DIO_LOW);
}

void CLCD_voidClear(void){
	// Display Clear:
	CLCD_voidSendInstruction(1);
}

void CLCD_voidSetCursorPosition(u8 Copy_u8Row, u8 Copy_u8Col){
	u8 Local_u8_address;
	if(Copy_u8Row == 0){
		Local_u8_address = Copy_u8Col;
	}
	else if(Copy_u8Row == 1){
		Local_u8_address = Copy_u8Col + 0x40; // 0x40 -> 0b0100,0000
	}
	else{
		// Error
	}

	SET_BIT(Local_u8_address, 7);

//	u8 Local_u8_address = 0b11001;
//	u8 Local_u8_address = 0b010000;
//	u8 Local_u8_address = Copy_u8Row;
//	Local_u8_address = Local_u8_address + 17;


	CLCD_voidSendInstruction(Local_u8_address);

}

//void CLCD_voidSendString(const char * Copy_str){
//	while( *(Copy_str) != '\0'){
//		CLCD_voidSendData(*(Copy_str++));
//	}
//}

void CLCD_voidSendSpecialCharacter(u8 * Copy_u8_pattern, u8 Copy_u8_pattern_number, u8 Copy_col, u8 Copy_row){
	u8 Local_u8_CGRAM_address, Local_u8Counter = 0;
	Local_u8_CGRAM_address = Copy_u8_pattern_number * 8;
	SET_BIT(Local_u8_CGRAM_address, 6);
	CLCD_voidSendInstruction(Local_u8_CGRAM_address);

	for(Local_u8Counter = 0; Local_u8Counter < 8 ; Local_u8Counter++){
	CLCD_voidSendData(Copy_u8_pattern[Local_u8Counter]);
	}

	CLCD_voidSetCursorPosition(Copy_col, Copy_row);

	CLCD_voidSendData(Copy_u8_pattern_number);
}

void CLCD_voidSendData(u8 Copy_u8Data){
	// Set R/S High to send Instruction
	DIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN, DIO_HIGH);
	// Set R/W low to write
	DIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN, DIO_LOW);

#if( CLCD_u8_MODE == CLCD_8BIT_MODE)
		// Send Data
		DIO_voidSetPortValue(CLCD_u8_DATA_PORT, Copy_u8Data);
		CLCD_sendEnablePulse();
#elif CLCD_u8_MODE == CLCD_4BIT_MODE
		CLCD_voidSetHalfPort(Copy_u8Data >> 4);
		CLCD_sendEnablePulse();
		CLCD_voidSetHalfPort(Copy_u8Data);
		CLCD_sendEnablePulse();
#endif


	// Send enable pulse
}

void CLCD_voidSendInstruction(u8 Copy_u8Instruction){
	// Set R/S low to send data
	DIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN, DIO_LOW);
	// Set R/W low to write
	DIO_voidSetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN, DIO_LOW);
	// Send Data
	#if( CLCD_u8_MODE == CLCD_8BIT_MODE)
			// Send Data
			DIO_voidSetPortValue(CLCD_u8_DATA_PORT, Copy_u8Instruction);
			CLCD_sendEnablePulse();
	#elif CLCD_u8_MODE == CLCD_4BIT_MODE
			CLCD_voidSetHalfPort(Copy_u8Instruction >> 4);
			CLCD_sendEnablePulse();
			CLCD_voidSetHalfPort(Copy_u8Instruction);
			CLCD_sendEnablePulse();
	#endif
}

void CLCD_voidInit(void){
	// delay 40ms
	_delay_ms(40);
	// function set 001(DL)NFXX ; DL:1 , N:1  , F:0 (00111000)

#if(CLCD_u8_MODE == CLCD_8BIT_MODE)
	CLCD_voidSendInstruction(0b00111000);

#elif (CLCD_u8_MODE == CLCD_4BIT_MODE)
//	CLCD_voidSendInstruction(0b00100010);
//	CLCD_voidSetHalfPort(0b00001000);
//	CLCD_sendEnablePulse();

	CLCD_voidSetHalfPort(0b00000010);
	CLCD_sendEnablePulse();
	CLCD_voidSetHalfPort(0b00000010);
	CLCD_sendEnablePulse();
	CLCD_voidSetHalfPort(0b00001000);
	CLCD_sendEnablePulse();0

#endif
	// Display ON/OFF:00001DCB ; D:1, C:1, B:0 (00001110)
	CLCD_voidSendInstruction(0b00001110);
	// Display Clear:
	CLCD_voidSendInstruction(1);

	// Entry mode set: 01ISXXXX
//	CLCD_voidSendInstruction(1);
}

void CLCD_voidSendString(const char * Copy_str){
//	for(int i = 0; i<size; i++){
//		CLCD_voidSendData(Copy_u8Name[i]);
//	}
	while(*Copy_str != '\0'){
		CLCD_voidSendData(*(Copy_str++));
	}
}
