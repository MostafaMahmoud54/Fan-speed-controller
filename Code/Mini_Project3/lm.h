/************************************************************************************
 * Sensor: LM35
 *
 * Filename: lm.h
 *
 * Description: Header file for the LM35 driver
 *
 * Created on: Oct 8, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/


#ifndef LM_H_
#define LM_H_
#include "std_types.h"
/***************************************************************************************
 * 									Definitions
 ***************************************************************************************/

#define VMAX_SENSOR 1.5
#define MAX_TEMP 150
#define MAX_OUTPUT 1023
#define VREF 2.56
#define LM_PIN 2

/***************************************************************************************
 * 								FUnction Prototypes
 ***************************************************************************************/
/*
 * Description:
 * function to get the adc reading and calculate the temperature
 */
uint8 LM35_getTemperature();
#endif /* LM_H_ */
