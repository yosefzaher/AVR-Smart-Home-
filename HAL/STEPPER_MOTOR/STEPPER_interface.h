/*********************************************
 *                                           *
 *  Author : ENG.Ahmed Shaboury              *
 *  Layer  : HAL                             *
 *  SWC    : STEPPER_MOTOR                   *
 *  Version : 1.2.0                          *
 *                                           *
 *********************************************/

/**
 * @file StepperMotor.h
 * @brief Header file for stepper motor control functions and macros.
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_

/**
 * @file StepperMotor.h
 * @brief Header file for stepper motor control functions and macros.
 */

/* Macros for Stepper Motor Control */

/**
 * @brief Macro to define full step mode for the stepper motor.
 * 
 * In full step mode, the motor moves one full step per pulse, providing higher torque but
 * less precision.
 */
#define STEPPER_FULL_STEP    1

/**
 * @brief Macro to define half step mode for the stepper motor.
 * 
 * In half step mode, the motor moves half a step per pulse, providing higher precision
 * but lower torque compared to full step mode.
 */
#define STEPPER_HALF_STEP    0

/**
 * @brief Macro to define clockwise rotation direction for the stepper motor.
 * 
 * When set to this value, the stepper motor will rotate in a clockwise direction.
 */
#define STEPPER_CLOCK_WISE       1

/**
 * @brief Macro to define counterclockwise rotation direction for the stepper motor.
 * 
 * When set to this value, the stepper motor will rotate in a counterclockwise direction.
 */
#define STEPPER_ANTI_CLOCK_WISE  0

/**
 * @brief Initializes the stepper motor.
 * 
 * This function is responsible for setting up the hardware and configurations required
 * for the stepper motor to operate correctly. This may include setting pin directions
 * and initializing any required peripherals.
 * 
 * @param None
 * @return None
 */
void STEPPER_voidInit(void);

/**
 * @brief Turns off the stepper motor.
 * 
 * This function deactivates the stepper motor, stopping any movement and turning off
 * the necessary control signals.
 * 
 * @param None
 * @return None
 */
void STEPPER_voidOff(void);

/**
 * @brief Activates the stepper motor with the specified step type and direction.
 * 
 * This function starts the stepper motor operation with the given step type (full step
 * or half step) and direction (clockwise or counterclockwise). The function controls
 * the motor by setting the appropriate pins to the correct state and may include a delay
 * between steps.
 * 
 * @param Copy_u8StepType The stepping mode to be used, defined by the STEPPER_FULL_STEP
 *                        or STEPPER_HALF_STEP macros.
 * @param Copy_u8Direction The direction of rotation, defined by the STEPPER_CLOCK_WISE
 *                        or STEPPER_ANTI_CLOCK_WISE macros.
 * @return None
 */
void STEPPER_voidOn(u8 Copy_u8StepType, u8 Copy_u8Direction);

#endif /* HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_ */
