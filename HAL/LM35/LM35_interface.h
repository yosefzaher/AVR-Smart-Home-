/*********************************************
 *                                           *
 *  Author : ENG.Ahmed Shaboury              *
 *  Layer  : HAL                             *
 *  SWC    : LM35 Temp Sensor                *
 *  Version : 1.2.2                          *
 *                                           *
 *********************************************/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

/**
 * @file ADC_config.h
 * @brief Definitions and structures for ADC configuration.
 */

/**
 * @brief Structure for ADC configuration.
 * 
 * This structure holds the configuration details for the ADC (Analog-to-Digital Converter).
 */
typedef struct
{
    u8 Vref;         /**< Reference voltage for the ADC. */
    u8 resolution;   /**< Resolution of the ADC in bits (e.g., 8-bit, 10-bit). */
} ADC_info;

/**
 * @brief ADC Resolution Options
 * 
 * The following defines represent the possible resolutions for the ADC.
 */
#define RES_EIGHT_BITS              8   /**< 8-bit ADC resolution. */
#define RES_TEN_BITS                10  /**< 10-bit ADC resolution. */

/**
 * @brief ADC Reference Voltage Options
 * 
 * The following defines represent the possible reference voltages for the ADC.
 */
#define Vref_AVCC                   5   /**< Reference voltage of 5V (AVCC). */
#define Vref_INTERNAL               2.56/**< Internal reference voltage of 2.56V. */

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
u8 LM35_getTemperature(ADC_info* Copy_component , u16 Dig_Temp , u16* Result);


#endif
