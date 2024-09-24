/*********************************************
 *                                           *
 *  Author : ENG.Ahmed Shaboury              *
 *  Layer  : HAL                             *
 *  SWC    : STEPPER_MOTOR                   *
 *  Version : 1.2.0                          *
 *                                           *
 *********************************************/

/**
 * @file StepperMotorConfig.h
 * @brief Configuration file for stepper motor control pins and port settings.
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_
#define HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_

/* Port and Pin Configuration for Stepper Motor */

/**
 * @brief Macro to define the port connected to the stepper motor.
 * 
 * The stepper motor control signals are connected to a specific port on the microcontroller.
 * Choose the port according to the hardware connections. The available options are:
 * 
 * - DIO_u8PORTA
 * - DIO_u8PORTB
 * - DIO_u8PORTC
 * - DIO_u8PORTD
 */
#define STEPPER_PORT  DIO_u8PORTC

/**
 * @brief Macro to define the pin connected to the blue coil of the stepper motor.
 * 
 * The pin on the specified port that controls the blue coil of the stepper motor.
 * Choose the pin according to the hardware connections. The available options are:
 * 
 * - DIO_u8PIN0
 * - DIO_u8PIN1
 * - DIO_u8PIN2
 * - DIO_u8PIN3
 * - DIO_u8PIN4
 * - DIO_u8PIN5
 * - DIO_u8PIN6
 * - DIO_u8PIN7
 */
#define STEPPER_BLUE_PIN     DIO_u8PIN3

/**
 * @brief Macro to define the pin connected to the pink coil of the stepper motor.
 * 
 * The pin on the specified port that controls the pink coil of the stepper motor.
 * Choose the pin according to the hardware connections. The available options are:
 * 
 * - DIO_u8PIN0
 * - DIO_u8PIN1
 * - DIO_u8PIN2
 * - DIO_u8PIN3
 * - DIO_u8PIN4
 * - DIO_u8PIN5
 * - DIO_u8PIN6
 * - DIO_u8PIN7
 */
#define STEPPER_PINK_PIN     DIO_u8PIN4

/**
 * @brief Macro to define the pin connected to the yellow coil of the stepper motor.
 * 
 * The pin on the specified port that controls the yellow coil of the stepper motor.
 * Choose the pin according to the hardware connections. The available options are:
 * 
 * - DIO_u8PIN0
 * - DIO_u8PIN1
 * - DIO_u8PIN2
 * - DIO_u8PIN3
 * - DIO_u8PIN4
 * - DIO_u8PIN5
 * - DIO_u8PIN6
 * - DIO_u8PIN7
 */
#define STEPPER_YELLOW_PIN   DIO_u8PIN5

/**
 * @brief Macro to define the pin connected to the orange coil of the stepper motor.
 * 
 * The pin on the specified port that controls the orange coil of the stepper motor.
 * Choose the pin according to the hardware connections. The available options are:
 * 
 * - DIO_u8PIN0
 * - DIO_u8PIN1
 * - DIO_u8PIN2
 * - DIO_u8PIN3
 * - DIO_u8PIN4
 * - DIO_u8PIN5
 * - DIO_u8PIN6
 * - DIO_u8PIN7
 */
#define STEPPER_ORANGE_PIN   DIO_u8PIN6

#endif /* HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_ */
