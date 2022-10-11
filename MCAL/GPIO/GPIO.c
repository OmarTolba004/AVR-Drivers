/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  GPIO.c
 *  Module:  	  GPIO
 *
 *  Description:  Source file for GPIO Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"GPIO.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_SetupPinDirection(GPIO_PortType port, GPIO_PinType pin, uint8 direction)
{
	if(direction == OUTPUT)
	{
		switch(port)
		{

		/*set the Direction register DDRA*/
		case PORTA_ID:
			SET_BIT(DDRA,pin);
			break;

		case PORTB_ID:
			SET_BIT(DDRB,pin);
			break;

		case PORTC_ID:
			SET_BIT(DDRC,pin);
			break;

		case PORTD_ID:
			SET_BIT(DDRD,pin);
			break;
		}
	}else if (direction == INPUT)
	{
		switch(port)
		{

		/*set the Direction register DDRA*/
		case PORTA_ID:
			CLEAR_BIT(DDRA,pin);
			break;

		case PORTB_ID:
			CLEAR_BIT(DDRB,pin);
			break;

		case PORTC_ID:
			CLEAR_BIT(DDRC,pin);
			break;

		case PORTD_ID:
			CLEAR_BIT(DDRD,pin);
			break;
		}
	}

}


/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_WriteChannel(GPIO_PortType port,GPIO_PinType pin, GPIO_OutputValueType value)
{
	if(value == HIGH)
	{
		switch(port)
		{

		/*set the Direction register DDRA*/
		case PORTA_ID:
			SET_BIT(PORTA,pin);
			break;

		case PORTB_ID:
			SET_BIT(PORTB,pin);
			break;

		case PORTC_ID:
			SET_BIT(PORTC,pin);
			break;

		case PORTD_ID:
			SET_BIT(PORTD,pin);
			break;
		}
	}else if (value == LOW)
	{
		switch(port)
		{

		/*set the Direction register DDRA*/
		case PORTA_ID:
			CLEAR_BIT(PORTA,pin);
			break;

		case PORTB_ID:
			CLEAR_BIT(PORTB,pin);
			break;

		case PORTC_ID:
			CLEAR_BIT(PORTC,pin);
			break;

		case PORTD_ID:
			CLEAR_BIT(PORTD,pin);
			break;
		}
	}
}


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_ReadChannel(GPIO_PortType port,GPIO_PinType pin)
{
	uint8 localReading = 0x00;
	switch(port)
	{
	case PORTA_ID:
		localReading = GET_BIT(PINA,pin);
		break;

	case PORTB_ID:
		localReading = GET_BIT(PINB,pin);
		break;

	case PORTC_ID:
		localReading = GET_BIT(PINC,pin);
		break;

	case PORTD_ID:
		localReading = GET_BIT(PIND,pin);
		break;
	}
	return localReading;
}


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_SetupPortDirection(GPIO_PortType port, uint8 direction)
{

	/*write direction value in the port DDRX register*/
	switch(port)
	{
	case PORTA_ID:
		DDRA = direction;
		break;
	case PORTB_ID:
		DDRB = direction;
		break;
	case PORTC_ID:
		DDRC = direction;
		break;
	case PORTD_ID:
		DDRD = direction;
		break;
	}

}


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_WritePort(GPIO_PortType port, uint8 value)
{

	/*write value in PORTX register*/
	switch(port)
	{
	case PORTA_ID:
		PORTA = value;
		break;
	case PORTB_ID:
		PORTB = value;
		break;
	case PORTC_ID:
		PORTC = value;
		break;
	case PORTD_ID:
		PORTD = value;
		break;
	}



}


/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_ReadPort(GPIO_PortType port)
{
	uint8 localReading=0x00;
	switch(port)
	{
	/*Read value in PINX register*/
	case PORTA_ID:
		localReading = PINA;
		break;
	case PORTB_ID:
		localReading = PINB;
		break;
	case PORTC_ID:
		localReading = PINC;
		break;
	case PORTD_ID:
		localReading = PIND;
		break;

	}
	return localReading;
}





/******************************************************************************************************
 * End of File GPIO.C
 ******************************************************************************************************/




