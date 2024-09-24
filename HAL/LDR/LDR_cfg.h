/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#ifndef LDR_CFG_H
#define LDR_CFG_H

/**
 * @brief Known resistor value used in the voltage divider calculation.
 *
 * This is the fixed resistor value (in ohms) used alongside the LDR
 * to create a voltage divider circuit. It is a known constant
 * used in resistance calculations.
 */
#define R_FIXED   330    // Known resistor value in ohms

/**
 * @brief ADC reference voltage.
 *
 * This is the reference voltage used by the ADC (Analog-to-Digital Converter)
 * for converting the analog voltage to a digital value. It is assumed
 * to be 5.0 volts in this configuration.
 */
#define VREF 5.0    // ADC reference voltage

#endif //LDR_CFG_H
