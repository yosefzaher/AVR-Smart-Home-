/******************************************************************/
/***************     Author: Zeinab EL_tantawy           **********/
/***************     Layer: HAL                          **********/
/***************     LED_Program                         **********/
/******************************************************************/

/**
 * @file led_control.c
 * @brief Functions to control LEDs.
 */

#include "DIO_interface.h"
#include  "BIT_math.h"
#include  "STD_types.h"
#include  "LED_interface.h"


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
void LED_voidInit(LED_T led )   
{
	DIO_u8_SetPinDirection(led.port, led.pin, DIO_u8PIN_OUTPUT);
}

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
void LED_voidOn(LED_T led )  
{
	if(led.Active_State == Active_High)
	{
		DIO_u8_SetPinValue(led.port, led.pin, DIO_u8PIN_HIGH);
	}
	else if(led.Active_State == Active_LOW)
	{
		DIO_u8_SetPinValue(led.port,led.pin,DIO_u8PIN_LOW);
	}	
}

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
void LED_voidOff(LED_T led )  
{
	if(led.Active_State == Active_High)
	{
		DIO_u8_SetPinValue(led.port,led.pin,DIO_u8PIN_LOW);
	}
	else if(led.Active_State == Active_LOW)
	{
		DIO_u8_SetPinValue(led.port,led.pin,DIO_u8PIN_HIGH);
	}
}
