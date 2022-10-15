/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Ultrasonic.c
 *  Module:  	  Ultrasonic
 *
 *  Description:  Source file for Ultrasonic Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  13/10/2022
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Ultrasonic.h"
#include "ICU.h"
#include "GPIO.h"
#include <avr/delay.h>

/**********************************************************************************************************************
 * STATIC GLOBAL VARIABLES
 *********************************************************************************************************************/
uint8 g_edgeCount = 0 ;
uint16 g_timeHigh = 0 ;
uint8 g_distance = 0;
uint8 g_flag = 0;

/**********************************************************************************************************************
 * FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/*
 * Description :
 * Initialize the ICU driver as required.
 * Setup the ICU call back function.
 * Setup the direction for the trigger pin as output pin through the GPIO driver
 */
void Ultrasonic_Init(void)
{
	/* Setting the configuration for the ICU Driver*/
	ICU_ConfigType Icu_Config ={F_CPU_8,RISING};
	/* Set the callback function*/
	ICU_SetCallBack(Ultrasonic_EdgeProcessing);
	/* Setting the configuration for the ICU Driver*/
	ICU_Init(&Icu_Config);
	/* Set the trigger pin as output pin*/
	GPIO_SetupPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN, OUTPUT);
}

/*
 * Description :
 * Send the Trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void)
{
	/* Sending at least 10us pulse at the trigger pin*/
	GPIO_WriteChannel(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, HIGH);
	_delay_ms(30);
	GPIO_WriteChannel(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOW);
}

/*
 * Description :
 * Send the trigger pulse by using Ultrasonic_Trigger function.
 * Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_ReadDistance(void)
{
	/* Injecting the trigger signal.*/
	Ultrasonic_Trigger();
	/* Wait till edge count equals to 2 */
//	while(g_edgeCount != 2);
//	/* Reset the value of edge count*/
////	while(g_flag == 0);/*wait till the flag is set*/
////	g_flag = 0;
//	g_edgeCount = 0;



	/* Calculating the distance*/
	g_distance = (g_timeHigh/58.8);
	/* Returning the value of distance*/
	return g_distance;
}

void Ultrasonic_EdgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount== 1)
	{
		/* Clear the value at the timer of ICU*/
		ICU_ClearTimerValue();
		/* Set the edge detection of the ICU to falling*/
		ICU_SetEdgeDetectionType(FALLING);
	}else if(g_edgeCount == 2)
	{
		/* Read the value of ICU timer*/
		g_timeHigh = ICU_GetInputCaptureValue();
		/* Set the edge detection of the ICU to rising*/
		ICU_SetEdgeDetectionType(RISING);
		/* Reset the value of edge count*/
		g_edgeCount = 0;
	}
}














