/*
 * Wash_MC_Sys_Dev.c
 *
 * Created: 1/31/2024 7:38:49 AM
 * Author : Konnor Kinnaman
 *
 *	This code is meant to simulate the operation of
 *  a washing machine. This is a multimodule program
 *	that incorporates the use of the stepper motor
 *	to simulate the operation of a washing machine.
 *	Inputs
 *		Hot -- PINA.0
 *		Warm -- PINA.1
 *		Cold -- PINA.2
 *		Door -- PINA.3
 *		Start -- PINA.4
 *	Outputs
 *		IN1 -- PORTC.0
 *		IN2 -- PORTC.2
 *		IN3 -- PORTC.4
 *		IN4 -- PORTC.6
 *		Drain -- PORTL.0
 *		Hot Valve -- PORTL.1
 *		Cold Valve -- PORTL.2
 *		Done -- PORTL.3
 *		Agitate -- PORTL.4
 *		Spin -- PORTL.5
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "Debugger.h"
#include <util/delay.h>

//Definitions
#define StartButton PINA4
#define DoorSwitch PINA3
#define CHECK_BIT(x,y) x&(1<<y)==(1<<y)
#define SET_BIT(x,y) x=x | (1<<y);

void init_io(void);
void fill(void);
void rinse(void);

int main(void)
{
	//initDebug();
	init_io();
	PORTC = 0x01;
    while (1) 
    {
		uint8_t StartCondition = 0;
		while (StartCondition == 0)
		{
			while ((PINA & (1<<StartButton))!=(1<<StartButton));	//Check for start button input
			if ((PINA & (1<<DoorSwitch))==(1<<DoorSwitch))	//Check if door is closed
			{
				StartCondition = 1;
			}
		}
		//PORTC = 0xFF;
		fill();
    }
}

void init_io(void)
{
	DDRA = 0x00;	//PORTA as input
	PINA = 0xFF;	//Turn pull-up resistors on
	DDRC = 0xFF;	//PORTC as output
	PORTC = 0x00;
	DDRL = 0xFF;	//PORTL as output
	PORTL = 0x00;
}

void fill(void)
{
	while (PINA == 0x08);	//Wait for temp switches to be flipped
	switch (PINA)
	{
		case 0x0C:	//Cold Water
			PORTC = 0x04;
			break;
		case 0x09:	//Hot Water
			PORTC = 0x02;
			break;
		case 0x0A:	//Warm Water
			PORTC = 0x06;
			break;
	}
	//_delay_ms(4000);
	return;
}

