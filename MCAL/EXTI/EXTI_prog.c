/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_reg.h"              
#include "EXTI_interface.h"        
#include "EXTI_prv.h"              
#include "EXTI_cfg.h"              

// Define an array of pointers to functions (callbacks) for EXTI interrupts (INT0, INT1, INT2), initialized to NULL
static void(*EXTI_pvCallBack[3])(void) = {NULL};  

/**
 * @brief  Initializes the EXTI (External Interrupt) module based on configuration settings.
 * @param  None
 * @return None
 */
void EXTI_voidInit(void)
{
    // Configuration for INT0 (External Interrupt 0)
    #if INT0_SENSE_CTRL == EXTI_LOW_LEVEL
        CLR_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);
    #elif INT0_SENSE_CTRL == EXTI_ON_CHANGE
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);
    #elif INT0_SENSE_CTRL == EXTI_FALLING_EDGE
        CLR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
    #elif INT0_SENSE_CTRL == EXTI_RISING_EDGE
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
    #else
        #error Wrong INT0_SENSE_CTRL configuration option
    #endif

    // Configuration for INT1 (External Interrupt 1)
    #if INT1_SENSE_CTRL == EXTI_LOW_LEVEL
        CLR_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);
    #elif INT1_SENSE_CTRL == EXTI_ON_CHANGE
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);
    #elif INT1_SENSE_CTRL == EXTI_FALLING_EDGE
        CLR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
    #elif INT1_SENSE_CTRL == EXTI_RISING_EDGE
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
    #else
        #error Wrong INT1_SENSE_CTRL configuration option
    #endif

    // Configuration for INT2 (External Interrupt 2)
    #if INT2_SENSE_CTRL == EXTI_FALLING_EDGE
        CLR_BIT(MCUCSR, MCUCSR_ISC2);
    #elif INT2_SENSE_CTRL == EXTI_RISING_EDGE
        SET_BIT(MCUCSR, MCUCSR_ISC2);
    #else
        #error Wrong INT2_SENSE_CTRL configuration option
    #endif

    // Enable or disable INT0 based on initial state configuration
    #if INT0_INIT_STATE == DISABLED
        CLR_BIT(GICR, GICR_INT0);
    #elif INT0_INIT_STATE == ENABLED
        SET_BIT(GICR, GICR_INT0);
    #else
        #error Wrong INT0_INIT_STATE configuration option
    #endif

    // Enable or disable INT1 based on initial state configuration
    #if INT1_INIT_STATE == DISABLED
        CLR_BIT(GICR, GICR_INT1);
    #elif INT1_INIT_STATE == ENABLED
        SET_BIT(GICR, GICR_INT1);
    #else
        #error Wrong INT1_INIT_STATE configuration option
    #endif

    // Enable or disable INT2 based on initial state configuration
    #if INT2_INIT_STATE == DISABLED
        CLR_BIT(GICR, GICR_INT2);
    #elif INT2_INIT_STATE == ENABLED
        SET_BIT(GICR, GICR_INT2);
    #else
        #error Wrong INT2_INIT_STATE configuration option
    #endif
}

/**
 * @brief  Sets the sense control (edge detection) for a specific interrupt channel.
 * @param  Copy_IntCh: The interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_SenseCtrl: The sense control mode (LOW_LEVEL, ON_CHANGE, FALLING_EDGE, RISING_EDGE).
 * @return Error status (NO_ERROR if successful, ERROR if an invalid configuration is passed).
 */
