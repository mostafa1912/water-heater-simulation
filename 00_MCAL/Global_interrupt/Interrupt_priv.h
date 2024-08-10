/*
 * Interrupt_priv.h
 *
 *  Created on: 4 May 2024
 *      Author: mosta
 */

#ifndef MCAL_GLOBAL_INTERRUPT_INTERRUPT_PRIV_H_
#define MCAL_GLOBAL_INTERRUPT_INTERRUPT_PRIV_H_

#define GIE_SREG *((volatile u8*)(0x5F))
#define GIE_Bit 7
#endif /* 00_MCAL_GLOBAL_INTERRUPT_INTERRUPT_PRIV_H_ */
