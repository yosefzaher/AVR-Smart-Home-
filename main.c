/**********************************************************************
***********************************************************************			       						    	                     
**							مبرمجي	الأرياف							 **	
**						     Application.c							 **
**							    1.0.0                                **
**                           17 / 09 / 2024                          **   
***********************************************************************
***********************************************************************/

/*Include Section Start*/

#include "main.h"

/*Include Section End*/

/*Defines Section Start*/

#define MAX_ATTEMPTS 3
#define KPD_NO_PRESSED_KEY 0xff
#define PASSWORD "12" // Example password for a 2x2 keypad

#define LVL_0_LIGHT 2550u
#define LVL_1_LIGHT	2295u
#define LVL_2_LIGHT	1530u
#define LVL_3_LIGHT	1020u
#define LVL_4_LIGHT	510u
#define LVL_5_LIGHT	253u

#define NUM_OF_CHANNELS 2u

/*Defines Section End*/


/*Global Variable Section Start*/

LED_T redLED = {DIO_u8PORTB, DIO_u8PIN0, Active_High};
LED_T greenLED = {DIO_u8PORTB, DIO_u8PIN1, Active_High};

LED_T LED1 = {DIO_u8PORTA, DIO_u8PIN7, Active_High};
LED_T LED2 = {DIO_u8PORTB, DIO_u8PIN3, Active_High};
LED_T LED3 = {DIO_u8PORTB, DIO_u8PIN4, Active_High};
LED_T LED4 = {DIO_u8PORTB, DIO_u8PIN5, Active_High};
LED_T LED5 = {DIO_u8PORTB, DIO_u8PIN7, Active_High};

BUZZER_T alarmBuzzer = {DIO_u8PORTB, DIO_u8PIN6, BUZZER_ACTIVE_HIGH};
BUZZER_T buzzer = {DIO_u8PORTB, DIO_u8PIN6, BUZZER_ACTIVE_HIGH};

ADC_info temp = {Vref_AVCC , RES_EIGHT_BITS};

u16 result[2] , Analog[2] = {0};
u8 attemptCount = 0 , Channels[2] = {4 , 5};
u8 Flag = 0u;

u8 fire[8] = 
{
		0b00000100,
		0b00001110,
		0b00001110,
		0b00011111,
		0b00011111,
		0b00001110,
		0b00000100,
		0b00000000
};

/*Global Variable Section End*/



/*Main Function Start*/

void main(void)
{

	Application_Initialization() ;

	handlePassword();

	while(1)
	{

		/*Start ADC conversion*/
		ADC_u8StartChainConvAsynch(NUM_OF_CHANNELS , Channels , result , GetNotification);
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("TEMP: ");
		CLCD_voidDisplayNumber((u32) Analog[0]);
		CLCD_voidSendString(" C");


		if(Analog[0] > 50)
		{
			while(!Flag)
			{
				CLCD_voidGoToXY(0 ,0) ;
				STEPPER_voidOn(STEPPER_HALF_STEP , STEPPER_CLOCK_WISE) ;
				CLCD_voidSendString("FIRE DETECTED ") ;
				CLCD_voidDisplaySpecialCharacter(fire , 0 , 0 , 15) ;
				BUZZER_voidOn(buzzer) ;
				EXTI_u8SetCallBack(INT2 ,&INIT2FUNC ) ;
			}
			CLCD_voidClearScreen() ;
			Flag-- ;
		}
		else if(Analog[0] > 25)
		{
			STEPPER_voidOn(STEPPER_HALF_STEP , STEPPER_CLOCK_WISE) ;
		}
		else if(Analog[0] < 23)
		{
			STEPPER_voidOff();
		}


		if(Analog[1] > LVL_0_LIGHT)
		{
			LED_voidOn(LED1);
			LED_voidOn(LED2);
			LED_voidOn(LED3);
			LED_voidOn(LED4);
			LED_voidOn(LED5);
		}
		else if(Analog[1] > LVL_1_LIGHT)
		{
			LED_voidOn(LED1);
			LED_voidOn(LED2);
			LED_voidOn(LED3);
			LED_voidOn(LED4);
			LED_voidOff(LED5);
		}
		else if(Analog[1] > LVL_2_LIGHT)
		{
			LED_voidOn(LED1);
			LED_voidOn(LED2);
			LED_voidOn(LED3);
			LED_voidOff(LED4);
			LED_voidOff(LED5);
		}
		else if(Analog[1] > LVL_3_LIGHT)
		{
			LED_voidOn(LED1);
			LED_voidOn(LED2);
			LED_voidOff(LED3);
			LED_voidOff(LED4);
			LED_voidOff(LED5);
		}
		else if(Analog[1] > LVL_4_LIGHT)
		{
			LED_voidOn(LED1);
			LED_voidOff(LED2);
			LED_voidOff(LED3);
			LED_voidOff(LED4);
			LED_voidOff(LED5);
		}
		else if(Analog[1] > LVL_5_LIGHT)
		{
			LED_voidOff(LED1);
			LED_voidOff(LED2);
			LED_voidOff(LED3);
			LED_voidOff(LED4);
			LED_voidOff(LED5);
		}
	}

}

