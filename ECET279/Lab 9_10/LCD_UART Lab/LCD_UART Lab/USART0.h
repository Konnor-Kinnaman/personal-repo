/*
 * USART0.h
 *
 * Created: 3/25/2024 5:43:05 PM
 *  Author: konno
 */ 


#ifndef USART0_H_
#define USART0_H_
#include <avr/io.h>
#define F_CPU 16000000UL

//Inclusions
#include <avr/interrupt.h>
#include "main.h"

//Definitions



//Function Prototypes
void init_USART_IO(void);
void UART_out(uint8_t ch);

volatile uint8_t rx_char;


#endif /* USART0_H_ */