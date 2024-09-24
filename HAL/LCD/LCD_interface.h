/***************************************************************/
/***************     Author:Zeinab Eltantawy    ****************/
/***************     Layer: HAL                *****************/
/***************     SWC: CLCD                   ***************/
/***************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_types.h"

/**
 * @brief Initializes the character LCD in 4-bit mode.
 * 
 * This function configures the LCD to operate in 4-bit mode and sets the necessary LCD parameters
 * such as display control, entry mode, and clearing the display.
 * 
 * @param None
 * @return None
 */
void CLCD_voidInit(void);

/**
 * @brief Sends a command to the LCD.
 * 
 * This function sends a command byte to the LCD to control its operations (e.g., clearing the display, 
 * setting the cursor position).
 * 
 * @param copy_u8command The 8-bit command to be sent to the LCD.
 * @return None
 */
void CLCD_voidSendCommand(u8 copy_u8command);

/**
 * @brief Sends a data byte to the LCD for display.
 * 
 * This function sends a character to be displayed on the LCD at the current cursor position.
 * 
 * @param copy_u8data The 8-bit data (character) to be displayed.
 * @return None
 */
void CLCD_voidSendData(u8 copy_u8data);

/**
 * @brief Displays a string on the LCD.
 * 
 * This function sends a null-terminated string to the LCD to be displayed starting from the 
 * current cursor position.
 * 
 * @param Copy_pcString Pointer to the null-terminated string to be displayed.
 * @return None
 */
void CLCD_voidSendString(const char* Copy_pcString);

/**
 * @brief Moves the LCD cursor to a specific position.
 * 
 * This function sets the cursor position on the LCD. The position is determined by the (X, Y) coordinates,
 * where X is the row (0 or 1) and Y is the column (0 to 15).
 * 
 * @param Copy_u8XPos The row position (0 for the first row, 1 for the second row).
 * @param Copy_u8YPos The column position (0-15).
 * @return None
 */
void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/**
 * @brief Displays a custom character on the LCD.
 * 
 * This function writes a custom character (defined by an 8-byte array) to the LCD's CGRAM, then displays it 
 * at the specified (X, Y) position. The custom character is identified by a block number (0-7).
 * 
 * @param Copy_u8ArrayPtr Pointer to the 8-byte array defining the custom character.
 * @param Copy_u8BlockNum The CGRAM block number (0-7) to store the custom character.
 * @param Copy_XPos The row position (0 or 1).
 * @param Copy_YPos The column position (0-15).
 * @return None
 */
void CLCD_voidDisplaySpecialCharacter(u8* Copy_u8ArrayPtr, u8 Copy_u8BlockNum, u8 Copy_XPos, u8 Copy_YPos);

/**
 * @brief Displays a number on the LCD.
 * 
 * This function converts a number to its string equivalent and displays it on the LCD, starting
 * from the current cursor position.
 * 
 * @param Copy_u32Number The number to be displayed (supports up to 32-bit unsigned integer).
 * @return None
 */
void CLCD_voidDisplayNumber(u32 Copy_u32Number);

/**
 * @brief Clears the LCD screen.
 * 
 * This function sends a command to the LCD to clear its display and reset the cursor to the home position.
 * 
 * @param None
 * @return None
 */
void CLCD_voidClearScreen(void);


#endif /* LCD_INTERFACE_H_ */
