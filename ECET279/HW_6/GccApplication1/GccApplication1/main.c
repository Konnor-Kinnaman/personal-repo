/*
 * GccApplication1.c
 *
 * Created: 2/16/2024 6:37:29 PM
 * Author : konno
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void init_IO(void);
int main(void)
{
    
    while (1) 
    {
    }
}

void init_IO(void)
{
	DDRE = 0xFF;
	PORTE = 0x00;
	DDRL = 0xFF;
	PORTL = 0x00;
	OCR5A = 4;
	TCCR5A = 
	TCCR5B = 
	
}

