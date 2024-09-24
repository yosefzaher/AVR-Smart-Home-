/*******************************************************************/
/***************     Author: Youssef_Farid		   *****************/
/***************     Layer: MCAL                   *****************/
/***************     ADC_program                   *****************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_math.h"

#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

/* 
 * ADC Driver for an AVR Microcontroller
 * 
 * This driver provides functionalities to configure the ADC, perform both
 * synchronous and asynchronous conversions, and handle multiple channel 
 * (chain) conversions in asynchronous mode using interrupts.
 */

/* Global Variables */
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;  // Callback function pointer for asynchronous mode
static u16* ADC_u16Result = NULL;                            // Pointer to store the ADC result
static u8 ADC_u8BusyFlag = IDLE;                             // Flag to track ADC's busy/idle status
static u8 ADC_u8ChainFlag = 0u;                              // Counter for chain conversions (async multi-channel)
static u8* ADC_ChannelArr = NULL;                            // Pointer to an array of channels for chain conversions

/*
 * Function: ADC_voidInit
 * ----------------------
 * Initializes the ADC with the configured settings for:
 *  - Reference voltage
 *  - Resolution (8-bit or 10-bit)
 *  - Conversion mode (manual or auto-trigger)
 *  - Prescaler division factor
 *
 * The function sets the corresponding bits in the hardware registers such as ADMUX, ADCSRA, and SFIOR.
 * Finally, it enables the ADC by setting the ADEN bit in the ADCSRA register.
 */
void ADC_voidInit(void) {
    /* Voltage reference configuration */
#if ADC_u8Voltage_Ref == AREF
    /* Set AREF as the reference voltage */
    CLR_BIT(ADMUX, ADMUX_REFS1);
    CLR_BIT(ADMUX, ADMUX_REFS0);
#elif ADC_u8Voltage_Ref == AVCC
    /* Set AVCC as the reference voltage */
    CLR_BIT(ADMUX, ADMUX_REFS1);
    SET_BIT(ADMUX, ADMUX_REFS0);
#elif ADC_u8Voltage_Ref == INTERNAL
    /* Set internal 2.56V reference voltage */
    SET_BIT(ADMUX, ADMUX_REFS1);
    SET_BIT(ADMUX, ADMUX_REFS0);
#else
#error Wrong voltage reference configuration option
#endif

    /* Resolution configuration */
#if ADC_u8Resolution == _8_BIT
    /* Set to 8-bit resolution */
    SET_BIT(ADMUX, ADMUX_ADLAR);
#elif ADC_u8Resolution == _10_BIT
    /* Set to 10-bit resolution */
    CLR_BIT(ADMUX, ADMUX_ADLAR);
#else
#error Wrong resolution configuration option
#endif

    /* Conversion mode configuration */
#if ADC_u8Conv_Mode == Manual
    /* Disable auto-trigger mode */
    CLR_BIT(ADCSRA, ADCSRA_ADATE);
#elif ADC_u8Conv_Mode == Auto_Trigger
    /* Enable auto-trigger mode */
    SET_BIT(ADCSRA, ADCSRA_ADATE);

    /* Configure the trigger source */
    SFIOR &= Trigger_Source_Bit_Mask;  // Clear trigger source bits
    SFIOR |= ADC_u8TriggerSource << Trigger_Source_Bit_Pos;
#else
#error Wrong conversion mode configuration option
#endif

    /* Configure prescaler division factor */
    ADCSRA &= Prescaler_Bit_Mask;  // Clear prescaler bits
    ADCSRA |= ADC_u8PrescalerDivisionFactor << Prescaler_Bit_Pos;

    /* Enable the ADC */
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

/*
 * Function: ADC_u8StartConversionSynch
 * ------------------------------------
 * Starts an ADC conversion on the specified channel and waits for the result.
 * This is a synchronous function that blocks until the conversion completes.
 *
 * Parameters:
 *  - Copy_u8Channel: The ADC channel to convert.
 *  - Copy_pu16Result: Pointer to store the result of the conversion.
 *
 * Returns:
 *  - NO_ERROR if the conversion is successful.
 *  - BUSY_ERR if the ADC is already busy.
 *  - NULL_PTR_ERR if the result pointer is NULL.
 *  - TIMEOUT_ERR if the conversion times out.
 */
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu16Result) {
    u8 Local_u8ErrState = NO_ERROR;
    u32 Local_u32Counter = 0u;

    if (Copy_pu16Result != NULL) {
        if (ADC_u8BusyFlag == IDLE) {
            /* Mark ADC as busy */
            ADC_u8BusyFlag = BUSY;

            /* Set ADC channel */
            ADMUX &= Channel_Bit_Mask;  // Clear channel bits
            ADMUX |= Copy_u8Channel;

            /* Start conversion */
            SET_BIT(ADCSRA, ADCSRA_ADSC);

            /* Polling with blocking until conversion is complete or timeout */
            while (((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0u) && (Local_u32Counter < ADC_u32TimeOut)) {
                Local_u32Counter++;
            }

            if (Local_u32Counter == ADC_u32TimeOut) {
                /* Timeout error */
                Local_u8ErrState = TIMEOUT_ERR;
            } else {
                /* Conversion complete */
                SET_BIT(ADCSRA, ADCSRA_ADIF);  // Clear the interrupt flag

                /* Store conversion result */
#if ADC_u8Resolution == _8_BIT
                *Copy_pu16Result = ADCH;  // 8-bit result from ADCH
#elif ADC_u8Resolution == _10_BIT
                *Copy_pu16Result = ADC;   // 10-bit result from ADC register
#endif
            }

            /* ADC is now idle */
            ADC_u8BusyFlag = IDLE;
        } else {
            /* ADC is busy */
            Local_u8ErrState = BUSY_ERR;
        }
    } else {
        /* Null pointer error */
        Local_u8ErrState = NULL_PTR_ERR;
    }

    return Local_u8ErrState;
}

/*
 * Function: ADC_u8StartConversionAsynch
 * -------------------------------------
 * Starts an ADC conversion on the specified channel in asynchronous mode.
 * The result is stored in a pointer, and a callback function is called when the conversion completes.
 *
 * Parameters:
 *  - Copy_u8Channel: The ADC channel to convert.
 *  - Copy_pu16Result: Pointer to store the result of the conversion.
 *  - Copy_pvNotificationFunc: Callback function to call when the conversion completes.
 *
 * Returns:
 *  - NO_ERROR if the conversion is started successfully.
 *  - BUSY_ERR if the ADC is already busy.
 *  - NULL_PTR_ERR if any pointer is NULL.
 */
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void)) {
    u8 Local_u8ErrState = NO_ERROR;

    if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL)) {
        if (ADC_u8BusyFlag == IDLE) {
            /* Mark ADC as busy */
            ADC_u8BusyFlag = BUSY;

            /* Store result and callback globally */
            ADC_u16Result = Copy_pu16Result;
            ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

            /* Set ADC channel */
            ADMUX &= Channel_Bit_Mask;  // Clear channel bits
            ADMUX |= Copy_u8Channel;

            /* Start conversion */
            SET_BIT(ADCSRA, ADCSRA_ADSC);

            /* Enable ADC interrupt */
            SET_BIT(ADCSRA, ADCSRA_ADIE);
        } else {
            /* ADC is busy */
            Local_u8ErrState = BUSY_ERR;
        }
    } else {
        /* Null pointer error */
        Local_u8ErrState = NULL_PTR_ERR;
    }

    return Local_u8ErrState;
}

