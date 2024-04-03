/*
 * EEPROM.c
 *
 * Created: 3/31/2024 5:44:56 PM
 *  Author: konno
 */ 

#include "EEPROM.h"

void EEPROM_write_one_char(uint16_t uiAddress, uint8_t ucData){
	EECR = 0x00;
	while (EECR & (1<<EEPE));	//Wait for previous write completion
	
	EEAR = uiAddress;
	EEDR = ucData;
	EECR |= (1<<EEMPE);	//Write logic one to EEMPE
	EECR |= (1<<EEPE);	//Start EEPROM write
	
}

void EEPROM_write_string(uint8_t uiAddress, char *ucData) {
	uint8_t track = uiAddress;
	while(*ucData != '\0') {
		EEPROM_write_one_char(track, *ucData);
		track++;
		ucData++;
		
	}
}

uint8_t EEPROM_read_one_char(uint16_t uiAddress) {
	while (EECR & (1<<EEPE));
	
	EEAR = uiAddress;
	EECR |= (1<<EERE);
	return EEDR;
}

void EEPROM_read_string(uint8_t uiAddress, char *EEPROM_buf_ptr) {
	uint16_t track = uiAddress;
	
	while (*(EEPROM_buf_ptr-1) != 0xFF) {
		*EEPROM_buf_ptr = EEPROM_read_one_char(track);
		track++;
		EEPROM_buf_ptr++;
	}
}

void EEPROM_write_locations(uint16_t uiAddress, uint16_t ucData) {
	
}