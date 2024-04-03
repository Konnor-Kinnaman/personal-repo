/*
 * EEPROM.h
 *
 * Created: 3/31/2024 5:45:09 PM
 *  Author: konno
 */ 

#include <avr/io.h>
#ifndef EEPROM_H_
#define EEPROM_H_

//Inclusions



//Definitions


//Function Prototypes
void EEPROM_write_one_char(uint16_t uiAddress, uint8_t ucData);
void EEPROM_write_string(uint8_t uiAddress, char *ucData);
uint8_t EEPROM_read_one_char(uint16_t uiAddress);
void EEPROM_read_string(uint8_t uiAddress, char *EEPROM_buf_ptr);
void EEPROM_write_locations(uint16_t uiAddress, uint16_t ucData);




#endif /* EEPROM_H_ */