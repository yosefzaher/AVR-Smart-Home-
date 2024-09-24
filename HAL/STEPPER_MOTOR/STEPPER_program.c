/*********************************************
 *                                           *
 *  Author : ENG.Ahmed Shaboury              *
 *  Layer  : HAL                             *
 *  SWC    : STEPPER_MOTOR                   *
 *  Version : 1.2.0                          *
 *                                           *
 *********************************************/

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_config.h"


/**
 * @brief Initializes the pins connected to the stepper motor as output pins.
 *
 * This function sets the direction of the four pins connected to the stepper motor 
 * (orange, yellow, blue, and pink) as output pins. It then initializes their 
 * output values to LOW (0) to ensure the motor is not activated unintentionally.
 *
 * @param None
 * @return None
 */
void STEPPER_voidInit(void) {
    // Set the direction of the stepper motor pins as output
    DIO_u8_SetPinDirection(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PORT_OUTPUT);
    DIO_u8_SetPinDirection(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PORT_OUTPUT);
    DIO_u8_SetPinDirection(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PORT_OUTPUT);
    DIO_u8_SetPinDirection(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PORT_OUTPUT);

    // Initialize all pins to LOW to ensure the motor is off initially
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
}


/**
 * @brief Controls the operation of the stepper motor, including step type, direction, and speed.
 *
 * This function activates the stepper motor by sending signals to the motor's pins in sequence. 
 * It supports both full-step and half-step modes, and the motor can rotate either 
 * clockwise (CW) or counterclockwise (anti-clockwise, ACW). The speed and degree of rotation 
 * depend on the input parameters.
 *
 * @param Copy_u8StepType Type of stepping (STEPPER_FULL_STEP or STEPPER_HALF_STEP).
 * @param Copy_u8Direction Direction of rotation (STEPPER_CLOCK_WISE or STEPPER_ANTI_CLOCK_WISE).
 * @return None
 */
void STEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction ){

	if( Copy_u8StepType == STEPPER_FULL_STEP )
	{
		if( Copy_u8Direction == STEPPER_CLOCK_WISE )
		{
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW );
				_delay_ms( 50 );
		}
		else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE )
		{
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
		}

	}
	else if( Copy_u8StepType == STEPPER_HALF_STEP )
	{
		if( Copy_u8Direction == STEPPER_CLOCK_WISE )
		{
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH   );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH   );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW);
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW );
				_delay_ms( 50 );
		}
		else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE )
		{
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH);
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH);
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH);
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW);
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_LOW  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   ,  DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   ,  DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN ,  DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN ,  DIO_u8PIN_HIGH );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_HIGH);
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_LOW );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH);
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH);
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   ,  DIO_u8PIN_LOW   );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   ,  DIO_u8PIN_LOW   );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN ,  DIO_u8PIN_HIGH  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN ,  DIO_u8PIN_HIGH  );
				_delay_ms( 50 );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_u8PIN_LOW  );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_u8PIN_HIGH );
				DIO_u8_SetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_u8PIN_HIGH );
				_delay_ms( 50 );
		}
	}
}

/**
 * @brief Turns off the stepper motor by setting all motor pins to LOW.
 *
 * This function disables the stepper motor by setting all connected pins 
 * (orange, yellow, blue, and pink) to LOW, effectively stopping the motor.
 *
 * @param None
 * @return None
 */
void STEPPER_voidOff(void) {
    // Set all stepper motor pins to LOW to turn off the motor
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
    DIO_u8_SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
}


