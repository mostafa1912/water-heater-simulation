#define F_CPU 16000000UL
#include "util/delay.h"
#include "../../03_Service/STD_TYPES.h"
#include "../../03_Service/BIT_MATH.h"
#include "DIO_priv.h"
#include "DIO_int.h"





void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Dir){
	// Validate Pin
	if(copy_u8PinId >= 0 && copy_u8PinId <= 7 )
	{
		// Validate Direction
		if(copy_u8Dir == DIO_OUTPUT){
			// Validate Port
			switch(copy_u8PortId){
				case DIO_PORTA: SET_BIT(DIO_DDRA_REG,copy_u8PinId); break;
				case DIO_PORTB: SET_BIT(DIO_DDRB_REG,copy_u8PinId); break;
				case DIO_PORTC: SET_BIT(DIO_DDRC_REG,copy_u8PinId); break;
				case DIO_PORTD: SET_BIT(DIO_DDRD_REG,copy_u8PinId); break;
				default: /* Error */;
			}
		}
		else if(copy_u8Dir == DIO_INPUT){
			// Validate Port
			switch(copy_u8PortId){
				case DIO_PORTA: CLR_BIT(DIO_DDRA_REG,copy_u8PinId); break;
				case DIO_PORTB: CLR_BIT(DIO_DDRB_REG,copy_u8PinId); break;
				case DIO_PORTC: CLR_BIT(DIO_DDRC_REG,copy_u8PinId); break;
				case DIO_PORTD: CLR_BIT(DIO_DDRD_REG,copy_u8PinId); break;
				default: /* Error */;
			}
		}
	}
	else{
		// Error
	}
}
void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Val){
	// Validate Pin
		if(copy_u8PinId >= 0 && copy_u8PinId <= 7 )
		{
			// Validate Value
			if(copy_u8Val > DIO_LOW){
				// Validate Port
				switch(copy_u8PortId){
					case DIO_PORTA: SET_BIT(DIO_PORTA_REG,copy_u8PinId); break;
					case DIO_PORTB: SET_BIT(DIO_PORTB_REG,copy_u8PinId); break;
					case DIO_PORTC: SET_BIT(DIO_PORTC_REG,copy_u8PinId); break;
					case DIO_PORTD: SET_BIT(DIO_PORTD_REG,copy_u8PinId); break;
					default: /* Error */;
				}
			}
			else if(copy_u8Val == DIO_LOW){
				// Validate Port
				switch(copy_u8PortId){
					case DIO_PORTA: CLR_BIT(DIO_PORTA_REG,copy_u8PinId); break;
					case DIO_PORTB: CLR_BIT(DIO_PORTB_REG,copy_u8PinId); break;
					case DIO_PORTC: CLR_BIT(DIO_PORTC_REG,copy_u8PinId); break;
					case DIO_PORTD: CLR_BIT(DIO_PORTD_REG,copy_u8PinId); break;
					default: /* Error */;
				}
			}
		}
		else{
			// Error
		}
}

void DIO_voidTogglePin(u8 copy_u8PortId, u8 copy_u8PinId){
	if(copy_u8PinId >= 0 && copy_u8PinId <= 7 ){
			switch(copy_u8PortId){
				case DIO_PORTA: TOG_BIT(DIO_PORTA_REG,copy_u8PinId); break;
				case DIO_PORTB: TOG_BIT(DIO_PORTB_REG,copy_u8PinId); break;
				case DIO_PORTC: TOG_BIT(DIO_PORTC_REG,copy_u8PinId); break;
				case DIO_PORTD: TOG_BIT(DIO_PORTD_REG,copy_u8PinId); break;
				default: /* Error */;
			}
		}
		else{
			/* Error */
		}

}

u8 DIO_u8GetPinValue(u8 copy_u8PortId, u8 copy_u8PinId){
	u8 Local_u8Val;
	if( copy_u8PinId >= 0 && copy_u8PinId <= 7 ){
		switch(copy_u8PortId){
			case DIO_PORTA: Local_u8Val = GET_BIT(DIO_PINA_REG, copy_u8PinId); break;
			case DIO_PORTB: Local_u8Val = GET_BIT(DIO_PINB_REG, copy_u8PinId); break;
			case DIO_PORTC: Local_u8Val = GET_BIT(DIO_PINC_REG, copy_u8PinId); break;
			case DIO_PORTD: Local_u8Val = GET_BIT(DIO_PIND_REG, copy_u8PinId); break;
			default: /* Error */; break;
						}
	}
	else{
		// Error
	}

	return Local_u8Val;
}


void DIO_voidEnablePullUpPin(u8 copy_u8PortId, u8 copy_u8PinId){
	if(copy_u8PinId >= 0 && copy_u8PinId <= 7){

		switch(copy_u8PortId){

			case DIO_PORTA: SET_BIT(DIO_PORTA_REG, copy_u8PinId); break;
			case DIO_PORTB: SET_BIT(DIO_PORTB_REG, copy_u8PinId); break;
			case DIO_PORTC: SET_BIT(DIO_PORTC_REG, copy_u8PinId); break;
			case DIO_PORTD: SET_BIT(DIO_PORTD_REG, copy_u8PinId); break;
			default: /* Error */; break;

		}

	}
	else{
		// Error
	}
}


