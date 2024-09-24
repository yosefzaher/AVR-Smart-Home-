/******************************************************************/
/***************     Author: Zeinab EL_tantawy         ************/
/***************     Layer: HAL                        ************/
/***************     Buzzer_program                    ************/
/******************************************************************/

/**
 * @file buzzer_control.c
 * @brief Functions to control a buzzer using GPIO pins.
 */


#include "BUZZER_interface.h"
#include "DIO_interface.h"

/**
 * @brief Initializes the buzzer by setting its pin direction and initial state.
 * 
 * This function sets the direction of the buzzer's pin to output and initializes the 
 * pin value based on the buzzer's active state. 
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidInit(BUZZER_T buzzer) 
{
    // Set the buzzer pin as output
    DIO_u8_SetPinDirection(buzzer.port, buzzer.pin, DIO_u8PIN_OUTPUT);
    
    // Set the initial pin value based on the buzzer's active state
    if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) 
    {
        // Active high: set pin to low (buzzer off initially)
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, DIO_u8PIN_LOW);  
    } 
    else 
    {
        // Active low: set pin to high (buzzer off initially)
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, DIO_u8PIN_HIGH); 
    }
}

/**
 * @brief Turns the buzzer on.
 * 
 * This function sets the pin value to turn on the buzzer based on its active state.
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidOn(BUZZER_T buzzer) 
{
    if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) 
    {
        // Active high: set pin to high (buzzer on)
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, DIO_u8PIN_HIGH); 
    } 
    else 
    {
        // Active low: set pin to low (buzzer on)
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, DIO_u8PIN_LOW); 
    }
}

/**
 * @brief Turns the buzzer off.
 * 
 * This function sets the pin value to turn off the buzzer based on its active state.
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidOff(BUZZER_T buzzer) 
{
    if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) 
    {
        // Active high: set pin to low (buzzer off)
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, DIO_u8PIN_LOW); 
    } 
    else 
    {
        // Active low: set pin to high (buzzer off)
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, DIO_u8PIN_HIGH); 
    }
}

/**
 * @brief Toggles the buzzer state.
 * 
 * This function changes the buzzer's state from on to off or off to on, based on its current state 
 * and active state configuration.
 * 
 * @param buzzer A structure of type `BUZZER_T` that specifies the buzzer's port, pin, and active state.
 */
void BUZZER_voidToggle(BUZZER_T buzzer) 
{
    u8 pinValue;
    
    // Get the current pin value
    DIO_u8_GetPinValue(buzzer.port, buzzer.pin, &pinValue);

    if (buzzer.Active_State == BUZZER_ACTIVE_HIGH) 
    {
        // Active high: toggle between high and low
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, pinValue == DIO_u8PIN_HIGH ? DIO_u8PIN_LOW : DIO_u8PIN_HIGH);
    } 
    else
    {
        // Active low: toggle between low and high
        DIO_u8_SetPinValue(buzzer.port, buzzer.pin, pinValue == DIO_u8PIN_LOW ? DIO_u8PIN_HIGH : DIO_u8PIN_LOW);
    }
}
