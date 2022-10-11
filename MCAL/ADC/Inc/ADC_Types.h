/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  ADC_Types.h
 *  Module:  	  ADC_Types
 *
 *  Description:  Header file for ADC_Types Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef enum
{
	AREF = 0 ,
	AVCC = 1,
	INTERNAL = 3,
}ADC_RefrenceVoltage;

typedef enum
{
	PRESCALER_2 = 0,
	PRESCALER_4 = 2,
	PRESCALER_8 = 3,
	PRESCALER_16 = 4,
	PRESCALER_32 = 5,
	PRESCALER_64 = 6,
	PRESCALER_128 = 7,

}ADC_Prescaler;

typedef struct
{
	ADC_RefrenceVoltage refrenceVoltage;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


#endif /* ADC_TYPES_H_ */
