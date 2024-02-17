/****************************************/
/*          Author: Marina Albert       */
/*          Date: 05-11-2023            */
/*          Version: 1.0                */
/*          Module: DIO                 */
/****************************************/
#ifndef DIO_REG_H
#define DIO_REG_H

#define PORTA *( ( volatile u8*) 0x3B )
#define DDRA  *( ( volatile u8*) 0x3A )
#define PINA  *( ( volatile u8*) 0x39 )
#define PORTB *( ( volatile u8*) 0x38 )
#define DDRB  *( ( volatile u8*) 0x37 )
#define PINB  *( ( volatile u8*) 0x36 )
#define PORTC *( ( volatile u8*) 0x35 )
#define DDRC  *( ( volatile u8*) 0x34 )
#define PINC  *( ( volatile u8*) 0x33 )
#define PORTD *( ( volatile u8*) 0x32 )
#define DDRD  *( ( volatile u8*) 0x31 )
#define PIND  *( ( volatile u8*) 0x30 )

#endif