/*Main Function End*/

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
void Application_Initialization(void)
{
    PORT_voidInit();
    CLCD_voidInit();
    LED_voidInit(redLED);
    LED_voidInit(greenLED);
    LED_voidInit(LED1);
    LED_voidInit(LED2);
    LED_voidInit(LED3);
    LED_voidInit(LED4);
    LED_voidInit(LED5);
    BUZZER_voidInit(alarmBuzzer);
    STEPPER_voidInit();
    ADC_voidInit();
    EXTI_voidInit();
    GIE_voidEnableGlobal();
    BUZZER_voidInit(buzzer);
}

/**
 * @brief Retrieves temperature and LDR sensor values.
 * 
 * This function reads data from the LM35 temperature sensor and the LDR (Light Dependent Resistor)
 * and stores the results in global variables.
 * 
 * @param None
 * @return void
 */
void GetNotification(void)
{
    LM35_getTemperature(&temp , result[0] , &Analog[0]);
    Analog[1] = LDR_u16GetResistanceFrom8BitADC(result[1]);
}

/**
 * @brief Interrupt callback function to turn off the buzzer.
 * 
 * This function is called during an interrupt (INT2), turning off the buzzer
 * and incrementing the global flag.
 * 
 * @param None
 * @return void
 */
void INIT2FUNC(void)
{
    BUZZER_voidOff(buzzer);
    Flag++;
}

/**
 * @brief Handles password input and validation.
 * 
 * This function prompts the user to enter a password using a keypad. If the password matches the stored
 * password, the green LED turns on and the door opens. After 3 failed attempts, the alarm is triggered.
 * 
 * @param None
 * @return void
 */
void handlePassword(void) 
{
    char enteredPassword[3]; // To store the entered password (2 digits + null terminator)
    u8 i = 0;
    u8 key;
    u8 attemptCount = 0;
    CLCD_voidClearScreen();

    while (attemptCount < MAX_ATTEMPTS) 
	{
        CLCD_voidSendString("Enter Password:");

        for (i = 0; i < 2; i++) 
		{
            enteredPassword[i] = 0;
        }

        for (i = 0; i < 2; i++) 
		{
            do 
			{
                key = KPD_u8GetPressedKey();
            } while (key == 0xff);

            if (key != KPD_NO_PRESSED_KEY) 
			{
                enteredPassword[i] = key;
                if (i == 0) {
                    CLCD_voidGoToXY(1, 0);
                }
                CLCD_voidSendData(key);
                _delay_ms(200);
            }
        }

        enteredPassword[2] = '\0';

        if (strcmp(enteredPassword, PASSWORD) == 0) 
		{
            CLCD_voidClearScreen();
            CLCD_voidSendString("Welcome Home");
            LED_voidOn(greenLED);
            openDoor();
            _delay_ms(3000);
            closeDoor();
            LED_voidOff(greenLED);
            CLCD_voidClearScreen();
            return;
        } 
		else 
		{
            CLCD_voidClearScreen();
            CLCD_voidSendString("Wrong Password");
            LED_voidOn(redLED);
            _delay_ms(1000);
            LED_voidOff(redLED);
            attemptCount++;
            CLCD_voidClearScreen();

            if (attemptCount >= MAX_ATTEMPTS) 
			{
                CLCD_voidSendString("Too Many Attempts");
                BUZZER_voidOn(alarmBuzzer);
                blinkRedLED();
                BUZZER_voidOff(alarmBuzzer);
            }
        }
    }
}

/**
 * @brief Simulates opening a door using a stepper motor.
 * 
 * The stepper motor is turned on to simulate opening the door in full-step mode,
 * rotating in the clockwise direction.
 * 
 * @param None
 * @return void
 */
void openDoor(void)
{
    STEPPER_voidOn(STEPPER_FULL_STEP, STEPPER_CLOCK_WISE);
}

/**
 * @brief Simulates closing a door using a stepper motor.
 * 
 * The stepper motor is turned off to simulate closing the door.
 * 
 * @param None
 * @return void
 */
void closeDoor(void) 
{
    STEPPER_voidOff();
}

/**
 * @brief Blinks the red LED for 5 seconds.
 * 
 * The red LED blinks on and off in 500ms intervals for a total of 5 seconds (10 iterations).
 * 
 * @param None
 * @return void
 */
void blinkRedLED(void) 
{
    for (u8 i = 0; i < 10; i++) 
	{
        LED_voidOn(redLED);
        _delay_ms(500);
        LED_voidOff(redLED);
        _delay_ms(500);
    }
}