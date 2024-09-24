/**********************************************************************
***********************************************************************			       						    	                     
**							مبرمجي	الأرياف							 **	
**						     Application.c							 **
**							    1.0.0                                **
**                           17 / 09 / 2024                          **   
***********************************************************************
***********************************************************************/

#ifndef	PORT_CONFIG_H
#define PORT_CONFIG_H

/**
 * @file port_config.h
 * @brief Pin direction and initial value configuration for MCU ports (PORTA, PORTB, PORTC, and PORTD).
 *
 * This file provides macros for configuring the direction and initial state of each pin 
 * in the microcontroller's I/O ports (PORTA, PORTB, PORTC, PORTD). The direction 
 * can be set as `INPUT` or `OUTPUT`, and the initial state depends on whether the pin 
 * is configured as an input (FLOATING or PULLED_UP) or an output (LOW or HIGH).
 */

/**
 * @brief Direction configuration for PORTA pins.
 * 
 * Options:
 * - INPUT: Configure the pin as an input.
 * - OUTPUT: Configure the pin as an output.
 */
#define PORTA_PIN0_DIR    OUTPUT  /**< Pin A0 direction: OUTPUT */
#define PORTA_PIN1_DIR    OUTPUT  /**< Pin A1 direction: OUTPUT */
#define PORTA_PIN2_DIR    INPUT   /**< Pin A2 direction: INPUT */
#define PORTA_PIN3_DIR    INPUT   /**< Pin A3 direction: INPUT */
#define PORTA_PIN4_DIR    INPUT   /**< Pin A4 direction: INPUT */
#define PORTA_PIN5_DIR    INPUT   /**< Pin A5 direction: INPUT */
#define PORTA_PIN6_DIR    INPUT   /**< Pin A6 direction: INPUT */
#define PORTA_PIN7_DIR    OUTPUT  /**< Pin A7 direction: OUTPUT */

/**
 * @brief Direction configuration for PORTB pins.
 */
#define PORTB_PIN0_DIR    OUTPUT  /**< Pin B0 direction: OUTPUT */
#define PORTB_PIN1_DIR    OUTPUT  /**< Pin B1 direction: OUTPUT */
#define PORTB_PIN2_DIR    INPUT   /**< Pin B2 direction: INPUT */
#define PORTB_PIN3_DIR    OUTPUT  /**< Pin B3 direction: OUTPUT */
#define PORTB_PIN4_DIR    OUTPUT  /**< Pin B4 direction: OUTPUT */
#define PORTB_PIN5_DIR    OUTPUT  /**< Pin B5 direction: OUTPUT */
#define PORTB_PIN6_DIR    OUTPUT  /**< Pin B6 direction: OUTPUT */
#define PORTB_PIN7_DIR    OUTPUT  /**< Pin B7 direction: OUTPUT */

/**
 * @brief Direction configuration for PORTC pins.
 */
#define PORTC_PIN0_DIR    OUTPUT  /**< Pin C0 direction: OUTPUT */
#define PORTC_PIN1_DIR    OUTPUT  /**< Pin C1 direction: OUTPUT */
#define PORTC_PIN2_DIR    OUTPUT  /**< Pin C2 direction: OUTPUT */
#define PORTC_PIN3_DIR    OUTPUT  /**< Pin C3 direction: OUTPUT */
#define PORTC_PIN4_DIR    OUTPUT  /**< Pin C4 direction: OUTPUT */
#define PORTC_PIN5_DIR    OUTPUT  /**< Pin C5 direction: OUTPUT */
#define PORTC_PIN6_DIR    OUTPUT  /**< Pin C6 direction: OUTPUT */
#define PORTC_PIN7_DIR    INPUT   /**< Pin C7 direction: INPUT */

/**
 * @brief Direction configuration for PORTD pins.
 */
#define PORTD_PIN0_DIR    OUTPUT  /**< Pin D0 direction: OUTPUT */
#define PORTD_PIN1_DIR    OUTPUT  /**< Pin D1 direction: OUTPUT */
#define PORTD_PIN2_DIR    OUTPUT  /**< Pin D2 direction: OUTPUT */
#define PORTD_PIN3_DIR    OUTPUT  /**< Pin D3 direction: OUTPUT */
#define PORTD_PIN4_DIR    OUTPUT  /**< Pin D4 direction: OUTPUT */
#define PORTD_PIN5_DIR    OUTPUT  /**< Pin D5 direction: OUTPUT */
#define PORTD_PIN6_DIR    OUTPUT  /**< Pin D6 direction: OUTPUT */
#define PORTD_PIN7_DIR    OUTPUT  /**< Pin D7 direction: OUTPUT */

