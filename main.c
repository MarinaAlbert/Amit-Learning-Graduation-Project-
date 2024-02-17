/*
 * Graduation Project.c
 *
 * Created: 2/13/2024 5:49:46 AM
 * Author : Marina Albert
 */ 

#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "STD_Types.h"
#include "TWI_int.h"
#include "EEPROM_int.h"
#include "LCD_int.h"
#include "ADC_int.h"
#include "Deaf Gloves.h"


int main(void)
{
	ADC_voidInit();
    LCD_voidInit();
    EEPROM_voidInit();
	
	LCD_gotoxy(2,0);
	_delay_ms(2);
	LCD_voidSendString("Deaf Glove");
	_delay_ms(2);
	LCD_gotoxy(3,1);
	_delay_ms(2);
	LCD_voidSendString("Project.");
	_delay_ms(1000);
	
	//Inserting the data on EEPROM
	EEPROM_InsertData ();
	
	
    u16 ADC_Value=0;
	u16 ADC_Value1=1;
	u16 x=0;
    while (1) 
    {
		//Collecting the data from the 5 flex sensors connected to ADC
		ADC_Value=ADC_CollectValue(&x);
		
		if (ADC_Value!=ADC_Value1)
		{
			LCD_voidSendCommand(Clear_Display);
			_delay_ms(2);
			LCD_voidSendCommand(Return_Home);
			
			//Recognizing which sign it is & printing it
			searchandprint(ADC_Value);
			
		}
		ADC_Value1=ADC_Value;
		
    }
}
