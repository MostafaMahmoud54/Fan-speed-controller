/************************************************************************************
 * Sensor: LM35
 *
 * Filename: lm.c
 *
 * Description: Source file for the LM35 driver
 *
 * Created on: Oct 8, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/


#include "lm.h"
#include "adc.h"
/*
 * Description:
 * function to get the adc reading and calculate the temperature
 */
uint8 LM35_getTemperature()
{
	uint16 reading=ADC_readChannel(LM_PIN);
	uint8 temp= (uint8)(((uint32)reading*VREF*MAX_TEMP)/(VMAX_SENSOR*MAX_OUTPUT));
	return temp;
}
