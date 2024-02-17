/****************************************/
/*          Author: Marina Albert       */        
/*          Date: 15-1-2024            */
/*          Version: 1.0                */
/*          Module: ADC                 */
/****************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*
options:

ADC_U8_AVCC
ADC_U8_AREF
ADC_U8_INTERNAL

*/

#define ADC_U8_VREF   ADC_U8_AVCC

/*
ADC_U8_LEFT
ADC_U8_RIGHT

*/
#define ADC_U8_ADJUSTMENT ADC_U8_RIGHT


/*
ADC_U8_BY2
ADC_U8_BY4
ADC_U8_BY8
ADC_U8_BY16
ADC_U8_BY32
ADC_U8_BY64
ADC_U8_BY128
*/
#define ADC_U8_PRESCALER ADC_U8_BY8

#endif
