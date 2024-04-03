/****************************************************/
/*													*/
/* Project name:	LCD_Test_8bit_parallel			*/
/* Displays a two line test message:				*/
/*													*/
/*		Test message: LCD is OK						*/
/*		in 8bit parallel mode						*/
/*   												*/
/* on the 2x16 dot matrix LCD at a specific 		*/
/* position using the ATMEL ATmega2560				*/
/*													*/
/* PORTL for LCD data:							 	*/
/* 													*/
/* L.0  LCD D0								        */
/* L.1  LCD D1 								        */
/* etc.									    		*/
/* L.7  LCD D7								        */
/*													*/
/* PORTD for LCD control:							*/
/*													*/
/*	D.0	LCD RS							         	*/
/*	D.1	LCD R/!W						        	*/
/*	D.2	LCD E							            */
/*													*/
/* 	The code is written as a single .c module		*/
/*													*/
/*	Author:		Prof A Oxtoby		*/
/*	Modified:	April Cheung						*/
/*	Date:		3-13-17								*/
/*	Ver:		1.0									*/
/*	Filename:	LCD_8bit_parallel.c		*/
/*													*/
/****************************************************/

/* #defines */

#define F_CPU 16000000UL // F_CPU must be defined BEFORE the #include <util/delay.h>

/*includes*/
#include "main.h"


int main(void)
{
	char T_mess[] = {"Test"};
	char B_mess1[] = {"Test"};
	char B_mess2[] = {"Test"};

	/* MUST initialize PORTs BEFORE initializing LCD */
	/* since need to write to LCD to initialize it */
	Init_PORTs();
	init_IO();
	init_USART_IO();
	Init_LCD();


	LCD_write(INSTR_WR, 0x01);
	_delay_ms(2);	//can remove if use Busy Flag check

	LCD_write(INSTR_WR, 0x02);
	_delay_ms(2);  //can remove if use Busy Flag check

	LCD_write(INSTR_WR, 0x85);
	//Print_string (T_mess);


	LCD_write(INSTR_WR, 0xC0);
	_delay_us(50);	//can remove if use Busy Flag check


	while(1) /* start of super loop */
	{

		/*LCD_write(INSTR_WR, 0xC5);	// Set DDRAM address to bottom row, left character
		_delay_us(50);	//can remove if use Busy Flag check
		Print_string (B_mess1);
		_delay_ms(2000);
		LCD_write(INSTR_WR, 0xC5);	// Set DDRAM address to bottom row, left character
		_delay_us(50);	//can remove if use Busy Flag check
		Print_string (B_mess2);
		_delay_ms(2000);*/
		
		if (LCD_update == 1)
		{
			LCD_update = 0;
			LCD_write(INSTR_WR, 0x01);
			_delay_us(50);
			Print_string(rx_buffer);
		}
		
		
		/*UART_out(PINC);
		PORTA = rx_char;*/

		}  /*end while(1) loop */

		return(0);

		}	/* end main */
		
		
void init_IO(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;	//Configure PORTA to output
	DDRC = 0x00;
	PORTC = 0xFF;	//Configure PORTC to input
}




