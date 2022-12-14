/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Ultrasonic.h
 *  Module:  	  Ultrasonic
 *
 *  Description:  Header file for Ultrasonic Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  13/10/2022
 *********************************************************************************************************************/
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
#define ULTRASONIC_TRIGGER_PIN   	PIN5_ID
#define ULTRASONIC_TRIGGER_PORT  	PORTB_ID

#define ULTRASONIC_ECHO_PIN   	PIN6_ID
#define ULTRASONIC_ECHO_PORT  	PORTD_ID


/**********************************************************************************************************************
 * FUNCTION PROTOTYPE
 *********************************************************************************************************************/

/*
 * Description :
 * Initialize the ICU driver as required.
 * Setup the ICU call back function.
 * Setup the direction for the trigger pin as output pin through the GPIO driver
 */
void Ultrasonic_Init(void);

/*
 * Description :
 * Send the Trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void);

/*
 * Description :
 * Send the trigger pulse by using Ultrasonic_Trigger function.
 * Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_ReadDistance(void);

/*
 * Description :
 * This is the call back function called by the ICU driver.
 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_EdgeProcessing(void);

#endif /* ULTRASONIC_H_ */



