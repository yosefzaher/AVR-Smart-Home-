/**********************************************************************
***********************************************************************			       						    	                     
**							مبرمجي	الأرياف							 **	
**						     Application.c							 **
**							    1.0.0                                **
**                           17 / 09 / 2024                          **   
***********************************************************************
***********************************************************************/

#ifndef _MAIN_H_
#define _MAIN_H_

/*Include Section Start*/

#include "LCD_interface.h"
#include "STEPPER_interface.h"
#include "LED_interface.h"
#include "KPD_interface.h"
#include "BUZZER_interface.h"
#include "LM35_interface.h"
#include "LDR_interface.h"

#include "EXTI_interface.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"

#include "STD_types.h"

#include <string.h>
#include <util/delay.h>

/*Include Section End*/

/*Function Declaration Secion Start*/

/**
 * @brief Retrieves temperature and LDR sensor values.
 * 
 * This function reads data from the LM35 temperature sensor and the LDR (Light Dependent Resistor)
 * and stores the results in global variables.
 * 
 * @param None
 * @return void
 */
void GetNotification(void);

/**
 * @brief Interrupt callback function to turn off the buzzer.
 * 
 * This function is called during an interrupt (INT2), turning off the buzzer
 * and incrementing the global flag.
 * 
 * @param None
 * @return void
 */
void INIT2FUNC(void);

/**
 * @brief Simulates opening a door using a stepper motor.
 * 
 * The stepper motor is turned on to simulate opening the door in full-step mode,
 * rotating in the clockwise direction.
 * 
 * @param None
 * @return void
 */
void openDoor(void) ;

/**
 * @brief Simulates closing a door using a stepper motor.
 * 
 * The stepper motor is turned off to simulate closing the door.
 * 
 * @param None
 * @return void
 */
void closeDoor(void) ;

/**
 * @brief Blinks the red LED for 5 seconds.
 * 
 * The red LED blinks on and off in 500ms intervals for a total of 5 seconds (10 iterations).
 * 
 * @param None
 * @return void
 */
void blinkRedLED(void) ;

/**
 * @brief Handles password input and validation.
 * 
 * This function prompts the user to enter a password using a keypad. If the password matches the stored
 * password, the green LED turns on and the door opens. After 3 failed attempts, the alarm is triggered.
 * 
 * @param None
 * @return void
 */
void handlePassword(void) ;

/**
 * @brief Initializes all necessary peripherals for the application.
 * 
 * This function initializes the following peripherals:
 * - Ports
 * - Character LCD (CLCD)
 * - LEDs (red, green, LED1, LED2, LED3, LED4, LED5)
 * - Buzzers (alarmBuzzer, buzzer)
 * - Stepper motor
 * - ADC for temperature and LDR readings
 * - External Interrupts (EXTI)
 * - Global Interrupts
 * 
 * @param None
 * @return void
 */
void Application_Initialization(void) ; 

/*Function Declaration Secion End*/

#endif