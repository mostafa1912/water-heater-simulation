/*
 * HAL_Button_int.h
 *
 *  Created on: Apr 24, 2024
 *      Author: msaeed
 */

#ifndef HAL_01_BUTTON_HAL_BUTTON_INT_H_
#define HAL_01_BUTTON_HAL_BUTTON_INT_H_

typedef struct{
	u8 BUTTON_port;
	u8 BUTTON_pin;
}BUTTON_t;

u8 Button_u8GetCurrentStatus(const BUTTON_t *);

#endif /* 01_HAL_01_BUTTON_HAL_BUTTON_INT_H_ */
