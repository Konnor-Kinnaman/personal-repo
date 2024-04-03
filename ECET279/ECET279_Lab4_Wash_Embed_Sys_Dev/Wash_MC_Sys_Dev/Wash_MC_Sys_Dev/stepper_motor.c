/*
 * stepper_motor.c
 *
 * Created: 1/23/2024 4:18:09 PM
 *  Author: Konnor Kinnaman
 *
 * Description:
 *	This module of the program controls
 *	the stepper motor's speed, direction of rotation
 *	and mode of operation.
 */ 

#include "stepper_motor.h"
//Arrays for Stepper Modes
uint8_t Wave[4] = {0x01, 0x02, 0x04, 0x08};
uint8_t Full[4] = {0x03, 0x06, 0x0C, 0x09};
uint8_t Half[8] = {0x09, 0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08};
	
void Stepper_Driver(char mode,uint8_t revolutions)
{
	uint16_t steps = 512;	//Number of steps needed for one revolution
	switch (mode)
	{
		case 'W':	//If case is Wave step
		steps = steps * revolutions;	//Determines # of steps for # of revolutions
		for(uint16_t i = 0; i< steps; i++)	//Revolutions loop
		{
			for(uint16_t j=0; j<4; j++)	//Array loop
			{
				stepper_output = Wave[j];
				_delay_ms(3);
			}
		}
		break;
		
		case 'F':	//If case is Full step
		steps = steps * revolutions;
			for(uint16_t i=0; i<steps; i++)	//Revolutions loop
			{
				for(uint16_t j=0; j<4; j++)	//Array loop
				{
					stepper_output = Full[j];
					_delay_ms(3);
				}
			}
		break;
		
		case 'H':	//If case is Half step
		steps = 2*(steps/2)*revolutions;
			for(uint16_t i=0; i<steps; i++)	//Revolutions loop
			{
				for(uint16_t j=0; j<8; j++)	//Array loop
				{
					stepper_output = Half[j];
					_delay_ms(3);
				}
			}
		break;
	}
}

void stepper_movement(char mode,uint8_t revolutions)	//Function for directional movement
{
	uint16_t steps = 512;
	switch (mode)
	{
		case 'C':	//Clockwise Case
			steps = steps * revolutions;
			for(uint16_t i = 0; i< steps; i++)	//Revolutions loop
			{
				for(uint16_t j=0; j<4; j++)	//Array loop
				{
					stepper_output = Full[j];
					_delay_ms(3);
				}
			}
		break;
		
		case 'L':	//Counter Clockwise Case
			steps  = steps * revolutions;
			for(uint16_t i = 0; i< steps; i++)	//Revolutions loop
			{
				for(uint16_t j=4; j>0; j--)	//Array loop decrements for CC motion
				{
					stepper_output = Full[j];
					_delay_ms(3);
				}
			
			}
		break;
	}
}