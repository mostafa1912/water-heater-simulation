/*
 * HAL_SSG_int.h
 *
 *  Created on: Apr 24, 2024
 *      Author: msaeed
 */

#ifndef HAL_02_7SEG_HAL_SSG_INT_H_
#define HAL_02_7SEG_HAL_SSG_INT_H_
#include "util/delay.h"

#define F_CPU 16000000UL

typedef struct{

u8 SSG_dataPort;
u8 SSG_dataPin[4];
u8 SSG_enablePort;
u8 SSG_enablePin;
u8 SSG_type;

}SSG_t;

#define SSG_CATHODE 0
#define SSG_ANODE 0

void SSG_voidEnable(const SSG_t *);
void SSG_voidDisable(const SSG_t *);
void SSG_voidWriteNumber(const SSG_t *, u8 Copy_u8Num);

void SSG_voidWriteTwoNumber(const SSG_t * SSG_1, const SSG_t * SSG_2, u8 Copy_u8Num1, u8 Copy_u8Num2);


#endif /* 01_HAL_02_7SEG_HAL_SSG_INT_H_ */
