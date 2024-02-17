/*
 * LCD_int.h
 *
 * Created: 12/15/2023 8:09:17 PM
 *  Author: Marina Albert
 */ 

#ifndef LCD_INT_H
#define LCD_INT_H

typedef enum{
	Clear_Display		=	0x01,
	Return_Home			=	0x02,
	Entry_Mode			=	0x06,
	bit8_2line_5x8font	=	0x38,
	bit4_2line_5x8font	=	0x28,
	bit8_1line			=	0x33,
	displayOn_cursorON  =	0x0E,
	displayOff  =	0x08
}LCD_Commands;


void LCD_voidInit(void);
void LCD_voidSendData(u8 LCD_u8_Data);
void LCD_voidSendCommand(u8 LCD_u8_Command);
void LCD_voidSendString(s8 String[]);
void LCD_Int_to_String(u16 input);
void LCD_gotoxy(u8 x, u8 y);

#endif