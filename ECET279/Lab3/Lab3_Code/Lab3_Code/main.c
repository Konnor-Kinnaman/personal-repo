/*
 * Lab3_StepperMotor.c
 *
 * Created: 1/17/2024 7:49:50 AM
 * Author : Konnor Kinnaman
 *
 * Project Name: Stepper Motor Control
 * Description:
 * This code controls a stepper motor
 * in three modes: Wave, Full, and Half Step.
 *
 * An array was declared for each mode, and the
 * contents of each array are the pattern for the
 * stepper motor stators. A loop cycles through each
 * array element to turn the shaft of the stepper
 * motor.
 *
 * The number of revolutions is hard-coded into the
 * program.
 *
 * Hardware:
 *	Output:
 *		IN1 --- PORTA.0
 *		IN2 --- PORTA.1
 *		IN3 --- PORTA.2
 *		IN4 --- PORTA.3
 *
 *	Input:
 *		SW0 --- PINC.0	Wave Step Mode
 *		SW1 --- PINC.1	Full Step Mode
 *		SW2 --- PINC.2	Half Step Mode
 *
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Debugger.h"
#include "stepper_motor.h"

//Function Prototypes
void init_IO(void);

int main(void)
{
    initDebug();	//Initializes Debugger
	init_IO();	//Initializes IO
    while (1) 
    {
		switch (PINC)	//Looks at PINC input
		{
			case Clockwise:	//if PINC.0 is pressed
			{
				stepper_movement('C',1);
				break;
			}
			case CC:	//if PINC.1 is pressed
			{
				stepper_movement('L',1);
				break;
			}
			case Half_Step:	//if PINC.2 is pressed
			{
				Stepper_Driver('H',2);
				break;
			}
			
			
		}
		stepper_output = 0x00;	//Clear output when done
    }
}

void init_IO(void)
{
	DDRA = 0xFF;	//Set PORTA to output
	PORTA = 0x00;
	DDRC = 0x00;	//Set PORTC to input
	PINC = 0xFF;	//Turn Pull-up resistors on
}

