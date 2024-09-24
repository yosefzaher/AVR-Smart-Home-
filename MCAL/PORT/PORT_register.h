/**********************************************************************
***********************************************************************			       						    	                     
**							مبرمجي	الأرياف							 **	
**						     Application.c							 **
**							    1.0.0                                **
**                           17 / 09 / 2024                          **   
***********************************************************************
***********************************************************************/


#ifndef	PORT_REGISTER_H
#define PORT_REGISTER_H

/**
 * @brief Memory-mapped addresses for I/O ports and data direction registers.
 * 
 * These macros define the memory addresses for the I/O ports (PORTA, PORTB, PORTC, and PORTD) 
 * and their corresponding data direction registers (DDRA, DDRB, DDRC, and DDRD). 
 * Each macro is cast to a volatile pointer to an 8-bit unsigned integer (`u8`), which allows direct 
 * manipulation of the hardware registers for setting pin directions and controlling the output state 
 * of the ports.
 * 
 * The volatile keyword is used to ensure that the compiler does not optimize accesses to these 
 * memory-mapped registers, as their values can change asynchronously due to hardware events.
 */

/* PORTA: Data Register for Port A */
#define PORTA    *((volatile u8*)0x3B)

/* DDRA: Data Direction Register for Port A */
#define DDRA     *((volatile u8*)0x3A)

/* PORTB: Data Register for Port B */
#define PORTB    *((volatile u8*)0x38)

/* DDRB: Data Direction Register for Port B */
#define DDRB     *((volatile u8*)0x37)

/* PORTC: Data Register for Port C */
#define PORTC    *((volatile u8*)0x35)

/* DDRC: Data Direction Register for Port C */
#define DDRC     *((volatile u8*)0x34)

/* PORTD: Data Register for Port D */
#define PORTD    *((volatile u8*)0x32)

/* DDRD: Data Direction Register for Port D */
#define DDRD     *((volatile u8*)0x31)
#endif
