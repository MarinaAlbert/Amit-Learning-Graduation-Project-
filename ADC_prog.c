/****************************************/
/*          Author: Marina Albert       */
/*          Date: 15-1-2024            */
/*          Version: 1.0                */
/*          Module: ADC                 */
/****************************************/

#include "STD_types.h"
#include "BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
	#if ADC_U8_VREF  == ADC_U8_AREF
	CLEAR_BIT(ADMUX , 6);
	CLEAR_BIT(ADMUX , 7);
	#elif ADC_U8_VREF  == ADC_U8_AVCC
	SET_BIT(ADMUX , 6);
	CLEAR_BIT(ADMUX , 7);
	#elif ADC_U8_VREF  == ADC_U8_INTERNAL
	SET_BIT(ADMUX , 6);
	SET_BIT(ADMUX , 7);
	#endif
	
	#if ADC_U8_ADJUSTMENT == ADC_U8_LEFT
	SET_BIT(ADMUX , 5);
	#elif ADC_U8_ADJUSTMENT == ADC_U8_RIGHT
	CLEAR_BIT(ADMUX , 5);
	#endif
	
	
	#if ADC_U8_PRESCALER == ADC_U8_BY2
	CLEAR_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	CLEAR_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY4
	SET_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
    #elif ADC_U8_PRESCALER == ADC_U8_BY8
	CLEAR_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY16
	SET_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	CLEAR_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY32
	SET_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY64
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	CLEAR_BIT(ADCSRA , 2);
    #elif ADC_U8_PRESCALER == ADC_U8_BY128
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#endif
}

void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA , 7);
}

void ADC_voidDisable(void)
{
	CLEAR_BIT(ADCSRA , 7);
}

#if ADC_U8_ADJUSTMENT == ADC_U8_LEFT
u8 ADC_u8Convert(u8 Local_u8Channel)
{
	ADC_voidDisable();
	ADMUX = ADMUX & 0b11100000; // mask
	ADMUX =  ADMUX | Local_u8Channel;
	ADC_voidEnable();
	// start conversion
	SET_BIT(ADCSRA , 6);
	// wait for ADC to finish conversion
	while(GET_BIT(ADCSRA , 6) == 1);
	
	return ADCH;
}

#elif ADC_U8_ADJUSTMENT == ADC_U8_RIGHT
u64 ADC_u16Convert(u8 Local_u8Channel)
{
	u8 Local_u8High = 0;
	u8 Local_u8LOW = 0;
	u64 Local_u64Result = 0;
	
	ADC_voidDisable();
	ADMUX = ADMUX & 0b11100000; // mask
	ADMUX =  ADMUX | Local_u8Channel;
	ADC_voidEnable();
	
	// start conversion
	SET_BIT(ADCSRA , 6);
	// wait for ADC to finish conversion
	while(GET_BIT(ADCSRA , 6) == 1);
	
	Local_u8LOW = ADCL; // 11111111
    Local_u8High = ADCH; // 000000011 << 8 => 000000011 00000000 | 11111111 => 000000011 11111111

	Local_u64Result = ( (Local_u8High & 0b00000011) << 8) | Local_u8LOW;
	
	return Local_u64Result;
}

#endif