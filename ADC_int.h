/****************************************/
/*          Author: Marina Albert       */
/*          Date: 15-1-2024            */
/*          Version: 1.0                */
/*          Module: ADC                 */
/****************************************/

#ifndef ADC_INT_H_
#define ADC_INT_H_


void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);

#define ADC_U8_Channel0  0
#define ADC_U8_Channel1  1
#define ADC_U8_Channel2  2
#define ADC_U8_Channel3  3
#define ADC_U8_Channel4  4
#define ADC_U8_Channel5  5
#define ADC_U8_Channel6  6
#define ADC_U8_Channel7  7


u8 ADC_u8Convert(u8 Local_u8Channel);
u64 ADC_u16Convert(u8 Local_u8Channel);

#endif


