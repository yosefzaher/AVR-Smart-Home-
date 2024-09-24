/***************************************************************/
/***************     Author: Zeinab EL_tantawy       ***********/
/***************     Layer: MCAL                     ***********/
/***************     DIO_interface                   ***********/
/***************************************************************/

#include "STD_types.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**
 * @brief Macro to set a pin as output.
 */
#define DIO_u8PIN_OUTPUT 1

/**
 * @brief Macro to set a pin as input.
 */
#define DIO_u8PIN_INPUT 0

/**
 * @brief Macro to set a pin to a high state (logic 1).
 */
#define DIO_u8PIN_HIGH 1

/**
 * @brief Macro to set a pin to a low state (logic 0).
 */
#define DIO_u8PIN_LOW  0


/**
 * @brief Macro to set all pins of a port as output.
 */
#define DIO_u8PORT_OUTPUT 0xFF

/**
 * @brief Macro to set all pins of a port as input.
 */
#define DIO_u8PORT_INPUT  0

/**
 * @brief Macros for PORTdentifier.
 */
#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

/**
 * @brief Macro for PINSdentifier.
 */
#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7


/**
 * @brief Sets the direction of a specific pin.
 * 
 * This function configures the direction of a specific pin on a given port
 * as either input or output.
 * 
 * @param copy_u8Port The port where the pin is located (e.g., DIO_u8PORTA).
 * @param copy_u8Pin The pin number to be configured (e.g., DIO_u8PIN0).
 * @param copy_u8Direction The direction to be set (DIO_u8PIN_INPUT or DIO_u8PIN_OUTPUT).
 * @return u8 Returns 0 on success, non-zero on failure.
 */
u8 DIO_u8_SetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction) ;

/**
 * @brief Sets the direction of all pins in a specific port.
 * 
 * This function configures the direction of all pins in a given port
 * as either input or output.
 * 
 * @param copy_u8Port The port to be configured (e.g., DIO_u8PORTA).
 * @param copy_u8Direction The direction to be set (DIO_u8PORT_INPUT or DIO_u8PORT_OUTPUT).
 * @return u8 Returns 0 on success, non-zero on failure.
 */
u8 DIO_u8_SetPortDirection(u8 copy_u8Port, u8 copy_u8Direction) ;

/**
 * @brief Sets the value of a specific pin.
 * 
 * This function sets the output value of a specific pin on a given port
 * to either high (logic 1) or low (logic 0).
 * 
 * @param copy_u8Port The port where the pin is located (e.g., DIO_u8PORTA).
 * @param copy_u8Pin The pin number to be set (e.g., DIO_u8PIN0).
 * @param copy_u8Value The value to be set (DIO_u8PIN_HIGH or DIO_u8PIN_LOW).
 * @return u8 Returns 0 on success, non-zero on failure.
 */
u8 DIO_u8_SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value) ;

/**
 * @brief Sets the value of all pins in a specific port.
 * 
 * This function sets the output value of all pins in a given port
 * to either high (logic 1) or low (logic 0).
 * 
 * @param copy_u8Port The port to be configured (e.g., DIO_u8PORTA).
 * @param copy_u8Value The value to be set (e.g., 0xFF for high, 0x00 for low).
 * @return u8 Returns 0 on success, non-zero on failure.
 */
u8 DIO_u8_SetPortValue(u8 copy_u8Port, u8 copy_u8Value) ;

/**
 * @brief Reads the value of a specific pin.
 * 
 * This function reads the input value of a specific pin on a given port.
 * 
 * @param copy_u8Port The port where the pin is located (e.g., DIO_u8PORTA).
 * @param copy_u8Pin The pin number to be read (e.g., DIO_u8PIN0).
 * @param copy_pu8Value Pointer to store the read value (1 for high, 0 for low).
 * @return u8 Returns 0 on success, non-zero on failure.
 */
u8 DIO_u8_GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_pu8Value) ;

#endif /* DIO_INTERFACE_H_ */