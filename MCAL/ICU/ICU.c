/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  ICU.c
 *  Module:  	  ICU
 *
 *  Description:  Source file for ICU Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ICU.h"
#include <avr/interrupt.h>
#include "GPIO.h"

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

static volatile void(*g_callBackFunctionPtr)(void) = NULL_PTR ;


/**********************************************************************************************************************
 *  INTERRUPT SERVICE ROUTINES
 *********************************************************************************************************************/
ISR(TIMER1_CAPT_vect)
{
	if(g_callBackFunctionPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		g_callBackFunctionPtr();
	}
}

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_Init(const ICU_ConfigType *ICU_configPTR)
{
	/* Configure ICP1/PD6 as i/p pin */
	GPIO_SetupPinDirection(PORTD_ID, PIN6_ID, INPUT);

	/* Timer1 always operates in Normal Mode */
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);

	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xF8) | (ICU_configPTR->clockType);

	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | ((ICU_configPTR->edgeType)<<6);

	/* Initial Value for Timer1 */
	TCNT1 = 0;

	/* Initial Value for the input capture register */
	ICR1 = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	SET_BIT(TIMSK,TICIE1);


}

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_SetCallBack(void volatile (*function)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackFunctionPtr=function;
}

/*
 * Description: Function to set the required edge detection.
 */
void ICU_SetEdgeDetectionType(const ICU_EdgeType edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | (edgeType<<6);
}


/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_GetInputCaptureValue(void)
{
	return ICR1;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_ClearTimerValue(void)
{
	TCNT1 = 0;
}

void ICU_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	CLEAR_BIT(TIMSK,TICIE1);

}
