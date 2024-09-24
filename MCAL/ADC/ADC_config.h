/*******************************************************************/
/***************     Author: Youssef_Farid		   *****************/
/***************     Layer: MCAL                   *****************/
/***************     ADC_config                    *****************/
/*******************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/**
 * @brief Configuration macros for ADC settings.
 *
 * These macros are used to configure the ADC settings including voltage reference,
 * resolution, conversion mode, prescaler, and trigger source.
 */

/**
 * @brief Macro for selecting the voltage reference for the ADC.
 * 
 * Options:
 *  - AREF: Use the voltage applied to the AREF pin as the reference voltage.
 *  - AVCC: Use the AVCC pin as the reference voltage (typically 5V).
 *  - INTERNAL: Use the internal 2.56V reference voltage.
 */
#define ADC_u8Voltage_Ref                     AVCC  /**< Voltage reference option */

/**
 * @brief Macro for selecting the ADC resolution.
 * 
 * Options:
 *  - _8_BIT: 8-bit resolution (the result is left-adjusted).
 *  - _10_BIT: 10-bit resolution (the result is right-adjusted).
 */
#define ADC_u8Resolution                     _8_BIT  /**< ADC resolution option */

/**
 * @brief Macro for selecting the ADC conversion mode.
 * 
 * Options:
 *  - Manual: Manual conversion mode (user initiates each conversion).
 *  - Auto_Trigger: Auto-trigger mode (conversion starts automatically based on a trigger source).
 */
#define ADC_u8Conv_Mode                      Manual  /**< ADC conversion mode option */

/**
 * @brief Macro for selecting the ADC prescaler division factor.
 * 
 * Options:
 *  - Division_by_2: ADC clock divided by 2.
 *  - Division_by_4: ADC clock divided by 4.
 *  - Division_by_8: ADC clock divided by 8.
 *  - Division_by_16: ADC clock divided by 16.
 *  - Division_by_32: ADC clock divided by 32.
 *  - Division_by_64: ADC clock divided by 64.
 *  - Division_by_128: ADC clock divided by 128.
 */
#define ADC_u8PrescalerDivisionFactor        Division_by_128  /**< Prescaler division factor option */

/**
 * @brief Macro to define the timeout period for ADC conversion in synchronous mode.
 */
#define ADC_u32TimeOut                       50000u  /**< Timeout period for ADC conversion (in clock cycles) */

#if ADC_u8Conv_Mode == Auto_Trigger

/**
 * @brief Macro for selecting the ADC trigger source when auto-trigger mode is enabled.
 * 
 * Options:
 *  - Free_Running_mode: Free running mode (continuous conversion).
 *  - Analog_Comparator: Triggered by the analog comparator.
 *  - External_Interrupt_Request_0: Triggered by external interrupt request 0.
 *  - Counter0_Compare_Match: Triggered by Timer/Counter0 compare match.
 *  - Counter0_Overflow: Triggered by Timer/Counter0 overflow.
 *  - Counter_Compare_Match B: Triggered by Timer/Counter compare match B.
 *  - Counter1_Overflow: Triggered by Timer/Counter1 overflow.
 *  - Counter1_Capture_Event: Triggered by Timer/Counter1 capture event.
 */
#define ADC_u8TriggerSource                  Free_Running_mode  /**< ADC trigger source option */


#endif

#endif
