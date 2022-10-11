/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  ADC.h
 *  Module:  	  ADC
 *
 *  Description:  Header file for ADC Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/
#ifndef ADC_H_
#define ADC_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"std_types.h"
#include"common_macros.h"
#include"ADC_Types.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_Init(const ADC_ConfigType* configTypePtr);

/* Description :
* Function responsible for read analog data from a certain ADC channel
* and convert it to digital using the ADC driver.
*/
uint16 ADC_ReadChannel(uint8 channelNum);


#endif /* ADC_H_ */
