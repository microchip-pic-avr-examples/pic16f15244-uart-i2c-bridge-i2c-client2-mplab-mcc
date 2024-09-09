/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APPLICATION_H
#define	APPLICATION_H

#include <xc.h> // include processor files - each processor file is guarded.  

/**
 * **********************************************************
 *  Macros definitions
 * **********************************************************
 **/
//#define DEBUG      //uncomment this to print debug message 
#define TEMP_CONSTANT         (float)(218.75)
#define TEMP_CONSTANT1        (float)(-66.875)
#define VDD                   (float)(3.3)
#define ADC_MAX_VALUE         (1024)
#define ZERO                  (0)
#define ONE                   (1)
#define SET                   (1)
#define CLEAR                 (0)
#define LENGTH                (2)
#define ADC_SAMPLES           (8)
#define SENSOR2_DATA_REGISTER_ADDRESS (*(volatile uint8_t*)0x76u)
#define SENSOR3_DATA_REGISTER_ADDRESS (*(volatile uint8_t*)0x77u)

#define CLOCK_STRETCH_ENABLE()         SSP1CON1bits.CKP = 0;
#define CLOCK_STRETCH_DISABLE()        SSP1CON1bits.CKP = 1;
#define DELAY_FUNCTION()               __delay_ms(1000);

typedef enum
{
    CLIENT2_7_BIT_ADDR = 0x0B,
} client_t;

client_t currentClient;

/**
 * **********************************************************
 *  File Global variables
 * **********************************************************
 **/
uint8_t sensor_Data_Register[2] __at(0x76);
//uint8_t sensor2_Data_Register_Adress[LENGTH] = {0x76};
//uint8_t sensor3_Data_Register_Adress[LENGTH] = {0x77};
uint8_t i2cWrData[LENGTH];
uint8_t i2cWrDataIndex;
uint8_t i2cRdData[LENGTH];
uint8_t i2cRdDataIndex;
uint8_t soilSensor_Value;
uint8_t temp_Value;
uint8_t i2cRxDataLength;
uint8_t i2cRxSensorRegisterAddress;
volatile uint8_t timerInterruptFlag = SET;
volatile uint8_t index = CLEAR;
/**
 * **********************************************************
 *  Function declarations
 * **********************************************************
 **/
void Application(void);
void I2C_WriteInterruptHandler(void);
void I2C_ReadInterruptHandler(void);
void TimerInterruptHandler(void);
void Sensor2_DataProcessing(void);
void Sensor3_DataProcessing(void);
void EUSART1_SendString(const char *str);
void SensorDataRegisterRead(uint8_t *sensorRevdData, uint8_t dataLength);
bool I2C_ClientInterruptHandler(i2c_client_transfer_event_t event);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

