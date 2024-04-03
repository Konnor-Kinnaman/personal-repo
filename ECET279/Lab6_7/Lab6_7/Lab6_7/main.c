/*
 * Lab6_7.c
 *
 * Created: 2/14/2024 7:45:11 AM
 * Author : Konnor Kinnaman
 *
 *	This program uses the PWM
 *	feature on the microcontroller
 *	to generate a PWM signal with
 *	variable duty cycle that increases
 *	at a rate that can be changed. This PWM
 *	signal is used to drive a motor.
 *
 *	Hardware:
 *	Inputs:
 *		PORTA.0 - Button for PWM mode
 *	Outputs:
 *		OC3A(PE.3) - Output PWM signal
 *		PORTC.0-8 - Output to LEDs
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

#include "Debugger.h"
//#include "PWM.h"

void init_IO(void);
void delay_1ms(void);
void custom_delay(uint8_t delay);
void ramp_up_delay_n_steps(uint8_t start, uint8_t end, uint16_t ms_time, uint8_t num_steps);
int main(void)
{
	init_IO();
	initDebug();
    while (1) 
    {
		TCCR3A = (1<<COM3A1)|(1<<WGM30)|(1<<WGM31);	//COM mode 2 WGM mode 1
		TCCR3B = (1<<CS30)|(1<<CS32);	//Set prescaler to 1024
		if (PINC == 0x01)
		{
			ramp_up_delay_n_steps(10, 90, 8000, 8);
		}
		if (PINC == 0x02)
		{
			OCR3A = 0;	
		}
    }
}

void init_IO()
{
	DDRC = 0x00;	//Set PORTA to input
	PINC = 0xFF;
	DDRF = 0x00;	//Set PORTF to input for ADC
	PINF = 0xFF;
	DDRA = 0xFF;	//Set PORTC to output
	PORTA = 0x00;
	//Timer Registers
	TCNT0 = 6;
	TCCR0A = 0;
	TCCR0B  = 0;
	//PWM Registers
	DDRE = 0xFF;	//Set PORTE to output for Timer3
	PORTE = 0x00;
}

void delay_1ms(void)
{
	TCCR0B = 0x03;	//Prescaler = 64
	while((TIFR0 & (1<<TOV0)) == 0);	//wait until overflow flag is set
	TCCR0B = 0;	//Stop Timer
	TIFR0 |= (1<<TOV0);	//Clear overflow flag
	TCNT0 = 6;
}

void custom_delay(uint8_t delay)	//Calls 1ms delay n number of times for custom delay
{
	for (int i = 0; i < delay; i++)
	{
		delay_1ms();
	}
}
void ramp_up_delay_n_steps(uint8_t start, uint8_t end, uint16_t ms_time, uint8_t num_steps)
{
	uint16_t scaled_start = (start*1.0/100)*1024;
	uint16_t scaled_end = (end*1.0/100)*1024;
	uint16_t duty_cycle_change = (scaled_end-scaled_start)/num_steps;
	uint16_t step_time = ms_time/num_steps;
	OCR3A = scaled_start;
	for (uint8_t i=0; i<num_steps; i++)
	{
		OCR3A = OCR3A + duty_cycle_change;
		custom_delay(step_time);
	}
}

