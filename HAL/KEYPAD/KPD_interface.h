/***************************************************************/
/***************     Author: Zeinab EL_tantawy    **************/
/***************     Layer: MCAL                  **************/
/***************     DIO_program                  **************/
/***************************************************************/

#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H


/**
 * @brief Scans the keypad and returns the pressed key value.
 * 
 * This function scans the keypad matrix to detect if any key is pressed. It checks each column by pulling it low
 * and then reads the corresponding row values to detect a key press. The function handles debouncing by waiting
 * for the key to be released before returning the key value.
 * 
 * @return u8 The value of the pressed key from the keypad matrix. If no key is pressed, it returns `KPD_NO_PRESSED_KEY`.
 */
u8 KPD_u8GetPressedKey(void);

#endif