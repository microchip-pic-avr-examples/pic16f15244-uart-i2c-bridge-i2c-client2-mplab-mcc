/**
  ADC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc.c

  @Summary
    This is the generated driver implementation file for the ADC driver.

  @Description
    This source file provides APIs for driver for ADC.
    Generation Information :
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.31
        MPLAB             :  MPLABX v5.45
*/

/*
© [2021] Microchip Technology Inc. and its subsidiaries.

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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../adc.h"
#include "../../system/clock.h"

/**
  Section: Macro Declarations
*/

#define ACQ_US_DELAY 5

void (*ADC_InterruptHandler)(void);
static void ADC_DefaultInterruptHandler(void);

/**
  Section: ADC Module APIs
*/

void ADC_Initialize(void)
{
    // ADPREF VDD; ADCS FOSC/4; ADFM right; 
    ADCON1 = 0xC0;

    // ADRESL 0x0; 
    ADRESL = 0x0;

    // ADRESH 0x0; 
    ADRESH = 0x0;

    // ADACT disabled; 
    ADACT = 0x0;

    // ADON enabled; GO_nDONE stop; CHS ANA0; 
    ADCON0 = 0x1;

    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
    
    //Configure interrupt handlers
    ADC_SetInterruptHandler(ADC_DefaultInterruptHandler);
    
    // Enabling ADC interrupt.
    PIE1bits.ADIE = 1;
}

void ADC_SelectChannel(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;    
    // Turn on the ADC module
    ADON = 1;  
}

void ADC_StartConversion(void)
{
    // Start the conversion
    GO_nDONE = 1;
}

bool ADC_IsConversionDone(void)
{
    // Start the conversion
   return ((bool)(!GO_nDONE));
}

adc_result_t ADC_GetConversionResult(void)
{
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

adc_result_t ADC_GetConversion(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;
    
    // Turn on the ADC module
    ADON = 1;

    // Acquisition time delay
    __delay_us(ACQ_US_DELAY);

    // Start the conversion
    GO_nDONE = 1;

    // Wait for the conversion to finish
    while (GO_nDONE)
    {
    }

    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

void ADC_TemperatureAcquisitionDelay(void)
{
    __delay_us(200);
}

void ADC_ISR(void)
{
    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
	
	if(ADC_InterruptHandler)
    {
        ADC_InterruptHandler();
    }
}

void ADC_SetInterruptHandler(void (* InterruptHandler)(void))
{
    ADC_InterruptHandler = InterruptHandler;
}

static void ADC_DefaultInterruptHandler(void)
{
    // add your ADC interrupt custom code
    // or set custom function using ADC_SetInterruptHandler()
}
