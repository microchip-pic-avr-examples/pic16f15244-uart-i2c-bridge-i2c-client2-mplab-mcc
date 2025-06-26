/**
 * ADC Type Definitions Header File
 *
 * @file adc_types.h
 *
 * @defgroup adc ADC
 *
 * @brief This file provides type definitions for the Analog-to-Digital Converter (ADC) module.
 *
 * @version ADC Driver Version 3.0.0
 * 
 * @version ADC Package Version 4.0.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef ADC_TYPES_H
#define	ADC_TYPES_H

// Section: Macros

/**
 @ingroup adc
 @brief ADC resolution value.
*/
#define ADC_RESOLUTION 10U

/**
 @ingroup adc
 @brief ADC bit set value.
*/
#define ADC_BIT_SET 1U

/**
 @ingroup adc
 @brief ADC bit clear value.
*/
#define ADC_BIT_CLEAR 0U

// Section: Types

/**
 @ingroup adc
 @typedef adc_result_t
 @brief ADC conversion result type.
*/
typedef int16_t adc_result_t;

// Section: Enumerations

/**
 * @ingroup adc
 * @enum adc_channel_t
 * @brief Describes the available Analog-to-Digital Converter (ADC) channels.
*/
typedef enum
{
    ADC_CHANNEL_AVSS =  0x24, /**< AVSS*/ 
    ADC_CHANNEL_FVR_BUF1 =  0x1e, /**< FVR_BUF1*/ 
    ADC_CHANNEL_ANB7 =  0xf, /**< IO_RB7: RB7*/ 
    ADC_CHANNEL_ANC4 =  0x14 /**< IO_RC4: RC4*/ 
} adc_channel_t;

/**
 * @ingroup adc
 * @typedef adc_trigger_source_t 
 * @brief Lists the ADC auto-trigger sources.
 */
typedef enum
{
    ADC_TRIGGER_SOURCE_DISABLED = 0x0, /**< Disabled*/  
    ADC_TRIGGER_SOURCE_ADACTPPS = 0x1, /**< ADACTPPS*/  
    ADC_TRIGGER_SOURCE_TMR0 = 0x2, /**< TMR0*/  
    ADC_TRIGGER_SOURCE_TMR1 = 0x3, /**< TMR1*/  
    ADC_TRIGGER_SOURCE_TMR2 = 0x4, /**< TMR2*/  
    ADC_TRIGGER_SOURCE_CCP1 = 0x5, /**< CCP1*/  
    ADC_TRIGGER_SOURCE_CCP2 = 0x6, /**< CCP2*/  
    ADC_TRIGGER_SOURCE_PWM3 = 0x7, /**< PWM3*/  
    ADC_TRIGGER_SOURCE_PWM4 = 0x8, /**< PWM4*/  
    ADC_TRIGGER_SOURCE_IOCIF = 0x9, /**< IOCIF*/  
    ADC_TRIGGER_SOURCE_ADRESH = 0xd /**< ADRESH*/  
} adc_trigger_source_t ;

#endif // ADC_TYPES_H