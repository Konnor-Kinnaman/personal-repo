/*
 * main.h
 *
 * Created: 3/25/2024 6:40:24 PM
 *  Author: konno
 */ 


#ifndef MAIN_H_
#define MAIN_H_
#define F_CPU 16000000UL // F_CPU must be defined BEFORE the #include <util/delay.h>
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "USART0.h"


void init_IO(void);

volatile uint16_t array_index;
volatile uint16_t LCD_update;
volatile char rx_buffer[25];




#endif /* MAIN_H_ */