/*
 * Function: ADC_u8StartChainConvAsynch
 * ------------------------------------
 * Starts a chain of conversions on multiple channels in asynchronous mode.
 * The conversion results are stored in a result array, and a callback function is called when all conversions are complete.
 *
 * Parameters:
 *  - Copy_u8NumOfChannels: Number of channels to convert in the chain.
 *  - Copy_u8Channels: Array of channels to convert.
 *  - Copy_pu16Results: Array to store the conversion results.
 *  - Copy_pvNotificationFunc: Callback function to call when all conversions are complete.
 *
 * Returns:
 *  - NO_ERROR if the chain conversion is started successfully.
 *  - BUSY_ERR if the ADC is already busy.
 *  - NULL_PTR_ERR if any pointer is NULL.
 */
u8 ADC_u8StartChainConvAsynch(u8 Copy_u8NumOfChannels, u8* Copy_u8Channels, u16* Copy_pu16Results, void(*Copy_pvNotificationFunc)(void)) {
    u8 Local_u8ErrState = NO_ERROR;

    if ((Copy_pu16Results != NULL) && (Copy_pvNotificationFunc != NULL) && (Copy_u8Channels != NULL)) {
        if (ADC_u8BusyFlag == IDLE) {
            /* Mark ADC as busy */
            ADC_u8BusyFlag = BUSY;

            /* Store chain information globally */
            ADC_u8ChainFlag = Copy_u8NumOfChannels;
            ADC_ChannelArr = Copy_u8Channels;

            /* Start the first conversion */
            ADC_u8StartConversionAsynch(*Copy_u8Channels, Copy_pu16Results, Copy_pvNotificationFunc);
        } else {
            /* ADC is busy */
            Local_u8ErrState = BUSY_ERR;
        }
    } else {
        /* Null pointer error */
        Local_u8ErrState = NULL_PTR_ERR;
    }

    return Local_u8ErrState;
}

/*
 * Interrupt Service Routine (ISR) for ADC conversion complete
 * -----------------------------------------------------------
 * This ISR is triggered when an ADC conversion completes.
 * It stores the conversion result and starts the next conversion in a chain if needed.
 * When all conversions are complete, the callback function is invoked.
 */
void __vector_16(void) __attribute__((signal));
void __vector_16(void) {
    /* Store conversion result */
#if ADC_u8Resolution == _8_BIT
    *ADC_u16Result = ADCH;  // 8-bit result from ADCH
#elif ADC_u8Resolution == _10_BIT
    *ADC_u16Result = ADC;   // 10-bit result from ADC register
#endif

    /* Chain conversion handling */
    ADC_u8ChainFlag--;
    if (ADC_u8ChainFlag > 0) {
        /* Start next conversion in the chain */
        ADC_u8StartConversionAsynch(ADC_ChannelArr[1], ADC_u16Result + 1, ADC_pvCallBackNotificationFunc);
    } else {
        /* All conversions complete, invoke the callback */
        ADC_pvCallBackNotificationFunc();

        /* ADC is now idle */
        ADC_u8BusyFlag = IDLE;

        /* Disable ADC interrupt */
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    }
}

