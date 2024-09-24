/*******************************************************************/
/***************     Author: Youssef_Farid		   *****************/
/***************     Layer: MCAL                   *****************/
/***************     ADC_interface                 *****************/
/*******************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/**
 * @brief Initialize the ADC registers.
 *
 * This function initializes the ADC by setting up the necessary configuration
 * registers (ADMUX, ADCSRA, SFIOR) based on predefined values from the 
 * configuration file (ADC_config.h). This includes selecting the voltage reference, 
 * resolution (8-bit or 10-bit), prescaler, and conversion mode (manual or auto-trigger).
 * 
 * After initialization, the ADC is ready for conversion.
 */
void ADC_voidInit(void);

/**
 * @brief Start ADC conversion in synchronous mode.
 *
 * This function initiates an ADC conversion on the specified channel. It then
 * waits for the conversion to complete before storing the result in the provided
 * result pointer. This function is blocking, meaning it will wait until the conversion
 * completes or times out.
 *
 * @param Copy_u8Channel: The ADC channel to start the conversion on (refer to the datasheet for channel numbers).
 * @param Copy_pu16Result: Pointer to store the result of the conversion.
 * @return u8: Status of the operation:
 * - '0u' on success,
 * - '2u' if the result pointer is NULL,
 * - '3u' if a timeout occurs before the conversion completes,
 * - '4u' if the ADC is already busy with another conversion.
 *
 * This function is useful when the application can afford to wait for the ADC to
 * complete the conversion.
 */
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu16Result);

/**
 * @brief Start ADC conversion in asynchronous mode.
 *
 * This function starts an ADC conversion on the specified channel in asynchronous mode.
 * It does not block the CPU and instead enables the ADC interrupt. When the conversion
 * is complete, the ADC interrupt service routine (ISR) assigns the result to the provided
 * pointer and calls the user-specified callback function.
 *
 * @note Global interrupts must be enabled for this function to work.
 *
 * @param Copy_u8Channel: The ADC channel to start the conversion on (refer to the datasheet for channel numbers).
 * @param Copy_pu16Result: Pointer to store the result of the conversion.
 * @param Copy_pvNotificationFunc: Function pointer to the callback function that will be called when the conversion completes.
 * @return u8: Status of the operation:
 * - '0u' on success,
 * - '2u' if the result pointer or callback pointer is NULL,
 * - '4u' if the ADC is already busy with another conversion.
 *
 * This function is useful for non-blocking applications where other tasks can be performed
 * while waiting for the ADC conversion to complete.
 */
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void));

/**
 * @brief Start ADC conversions on a chain of channels in asynchronous mode.
 *
 * This function allows for sequential conversions on multiple ADC channels, in a chain.
 * It starts with the first channel and, after each conversion is completed, stores the result
 * in the provided result array. Once all channels in the chain are converted, the callback
 * function is called. The process is done asynchronously, meaning it will not block the CPU.
 *
 * @note Global interrupts must be enabled for this function to work.
 *
 * @param Copy_u8NumOfChannels: The number of channels to convert.
 * @param Copy_u8Channels: Pointer to an array of channel numbers specifying the sequence of conversions.
 * @param Copy_pu16Results: Pointer to an array where the converted results will be stored.
 * @param Copy_pvNotificationFunc: Function pointer to the callback function that will be called when all conversions are complete.
 * @return u8: Status of the operation:
 * - '0u' on success,
 * - '2u' if any of the pointers (channel array, result array, or callback function) are NULL,
 * - '4u' if the ADC is already busy with another conversion.
 *
 * This function is ideal for applications where multiple ADC channels need to be sampled sequentially 
 * without blocking the main program execution.
 */
u8 ADC_u8StartChainConvAsynch(u8 Copy_u8NumOfChannels, u8* Copy_u8Channels, u16* Copy_pu16Results, void(*Copy_pvNotificationFunc)(void));
#endif
