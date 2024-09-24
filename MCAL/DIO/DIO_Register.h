/***************************************************************/
/***************     Author: Zeinab EL_tantawy       ***********/
/***************     Layer: MCAL                     ***********/
/***************     DIO_Register                    ***********/
/***************************************************************/


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/**
 * @brief Memory-mapped input register for Port A.
 * 
 * This macro provides direct access to the PINA register, which is used to read the input 
 * values of Port A's pins. Each bit corresponds to the state of one of the port's pins (high or low).
 */
#define PINA    *((volatile u8*)0X39)

/**
 * @brief Memory-mapped input register for Port B.
 * 
 * This macro provides direct access to the PINB register, which is used to read the input 
 * values of Port B's pins. Each bit corresponds to the state of one of the port's pins (high or low).
 */
#define PINB    *((volatile u8*)0X36)

/**
 * @brief Memory-mapped input register for Port C.
 * 
 * This macro provides direct access to the PINC register, which is used to read the input 
 * values of Port C's pins. Each bit corresponds to the state of one of the port's pins (high or low).
 */
#define PINC    *((volatile u8*)0X33)

/**
 * @brief Memory-mapped input register for Port D.
 * 
 * This macro provides direct access to the PIND register, which is used to read the input 
 * values of Port D's pins. Each bit corresponds to the state of one of the port's pins (high or low).
 */
#define PIND    *((volatile u8*)0X30)

/**
 * @brief Memory-mapped output register for Port A.
 * 
 * This macro provides direct access to the PORTA register, which is used to write output values 
 * to the pins of Port A. Setting a bit to 1 drives the corresponding pin high, while setting it to 0 drives it low.
 */
#define PORTA   *((volatile u8*)0X3B)

/**
 * @brief Memory-mapped output register for Port B.
 * 
 * This macro provides direct access to the PORTB register, which is used to write output values 
 * to the pins of Port B. Setting a bit to 1 drives the corresponding pin high, while setting it to 0 drives it low.
 */
#define PORTB   *((volatile u8*)0X38)

/**
 * @brief Memory-mapped output register for Port C.
 * 
 * This macro provides direct access to the PORTC register, which is used to write output values 
 * to the pins of Port C. Setting a bit to 1 drives the corresponding pin high, while setting it to 0 drives it low.
 */
#define PORTC   *((volatile u8*)0X35)

/**
 * @brief Memory-mapped output register for Port D.
 * 
 * This macro provides direct access to the PORTD register, which is used to write output values 
 * to the pins of Port D. Setting a bit to 1 drives the corresponding pin high, while setting it to 0 drives it low.
 */
#define PORTD   *((volatile u8*)0X32)

/**
 * @brief Memory-mapped data direction register for Port A.
 * 
 * This macro provides direct access to the DDRA register, which is used to configure the 
 * direction of Port A's pins. Setting a bit to 1 configures the corresponding pin as an output, 
 * while setting it to 0 configures it as an input.
 */
#define DDRA	*((volatile u8*)0X3A)

/**
 * @brief Memory-mapped data direction register for Port B.
 * 
 * This macro provides direct access to the DDRB register, which is used to configure the 
 * direction of Port B's pins. Setting a bit to 1 configures the corresponding pin as an output, 
 * while setting it to 0 configures it as an input.
 */
#define DDRB	*((volatile u8*)0X37)

/**
 * @brief Memory-mapped data direction register for Port C.
 * 
 * This macro provides direct access to the DDRC register, which is used to configure the 
 * direction of Port C's pins. Setting a bit to 1 configures the corresponding pin as an output, 
 * while setting it to 0 configures it as an input.
 */
#define DDRC	*((volatile u8*)0X34)

/**
 * @brief Memory-mapped data direction register for Port D.
 * 
 * This macro provides direct access to the DDRD register, which is used to configure the 
 * direction of Port D's pins. Setting a bit to 1 configures the corresponding pin as an output, 
 * while setting it to 0 configures it as an input.
 */
#define DDRD	*((volatile u8*)0X31)

#endif /* DIO_REGISTER_H_ */