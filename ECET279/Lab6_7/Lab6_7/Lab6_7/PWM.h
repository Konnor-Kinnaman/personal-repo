/*
 * PWM.h
 *
 * Created: 2/20/2024 8:22:00 PM
 *  Author: Konnor Kinnaman
 */ 


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>
#define F_CPU 16000000UL


void ramp_up_delay_n_steps(uint8_t start, uint8_t end, uint16_t ms_time, uint8_t num_steps);



#endif /* PWM_H_ */