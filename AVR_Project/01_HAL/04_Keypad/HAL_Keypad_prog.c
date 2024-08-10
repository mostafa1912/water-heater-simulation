/*
 * HAL_Keypad_prog.c
 *
 *  Created on: 3 May 2024
 *      Author: mosta
 */
#include "../../03_Service/STD_TYPES.H"
#include "../../03_Service/BIT_math.h"

#include "HAL_Keypad_int.h"
#include "HAL_Keypad_config.h"



u8 Col_arr[] ={ KEYPAD_U8_COL_PIN0,KEYPAD_U8_COL_PIN1,KEYPAD_U8_COL_PIN2,KEYPAD_U8_COL_PIN3};
u8 Row_arr[] ={ KEYPAD_U8_ROW_PIN0,KEYPAD_U8_ROW_PIN1,KEYPAD_U8_ROW_PIN2,KEYPAD_U8_ROW_PIN3};






u8 KEYPAD_u8_ReadButtonState(u8* Copy_pu8COL_index, u8* Copy_pu8ROW_index)
{



	for (u8 i=0; i<KEYPAD_U8_NO_OF_COLUMNS;i++) //LOOPING OVER COLUMNS
	{
		//ASSUME PULLUP ENABLED
		DIO_voidSetPinValue(KEYPAD_U8_COL_PORT, Col_arr[i], DIO_LOW);


		for(u8 j = 0; j < KEYPAD_U8_NO_OF_ROWS;j++)
		{
			if (DIO_u8GetPinValue(KEYPAD_U8_ROW_PORT, j )== DIO_LOW )
			{
				*Copy_pu8COL_index = i;
				*Copy_pu8COL_index = j;
				return 0;
			}


		DIO_voidSetPinValue(KEYPAD_U8_COL_PORT, Row_arr[j], DIO_HIGH);


		}
	}
	return -1;
}


