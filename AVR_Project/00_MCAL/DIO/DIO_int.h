
#ifndef MCAL_00_DIO_DIO_INT_H_
#define MCAL_00_DIO_DIO_INT_H_

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Dir);
void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Val);
void DIO_voidTogglePin(u8 copy_u8PortId, u8 copy_u8PinId);
u8 DIO_u8GetPinValue(u8 copy_u8PortId, u8 copy_u8PinId);
void DIO_voidEnablePullUpPin(u8 copy_u8PortId, u8 copy_u8PinId);
void DIO_voidDisablePullUpPin(u8 copy_u8PortId, u8 copy_u8PinId);

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8Dir);
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8Val);
u8 DIO_u8GetPortValue(u8 copy_u8PortId);
void DIO_voidEnablePullUpPort(u8 copy_u8PortId);
void DIO_voidDisablePullUpPort(u8 copy_u8PortId);
void DIO_voidTogglePort(u8 copy_u8PortId);

void my_delay();

void assignment1();
void assignment2();
void assignment3();

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_OUTPUT 0xff
#define DIO_INPUT 0x00

#define DIO_HIGH 0xff
#define DIO_LOW 0x00

#endif /* 00_MCAL_DIO_DIO_INT_H_ */
