/****************************************/
/*          Author: Marina Albert       */
/*          Date: 15-1-2024            */
/*          Version: 1.0                */
/*          Module: ADC                 */
/****************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_U8_AVCC       0
#define ADC_U8_AREF       1
#define ADC_U8_INTERNAL   2

#define ADC_U8_LEFT     3
#define ADC_U8_RIGHT    4

#define ADC_U8_BY2    1
#define ADC_U8_BY4    2
#define ADC_U8_BY8    3
#define ADC_U8_BY16   4
#define ADC_U8_BY32   5
#define ADC_U8_BY64   6
#define ADC_U8_BY128  7

#define ADCL    *((volatile u8 *)0x24)
#define ADCH    *((volatile u8 *)0x25)
#define ADCSRA  *((volatile u8 *)0x26)
#define ADMUX   *((volatile u8 *)0x27)

#endif