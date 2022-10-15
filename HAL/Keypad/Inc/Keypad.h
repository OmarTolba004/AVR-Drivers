/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Keybad.h
 *  Module:  	  Keybad
 *
 *  Description:  header file for Keybad Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/
#ifndef KEYBAD_H_
#define KEYBAD_H_


/**********************************************************************************************************************
 *  Definitions
 *********************************************************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTA_ID
#define KEYPAD_FIRST_ROW_PIN_ID           0

#define KEYPAD_COL_PORT_ID                PORTA_ID
#define KEYPAD_FIRST_COL_PIN_ID           4

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

/**********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_GetPressedKey(void);



#endif /* KEYBAD_H_ */

/******************************************************************************************************
 * End of File
 ******************************************************************************************************/
