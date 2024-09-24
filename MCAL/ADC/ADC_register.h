/*******************************************************************/
/***************     Author: Youssef_Farid		   *****************/
/***************     Layer: MCAL                   *****************/
/***************     ADC_register                  *****************/
/*******************************************************************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

/**
 * @brief Macros for ADC Register and Bit Definitions.
 *
 * These macros provide access to various ADC-related registers and their bit fields.
 */

/**
 * @brief ADC Multiplexer Selection Register (ADMUX).
 *
 * This register configures the ADC multiplexer, reference voltage, and result alignment.
 * 
 * - ADMUX_REFS1 (Bit 7): Reference selection bit 1.
 * - ADMUX_REFS0 (Bit 6): Reference selection bit 0.
 * - ADMUX_ADLAR (Bit 5): Left adjust ADC result (for 8-bit resolution).
 * 
 * ADMUX is located at I/O address 0x27.
 */
#define ADMUX               *((volatile u8*)0x27)  /**< ADC Multiplexer Selection Register */
#define ADMUX_REFS1         7u                       /**< Reference Selection Bit 1 */
#define ADMUX_REFS0         6u                       /**< Reference Selection Bit 0 */
#define ADMUX_ADLAR         5u                       /**< Left Adjust Result */

/**
 * @brief ADC Control and Status Register A (ADCSRA).
 *
 * This register controls the ADC operation and status flags.
 * 
 * - ADCSRA_ADEN (Bit 7): ADC Enable.
 * - ADCSRA_ADSC (Bit 6): Start Conversion.
 * - ADCSRA_ADATE (Bit 5): Auto Trigger Enable.
 * - ADCSRA_ADIF (Bit 4): ADC Interrupt Flag (set when conversion is complete).
 * - ADCSRA_ADIE (Bit 3): ADC Interrupt Enable.
 * 
 * ADCSRA is located at I/O address 0x26.
 */
#define ADCSRA              *((volatile u8*)0x26)  /**< ADC Control and Status Register A */
#define ADCSRA_ADEN         7u                      /**< ADC Enable */
#define ADCSRA_ADSC         6u                      /**< Start Conversion */
#define ADCSRA_ADATE        5u                      /**< Auto Trigger Enable */
#define ADCSRA_ADIF         4u                      /**< ADC Interrupt Flag */
#define ADCSRA_ADIE         3u                      /**< ADC Interrupt Enable */

/**
 * @brief Special Function I/O Register (SFIOR).
 *
 * This register is used for special functions and configuration.
 * 
 * SFIOR is located at I/O address 0x50.
 */
#define SFIOR               *((volatile u8*)0x50)  /**< Special Function I/O Register */

/**
 * @brief ADC Data High Register (ADCH).
 *
 * This register holds the high byte of the ADC conversion result in 10-bit mode.
 * 
 * ADCH is located at I/O address 0x25.
 */
#define ADCH                *((volatile u8*)0x25)  /**< ADC Data High Register */

/**
 * @brief ADC Data Low Register (ADCL).
 *
 * This register holds the low byte of the ADC conversion result in 10-bit mode.
 * 
 * ADCL is located at I/O address 0x24.
 */
#define ADCL                *((volatile u8*)0x24)  /**< ADC Data Low Register */

/**
 * @brief ADC Data Register (ADC).
 *
 * This register provides the complete 10-bit ADC conversion result. It is read as a 16-bit value where ADCL contains the lower byte and ADCH contains the higher byte.
 * 
 * ADC is located at I/O address 0x24. It is accessed as a 16-bit value.
 */
#define ADC                 *((volatile uint16*)0x24)  /**< ADC Data Register (10-bit Resolution) */


#endif
