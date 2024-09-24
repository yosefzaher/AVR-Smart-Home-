/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/


#ifndef EXTI_interface_H
#define EXTI_interface_H

#include "STD_TYPES.h"

/**
 * @brief Enum to represent the external interrupt channels (INT0, INT1, INT2).
 */
typedef enum
{
    INT0, 
    INT1, 
    INT2
} IntChannel_t;

/**
 * @brief Enum to represent the sense control options for edge detection.
 */
typedef enum
{
    LOW_LEVEL, 
    ON_CHANGE, 
    FALLING_EDGE, 
    RISING_EDGE
} SenseCtrl_t;

/**
 * @brief  Initializes the EXTI module based on configuration settings.
 * @param  None
 * @return None
 */
void EXTI_voidInit(void);

/**
 * @brief  Sets the sense control (edge detection) for a specific interrupt channel.
 * @param  Copy_IntCh: The interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_SenseCtrl: The sense control mode (LOW_LEVEL, ON_CHANGE, FALLING_EDGE, RISING_EDGE).
 * @return Error status (OK if successful, NOK if an invalid configuration is passed).
 */
u8 EXTI_u8SetSenseCtrl(IntChannel_t Copy_IntCh, SenseCtrl_t Copy_SenseCtrl);

/**
 * @brief  Enables a specific interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_IntCh: The interrupt channel to enable.
 * @return Error status (OK if successful, NOK if an invalid channel is passed).
 */
u8 EXTI_u8EnableIntChannel(IntChannel_t Copy_IntCh);

/**
 * @brief  Disables a specific interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_IntCh: The interrupt channel to disable.
 * @return Error status (OK if successful, NOK if an invalid channel is passed).
 */
u8 EXTI_u8DisableIntChannel(IntChannel_t Copy_IntCh);

/**
 * @brief  Sets a callback function for a specific interrupt channel.
 * @param  Copy_IntCh: The interrupt channel (INT0, INT1, or INT2).
 * @param  Copy_pvCallBackFunc: Pointer to the callback function.
 * @return Error status (OK if successful, NULL_PTR_ERR if the callback is NULL).
 */
u8 EXTI_u8SetCallBack(IntChannel_t Copy_IntCh, void(*Copy_pvCallBackFunc)(void));

#endif
