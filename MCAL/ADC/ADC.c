/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  ADC.c
 *  Module:  	  ADC
 *
 *  Description:  Source file for ADC Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"ADC.h"
#include<avr/io.h>

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITION
 *********************************************************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_Init(const ADC_ConfigType* configTypePtr)
{

	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = choose channel as initialization
	 */
	ADMUX = ((configTypePtr->refrenceVoltage &0x03)<<6);

	/*  ADCSRA
	 * 	ADEN = 1 --> ADC Enable
	 *  Bits 2:0 – ADPS2:0 = 011 --> ADC Prescaler Select Bits (1MHz / 8 =125 KHz) --> ADC must operate in range 50-200Khz
	 *inserting the preScaler configuration
	 */
	ADCSRA = (configTypePtr->prescaler & 0x07);

	SET_BIT(ADCSRA,ADEN);

}

uint16 ADC_ReadChannel(uint8 channelNum)
{
	/* Input channel number must be from 0 --> 7 */
	channelNum &= 0x07;
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX &= 0xE0;
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX = ADMUX | channelNum;
	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);
	/* Wait for conversion to complete, ADIF becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/* Clear ADIF by write '1' to it :) */
	SET_BIT(ADCSRA,ADIF);
	/* Read the digital value from the data register */
	return ADC;
}

