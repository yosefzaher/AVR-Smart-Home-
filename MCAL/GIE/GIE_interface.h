/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

/**
 * @brief Enable Global Interrupts
 * 
 * This function enables global interrupts by setting the Global Interrupt Enable bit in the SREG register.
 * It allows the microcontroller to respond to external and internal interrupt requests.
 */
void GIE_voidEnableGlobal(void);

/**
 * @brief Disable Global Interrupts
 * 
 * This function disables global interrupts by clearing the Global Interrupt Enable bit in the SREG register.
 * This prevents the microcontroller from responding to external and internal interrupt requests.
 */
void GIE_voidDisableGlobal(void);

#endif
