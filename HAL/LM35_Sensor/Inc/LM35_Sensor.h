/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  LM35_Sensor.h
 *  Module:  	  LM35_Sensor
 *
 *  Description:  Header file for LM35_Sensor Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"std_types.h"
#include"common_macros.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define LM35_SENSOR_CHANNEL_ID			2
#define LM35_SENSOR_MAX_VOLT_VALUE     1.5
#define LM35_SENSOR_MAX_TEMPERATURE    150

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void);

#endif /*LM35_SENSOR_H_ */
