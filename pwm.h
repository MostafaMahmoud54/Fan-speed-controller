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

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/********************************************************************************
 * 							Function Prototypes									*
 ********************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