/**
 * @brief Initial value configuration for PORTA pins.
 * 
 * - For input pins: Options are FLOATING (no pull-up resistor) or PULLED_UP (pull-up resistor enabled).
 * - For output pins: Options are LOW (0V) or HIGH (VCC).
 */
#define PORTA_PIN0_INIT_VAL    HIGH       /**< Initial value for Pin A0: HIGH */
#define PORTA_PIN1_INIT_VAL    HIGH       /**< Initial value for Pin A1: HIGH */
#define PORTA_PIN2_INIT_VAL    PULLED_UP  /**< Initial value for Pin A2: PULLED_UP */
#define PORTA_PIN3_INIT_VAL    PULLED_UP  /**< Initial value for Pin A3: PULLED_UP */
#define PORTA_PIN4_INIT_VAL    FLOATING   /**< Initial value for Pin A4: FLOATING */
#define PORTA_PIN5_INIT_VAL    FLOATING   /**< Initial value for Pin A5: FLOATING */
#define PORTA_PIN6_INIT_VAL    FLOATING   /**< Initial value for Pin A6: FLOATING */
#define PORTA_PIN7_INIT_VAL    FLOATING   /**< Initial value for Pin A7: FLOATING */

/**
 * @brief Initial value configuration for PORTB pins.
 */
#define PORTB_PIN0_INIT_VAL    FLOATING  /**< Initial value for Pin B0: FLOATING */
#define PORTB_PIN1_INIT_VAL    FLOATING  /**< Initial value for Pin B1: FLOATING */
#define PORTB_PIN2_INIT_VAL    FLOATING  /**< Initial value for Pin B2: FLOATING */
#define PORTB_PIN3_INIT_VAL    FLOATING  /**< Initial value for Pin B3: FLOATING */
#define PORTB_PIN4_INIT_VAL    FLOATING  /**< Initial value for Pin B4: FLOATING */
#define PORTB_PIN5_INIT_VAL    FLOATING  /**< Initial value for Pin B5: FLOATING */
#define PORTB_PIN6_INIT_VAL    FLOATING  /**< Initial value for Pin B6: FLOATING */
#define PORTB_PIN7_INIT_VAL    FLOATING  /**< Initial value for Pin B7: FLOATING */

/**
 * @brief Initial value configuration for PORTC pins.
 */
#define PORTC_PIN0_INIT_VAL    FLOATING  /**< Initial value for Pin C0: FLOATING */
#define PORTC_PIN1_INIT_VAL    FLOATING  /**< Initial value for Pin C1: FLOATING */
#define PORTC_PIN2_INIT_VAL    FLOATING  /**< Initial value for Pin C2: FLOATING */
#define PORTC_PIN3_INIT_VAL    FLOATING  /**< Initial value for Pin C3: FLOATING */
#define PORTC_PIN4_INIT_VAL    FLOATING  /**< Initial value for Pin C4: FLOATING */
#define PORTC_PIN5_INIT_VAL    FLOATING  /**< Initial value for Pin C5: FLOATING */
#define PORTC_PIN6_INIT_VAL    FLOATING  /**< Initial value for Pin C6: FLOATING */
#define PORTC_PIN7_INIT_VAL    FLOATING  /**< Initial value for Pin C7: FLOATING */

/**
 * @brief Initial value configuration for PORTD pins.
 */
#define PORTD_PIN0_INIT_VAL    FLOATING  /**< Initial value for Pin D0: FLOATING */
#define PORTD_PIN1_INIT_VAL    FLOATING  /**< Initial value for Pin D1: FLOATING */
#define PORTD_PIN2_INIT_VAL    FLOATING  /**< Initial value for Pin D2: FLOATING */
#define PORTD_PIN3_INIT_VAL    FLOATING  /**< Initial value for Pin D3: FLOATING */
#define PORTD_PIN4_INIT_VAL    FLOATING  /**< Initial value for Pin D4: FLOATING */
#define PORTD_PIN5_INIT_VAL    FLOATING  /**< Initial value for Pin D5: FLOATING */
#define PORTD_PIN6_INIT_VAL    FLOATING  /**< Initial value for Pin D6: FLOATING */
#define PORTD_PIN7_INIT_VAL    FLOATING  /**< Initial value for Pin D7: FLOATING */

#endif
