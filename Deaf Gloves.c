/*
 * Deaf_Gloves.c
 *
 * Created: 2/17/2024 5:22:47 AM
 *  Author: Marina Albert
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


/*
Inserting all words in EEPROM with their ADC_AdjustedValues
and their addresses are related to each other to simplify searching
as Word_addr=Values_addr-0x0100
the values are decimal no., converted to a binary no.
representing the position of every finger with 3bits for each
ordered where the thumb in LSBs and pinkie in MSBs
*/
void EEPROM_InsertData ()              
{										   						// Little F., Ring F., Middle F., Index F., Thumb
	EEPROM_VoidWriteString(0x0100,"0");		     				//    0%        0%        0%         0%      0%
	_delay_ms(10);
	EEPROM_VoidWriteString(0x0000,"Hello!");                    //0b0 000      000        000       000      000
	_delay_ms(10);
	
	EEPROM_VoidWriteString(0x0110,"1752");	    				//   0%        100%      100%      100%      0%
	_delay_ms(10);														      	        	       		     
	EEPROM_VoidWriteString(0x0010,"Not sure.");                 //0b0 000      011       011       011       000
	_delay_ms(10);
	
	EEPROM_VoidWriteString(0x0120,"14016");                     //  100%       100%      100%       0%       0%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0020,"See you later.");            //0b0 011       011      011       000       000
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0130,"14034");                     //  100%       100%      100%      50%       50%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0030,"LOL!");                      //0b0 011       011      011       010       010
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0140,"13970");                     //  100%       100%      50%       50%       50%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0040,"No.");						//0b0 011       011      010       010       010
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0150,"82");                        //     0%        0%       5%       50%       50%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0050,"Perfect!");					//0b0 000       000      001       010       010
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0160,"14027");                     //  100%       100%      100%      25%       100%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0060,"A Question.");				//0b0 011       011      011       001       011
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0170,"1728");                      //    0%       100%      100%       0%       0%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0070,"I Love you.");				//0b0 000       011      011       000       000
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0180,"1536");                      //     0%       100%      0%       0%        0%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0080,"Really Love you");		    //0b0 000       011      000       000       000
	_delay_ms(10); 														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0190,"13899");                     //  100%       100%      25%       25%       100%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0090,"A Quote.");					//0b0 011       011      001       001       011
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01A0,"1731");                      //    0%       100%      100%       0%       100%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00A0,"It is terrible");			//0b0 000       011      011       000       011
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01B0,"13971");                     //  100%       100%      60%       60%       100%
	_delay_ms(10);										     			       		     	       	         
	EEPROM_VoidWriteString(0x00B0,"I watch you");	            //0b0 011       011      010       010       011
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01C0,"14040");                     //  100%       100%      100%      100%       0%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00C0,"Good job!");					//0b0 011       011      011       011       000
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01D0,"14043");                     //  100%       100%      100%      100%       100%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00D0,"I agree.");					//0b0 011       011      011       011       011
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01E0,"14019");                     //  100%       100%      100%       0%       100%
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00E0,"You.");						//0b0 011       011      011       000       011
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01F0,"576");                       //     0%        5%       5%        0%        0%
	_delay_ms(10);									           			       		     	       	         
	EEPROM_VoidWriteString(0x00F0,"Iwishhappylife");            //0b0 000       001      001       000       000
	_delay_ms(10);
	
}

/*
convert the data of the 5 fingers ordered from L.F to Thumb from ADC.
get their positions and representing it with binary no..
collect the 5 positions in 1 variable and return it.
*/
u16  ADC_CollectValue(u16* value)
{
	u16 ADC_value;
	u16 collect=0x0000;
	
	for (u8 i=0;i<5;i++)
	{
		ADC_value=ADC_u16Convert(4-i);
		if (ADC_value==0)                         //assume 0 refers to 0% bending (open finger)
		{  collect=(collect<<3)|(0b000);    }
		else if (ADC_value>0&&ADC_value<=340)     //assume range from (0<) to 340 refers to >=33.33% bending
		{  collect=(collect<<3)|(0b001);    }
		else if (ADC_value>340&&ADC_value<=679)   //assume range from 340 to 679 refers to >=66.667% bending
		{  collect=(collect<<3)|(0b010);    }
		else if (ADC_value>679)                   //assume range from 679 to 1019 refers to 100% bending (closed finger)
		{  collect=(collect<<3)|(0b011);    }
    }
    *value=collect;
	return collect;
}

/*
searching for the correct sentence stored in EEPROM
by converting the data came from  ADC_CollectValue() to string
then compare it with the string values in EEPROM. When it reaches the right
value, it summons the sentence related to this value
and send it to LCD_voidSendString to print it
*/
void searchandprint(u16 data)
{
	s8 str_num[25];                                
	s8 str_word[25];                               
	s8 str_data[5];                                
	sprintf(str_data,"%u",data);
	for (u16 i=0x0100;i<=0x01F0;i+=0x0010)
	{											   //searching for the correct sentence stored in EEPROM
		EEPROM_u8ReadString(i, str_num);		   //by comparing data came from  ADC_CollectAddress() 
		int value = strcmp(str_num,str_data);	   //with the data on EEPROM and when it reaches the right
		if(value == 0)							   //data, it summons the sentence that its address related
		{										   //to the address of the data.
			EEPROM_u8ReadString(i-0x0100,str_word);
			LCD_voidSendString(str_word);
			return ;
		}
		
	}
	/*
	u16 x;
	s8 str_word[25];
	
	for (u16 i=0x0100;i<=0x01F0;i+=0x0010)
	{
		x=EEPROM_u8ReadByte(i);
		if(x==data)
		{
			EEPROM_u8ReadString(i-0x0100,str_word);
			LCD_voidSendString(str_word);
			return ;
		}
	}
	*/
}