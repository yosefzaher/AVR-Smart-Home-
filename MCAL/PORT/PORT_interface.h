/**********************************************************************
***********************************************************************			       						    	                     
**							مبرمجي	الأرياف							 **	
**						     Application.c							 **
**							    1.0.0                                **
**                           17 / 09 / 2024                          **   
***********************************************************************
***********************************************************************/

#ifndef	PORT_INTERFACE_H
#define PORT_INTERFACE_H

/**
 * @brief Initializes the direction and initial values of all I/O ports (A, B, C, and D).
 * 
 * This function configures the data direction for each pin in ports A, B, C, and D by setting 
 * the values of the DDR (Data Direction Register) for each port. It also sets the initial output values 
 * of the ports by writing to the corresponding PORT registers.
 * 
 * The direction (input/output) of each pin is set based on the predefined values `PORTA_DIR`, `PORTB_DIR`, 
 * `PORTC_DIR`, and `PORTD_DIR`, which should be defined elsewhere in the code. Similarly, the initial 
 * values for the pins are defined by `PORTA_INIT_VAL`, `PORTB_INIT_VAL`, `PORTC_INIT_VAL`, and `PORTD_INIT_VAL`.
 * 
 * @note This function must be called before using the I/O ports to ensure they are configured properly.
 */
void PORT_voidInit(void);

#endif
