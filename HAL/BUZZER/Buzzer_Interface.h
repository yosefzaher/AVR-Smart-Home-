/******************************************************************/
/***************     Author: Zeinab EL_tantawy         ************/
/***************     Layer: HAL                        ************/
/***************     Buzzer_interface                  ************/
/******************************************************************/


/**
 * @file buzzer_interface.h
 * @brief Definitions and structure for buzzer control configuration.
 */


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "STD_types.h"

/**
 * @brief Buzzer active states.
 * 
 * Defines the active states for the buzzer control. The active state determines
 * how the buzzer is turned on or off by setting the GPIO pin to high or low.
 */
#define BUZZER_ACTIVE_HIGH  1  /**< Buzzer is active when the GPIO pin is high. */
#define BUZZER_ACTIVE_LOW   0  /**< Buzzer is active when the GPIO pin is low. */

/**
 * @struct BUZZER_T
 * @brief Buzzer configuration structure.
 * 
 * This structure holds the configuration for the buzzer, including the GPIO port,
 * pin number, and the active state of the buzzer.
 * 
 * @var BUZZER_T::port
 * The GPIO port number where the buzzer is connected.
 * 
 * @var BUZZER_T::pin
 * The GPIO pin number where the buzzer is connected.
 * 
 * @var BUZZER_T::Active_State
 * The active state of the buzzer. Determines whether the buzzer is active high or active low.
 */
typedef struct {
    u8 port;          /**< GPIO port number for the buzzer. */
    u8 pin;           /**< GPIO pin number for the buzzer. */
    u8 Active_State;  /**< Active state of the buzzer: BUZZER_ACTIVE_HIGH or BUZZER_ACTIVE_LOW. */
} BUZZER_T;

/**
 * @brief Initializes the buzzer by setting its pin direction and initial state.
 * 
 * This function sets the direction of the buzzer's pin to output and initializes the 
 * pin value based on the buzzer's active state. 
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidInit(BUZZER_T buzzer)  ;

/**
 * @brief Turns the buzzer on.
 * 
 * This function sets the pin value to turn on the buzzer based on its active state.
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidOn(BUZZER_T buzzer)  ;

/**
 * @brief Turns the buzzer off.
 * 
 * This function sets the pin value to turn off the buzzer based on its active state.
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidOff(BUZZER_T buzzer)  ;

/**
 * @brief Toggles the buzzer state.
 * 
 * This function changes the buzzer's state from on to off or off to on, based on its current state 
 * and active state configuration.
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidToggle(BUZZER_T buzzer)  ;


#endif /* BUZZER_INTERFACE_H_ */
