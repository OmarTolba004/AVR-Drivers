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

#include"LCD.h"
#include"LCD_Types.h"
#include"GPIO.h"
#include"avr/delay.h"
#include<stdlib.h>
/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/



/*
 * Description :
 * Send the required command to the screen
 */
void LCD_SendCommand(uint8 command)
{
	/*instruction mode RS=0*/
	GPIO_WriteChannel(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOW);
	_delay_ms(1);

	/*set Enable to high*/
	GPIO_WriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, HIGH);
	_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,5));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,6));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WriteChannel(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_WriteChannel(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,0));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,1));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,2));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WriteChannel(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	/*send the required command*/
	GPIO_WritePort(LCD_DATA_PORT_ID, command);
	_delay_ms(1);

	/*set Enable to high*/
	GPIO_WriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW);
	_delay_ms(1);
#endif

}

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_Init(void)
{
	/*set RS as an output pin*/
	GPIO_SetupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, OUTPUT);
	/*set E as an output pin*/
	GPIO_SetupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, OUTPUT);
	/*LCD power on delay > 15 milliseconds*/
	_delay_ms(20);
#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	GPIO_SetupPinDirection(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,OUTPUT);
	GPIO_SetupPinDirection(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,OUTPUT);
	GPIO_SetupPinDirection(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,OUTPUT);
	GPIO_SetupPinDirection(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)

	/*set data port as an output pin*/
	GPIO_SetupPortDirection(LCD_DATA_PORT_ID, OUTPUT);
	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_SendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	/* cursor off */
#endif
	LCD_SendCommand(LCD_CURSOR_OFF);
	/* clear LCD at the beginning */
	LCD_SendCommand(LCD_CLEAR_COMMAND);
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_DisplayCharacter(uint8 data)
{
	/*instruction mode RS=0*/
	GPIO_WriteChannel(LCD_RS_PORT_ID, LCD_RS_PIN_ID, HIGH);
	_delay_ms(1);

	/*set Enable to high*/
	GPIO_WriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, HIGH);
	_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,4));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,5));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,6));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WriteChannel(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_WriteChannel(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,0));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,1));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,2));
	GPIO_WriteChannel(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WriteChannel(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	/*send the required command*/
	GPIO_WritePort(LCD_DATA_PORT_ID, data);
	_delay_ms(1);

	/*set Enable to high*/
	GPIO_WriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW);
	_delay_ms(1);
#endif

}


/*
 * Description :
 * Display the required string on the screen
 */
void LCD_DisplayString(uint8* string)
{
	uint8 index=0;
	while(string[index]!='\0')
	{
		LCD_DisplayCharacter(string[index]);
		index++;
	}
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_MoveCursor(uint8 row, uint8 col)
{
	uint8 lcdMemoryAddress;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcdMemoryAddress = col;
		break;
	case 1:
		lcdMemoryAddress = 0x40+col;
		break;
	case 2:
		lcdMemoryAddress = 0x10+col;
		break;
	case 3:
		lcdMemoryAddress =0x50+ col;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_SendCommand(lcdMemoryAddress | LCD_SET_CURSOR_LOCATION);
}


/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_DisplayStringRowCol(uint8 row, uint8 col, uint8* string)
{
	LCD_MoveCursor(row, col);
	LCD_DisplayString(string);
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_IntegerToString(uint32 integerData)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(integerData,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_DisplayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_ClearScreen(void)
{
	LCD_SendCommand(LCD_CLEAR_COMMAND);
}

/******************************************************************************************************
 * End of File LCD.C
 ******************************************************************************************************/
