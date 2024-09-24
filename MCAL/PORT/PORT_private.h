/**********************************************************************
***********************************************************************			       						    	                     
**							مبرمجي	الأرياف							 **	
**						     Application.c							 **
**							    1.0.0                                **
**                           17 / 09 / 2024                          **   
***********************************************************************
***********************************************************************/

#ifndef	PORT_PRIVATE_H
#define PORT_PRIVATE_H

/**
 * @file port_macros.h
 * @brief Configuration macros for defining pin directions, initial values, and port manipulation.
 *
 * These macros define how the pins of various ports (PORTA, PORTB, PORTC, PORTD) should be configured,
 * whether as input or output, floating or pulled-up, and their initial values (HIGH or LOW). The macros 
 * make use of concatenation to combine individual pin configurations into a single 8-bit binary value for each port.
 */

/* Pin direction configuration */
#define INPUT       0   /**< Define pin as input */
#define OUTPUT      1   /**< Define pin as output */

/* Pin state configuration */
#define FLOATING    0   /**< Define input pin as floating */
#define PULLED_UP   1   /**< Define input pin with internal pull-up resistor enabled */

/* Pin output values */
#define LOW         0   /**< Set output pin to low (0V) */
#define HIGH        1   /**< Set output pin to high (VCC) */

/**
 * @brief Macro to concatenate 8 individual bits into a single byte.
 * 
 * @param b7 Most significant bit.
 * @param b6 Bit 6.
 * @param b5 Bit 5.
 * @param b4 Bit 4.
 * @param b3 Bit 3.
 * @param b2 Bit 2.
 * @param b1 Bit 1.
 * @param b0 Least significant bit.
 * @return 8-bit binary number formed by concatenating the bits.
 */
#define CONC(b7, b6, b5, b4, b3, b2, b1, b0)              CONC_HELPER(b7, b6, b5, b4, b3, b2, b1, b0)

/**
 * @brief Helper macro to form the 8-bit binary number using the `0b` prefix.
 * 
 * @param b7 Most significant bit.
 * @param b6 Bit 6.
 * @param b5 Bit 5.
 * @param b4 Bit 4.
 * @param b3 Bit 3.
 * @param b2 Bit 2.
 * @param b1 Bit 1.
 * @param b0 Least significant bit.
 * @return 8-bit binary number prefixed with `0b`.
 */
#define CONC_HELPER(b7, b6, b5, b4, b3, b2, b1, b0)       0b##b7##b6##b5##b4##b3##b2##b1##b0

/**
 * @brief Macros to define the direction of each pin in the respective ports.
 * 
 * Each `PORTX_DIR` macro concatenates the direction settings (input/output) of all 8 pins in the port.
 */
#define PORTA_DIR   CONC(PORTA_PIN7_DIR, PORTA_PIN6_DIR, PORTA_PIN5_DIR, PORTA_PIN4_DIR, PORTA_PIN3_DIR, PORTA_PIN2_DIR, PORTA_PIN1_DIR, PORTA_PIN0_DIR)
#define PORTB_DIR   CONC(PORTB_PIN7_DIR, PORTB_PIN6_DIR, PORTB_PIN5_DIR, PORTB_PIN4_DIR, PORTB_PIN3_DIR, PORTB_PIN2_DIR, PORTB_PIN1_DIR, PORTB_PIN0_DIR)
#define PORTC_DIR   CONC(PORTC_PIN7_DIR, PORTC_PIN6_DIR, PORTC_PIN5_DIR, PORTC_PIN4_DIR, PORTC_PIN3_DIR, PORTC_PIN2_DIR, PORTC_PIN1_DIR, PORTC_PIN0_DIR)
#define PORTD_DIR   CONC(PORTD_PIN7_DIR, PORTD_PIN6_DIR, PORTD_PIN5_DIR, PORTD_PIN4_DIR, PORTD_PIN3_DIR, PORTD_PIN2_DIR, PORTD_PIN1_DIR, PORTD_PIN0_DIR)

/**
 * @brief Macros to define the initial value of each pin in the respective ports.
 * 
 * Each `PORTX_INIT_VAL` macro concatenates the initial value (HIGH/LOW) of all 8 pins in the port.
 */
#define PORTA_INIT_VAL   CONC(PORTA_PIN7_INIT_VAL, PORTA_PIN6_INIT_VAL, PORTA_PIN5_INIT_VAL, PORTA_PIN4_INIT_VAL, PORTA_PIN3_INIT_VAL, PORTA_PIN2_INIT_VAL, PORTA_PIN1_INIT_VAL, PORTA_PIN0_INIT_VAL)
#define PORTB_INIT_VAL   CONC(PORTB_PIN7_INIT_VAL, PORTB_PIN6_INIT_VAL, PORTB_PIN5_INIT_VAL, PORTB_PIN4_INIT_VAL, PORTB_PIN3_INIT_VAL, PORTB_PIN2_INIT_VAL, PORTB_PIN1_INIT_VAL, PORTB_PIN0_INIT_VAL)
#define PORTC_INIT_VAL   CONC(PORTC_PIN7_INIT_VAL, PORTC_PIN6_INIT_VAL, PORTC_PIN5_INIT_VAL, PORTC_PIN4_INIT_VAL, PORTC_PIN3_INIT_VAL, PORTC_PIN2_INIT_VAL, PORTC_PIN1_INIT_VAL, PORTC_PIN0_INIT_VAL)
#define PORTD_INIT_VAL   CONC(PORTD_PIN7_INIT_VAL, PORTD_PIN6_INIT_VAL, PORTD_PIN5_INIT_VAL, PORTD_PIN4_INIT_VAL, PORTD_PIN3_INIT_VAL, PORTD_PIN2_INIT_VAL, PORTD_PIN1_INIT_VAL, PORTD_PIN0_INIT_VAL)

#endif
