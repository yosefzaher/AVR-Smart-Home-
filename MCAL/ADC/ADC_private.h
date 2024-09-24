/*******************************************************************/
/***************     Author: Youssef_Farid		   *****************/
/***************     Layer: MCAL                   *****************/
/***************     ADC_private                   *****************/
/*******************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/**
 * @brief Macros for Voltage Reference options.
 *
 * These macros define the different reference voltage options that can be used for ADC conversion:
 * - AREF: External voltage reference at the AREF pin.
 * - AVCC: AVCC with external capacitor at AREF pin (commonly used for 5V or 3.3V systems).
 * - INTERNAL: Internal 2.56V reference voltage with external capacitor at AREF pin.
 *
 * Usage: Select one of these macros to set the voltage reference in the ADC configuration.
 */
#define AREF        1u
#define AVCC        2u
#define INTERNAL    3u

/**
 * @brief Macros for ADC Resolution options.
 *
 * These macros define the resolution of the ADC conversion:
 * - _8_BIT: 8-bit resolution (left-adjusted result in ADCH register).
 * - _10_BIT: 10-bit resolution (right-adjusted result in ADC register).
 *
 * Usage: Choose the desired resolution in the ADC configuration.
 */
#define _8_BIT      1u
#define _10_BIT     2u

/**
 * @brief Macros for Conversion Mode options.
 *
 * These macros define the conversion mode of the ADC:
 * - Manual: Conversion is triggered manually.
 * - Auto_Trigger: Conversion is automatically triggered by an event.
 *
 * Usage: Select the appropriate conversion mode based on your application needs.
 */
#define Manual        1u
#define Auto_Trigger  2u

/**
 * @brief Macros for ADC Prescaler Division Factor options and bit positions.
 *
 * These macros define the available division factors for the ADC clock prescaler, which scales down the system clock to
 * a suitable frequency for the ADC (typically 50kHz - 200kHz):
 * - Division_by_2: ADC clock = system clock / 2.
 * - Division_by_4: ADC clock = system clock / 4.
 * - Division_by_8: ADC clock = system clock / 8.
 * - Division_by_16: ADC clock = system clock / 16.
 * - Division_by_32: ADC clock = system clock / 32.
 * - Division_by_64: ADC clock = system clock / 64.
 * - Division_by_128: ADC clock = system clock / 128.
 *
 * Prescaler_Bit_Mask is used to clear the prescaler bits in ADCSRA register, and Prescaler_Bit_Pos defines the bit
 * position for setting the prescaler value.
 *
 * Usage: Choose one of these division factors based on your clock frequency and desired ADC clock.
 */
#define Division_by_2    1u
#define Division_by_4    2u
#define Division_by_8    3u
#define Division_by_16   4u
#define Division_by_32   5u
#define Division_by_64   6u
#define Division_by_128  7u

#define Prescaler_Bit_Mask  0b11111000
#define Prescaler_Bit_Pos   0u

/**
 * @brief Macros for Trigger Source options in Auto Trigger mode.
 *
 * These macros define the available trigger sources when the ADC is in Auto Trigger mode:
 * - Free_Running_mode: Continuous conversion.
 * - Analog_Comparator: Conversion is triggered by the analog comparator output.
 * - External_Interrupt_Request_0: Conversion is triggered by external interrupt request 0.
 * - Counter0_Compare_Match: Conversion is triggered by Timer/Counter0 Compare Match.
 * - Counter0_Overflow: Conversion is triggered by Timer/Counter0 Overflow.
 * - Counter_Compare_Match_B: Conversion is triggered by Timer/Counter Compare Match B.
 * - Counter1_Overflow: Conversion is triggered by Timer/Counter1 Overflow.
 * - Counter1_Capture_Event: Conversion is triggered by Timer/Counter1 Capture Event.
 *
 * Trigger_Source_Bit_Mask is used to clear the trigger source bits in SFIOR register, and Trigger_Source_Bit_Pos
 * defines the bit position for setting the trigger source.
 *
 * Usage: Choose the appropriate trigger source when Auto Trigger mode is enabled.
 */
#if ADC_u8Conv_Mode == Auto_Trigger
#define Free_Running_mode               0u
#define Analog_Comparator               1u
#define External_Interrupt_Request_0    2u
#define Counter0_Compare_Match          3u
#define Counter0_Overflow               4u
#define Counter_Compare_Match_B         5u
#define Counter1_Overflow               6u
#define Counter1_Capture_Event          7u

#define Trigger_Source_Bit_Mask         0b00011111
#define Trigger_Source_Bit_Pos          5u
#endif

/**
 * @brief Macro to clear the channel bits in the ADMUX register.
 *
 * This macro defines a bit mask that clears the channel selection bits in the ADMUX register.
 * The ADC channel selection is stored in the least significant 3 bits of ADMUX.
 *
 * Usage: Use this mask to clear the existing channel selection before setting a new channel.
 */
#define Channel_Bit_Mask  0b11100000

/**
 * @brief Macros to define ADC busy and idle states.
 *
 * These macros define the states of the ADC:
 * - IDLE: ADC is not busy and ready for a new conversion.
 * - BUSY: ADC is currently performing a conversion.
 *
 * Usage: Use these macros to track the status of the ADC to avoid initiating a new conversion while another is in progress.
 */
#define IDLE  0u
#define BUSY  1u

#endif
