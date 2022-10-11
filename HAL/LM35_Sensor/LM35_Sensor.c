/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  LM35_Sensor.c
 *  Module:  	  LM35_Sensor
 *
 *  Description:  Source file for LM35_Sensor Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include"LM35_Sensor.h"
#include"ADC.h"

uint8 LM35_GetTemperature(void)
{
		uint8 tempValue=0;

		uint16 ADCValue=0;

		/* Read ADC channel where the temperature sensor is connected */
		ADCValue = ADC_ReadChannel(LM35_SENSOR_CHANNEL_ID);

		//tempValue = (uint8)(((uint32)LM35_SENSOR_MAX_TEMPERATURE*ADCValue*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LM35_SENSOR__MAX_VOLT_VALUE));
		tempValue = (uint8)(((uint32)ADCValue*LM35_SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LM35_SENSOR_MAX_VOLT_VALUE));
		return tempValue;

}
