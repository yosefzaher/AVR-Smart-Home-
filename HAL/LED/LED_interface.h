/******************************************************************/
/***************     Author: Zeinab EL_tantawy           **********/
/***************     Layer: HAL                          **********/
/***************     LED_interface                       **********/
/******************************************************************/

/**
 * @file led_control.h
 * @brief Definitions for LED configuration.
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/**
 * @def Active_High
 * @brief Defines the LED active state as high.
 * 
 * When an LED is configured with this active state, it will turn on when the associated
 * GPIO pin is set to high voltage (logic 1).
 */
#define Active_High 1

/**
 * @def Active_LOW
 * @brief Defines the LED active state as low.
 * 
 * When an LED is configured with this active state, it will turn on when the associated
 * GPIO pin is set to low voltage (logic 0).
 */
#define Active_LOW  0


/**
 * @struct LED_T
 * @brief Structure to define the configuration of an LED.
 * 
 * This structure holds the information required to control an LED connected to a specific
 * GPIO port and pin, and its active state.
 */
typedef struct 
{
    u8 port;           /**< The GPIO port where the LED is connected (e.g., DIO_u8PORTA). */
    u8 pin;            /**< The GPIO pin number where the LED is connected (e.g., DIO_u8PIN0). */
    u8 Active_State;   /**< The active state of the LED (Active_High or Active_LOW). */
} LED_T;

/**
 * @brief Initialize the LED.
 * 
 * Configures the specified GPIO pin as an output for the LED.
 * 
 * @param led
 * A `LED_T` structure that contains the configuration details for the LED:
 * - `port`: The GPIO port where the LED is connected.
 * - `pin`: The GPIO pin number where the LED is connected.
 * - `Active_State`: The active state of the LED (Active_High or Active_LOW).
 */
void LED_voidInit(LED_T led);

/**
 * @brief Turn on the LED.
 * 
 * Sets the GPIO pin to the appropriate state to turn the LED on based on its active state.
 * 
 * @param led
 * A `LED_T` structure that contains the configuration details for the LED:
 * - `port`: The GPIO port where the LED is connected.
 * - `pin`: The GPIO pin number where the LED is connected.
 * - `Active_State`: The active state of the LED (Active_High or Active_LOW).
 */
void LED_voidOn(LED_T led);

/**
 * @brief Turn off the LED.
 * 
 * Sets the GPIO pin to the appropriate state to turn the LED off based on its active state.
 * 
 * @param led
 * A `LED_T` structure that contains the configuration details for the LED:
 * - `port`: The GPIO port where the LED is connected.
 * - `pin`: The GPIO pin number where the LED is connected.
 * - `Active_State`: The active state of the LED (Active_High or Active_LOW).
 */
void LED_voidOff(LED_T led);



#endif /* LED_INTERFACE_H_ */