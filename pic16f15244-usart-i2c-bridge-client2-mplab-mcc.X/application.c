#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adc/adc.h"
#include "application.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

/*******************************************************************************
 * void Application(void)
 *
 * API which measures the connected ph sensor data through ADC interface periodically. 
 * By default Slave will be in the sleep mode and it wakes up after every 5sec using
 * Timer interrupt or whenever I2C start condition is detected.
 *
 * @param void 
 * @return void
 ******************************************************************************/
void Application(void)
{
     //To read the sensor data periodically for every 5 sec
    if(timerInterruptFlag == SET)
    { 
#ifdef DEBUG 
            EUSART1_SendString("Timer WakeUP\n");  // only for debug
#endif
        Sensor2_DataProcessing(); //Read Analog Sensor 2 and calibration
        Sensor3_DataProcessing(); //Read Analog Sensor 3 and calibration
        timerInterruptFlag = CLEAR;
    }
    else if(SSP1STATbits.I2C_START)
    {
#ifdef DEBUG 
            EUSART1_SendString(" I2C WakeUP\n");    //only for debug
#endif
        if(i2cRdDataIndex >= LENGTH)
        {
            CLOCK_STRETCH_ENABLE(); 
            i2cRxDataLength = i2cRdData[ONE];
            i2cRxSensorRegisterAddress = i2cRdData[ZERO];
            SensorDataRegisterRead(i2cRxSensorRegisterAddress,i2cRxDataLength);
            i2cWrDataIndex = 0;
            CLOCK_STRETCH_DISABLE(); 
            i2cRdDataIndex = ZERO;
            DELAY_FUNCTION();
        }
    }
    else
    {
     //   SLEEP();
    }
  
}

/*******************************************************************************
 * void EUSART1_SendString(const char *str)
 *
 * API to print a sequence of characters on the terminal window
 * 
 * @param *str - to send a sequence of strings on terminal window
 * @return void
 ******************************************************************************/
void EUSART1_SendString(const char *str)
{
    for(uint8_t index = 0; index < strlen(str); index++)
    {
        EUSART1_Write(str[index]);
    }
}

/*******************************************************************************
 * void SensorDataRegisterAddrMatch(uint8_t *sensorDataAddress)
 *
 * API which reads the data stored in static RAM location into an i2cWrData buffer 
 * which is transmitted to the host through i2c interface
 * 
 * @param *sensorDataAddress - holds the sensor data register address sent from the 
 *                             host device 
 * @return void
 ******************************************************************************/
void SensorDataRegisterRead(uint8_t *sensorRevdData, uint8_t dataLength)
{
    uint8_t index = 0;
    
    //Clears the i2cWrData array
    memset((uint8_t*)i2cWrData, 0 , sizeof(i2cWrData));
    
    for( index = 0;index < dataLength;index++)
    {
         i2cWrData[index] = *(sensorRevdData+index); 
    }
}

/*******************************************************************************
 * void Sensor2_DataProcessing(void)
 *
 * API to measure the temperature sensor through ADC interface and calculate 
 * the temperature value using the formula. Store the temperature value in static RAM 
 * location.
 * 
 * @param void 
 * @return void
 ******************************************************************************/
void Sensor2_DataProcessing(void)
{
    uint16_t adcBuffer = 0;
    float dataBuffer = 0;
    float buffer = 0;
    
    adcBuffer = ADC_GetConversion(channel_ANB7);
    dataBuffer = (((float)adcBuffer/ADC_MAX_VALUE )* VDD);
    buffer =  ((dataBuffer / VDD) * TEMP_CONSTANT);
    temp_Value = (uint8_t)(TEMP_CONSTANT1 + buffer);
    sensor_Data_Register[ZERO]= temp_Value;   
}

/*******************************************************************************
 * void Sensor3_DataProcessing(void)
 *
 * API to measure the Soil moisture sensor data through ADC interface and calculate 
 * the soil moisture value using the formula. Store the soil moisture value in 
 * static RAM location.
 * 
 * @param void 
 * @return void
 ******************************************************************************/
void Sensor3_DataProcessing(void)
{
    uint16_t adcBuffer = 0;
    float dataBuffer = 0;
    float  buffer = 0;
 
    adcBuffer = ADC_GetConversion(channel_ANC4);
    dataBuffer = ADC_MAX_VALUE - adcBuffer;
    buffer = (dataBuffer / (ADC_MAX_VALUE-1));
    soilSensor_Value = (uint8_t)(buffer * 100);
    sensor_Data_Register[ONE] = soilSensor_Value;
}

/*******************************************************************************
 * void TimerInterruptHandler(void)
 *
 * API to handle Timer interrupt, which generates interrupt for every 5 sec.
 * 
 * @param void 
 * @return void
 ******************************************************************************/
void TimerInterruptHandler(void)
{
    timerInterruptFlag = SET;
}  

/*******************************************************************************
 * bool I2C_ClientInterruptHandler(i2c_client_transfer_event_t event)
 *
 * API to handle I2C Read and Write Interrupt handler
 * 
 * @param void 
 * @return void
 ******************************************************************************/
bool I2C_ClientInterruptHandler(i2c_client_transfer_event_t event)
{
   
    switch (event)
    {
    case I2C_CLIENT_TRANSFER_EVENT_ADDR_MATCH:
        
        if (I2C1_TransferDirGet() == I2C_CLIENT_TRANSFER_DIR_WRITE)
        {
            if (I2C1_ReadAddr() ==  CLIENT2_7_BIT_ADDR)
            {
                currentClient =  CLIENT2_7_BIT_ADDR;   
            }
        }
        break;

    case I2C_CLIENT_TRANSFER_EVENT_RX_READY:
        if(currentClient ==  CLIENT2_7_BIT_ADDR)
        {
            
            {
                i2cRdData[i2cRdDataIndex++] = I2C1_ReadByte();
            } 
        }
        break;
    case I2C_CLIENT_TRANSFER_EVENT_TX_READY:
        if(currentClient ==  CLIENT2_7_BIT_ADDR)
        {   
            for( uint8_t index = 0;index < i2cRxDataLength;index++)
            {
                I2C1_WriteByte(i2cWrData[index]);
            }
            i2cRxDataLength = 0; 
        }
        break;
            
    case I2C_CLIENT_TRANSFER_EVENT_STOP_BIT_RECEIVED:
          //  i2cRdDataIndex = 0x00;
        break;

    default:
        break;
    }
    return true;
}

/**
 End of File
*/
