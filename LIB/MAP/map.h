/****************************************
*            Author  : ENG.Yosef Zaher  *                         
*            Date    : 9/11/2024        *                      
*            Version : 1.0.0            *                     
*****************************************/

/**
 * @file mapping.h
 * @brief Function for mapping a value from one range to another.
 */


#ifndef MAP_H
#define MAP_H


/**
 * @brief Maps an input value from one range to another.
 *
 * This function takes an input value and scales it from its current range
 * (specified by `InputRangeMin` and `InputRangeMax`) to a new range
 * (specified by `OutputRangeMin` and `OutputRangeMax`). The result is an
 * output value that corresponds to the same proportion within the new range.
 *
 * @param InputRangeMin  The minimum value of the input range.
 * @param InputRangeMax  The maximum value of the input range.
 * @param OutputRangeMin The minimum value of the output range.
 * @param OutputRangeMax The maximum value of the output range.
 * @param InputValue     The value to be mapped.
 *
 * @return The mapped value in the output range.
 *
 * @note This function assumes that the input value is within the input range.
 */
s32 Map(s32 InputRangeMin, s32 InputRangeMax , s32 OutputRangeMin , s32 OutputRangeMax , s32 InputValue);

#endif
