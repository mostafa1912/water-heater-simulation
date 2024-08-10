/*
 * HAL_Led_int.h
 *
 *  Created on: Apr 24, 2024
 *      Author: msaeed
 */

#ifndef HAL_00_LED_HAL_LED_INT_H_
#define HAL_00_LED_HAL_LED_INT_H_

#define LED_REVERSED 0
#define LED_FORWARD 1

#define OK 0
#define WRONG_CONNECTION 2

typedef struct{

	u8 LED_port;
	u8 LED_pin;
	u8 LED_connection;

}LED_t;

u8 LED_u8ON(const LED_t *);
u8 LED_u8OFF(const LED_t *);
void LED_voidTOG(const LED_t *);

#endif /* 01_HAL_00_LED_HAL_LED_INT_H_ */
