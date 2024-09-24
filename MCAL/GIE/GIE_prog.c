/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_reg.h"
#include "GIE_interface.h"

/**
 * @brief Enable Global Interrupts
 * 
 * This function sets the Global Interrupt Enable bit in the SREG register, enabling global interrupts
 * for the microcontroller. It allows the processor to respond to external and internal interrupt requests.
 */
void GIE_voidEnableGlobal(void)
{
    SET_BIT(SREG, SREG_I);
}

/**
 * @brief Disable Global Interrupts
 * 
 * This function clears the Global Interrupt Enable bit in the SREG register, disabling global interrupts
 * for the microcontroller. This prevents the processor from responding to external and internal interrupt requests.
 */
void GIE_voidDisableGlobal(void)
{
    CLR_BIT(SREG, SREG_I);
}
