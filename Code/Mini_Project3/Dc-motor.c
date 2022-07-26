/************************************************************************************
 * Module: Dc-motor
 *
 * Filename: Dc-motor.c
 *
 * Description: source file for the Dc-motor driver
 *
 * Created on: Oct 8, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/
#include "gpio.h"
#include "Dc-motor.h"
#include "pwm.h"

/*
 * Function to initialize the Dc-motor pins and stop the motor at the beginning
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(Dc_MOTOR_PORT,Dc_MOTOR_PIN0,PIN_OUTPUT);
	GPIO_setupPinDirection(Dc_MOTOR_PORT,Dc_MOTOR_PIN1,PIN_OUTPUT);
	GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN0,LOGIC_LOW);
	GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN1,LOGIC_LOW);
}
/*
 * Description:
 * Function to set the direction of the Dc-motor with a given speed
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch(state)
	{
	case stop:
		GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN0,LOGIC_LOW);
		GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN1,LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN1,LOGIC_HIGH);
		GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN0,LOGIC_LOW);
		break;
	case ACW:
		GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN0,LOGIC_HIGH);
		GPIO_writePin(Dc_MOTOR_PORT,Dc_MOTOR_PIN1,LOGIC_LOW);
		break;
	}
	PWM_Timer0_Start(speed);
}
