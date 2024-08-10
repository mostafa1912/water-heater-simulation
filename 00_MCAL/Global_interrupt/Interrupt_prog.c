/*
 * Interrupt_prog.c
 *
 *  Created on: 4 May 2024
 *      Author: mosta
 */
#include "Interrupt_priv.h"
#include "Interrupt_int.h"


void GIE_Enable()
{
	__asm__("SEI");
}

void GIE_Disable()
{
	__asm__("CLI");
}


