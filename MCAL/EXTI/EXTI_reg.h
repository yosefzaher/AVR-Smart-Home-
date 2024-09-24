/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#ifndef EXTI_REG_H
#define EXTI_REG_H

/**
 * @brief General Interrupt Control Register (GICR)
 * 
 * This register is used to enable and disable external interrupt requests (INT0, INT1, and INT2).
 * The bits within this register control the interrupt enable flags for each external interrupt.
 */
#define GICR            *((volatile u8*)0x5B)   /**< GICR address in memory */
#define GICR_INT1       7u                         /**< INT1 enable bit in GICR */
#define GICR_INT0       6u                         /**< INT0 enable bit in GICR */
#define GICR_INT2       5u                         /**< INT2 enable bit in GICR */

/**
 * @brief MCU Control Register (MCUCR)
 * 
 * This register controls the sense control for external interrupts INT0 and INT1. 
 * It allows configuration of how the external interrupts will be triggered (low level, any logical change, falling edge, or rising edge).
 */
#define MCUCR           *((volatile u8*)0x55)   /**< MCUCR address in memory */
#define MCUCR_ISC00     0u                         /**< INT0 sense control bit 0 */
#define MCUCR_ISC01     1u                         /**< INT0 sense control bit 1 */
#define MCUCR_ISC10     2u                         /**< INT1 sense control bit 0 */
#define MCUCR_ISC11     3u                         /**< INT1 sense control bit 1 */

/**
 * @brief MCU Control and Status Register (MCUCSR)
 * 
 * This register controls the sense control for external interrupt INT2. It allows configuration of how INT2 will be triggered (falling edge or rising edge).
 */
#define MCUCSR          *((volatile u8*)0x54)   /**< MCUCSR address in memory */
#define MCUCSR_ISC2     6u                         /**< INT2 sense control bit */

#endif
