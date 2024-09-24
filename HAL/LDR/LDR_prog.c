/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#include "BIT_math.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_cfg.h"
#include "LDR_prv.h"


/**
 * @brief Initialize the Light Dependent Resistor (LDR) system.
 *
 * This function initializes the ADC (Analog-to-Digital Converter) 
 * which is used for reading the LDR values. It calls the 
 * `ADC_voidInit` function to set up the ADC with the appropriate 
 * configuration.
 */
void LDR_VoidInit(void)
{
    ADC_voidInit();
}

/**
 * @brief Calculate the LDR resistance from an 8-bit ADC result.
 *
 * This function converts the ADC digital result from an 8-bit ADC to 
 * the corresponding voltage, then uses the voltage divider formula 
 * to calculate the LDR (Light Dependent Resistor) resistance.
 *
 * @param Copy_u16Adc_Res: The ADC digital result (8-bit) read from the LDR.
 * @return u16: The calculated LDR resistance in ohms.
 *
 * @note Assumes that the ADC resolution is 8 bits (max value = 255).
 */
u16 LDR_u16GetResistanceFrom8BitADC(u16 Copy_u16Adc_Res)
{
    f32 Local_f32Get_Voltage = 0;
    u16 Local_u16Ldr_Res  = 0;

    // Convert ADC digital result to voltage (assuming an 8-bit ADC, max value = 255)
    Local_f32Get_Voltage = ((float)Copy_u16Adc_Res / 255.0) * VREF;

    if (Local_f32Get_Voltage > 0 && Local_f32Get_Voltage < VREF)
    {
        // Use voltage divider formula to calculate LDR resistance
        Local_u16Ldr_Res = (u16)((R_FIXED * (VREF - Local_f32Get_Voltage)) / Local_f32Get_Voltage);
    }

    return Local_u16Ldr_Res;
}

/**
 * @brief Calculate the LDR resistance from a 10-bit ADC result.
 *
 * This function converts the ADC digital result from a 10-bit ADC to 
 * the corresponding voltage, then uses the voltage divider formula 
 * to calculate the LDR (Light Dependent Resistor) resistance.
 *
 * @param Copy_u16Adc_Res: The ADC digital result (10-bit) read from the LDR.
 * @return u16: The calculated LDR resistance in ohms.
 *
 * @note Assumes that the ADC resolution is 10 bits (max value = 1023).
 */
u16 LDR_u16GetResistanceFrom10BitADC(u16 Copy_u16Adc_Res)
{
    f32 Local_f32Get_Voltage = 0;
    u16 Local_u16Ldr_Res  = 0;

    // Convert ADC digital result to voltage (assuming a 10-bit ADC, max value = 1023)
    Local_f32Get_Voltage = ((float)Copy_u16Adc_Res / 1023.0) * VREF;

    // Ensure voltage is not zero to avoid division by zero
    if (Local_f32Get_Voltage > 0 && Local_f32Get_Voltage < VREF)
    {
        // Use voltage divider formula to calculate LDR resistance
        Local_u16Ldr_Res = (u16)((R_FIXED * (VREF - Local_f32Get_Voltage)) / Local_f32Get_Voltage);
    }

    return Local_u16Ldr_Res;
}