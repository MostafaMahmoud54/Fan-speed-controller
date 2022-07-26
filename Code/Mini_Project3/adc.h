/************************************************************************************
 * Module: ADC
 *
 * Filename: adc.c
 *
 * Description: Header file for the adc driver
 *
 * Created on: Oct 8, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "std_types.h"

#define aref 6
/************************************************************************************
 * 								 Types Declaration
 ************************************************************************************/
typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef enum
{
	AREF,AVCC,Internal=3
}ADC_ReferenceVolatge;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/************************************************************************************
 * 								Function Prototypes
 ************************************************************************************/

/*
 * Description:
 * A function to initialize the adc
 */
void ADC_INIT(const ADC_ConfigType * Config_Ptr);
/*
 * Description:
 * A function to:
 * 1- read the analog value
 * 2- start conversion
 * 3- return the digital value
 */
uint16 ADC_readChannel(uint8 ch_num);
#endif /* ADC_H_ */
