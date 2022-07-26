/************************************************************************************
 * Module: PWM
 *
 * Filename: pwm.c
 *
 * Description: source file for the pwm driver
 *
 * Created on: Oct 8, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/
#include <avr/io.h>
#include "gpio.h"

/*
 * Description:
 * Function to initialize timer0 in the PWM mode with the required duty cycle
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);
	TCNT0=0;
	OCR0=duty_cycle*2.55; //duty cycle
}
