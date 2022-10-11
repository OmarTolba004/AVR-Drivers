/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  LCD.h
 *  Module:  	  LCD
 *
 *  Description:  Header file for LCD Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/



#ifndef LCD_H_
#define LCD_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include"std_types.h"
#include"common_macros.h"


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_Init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_SendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_DisplayCharacter(uint8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_DisplayString(uint8* string);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_MoveCursor(uint8 row, uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_DisplayStringRowCol(uint8 row, uint8 col, uint8* string);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_IntegerToString(uint32 integerData);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_ClearScreen(void);







#endif /* HLCD_H_ */
/******************************************************************************************************
 * End of File LCD.h
 ******************************************************************************************************/