void DIO_voidDisablePullUpPin(u8 copy_u8PortId, u8 copy_u8PinId){
	if(copy_u8PinId >= 0 && copy_u8PinId <= 7){

		switch(copy_u8PortId){

			case DIO_PORTA: CLR_BIT(DIO_PORTA_REG, copy_u8PinId); break;
			case DIO_PORTB: CLR_BIT(DIO_PORTB_REG, copy_u8PinId); break;
			case DIO_PORTC: CLR_BIT(DIO_PORTC_REG, copy_u8PinId); break;
			case DIO_PORTD: CLR_BIT(DIO_PORTD_REG, copy_u8PinId); break;
			default: /* Error */; break;

		}

	}
	else{
		// Error
	}
}

/* #####  PORT Function #### */

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8Dir){

	switch(copy_u8PortId)
		{
			case DIO_PORTA: DIO_DDRA_REG = copy_u8Dir; break;
			case DIO_PORTB: DIO_DDRB_REG = copy_u8Dir; break;
			case DIO_PORTC: DIO_DDRC_REG = copy_u8Dir; break;
			case DIO_PORTD: DIO_DDRD_REG = copy_u8Dir; break;
			default: /* Error */; break;
		}

}

void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8Val){

	switch(copy_u8PortId)
			{
			case DIO_PORTA: DIO_PORTA_REG = copy_u8Val; break;
			case DIO_PORTB: DIO_PORTB_REG = copy_u8Val; break;
			case DIO_PORTC: DIO_PORTC_REG = copy_u8Val; break;
			case DIO_PORTD: DIO_PORTD_REG = copy_u8Val; break;
			default: /* Error */; break;
			}

}

void DIO_voidTogglePort(u8 copy_u8PortId){
			switch(copy_u8PortId){
				case DIO_PORTA: DIO_PORTA_REG ^= 0xff; break;
				case DIO_PORTB: DIO_PORTB_REG ^= 0xff; break;
				case DIO_PORTC: DIO_PORTC_REG ^= 0xff; break;
				case DIO_PORTD: DIO_PORTD_REG ^= 0xff; break;
				default: /* Error */;
			}
}

u8 DIO_u8GetPortValue(u8 copy_u8PortId){
	u8 Local_u8Val;
	switch(copy_u8PortId)
	{
		case DIO_PORTA: Local_u8Val = DIO_PINA_REG; break;
		case DIO_PORTB: Local_u8Val = DIO_PINB_REG; break;
		case DIO_PORTC: Local_u8Val = DIO_PINC_REG; break;
		case DIO_PORTD: Local_u8Val = DIO_PIND_REG; break;
		default: /* Error */; break;
	}

	return Local_u8Val;
}

void DIO_voidEnablePullUpPort(u8 copy_u8PortId){
	switch(copy_u8PortId)
	{
		case DIO_PORTA: DIO_PORTA_REG = DIO_HIGH; break;
		case DIO_PORTB: DIO_PORTB_REG = DIO_HIGH; break;
		case DIO_PORTC: DIO_PORTC_REG = DIO_HIGH; break;
		case DIO_PORTD: DIO_PORTD_REG = DIO_HIGH; break;
		default: /* Error */; break;
	}
}

void DIO_voidDisablePullUpPort(u8 copy_u8PortId){
	switch(copy_u8PortId)
	{
		case DIO_PORTA: DIO_PORTA_REG = DIO_LOW; break;
		case DIO_PORTB: DIO_PORTB_REG = DIO_LOW; break;
		case DIO_PORTC: DIO_PORTC_REG = DIO_LOW; break;
		case DIO_PORTD: DIO_PORTD_REG = DIO_LOW; break;
		default: /* Error */; break;
	}
}


void my_delay(){
	u32 counter = 0;

	while( counter < 65000UL){
		counter++;
	}

}

void assignment1(){
	u8 local_val = 1;
	for(int i = 0; i<= 7; i++){
		local_val = 1 << i;
		DIO_voidSetPortValue(DIO_PORTA, local_val);
//		local_val = local_val << 1;
		_delay_ms(100);
	}
}
void assignment2(){
	u8 local_val = 1 << 7; // 0x80
	for(int i = 0; i<= 7; i++){
		DIO_voidSetPortValue(DIO_PORTA, local_val);
		local_val = local_val >> 1;
		_delay_ms(100);
	}
}
void assignment3(){
	u8 local_val = 0;
	u8 add = 1;
	for(int i = 0; i<= 7; i++){
		local_val += add;
		add = add << 1;
		DIO_voidSetPortValue(DIO_PORTA, local_val);
//		local_val = local_val << 1;
		_delay_ms(100);
	}
}

