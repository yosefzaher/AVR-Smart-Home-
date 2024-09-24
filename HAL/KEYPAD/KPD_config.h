/***************************************************************/
/***************     Author: Zeinab EL_tantawy    **************/
/***************     Layer: MCAL                  **************/
/***************     DIO_program                  **************/
/***************************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/**
 * @brief Macro to define the port used for the keypad.
 *
 * This macro specifies the port on which the keypad is connected. 
 * It uses the port defined in the Digital I/O (DIO) module.
 */
#define KPD_PORT            DIO_u8PORTA

/**
 * @brief Macro to define the number of columns in the keypad.
 *
 * This macro specifies the number of columns present in the keypad matrix.
 */
#define COLUMNS_NUM         2

/**
 * @brief Macro to define the number of rows in the keypad.
 *
 * This macro specifies the number of rows present in the keypad matrix.
 */
#define ROWS_NUM            2

/**
 * @brief Macro to define the pin number for the first column of the keypad.
 *
 * This macro specifies the pin connected to the first column of the keypad.
 */
#define KPD_COLUMN0_PIN     DIO_u8PIN0

/**
 * @brief Macro to define the pin number for the second column of the keypad.
 *
 * This macro specifies the pin connected to the second column of the keypad.
 */
#define KPD_COLUMN1_PIN     DIO_u8PIN1

/**
 * @brief Macro to define the pin number for the first row of the keypad.
 *
 * This macro specifies the pin connected to the first row of the keypad.
 */
#define KPD_ROW0_PIN        DIO_u8PIN2

/**
 * @brief Macro to define the pin number for the second row of the keypad.
 *
 * This macro specifies the pin connected to the second row of the keypad.
 */
#define KPD_ROW1_PIN        DIO_u8PIN3

/**
 * @brief Macro to represent a state where no key is pressed.
 *
 * This macro defines a value that indicates no key has been pressed on the keypad.
 */
#define KPD_NO_PRESSED_KEY  0xFF

/**
 * @brief Macro to define the keypad matrix values.
 *
 * This macro specifies the character values in the keypad matrix.
 * The matrix is defined as:
 *    {{'1', '2'},
 *     {'3', '4'}}
 */
#define KPD_ARR_VAL         {{'1', '2'}, {'3', '4'}}


#endif
