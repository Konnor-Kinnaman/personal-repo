/*
 * LCD.h
 *
 * Created: 3/19/2024 4:29:04 PM
 *  Author: konno
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL
//Inclusions
#include <avr/io.h>
#include <util/delay.h>

//Definitions
#define INSTR_WR	0
#define DATA_WR		1

//Function Prototypes
void Init_PORTs (void);
void Init_LCD (void);
void LCD_write (unsigned char RS, unsigned char data);
void Print_string(char *data_ptr);



#endif /* LCD_H_ */