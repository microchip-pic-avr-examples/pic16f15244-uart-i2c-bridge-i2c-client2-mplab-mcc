/**
 * ADC Generated Driver File
 * 
 * @file adc.c
 * 
 * @ingroup  adc
 * 
 * @brief This file contains the API implementations for the ADC driver.
 *
 * @version ADC Driver Version 3.0.0
 * 
 * @version ADC Package Version 4.0.0
*/

/*
� [2025] Microchip Technology Inc. and its subsidiaries.

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

// Section: Included Files

#include <xc.h>
#include "../adc.h"
#include "../adc_types.h"
#include "../../system/clock.h"



static void (*ADC_ConversionDoneCallback)(void);

void ADC_Initialize(void)
{
    ADCON0bits.ADON = ADC_BIT_CLEAR;    
    ADCON0 = (1 << _ADCON0_ADON_POSITION)	/* ADON enabled(1) */
			|(0 << _ADCON0_GO_nDONE_POSITION)	/* GO_nDONE stop(0) */
			|(20 << _ADCON0_CHS_POSITION);	/* CHS ANC4(20) */
    ADCON1 = (0 << _ADCON1_ADPREF_POSITION)	/* ADPREF VDD(0) */
			|(0 << _ADCON1_ADCS_POSITION)	/* ADCS FOSC/2(0) */
			|(1 << _ADCON1_ADFM_POSITION);	/* ADFM right(1) */
    ADRESH = (0 << _ADRESH_ADRESH_POSITION);	/* ADRESH 0x0(0) */
    ADRESL = (0 << _ADRESL_ADRESL_POSITION);	/* ADRESL 0x0(0) */
    ADACT = (0 << _ADACT_ADACT_POSITION);	/* ADACT disabled(0) */ 
    ADC_ConversionDoneCallback = NULL;
    PIR1bits.ADIF = ADC_BIT_CLEAR;
    PIE1bits.ADIE = ADC_BIT_SET;
    ADCON0 = (1 << _ADCON0_ADON_POSITION)	/* ADON enabled(1) */
			|(0 << _ADCON0_GO_nDONE_POSITION)	/* GO_nDONE stop(0) */
			|(20 << _ADCON0_CHS_POSITION);	/* CHS ANC4(20) */
}

void ADC_Deinitialize(void)
{
    ADCON0 = 0x0;
    PIR1bits.ADIF = ADC_BIT_CLEAR;
    PIE1bits.ADIE = ADC_BIT_CLEAR;
    ADCON1 = 0x0;
    ADRESH = 0x0;
    ADRESL = 0x0;
    ADACT = 0x0;
}

void ADC_Enable(void)
{
    ADCON0bits.ADON = ADC_BIT_SET;
}

void ADC_Disable(void)
{
    ADCON0bits.ADON = ADC_BIT_CLEAR;
}

void ADC_ChannelSelect(adc_channel_t channel)
{
    ADCON0bits.CHS = (uint8_t)channel;    
}

void ADC_ConversionStart(void)
{
    ADCON0bits.GO_nDONE = ADC_BIT_SET;
}

bool ADC_IsConversionDone(void)
{
    return ((bool)(!ADCON0bits.GO_nDONE));
}

void ADC_ConversionStop(void)
{
    ADCON0bits.GO_nDONE = ADC_BIT_CLEAR;
}

adc_result_t ADC_ConversionResultGet(void)
{
    return ((adc_result_t)((ADRESH << 8U) | ADRESL));
}

adc_result_t ADC_ChannelSelectAndConvert(adc_channel_t channel)
{
    ADCON0bits.CHS = (uint8_t)channel;  
    __delay_us(ACQ_US_DELAY);
    ADCON0bits.GO_nDONE = ADC_BIT_SET;

    while (true == ADCON0bits.GO_nDONE)
    {
    }
    return ((adc_result_t)((ADRESH << 8U) | ADRESL));
}

void ADC_AutoTriggerSourceSet(adc_trigger_source_t triggerSource)
{
    ADACT = triggerSource;
}

uint8_t ADC_ResolutionGet(void)
{
    return ADC_RESOLUTION;
}

void ADC_ConversionDoneInterruptFlagClear(void)
{
    PIR1bits.ADIF = ADC_BIT_CLEAR;
}

bool ADC_IsConversionDoneInterruptFlagSet(void)
{
    return PIR1bits.ADIF; 
}

void ADC_ConversionDoneCallbackRegister(void (*callback)(void))
{
    ADC_ConversionDoneCallback = callback;
}

void ADC_ConversionDoneInterruptEnable(void)
{
    PIE1bits.ADIE = ADC_BIT_SET;
}

void ADC_ConversionDoneInterruptDisable(void)
{
    PIE1bits.ADIE = ADC_BIT_CLEAR;
}

void ADC_ISR(void)
{
    PIR1bits.ADIF = ADC_BIT_CLEAR;

    if (NULL != ADC_ConversionDoneCallback)
    {
        ADC_ConversionDoneCallback();
    }
    else
    {
        // Do nothing
    }
}
