/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  DC_Motor.c
 *  Module:  	  DC_Motor
 *
 *  Description:  Source file for DC Motor Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  04/10/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"DC_Motor.h"
#include"GPIO.h"
#include"PWM.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITION
 *********************************************************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 *
 */
void DCMotor_Init(void)
{
	/* set enable pin as output*/
	GPIO_SetupPinDirection(DC_MOTOR_EN_PORT, DC_MOTOR_EN_PIN, OUTPUT);

	/* set IN1 pin as output*/
	GPIO_SetupPinDirection(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, OUTPUT);

	/* set IN2 pin as output*/
	GPIO_SetupPinDirection(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, OUTPUT);

	/* Stop at the DC-Motor at the beginning through the GPIO driver.*/
	GPIO_WriteChannel(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOW);
	GPIO_WriteChannel(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOW);

}

void DCMotor_Rotate(DC_MotorStateType motorState, uint8 speed )
{
	switch(motorState)
	{
	case STOP:
		/* Stop at the DC-Motor.*/
		GPIO_WriteChannel(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOW);
		GPIO_WriteChannel(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOW);
		break;
	case CLOCKWISE:
		/* Make the the DC-Motor rotates ClockWise.*/
		GPIO_WriteChannel(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOW);
		GPIO_WriteChannel(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, HIGH);
		break;
	case ANTI_CLOCKWISE:
		/* Make the the DC-Motor rotates Anti-ClockWise.*/
		GPIO_WriteChannel(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, HIGH);
		GPIO_WriteChannel(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOW);
		break;
	}

	speed = (uint8)((speed/100.0)*255);
	PWM_Timer0_Init(speed);
}

