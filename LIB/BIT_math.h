/***************************************************************/
/***************     Author: Zeinab EL_tantawy    **************/
/***************     Layer: LIB                   **************/
/***************     BIT_MATH                     **************/
/***************************************************************/


/**
 * @file bitwise_macros.h
 * @brief Macros for bit manipulation operations.
 */

#ifndef BIT_math_H_
#define BIT_math_H_


/**
 * @brief Macro to set a specific bit in a variable.
 * 
 * This macro sets the bit at position `BITNO` of the variable `VAR` to 1.
 * 
 * @param VAR   The variable in which the bit needs to be set.
 * @param BITNO The bit position to set (0-based index).
 */
#define SET_BIT(VAR, BITNO)   ((VAR) |= (1 << (BITNO)))

/**
 * @brief Macro to clear a specific bit in a variable.
 * 
 * This macro clears the bit at position `BITNO` of the variable `VAR`, setting it to 0.
 * 
 * @param VAR   The variable in which the bit needs to be cleared.
 * @param BITNO The bit position to clear (0-based index).
 */
#define CLR_BIT(VAR, BITNO)   ((VAR) &= ~(1 << (BITNO)))

/**
 * @brief Macro to toggle a specific bit in a variable.
 * 
 * This macro toggles the bit at position `BITNO` of the variable `VAR`. 
 * If the bit is 0, it is set to 1; if it is 1, it is set to 0.
 * 
 * @param VAR   The variable in which the bit needs to be toggled.
 * @param BITNO The bit position to toggle (0-based index).
 */
#define TOG_BIT(VAR, BITNO)   ((VAR) ^= (1 << (BITNO)))

/**
 * @brief Macro to get the value of a specific bit in a variable.
 * 
 * This macro retrieves the value of the bit at position `BITNO` of the variable `VAR`.
 * 
 * @param VAR   The variable from which the bit value is retrieved.
 * @param BITNO The bit position to get the value of (0-based index).
 * 
 * @return The value of the bit (0 or 1).
 */
#define GET_BIT(VAR, BITNO)   (((VAR) >> (BITNO)) & 0x01)
#endif