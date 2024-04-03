/*
 * HW7.c
 *
 * Created: 2/24/2024 8:14:42 PM
 * Author : konno
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void init_IO(void);
uint16_t ADC_10_bit(uint8_t channel);
void pwm_init(uint16_t duty_cycle);

int main(void)
{
	init_IO();  
    while (1) 
    {
		uint16_t adc_result = 0;
		uint16_t adc_result = ADC_10_bit(0);	//Store ADC result
		pwm_init(adc_result);	//Generate PWM signal with DC of adc_result/1024
    }
}

void init_IO()
{
	DDRE = 0xFF;	//Set PORTE to output for Timer3
	PORTE = 0x00;
	DDRF = 0x00;	//Set PORTF to input with pull-up resistors off
	PORTF = 0x00;
}

uint16_t ADC_10_bit(uint8_t channel)
{
	uint16_t adc_value = 0;
	ADMUX = (ADMUX & 0x0E)|channel;	//Channel Select
	ADCSRA |= (1<<ADSC);	//Start Conversion
	while((ADCSRA & (1<<ADSC))==1);	//Wait for conversion to finish
	
	adc_value = ADCL;
	adc_value |= (ADCH<<8);	//Shift ADCH value
	return adc_value;
}

void pwm_init(uint16_t duty_cycle)
{
	uint8_t scaled_dc = (duty_cycle/1024)*255;
	TCCR3A = (1<<COM3A1)|(1<<WGM30);	//Set COM mode 2 WGM mode 1
	TCCR3B = (1<<CS00)|(1<<CS02);	//Set prescalar = 1024
	OCR3A = scaled_dc;	//Set OCR3A
}
