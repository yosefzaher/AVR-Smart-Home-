/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#ifndef GIE_REG_H
#define GIE_REG_H

/**
 * @brief Status Register
 * 
 * This register contains the global interrupt enable bit (SREG_I). It controls the global interrupt state.
 */
#define SREG    *((volatile u8*)0x5F)  /**< Status register base address */

/**
 * @brief Interrupt Enable Bit in Status Register
 * 
 * This bit (bit 7) in the Status Register (SREG) controls the global interrupt enable functionality.
 * - 0: Global interrupts disabled
 * - 1: Global interrupts enabled
 */
#define SREG_I  7u  /**< Interrupt enable bit position in SREG */

#endif
