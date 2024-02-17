/*
 * LCD_prog.h
 *
 * Created: 12/15/2023 8:09:17 PM
 *  Author: Marina Albert
 */ 

#include <stdio.h>
#include "STD_types.h"
#include "LCD_int.h"
#include "DIO_int.h"
#include "LCD_config.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void LCD_voidInit(void)
{
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D4 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D5 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D6 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D7 ,DIO_U8_OUTPUT);
	
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_OUTPUT);
	
	_delay_ms(35);
	LCD_voidSendCommand(Return_Home);
	_delay_ms(2);
	LCD_voidSendCommand(bit4_2line_5x8font);
	_delay_ms(2);
	LCD_voidSendCommand(displayOn_cursorON);
	_delay_ms(2);
	LCD_voidSendCommand(Entry_Mode);
	_delay_ms(2);
	LCD_voidSendCommand(Clear_Display);
	_delay_ms(2);
}
void LCD_voidSendData(u8 LCD_u8_Data)
{
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_HIGH);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Data & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , (LCD_u8_Data << 4) & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 LCD_u8_Command)
{
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_LOW);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Command & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , (LCD_u8_Command << 4) & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendString(s8 String[])
{
	u8 index = 0;
	while(String[index] != '\0' )
	{
		LCD_voidSendData(String[index]);
		index++;
	}
}

void LCD_Int_to_String(u16 input)
{
	s8 str[5];
	sprintf(str,"%u",input);
	LCD_voidSendString(str);
}

void LCD_gotoxy(u8 x, u8 y)
{
	u8 address;

	if (y == 0)
	address = 0x80 + x; // First line address starts from 0x80
	else
	address = 0xC0 + x; // Second line address starts from 0xC0

	LCD_voidSendCommand(address); // Set DDRAM address
}