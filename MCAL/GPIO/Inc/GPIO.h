/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  GPIO.h
 *  Module:  	  GPIO
 *
 *  Description:  Header file for GPIO Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"GPIO_Types.h"
#include"std_types.h"
#include"common_macros.h"
#include<avr/io.h>

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_SetupPinDirection(GPIO_PortType port, GPIO_PinType pin, GPIO_DirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_WriteChannel(GPIO_PortType port,GPIO_PinType pin, GPIO_OutputValueType value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_ReadChannel(GPIO_PortType port,GPIO_PinType pin);

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_SetupPortDirection(GPIO_PortType port, uint8 direction);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_WritePort(GPIO_PortType port, uint8 value);


/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_ReadPort(GPIO_PortType port);



#endif /*GPIO_H_ */

/******************************************************************************************************
 * End of File GPIO.h
 ******************************************************************************************************/
