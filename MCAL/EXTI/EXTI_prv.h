/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/


#ifndef EXTI_PRV_H
#define EXTI_PRV_H

/**
 * @brief Defines for EXTI sense control modes.
 * These are used to configure the external interrupt trigger conditions.
 */
#define EXTI_LOW_LEVEL          1u  /**< Interrupt triggered on low level */
#define EXTI_ON_CHANGE          2u  /**< Interrupt triggered on any logical change */
#define EXTI_FALLING_EDGE       3u  /**< Interrupt triggered on falling edge */
#define EXTI_RISING_EDGE        4u  /**< Interrupt triggered on rising edge */

/**
 * @brief Defines for enabling or disabling interrupt channels.
 * These values are used to control the state of interrupt channels.
 */
#define ENABLED                 1u  /**< Interrupt channel enabled */
#define DISABLED                2u  /**< Interrupt channel disabled */

#endif
