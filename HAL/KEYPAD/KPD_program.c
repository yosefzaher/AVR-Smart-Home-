/***************************************************************/
/***************     Author: Zeinab EL_tantawy    **************/
/***************     Layer: MCAL                  **************/
/***************     DIO_program                  **************/
/***************************************************************/

#include <util/delay.h>

#include "STD_types.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"


/**
 * @brief Scans the keypad and returns the pressed key value.
 * 
 * This function scans the keypad matrix to detect if any key is pressed. It checks each column by pulling it low
 * and then reads the corresponding row values to detect a key press. The function handles debouncing by waiting
 * for the key to be released before returning the key value.
 * 
 * @return u8 The value of the pressed key from the keypad matrix. If no key is pressed, it returns `KPD_NO_PRESSED_KEY`.
 */
u8 KPD_u8GetPressedKey(void) {
    u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY, Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;
    
    // Keypad mapping to button values
    static u8 Local_u8KPDArr[ROWS_NUM][COLUMNS_NUM] = KPD_ARR_VAL;
    
    // Pin numbers for columns
    static u8 Local_u8ColumnArr[COLUMNS_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN};
    
    // Pin numbers for rows
    static u8 Local_u8RowArr[ROWS_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN};
    
    // Loop through columns
    for (Local_u8ColumnIdx = 0; Local_u8ColumnIdx < COLUMNS_NUM; Local_u8ColumnIdx++) {
        // Activate the current column by pulling it low
        DIO_u8_SetPinValue(KPD_PORT, Local_u8ColumnArr[Local_u8ColumnIdx], DIO_u8PIN_LOW);
        
        // Loop through rows
        for (Local_u8RowIdx = 0; Local_u8RowIdx < ROWS_NUM; Local_u8RowIdx++) {
            // Read the state of the row pin
            DIO_u8_GetPinValue(KPD_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);
            
            // Check if the pin is low, indicating a pressed key
            if (DIO_u8PIN_LOW == Local_u8PinState) {
                // Get the corresponding key value from the keypad array
                Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
                
                // Wait for the key to be released (debouncing)
                while (DIO_u8PIN_LOW == Local_u8PinState) {
                    DIO_u8_GetPinValue(KPD_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);
                }
                
                _delay_ms(10);  // Debouncing delay
                
                // Deactivate the column by setting it high again
                DIO_u8_SetPinValue(KPD_PORT, Local_u8ColumnArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
                return Local_u8PressedKey;  // Return the pressed key value
            }
        }
        
        // Deactivate the current column by setting it high again
        DIO_u8_SetPinValue(KPD_PORT, Local_u8ColumnArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
    }
    
    return Local_u8PressedKey;  // Return if no key was pressed
}