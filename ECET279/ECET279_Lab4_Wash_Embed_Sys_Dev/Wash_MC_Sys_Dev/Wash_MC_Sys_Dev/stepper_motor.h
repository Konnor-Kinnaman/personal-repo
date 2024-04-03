/*
 * stepper_motor.h
 *
 * Created: 1/23/2024 4:18:41 PM
 *  Author: Konnor Kinnaman
 *
 * Description:
 *	This is the header file for
 *	the stepper_motor.c file.
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#define F_CPU 16000000UL

//Include Files
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

//Function Prototypes
void Stepper_Driver(char mode, uint8_t revolutions);

void Stepper_init(void);

void Stepper_Position(char mode, uint16_t degrees);

void stepper_movement(char mode, uint8_t revolutions);

//Definitions
#define Wave_Step	0x01
#define Full_Step	0x02
#define Half_Step	0x04
#define Clockwise	0x01
#define CC			0x02
#define stepper_output	(PORTA)

//Global Variables
extern uint8_t Wave[4];
extern uint8_t Full[4];
extern uint8_t Half[8];



#endif /* STEPPER_MOTOR_H_ */