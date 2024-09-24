/***************************************************************/
/***************     Author:Zeinab Eltantawy    ****************/
/***************     Layer: HAL                *****************/
/***************     SWC: CLCD                   ***************/
/***************************************************************/

#include "BIT_math.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "STD_types.h"
#include "DIO_interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"


/**
 * @brief Sends a command to the LCD.
 * 
 * This function sends a command byte to the LCD to control its operations (e.g., clearing the display, 
 * setting the cursor position).
 * 
 * @param copy_u8command The 8-bit command to be sent to the LCD.
 * @return None
 */
void CLCD_voidSendCommand   (u8 copy_u8command)
{

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8RW_PIN,DIO_u8PIN_LOW);  // Set RW pin to LOW (Write mode)

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8RS_PIN,DIO_u8PIN_LOW);  // Set RS pin to LOW (Command mode)

	DIO_u8_SetPortValue(LCD_u8Data_PORT,copy_u8command);            // Send the command to the data port

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8E_PIN,DIO_u8PIN_HIGH);  // Enable the E pin

	_delay_ms(2);                                                   // Delay to ensure command is processed

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8E_PIN,DIO_u8PIN_LOW);    // Disable the E pin
}



/**
 * @brief Sends a data byte to the LCD for display.
 * 
 * This function sends a character to be displayed on the LCD at the current cursor position.
 * 
 * @param copy_u8data The 8-bit data (character) to be displayed.
 * @return None
 */
void CLCD_voidSendData  (u8 copy_u8data)
{

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8RW_PIN,DIO_u8PIN_LOW);   // Set RW pin to LOW (Write mode)

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8RS_PIN,DIO_u8PIN_HIGH);  // Set RS pin to HIGH (Data mode)

	DIO_u8_SetPortValue(LCD_u8Data_PORT,copy_u8data);                // Send the data to the data port

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8E_PIN,DIO_u8PIN_HIGH);   // Enable the E pin

	_delay_ms(2);                                                    // Delay to ensure command is processed

	DIO_u8_SetPinValue(LCD_u8CLR_PORT,LCD_u8E_PIN,DIO_u8PIN_LOW);    // Disable the E pin
}

/**
 * @brief Initializes the character LCD in 4-bit mode.
 * 
 * This function configures the LCD to operate in 4-bit mode and sets the necessary LCD parameters
 * such as display control, entry mode, and clearing the display.
 * 
 * @param None
 * @return None
 */
void CLCD_voidInit (void)
{

	DIO_u8_SetPortDirection(LCD_u8Data_PORT, DIO_u8PORT_OUTPUT);   // Set data port direction to output
	DIO_u8_SetPortDirection(LCD_u8CLR_PORT, DIO_u8PORT_OUTPUT);   // Set control port direction to output

	_delay_ms(40);  // Delay to allow LCD to stabilize after power on

	CLCD_voidSendCommand(0x38);      // Set LCD to 8-bit mode
	CLCD_voidSendCommand(0x0C);     // Turn on the display and hide the cursor
	CLCD_voidSendCommand(0x01);    // Clear the display
	CLCD_voidSendCommand(0x06);   // Set entry mode (increment address, no shift)
}


/**
 * @brief Displays a string on the LCD.
 * 
 * This function sends a null-terminated string to the LCD to be displayed starting from the 
 * current cursor position.
 * 
 * @param Copy_pcString Pointer to the null-terminated string to be displayed.
 * @return None
 */
void CLCD_voidSendString   (const char* Copy_pcString)
{
	u8 counter=0;
	while(Copy_pcString[counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[counter++]);
	}
}


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
void CLCD_voidGoToXY(u8 Xpos  ,u8 Ypos)
{
	u8 add = 0;
	if(Xpos == 0)
	{
		add = Ypos;
	}
	else if(Xpos == 1)
	{
		add = Ypos+ 0x40 ;
	}
	CLCD_voidSendCommand(add + 128);   // Send command to move the cursor
}

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
void CLCD_voidDisplaySpecialCharacter(u8* Copy_u8ArrayPtr, u8 Copy_u8BlockNum, u8 Copy_XPos, u8 Copy_YPos)
{
	u8 add = 0;
	add = 8 * Copy_u8BlockNum;           // Calculate address in CGRAM
	CLCD_voidSendCommand(add + 64);      // Send command to set CGRAM address
	for (u8 Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++) 
	{
		CLCD_voidSendData(Copy_u8ArrayPtr[Local_u8Counter]); // Send custom character data
	}
	CLCD_voidGoToXY(Copy_XPos, Copy_YPos);  // Move cursor to specified position
	CLCD_voidSendData(Copy_u8BlockNum);     // Display the custom character

}

/**
 * @brief Displays a number on the LCD.
 * 
 * This function converts a number to its string equivalent and displays it on the LCD, starting
 * from the current cursor position.
 * 
 * @param Copy_u32Number The number to be displayed (supports up to 32-bit unsigned integer).
 * @return None
 */
void CLCD_voidDisplayNumber(u32 Copy_u32Number) 
{
    char str[11];  // Max 10 digits for 32-bit number + 1 for null terminator
    u8 i = 0;

    // Special case for 0
    if (Copy_u32Number == 0) 
	{
        CLCD_voidSendData('0');
        return;
    }

    // Convert number to characters by extracting digits
    while (Copy_u32Number > 0) 
	{
        str[i++] = (Copy_u32Number % 10) + '0';  // Get last digit, convert to char
        Copy_u32Number /= 10;  // Remove last digit
    }

    // Display the digits in reverse order
    for (u8 j = i; j > 0; j--) 
	{
        CLCD_voidSendData(str[j - 1]);  // Send each digit to LCD
    }
}


/**
 * @brief Clears the LCD screen.
 * 
 * This function sends a command to the LCD to clear its display and reset the cursor to the home position.
 * 
 * @param None
 * @return None
 */
void CLCD_voidClearScreen(void)
{
	/* Clear the first row */
	CLCD_voidGoToXY(0, 0);
	CLCD_voidSendString("                ");
	
	/* Clear the second row */
	CLCD_voidGoToXY(1, 0);
	CLCD_voidSendString("                ");
	
	/* Return the cursor to the home position */
	CLCD_voidGoToXY(0, 0);
}