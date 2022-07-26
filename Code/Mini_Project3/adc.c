/************************************************************************************
 * Module: ADC
 *
 * Filename: adc.c
 *
 * Description: source file for the adc driver
 *
 * Created on: Oct 8, 2021
 *
 * Author: Mostafa Mahmoud
 ************************************************************************************/


#include "adc.h"
#include <avr/io.h>
/*
 * Description:
 * A function to initialize the adc
 */
void ADC_INIT(const ADC_ConfigType * Config_Ptr)
{
	ADMUX=(0x03 & Config_Ptr->ref_volt)<<6;
	ADCSRA|=(1<<ADEN);
	ADCSRA|=(Config_Ptr->prescaler & 0x07);

}

/*
 * Description:
 * A function to:
 * 1- read the analog value
 * 2- start conversion
 * 3- return the digital value
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX=(ADMUX& 0xE0)|(ch_num & 0x07);
	ADCSRA|=(1<<ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
