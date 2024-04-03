/*
 * PWM.c
 *
 * Created: 2/20/2024 8:21:48 PM
 *  Author: Konnor Kinnaman
 */ 

#include "PWM.h"

void ramp_up_delay_n_steps(uint8_t start, uint8_t end, uint16_t ms_time, uint8_t num_steps)
{
	uint8_t scaled_start = (start/100)*255;
	uint8_t scaled_end = (end/100)*255;
	uint16_t duty_cycle_change = (scaled_end-scaled_start)/num_steps;
	uint16_t step_time = duty_cycle_change/ms_time;
}