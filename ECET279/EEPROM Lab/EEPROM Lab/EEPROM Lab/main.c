/*
 * EEPROM Lab.c
 *
 * Created: 3/31/2024 5:43:42 PM
 * Author : Konnor Kinnaman
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "EEPROM.h"

#define EEPROM_start_address 0x0000
void init_IO(void);
char message[6] = {"String"};
char output[6] = {};
uint16_t locations[6] = {100, 400, 800, 1000, 1500, 2148};


int main(void)
{
	init_IO();
    while (1) 
    {
		//EEPROM_write_one_char(0x0000, 0x41);
		EEPROM_write_string(EEPROM_start_address, message);
		EEPROM_read_string(EEPROM_start_address, output);
    }
}

void init_IO() {
	DDRC = 0x00:
	PORTC = 0xFF;	//Init PORTC as input
}

