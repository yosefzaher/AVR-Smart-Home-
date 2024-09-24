/*********************************************
 *                                           *
 *  Author : ENG.Ahmed Shaboury              *
 *  Layer  : HAL                             *
 *  SWC    : LM35 Temp Sensor                *
 *  Version : 1.2.2                          *
 *                                           *
 *********************************************/

#include "STD_types.h"
#include "map.h"

#include "LM35_interface.h"

#include "ADC_interface.h"

/**
 * @brief Get the temperature reading from an LM35 temperature sensor.
 * 
 * This function converts the raw ADC value from the LM35 sensor to a temperature value based on
 * the sensor's resolution and reference voltage.
 * 
 * @param[in] Copy_component Pointer to an `ADC_info` structure containing ADC configuration details.
 * @param[in] Dig_Temp The raw ADC value read from the LM35 sensor.
 * @param[out] Result Pointer to a `u16` variable where the calculated temperature value will be stored.
 * 
 * @return `u8` Error status code:
 *         - `NO_ERROR` if the operation is successful.
 *         - `ERROR` if the resolution in `Copy_component` is neither 8 nor 10 bits.
 *         - `NULL_PTR_ERR` if the `Copy_component` pointer is NULL.
 */
u8 LM35_getTemperature(ADC_info* Copy_component, u16 Dig_Temp, u16* Result)
{
    u8 Local_u8ErrState = NO_ERROR;
    
    if (Copy_component != NULL)
    {
        if (Copy_component->resolution == 8)
        {
            // Convert 8-bit ADC value to temperature
            Dig_Temp = (u16) Map(0, 5, 0, Copy_component->Vref, Dig_Temp);
            *Result = (u16)(((u32)Dig_Temp * ((u32)(Copy_component->Vref) * 100UL)) / 255UL);
        }
        else if (Copy_component->resolution == 10)
        {
            // Convert 10-bit ADC value to temperature
            Dig_Temp = (u16) Map(0, 1023, 0, 255, Dig_Temp);
            *Result = (u16)(((u32)Dig_Temp * ((u32)(Copy_component->Vref) * 100UL)) / 1023UL);
        }
        else
        {
            // Invalid resolution
            Local_u8ErrState = ERROR;
        }
    }
    else
    {
        // Null pointer error
        Local_u8ErrState = NULL_PTR_ERR;
    }
    
    return Local_u8ErrState;
}