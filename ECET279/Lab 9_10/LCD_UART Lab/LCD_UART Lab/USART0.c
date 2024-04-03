/*
 * USART0.c
 *
 * Created: 3/25/2024 5:42:53 PM
 *  Author: konno
 */ 

#include "USART0.h"
uint8_t n = 0;

void init_USART_IO()
{
	uint16_t myubr;
	DDRE = 0x00;
	PORTE = 0xFF;	//configure PORT E to output
	sei();
	UCSR0A = 0x00;
	UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	
	myubr = (F_CPU / 16UL*9600)-1;
	UBRR0L = myubr;
	UBRR0H = 0x00;
}

void UART_out(uint8_t ch)
{
	while ((UCSR0A & (1 << UDRE0))==0)
	{
		//wait to complete transmission
	}
	UDR0 = ch;
}


ISR(USART0_RX_vect)
{
	rx_char = UDR0;
	if (rx_char != 0x0D)
	{
		rx_buffer[n] = rx_char;
		n++;
	}
	else if (rx_char == 0x0D)
	{
		rx_buffer[n] = '\0';
		n = 0;
	}
	LCD_update = 1;
}