/*
 * HAL_CLCD_int.h
 *
 *  Created on: Apr 26, 2024
 *      Author: msaeed
 */

#ifndef HAL_03_CLCD_HAL_CLCD_INT_H_
#define HAL_03_CLCD_HAL_CLCD_INT_H_

void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendInstruction(u8 Copy_u8Instruction);
void CLCD_voidInit(void);
void CLCD_voidSendString(const char * Copy_str);
void CLCD_voidClear(void);
void CLCD_voidSetCursorPosition(u8 Copy_u8Row, u8 Copy_u8Col);
//void CLCD_voidSendString(const char * Copy_str);
void CLCD_voidSendSpecialCharacter(u8 * Copy_u8_pattern, u8 Copy_u8_pattern_number, u8 Copy_col, u8 Copy_row);


#endif /* 01_HAL_03_CLCD_HAL_CLCD_INT_H_ */