u8 EXTI_u8SetSenseCtrl(IntChannel_t Copy_IntCh, SenseCtrl_t Copy_SenseCtrl )
{
    u8 Local_u8ErrorState = NO_ERROR;

    // Set sense control for INT0
    if(Copy_IntCh == INT0)
    {
        switch (Copy_SenseCtrl)
        {
            case LOW_LEVEL:
                CLR_BIT(MCUCR, MCUCR_ISC00);
                CLR_BIT(MCUCR, MCUCR_ISC01);
                break;
            case ON_CHANGE:
                SET_BIT(MCUCR, MCUCR_ISC00);
                CLR_BIT(MCUCR, MCUCR_ISC01);
                break;
            case FALLING_EDGE:
                CLR_BIT(MCUCR, MCUCR_ISC00);
                SET_BIT(MCUCR, MCUCR_ISC01);
                break;
            case RISING_EDGE:
                SET_BIT(MCUCR, MCUCR_ISC00);
                SET_BIT(MCUCR, MCUCR_ISC01);
                break;
            default:
                Local_u8ErrorState = ERROR;
                break;
        }
    }
    // Set sense control for INT1
    else if(Copy_IntCh == INT1)
    {
        switch (Copy_SenseCtrl)
        {
            case LOW_LEVEL:
                CLR_BIT(MCUCR, MCUCR_ISC10);
                CLR_BIT(MCUCR, MCUCR_ISC11);
                break;
            case ON_CHANGE:
                SET_BIT(MCUCR, MCUCR_ISC10);
                CLR_BIT(MCUCR, MCUCR_ISC11);
                break;
            case FALLING_EDGE:
                CLR_BIT(MCUCR, MCUCR_ISC10);
                SET_BIT(MCUCR, MCUCR_ISC11);
                break;
            case RISING_EDGE:
                SET_BIT(MCUCR, MCUCR_ISC10);
                SET_BIT(MCUCR, MCUCR_ISC11);
                break;
            default:
                Local_u8ErrorState = ERROR;
                break;
        }
    }
    // Set sense control for INT2
    else if(Copy_IntCh == INT2)
    {
        switch (Copy_SenseCtrl)
        {
            case FALLING_EDGE:
                CLR_BIT(MCUCSR, MCUCSR_ISC2);
                break;
            case RISING_EDGE:
                SET_BIT(MCUCSR, MCUCSR_ISC2);
                break;
            default:
                Local_u8ErrorState = ERROR;
                break;
        }
    }
    else
    {
        Local_u8ErrorState = ERROR;
    }

    return Local_u8ErrorState;
}

/**
 * @brief  Enables a specific interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_IntCh: The interrupt channel to enable.
 * @return Error status (NO_ERROR if successful, ERROR if an invalid channel is passed).
 */
u8 EXTI_u8EnableIntChannel(IntChannel_t Copy_IntCh)
{
    u8 Local_u8ErrorState = NO_ERROR;

    switch(Copy_IntCh)
    {
        case INT0:
            SET_BIT(GICR, GICR_INT0);
            break;
        case INT1:
            SET_BIT(GICR, GICR_INT1);
            break;
        case INT2:
            SET_BIT(GICR, GICR_INT2);
            break;
        default:
            Local_u8ErrorState = ERROR;
            break;
    }

    return Local_u8ErrorState;
}

/**
 * @brief  Disables a specific interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_IntCh: The interrupt channel to disable.
 * @return Error status (NO_ERROR if successful, ERROR if an invalid channel is passed).
 */
u8 EXTI_u8DisableIntChannel(IntChannel_t Copy_IntCh)
{
    u8 Local_u8ErrorState = NO_ERROR;

    switch(Copy_IntCh)
    {
        case INT0:
            CLR_BIT(GICR, GICR_INT0);
            break;
        case INT1:
            CLR_BIT(GICR, GICR_INT1);
            break;
        case INT2:
            CLR_BIT(GICR, GICR_INT2);
            break;
        default:
            Local_u8ErrorState = ERROR;
            break;
    }

    return Local_u8ErrorState;
}

/**
 * @brief  Sets a callback function for a specific interrupt channel.
 * @param  Copy_IntCh: The interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_pvCallBackFunc: Pointer to the callback function.
 * @return Error status (NO_ERROR if successful, NULL_PTR_ERR if the callback is NULL).
 */
u8 EXTI_u8SetCallBack(IntChannel_t Copy_IntCh, void(*Copy_pvCallBackFunc)(void))
{
    u8 Local_u8ErrorStatus = NO_ERROR;

    if(Copy_pvCallBackFunc != NULL)
    {
        EXTI_pvCallBack[Copy_IntCh] = Copy_pvCallBackFunc;
    }
    else
    {
        Local_u8ErrorStatus = NULL_PTR_ERR;
    }

    return Local_u8ErrorStatus;
}

/**
 * @brief  ISR (Interrupt Service Routine) for INT0.
 * @param  None
 * @return None
 */
__attribute__((signal)) void __vector_1 (void);
void __vector_1 (void)
{
    if(EXTI_pvCallBack[INT0] != NULL)
    {
        EXTI_pvCallBack[INT0]();
    }
}

/**
 * @brief  ISR (Interrupt Service Routine) for INT1.
 * @param  None
 * @return None
 */
__attribute__((signal)) void __vector_2 (void);
void __vector_2 (void)
{
    if(EXTI_pvCallBack[INT1] != NULL)
    {
        EXTI_pvCallBack[INT1]();
    }
}

/**
 * @brief  ISR (Interrupt Service Routine) for INT2.
 * @param  None
 * @return None
 */
__attribute__((signal)) void __vector_3 (void);
void __vector_3 (void)
{
    if(EXTI_pvCallBack[INT2] != NULL)
    {
        EXTI_pvCallBack[INT2]();
    }
}
