/************************************************************************************
 * Filename: main.c
 *
 * Description: main source file for mini project 3
 *
 * Created on: Oct 11, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/
#include "gpio.h"
#include "adc.h"
#include "lcd.h"
#include "lm.h"
#include "Dc-motor.h"
#include "pwm.h"
int main()
{
	/******************************
	 * peripherals Initialization
	 ******************************/
	LCD_init(); //Initialize the ADC
	DcMotor_Init(); //Initialize the motor and make it off at the beginning
	ADC_ConfigType config={Internal,F_CPU_8}; //Vref= internal 2.56 and frequency =cpu/8
	ADC_INIT(&config); //Initialize the ADC

	uint8 temp=0;

	while(1)
	{
		LCD_moveCursor(0,4);
		temp=LM35_getTemperature();
		/*
		 *Display the fan state and the motor speed according to the temperature
		 */
		if(temp>=120)
		{
			DcMotor_Rotate(CW,100); //duty cycle=100%
			LCD_displayString("FAN is ON");
		}
		else if(temp>=90)
		{
			DcMotor_Rotate(CW,75); //duty cycle=75%
			LCD_displayString("FAN is ON");
		}
		else if(temp>=60)
		{
			DcMotor_Rotate(CW,50); //duty cycle=50%
			LCD_displayString("FAN is ON");
		}
		else if(temp>=30)
		{
			DcMotor_Rotate(CW,25); //duty cycle=25%
			LCD_displayString("FAN is ON");
			LCD_displayCharacter(' ');
		}
		else if(temp<30)
		{
			DcMotor_Rotate(stop,0); //duty cycle=0
			LCD_displayString("FAN is OFF");
		}
		LCD_moveCursor(1,4);
		LCD_displayString("Temp = ");
		LCD_intgerToString(temp);
		LCD_displayCharacter('C');
		LCD_displayCharacter(' ');
	}
}
