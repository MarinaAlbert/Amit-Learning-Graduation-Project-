#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void EEPROM_voidInit(void);
void EEPROM_VoidWriteByte(u16 Copy_Location , u8 Copy_Data);
u8   EEPROM_u8ReadByte(u16 Copy_Location);
void EEPROM_VoidWriteString(u16 Copy_Location,s8 Copy_Str[]);
void EEPROM_u8ReadString(u16 Copy_Location, s8 Copy_Str[]);

#endif /* EEPROM_INT_H_ */
