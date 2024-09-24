/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

/**
 * @brief Initialize the Light Dependent Resistor (LDR) system.
 *
 * This function initializes the ADC (Analog-to-Digital Converter) 
 * which is used for reading the LDR values. It calls the 
 * `ADC_voidInit` function to set up the ADC with the appropriate 
 * configuration.
 */
void LDR_VoidInit(void) ;

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
u16 LDR_u16GetResistanceFrom8BitADC(u16 Copy_u16Adc_Res) ;

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
u16 LDR_u16GetResistanceFrom10BitADC(u16 Copy_u16Adc_Res) ;

#endif //LDR_INTERFACE_H
