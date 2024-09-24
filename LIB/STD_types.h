/***************************************************************/
/***************     Author: Zeinab EL_tantawy     *************/
/***************     Layer: LIB                    *************/
/***************     STD_TYPEs                     *************/
/***************************************************************/

/**
 * @file types.h
 * @brief Custom type definitions and error codes.
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/**
 * @brief Custom type definitions for unsigned integers.
 * 
 * These typedefs represent different sizes of unsigned integer types.
 */
typedef unsigned char   u8;    /**< Unsigned 8-bit integer. */
typedef unsigned short  u16;   /**< Unsigned 16-bit integer. */
typedef unsigned long   u32;   /**< Unsigned 32-bit integer. */

/**
 * @brief Custom type definitions for signed integers.
 * 
 * These typedefs represent different sizes of signed integer types.
 */
typedef signed char     s8;    /**< Signed 8-bit integer. */
typedef signed short    s16;   /**< Signed 16-bit integer. */
typedef signed long     s32;   /**< Signed 32-bit integer. */

/**
 * @brief Custom type definitions for floating-point numbers.
 * 
 * These typedefs represent different precision levels of floating-point numbers.
 */
typedef float           f32;   /**< Single-precision floating-point number (32-bit). */
typedef double          f64;   /**< Double-precision floating-point number (64-bit). */

/**
 * @brief Macro definitions.
 * 
 * These macros represent common constants and error codes used throughout the codebase.
 */
#define NULL            0    /**< Macro for null pointer. */

/**
 * @brief Error code definitions.
 * 
 * These constants represent various error states.
 */
#define NO_ERROR        0    /**< No error occurred. */
#define ERROR           1    /**< General error. */
#define NULL_PTR_ERR    2    /**< Null pointer error. */
#define TIMEOUT_ERR     3    /**< Timeout error. */
#define BUSY_ERR        4    /**< Busy error. */

/**
 * @brief Boolean type definition.
 * 
 * This enumeration represents boolean values.
 */
typedef enum
{
    false,   /**< Represents the boolean value 'false'. */
    true     /**< Represents the boolean value 'true'. */
} bool;

#endif /* STD_TYPES_H_ */