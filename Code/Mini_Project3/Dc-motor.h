/*
 * Dc-motor.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Mostafa Mahmoud
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
/************************************************************************************
 *                                Definitions
 ************************************************************************************/
#define Dc_MOTOR_PIN0 PIN0_ID
#define Dc_MOTOR_PIN1 PIN1_ID
#define Dc_MOTOR_PORT PORTB_ID
/************************************************************************************
 * 								 Types Declaration
 ************************************************************************************/
typedef enum
{
	stop,CW,ACW
}DcMotor_State;

/************************************************************************************
 * 						Function Prototypes
 ************************************************************************************/
/*
 * Function to initialize the Dc-motor pins and stop the motor at the beginning
 */
void DcMotor_Init(void);
/*
 * Description:
 * Function to set the direction of the Dc-motor with a given speed
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
