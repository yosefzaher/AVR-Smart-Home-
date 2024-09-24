/***************************************************************/
/***************     Author: Zeinab EL_tantawy    **************/
/***************     Layer: MCAL                  **************/
/***************     DIO_program                  **************/
/***************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "DIO_Register.h"

/**
 * @brief Sets the direction of a specific pin on a given port.
 * 
 * This function configures the direction of a specific pin (input or output) on a given port (PORTA, PORTB, PORTC, or PORTD).
 * 
 * @param copy_u8Port The port number (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, or DIO_u8PORTD).
 * @param copy_u8Pin The pin number (0 to 7) on the specified port.
 * @param copy_u8Direction The desired direction (DIO_u8PIN_INPUT or DIO_u8PIN_OUTPUT).
 * 
 * @return u8 Error state: 
 * - 0 if the operation is successful.
 * - 1 if the pin or direction is invalid or the port is incorrect.
 */
u8 DIO_u8_SetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction) 
{
    u8 Local_u8ErrorState = 0;

    if ((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Pin >= DIO_u8PIN0)) 
	{
        if (copy_u8Direction == DIO_u8PIN_INPUT) 
		{
            switch (copy_u8Port) 
			{
                case DIO_u8PORTA: CLR_BIT(DDRA, copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(DDRB, copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(DDRC, copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(DDRD, copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        } 
		else if (copy_u8Direction == DIO_u8PIN_OUTPUT) 
		{
            switch (copy_u8Port) 
			{
                case DIO_u8PORTA: SET_BIT(DDRA, copy_u8Pin); break;
                case DIO_u8PORTB: SET_BIT(DDRB, copy_u8Pin); break;
                case DIO_u8PORTC: SET_BIT(DDRC, copy_u8Pin); break;
                case DIO_u8PORTD: SET_BIT(DDRD, copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        } 
		else 
		{
            Local_u8ErrorState = 1;
        }
    } 
	else 
	{
        Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

/**
 * @brief Sets the direction of all pins on a given port.
 * 
 * This function configures the direction (input or output) of all pins on the specified port.
 * 
 * @param copy_u8Port The port number (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, or DIO_u8PORTD).
 * @param copy_u8Direction The desired direction for all pins (input or output).
 * 
 * @return u8 Error state:
 * - 0 if successful.
 * - 1 if the port is invalid.
 */
u8 DIO_u8_SetPortDirection(u8 copy_u8Port, u8 copy_u8Direction) 
{
    u8 local_u8ErrorState = 0;

    switch (copy_u8Port) 
	{
        case DIO_u8PORTA: DDRA = copy_u8Direction; break;
        case DIO_u8PORTB: DDRB = copy_u8Direction; break;
        case DIO_u8PORTC: DDRC = copy_u8Direction; break;
        case DIO_u8PORTD: DDRD = copy_u8Direction; break;
        default: local_u8ErrorState = 1;
    }

    return local_u8ErrorState;
}

/**
 * @brief Sets the value of a specific pin on a given port.
 * 
 * This function sets the value (high or low) of a specific pin on a given port (PORTA, PORTB, PORTC, or PORTD).
 * 
 * @param copy_u8Port The port number (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, or DIO_u8PORTD).
 * @param copy_u8Pin The pin number (0 to 7) on the specified port.
 * @param copy_u8Value The desired value for the pin (DIO_u8PIN_HIGH or DIO_u8PIN_LOW).
 * 
 * @return u8 Error state:
 * - 0 if the operation is successful.
 * - 1 if the pin or value is invalid or the port is incorrect.
 */
u8 DIO_u8_SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value) 
{
    u8 Local_u8ErrorState = 0;

    if ((copy_u8Pin <= DIO_u8PIN7) && (copy_u8Pin >= DIO_u8PIN0)) 
	{
        if (copy_u8Value == DIO_u8PIN_LOW) 
		{
            switch (copy_u8Port) 
			{
                case DIO_u8PORTA: CLR_BIT(PORTA, copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(PORTB, copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(PORTC, copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(PORTD, copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        } 
		else if (copy_u8Value == DIO_u8PIN_HIGH) 
		{
            switch (copy_u8Port) 
			{
                case DIO_u8PORTA: SET_BIT(PORTA, copy_u8Pin); break;
                case DIO_u8PORTB: SET_BIT(PORTB, copy_u8Pin); break;
                case DIO_u8PORTC: SET_BIT(PORTC, copy_u8Pin); break;
                case DIO_u8PORTD: SET_BIT(PORTD, copy_u8Pin); break;
                default: Local_u8ErrorState = 1;
            }
        } 
		else 
		{
            Local_u8ErrorState = 1;
        }
    } 
	else 
	{
        Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

/**
 * @brief Sets the value of all pins on a given port.
 * 
 * This function sets the value (high or low) of all pins on the specified port.
 * 
 * @param copy_u8Port The port number (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, or DIO_u8PORTD).
 * @param copy_u8Value The desired value for all pins on the port.
 * 
 * @return u8 Error state:
 * - 0 if successful.
 * - 1 if the port is invalid.
 */
u8 DIO_u8_SetPortValue(u8 copy_u8Port, u8 copy_u8Value) 
{
    u8 local_u8ErrorState = 0;

    switch (copy_u8Port) 
	{
        case DIO_u8PORTA: PORTA = copy_u8Value; break;
        case DIO_u8PORTB: PORTB = copy_u8Value; break;
        case DIO_u8PORTC: PORTC = copy_u8Value; break;
        case DIO_u8PORTD: PORTD = copy_u8Value; break;
        default: local_u8ErrorState = 1;
    }

    return local_u8ErrorState;
}

/**
 * @brief Reads the value of a specific pin on a given port.
 * 
 * This function reads the digital value (high or low) of a specific pin on a given port (PORTA, PORTB, PORTC, or PORTD).
 * 
 * @param copy_u8Port The port number (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, or DIO_u8PORTD).
 * @param copy_u8Pin The pin number (0 to 7) on the specified port.
 * @param copy_pu8Value Pointer to store the pin value (high or low).
 * 
 * @return u8 Error state:
 * - 0 if successful.
 * - 1 if the pin or port is invalid, or the pointer is NULL.
 */
u8 DIO_u8_GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_pu8Value) 
{
    u8 Local_u8ErrorState = 0;

    if ((copy_pu8Value != NULL) && (copy_u8Pin <= DIO_u8PIN7)) 
	{
        switch (copy_u8Port) 
		{
            case DIO_u8PORTA: *copy_pu8Value = GET_BIT(PINA, copy_u8Pin); break;
            case DIO_u8PORTB: *copy_pu8Value = GET_BIT(PINB, copy_u8Pin); break;
            case DIO_u8PORTC: *copy_pu8Value = GET_BIT(PINC, copy_u8Pin); break;
            case DIO_u8PORTD: *copy_pu8Value = GET_BIT(PIND, copy_u8Pin); break;
            default: Local_u8ErrorState = 1;
        }
    } 
	else 
	{
        Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

