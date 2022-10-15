/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  ICU.h
 *  Module:  	  ICU
 *
 *  Description:  Header file for ICU Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/
#ifndef ICU_H_
#define ICU_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"std_types.h"
#include"common_macros.h"
#include"ICU_Types.h"

/**********************************************************************************************************************
 * FUNCTION PROTOTYPE
 *********************************************************************************************************************/

/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_Init(const ICU_ConfigType *ICU_configPTR);

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_SetCallBack(void(*function)(void));

/*
 * Description: Function to set the required edge detection.
 */
void ICU_SetEdgeDetectionType(const ICU_EdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_GetInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_ClearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_DeInit(void);



#endif /* ICU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: ICU.h
 *********************************************************************************************************************/
