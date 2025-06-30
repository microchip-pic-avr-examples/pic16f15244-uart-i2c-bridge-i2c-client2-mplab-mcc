/**
 * MSSP1 Generated Driver API Header File
 *
 * @file mssp1.h
 *
 * @defgroup i2c_client I2C1_CLIENT
 *
 * @brief This file contains API prototypes and other data types for the I2C1 module.
 *
 * @version I2C1 Driver Version 2.1.0
 */

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef MSSP1_H
#define MSSP1_H

#include <stdbool.h>
#include <stdint.h>
#include "i2c_client_interface.h"

/**
 Section: Data Type Definitions
*/
#define i2c1_client_client_interface I2C1_Client


#define I2C1_Client_Initialize I2C1_Initialize
#define I2C1_Client_Deinitialize I2C1_Deinitialize
#define I2C1_Client_WriteByte I2C1_WriteByte
#define I2C1_Client_ReadByte I2C1_ReadByte
#define I2C1_Client_ReadAddr I2C1_ReadAddr
#define I2C1_Client_ErrorGet I2C1_ErrorGet
#define I2C1_Client_TransferDirGet I2C1_TransferDirGet
#define I2C1_Client_LastByteAckStatusGet I2C1_LastByteAckStatusGet
#define I2C1_Client_CallbackRegister I2C1_CallbackRegister
#define I2C1_Client_Tasks I2C1_Tasks
/**
 * @ingroup i2c_client
 * @brief External object for I2C1_Client
 */
extern const struct I2C_CLIENT_INTERFACE I2C1_Client;

/**
 * @ingroup i2c_client
 * @brief Initializes the I2C1 module.
 *        This routine will be called before any other I2C1 routine is called.
 *        This routine will only be called once during system initialization.
 * @param None.
 * @return None.
 */
void I2C1_Initialize(void);

/**
 * @ingroup i2c_client
 * @brief Deinitializes the I2C1 module.
 *        This routine disables the I2C1 module.
 * @param None.
 * @return None.
 */
void I2C1_Deinitialize(void);

/**
 * @ingroup i2c_client
 * @brief Writes data to a host on the bus.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param [in] wrByte - I2C1 client write byte
 * @return None.
 */
void I2C1_WriteByte(uint8_t wrByte);

/**
 * @ingroup i2c_client
 * @brief Reads data from a host on the bus.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @return data byte -I2C1 client read byte
 */
uint8_t I2C1_ReadByte(void);

/**
 * @ingroup i2c_client
 * @brief Reads requested address from a host on the bus.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @return address byte -I2C1 client read byte
 */
uint16_t I2C1_ReadAddr(void);

/**
 * @ingroup i2c_client
 * @brief Gets the error occurred during I2C Transmit and Receive.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @retval
 *        I2C_CLIENT_ERROR_BUS_COLLISION    - I2C Bus Collision Error
 *        I2C_CLIENT_ERROR_WRITE_COLLISION  - I2C Write Collision Error
 *        I2C_CLIENT_ERROR_RECEIVE_OVERFLOW - I2C Receive overflow
 *        I2C_CLIENT_ERROR_NONE             - No Error
 */
i2c_client_error_t I2C1_ErrorGet(void);

/**
 * @ingroup i2c_client
 * @brief Gets the I2C Transfer direction.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @retval
 *        I2C_CLIENT_TRANSFER_DIR_WRITE  - I2C Host is writing to client
 *        I2C_CLIENT_TRANSFER_DIR_READ   - I2C Host is reading from client
 */
i2c_client_transfer_dir_t I2C1_TransferDirGet(void);

/**
 * @ingroup i2c_client
 * @brief Gets the I2C Host ACK status.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @retval
 *        I2C_CLIENT_ACK_STATUS_RECEIVED_ACK   - I2C Host is send ACK to client
 *        I2C_CLIENT_ACK_STATUS_RECEIVED_NACK  - I2C Host is send NACK to client
 */
i2c_client_ack_status_t I2C1_LastByteAckStatusGet(void);

/**
 * @ingroup i2c_client
 * @brief Sets the pointer to be called "back" when
 *        the given I2C transfer events, Bus collision and Write collision occur.
 * @param handler - A pointer to a function that will be called when a client transfer event occurs.
 * @return None.
 */
void I2C1_CallbackRegister(bool (*callback)(i2c_client_transfer_event_t clientEvent));

/**
 * @ingroup i2c_client
 * @brief Common ISR function for all I2C1 interrupts.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void I2C1_ISR(void);

/**
 * @ingroup i2c_client
 * @brief Common ISR function for all I2C1 error interrupts.
 *        I2C1 should be intitialized with I2C1_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void I2C1_ERROR_ISR(void);


#endif //MSSP1_H
