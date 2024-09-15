<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# UART-I2C Bridge Implementation: I2C Client (Client-2) Implementation Using PIC16F15244 Microcoontroller

This code example is a good use case to demonstrate UART-I2C bridge implementation using the PIC16F152XX family of microcontrollers. In this code example, the PIC16F15244 MCU acts as device 2 for the I2C client. It periodically collects the data from the sensor, processes the acquired data and keeps the data ready to transmit to Host device over the I2C interface. When the Host device requests to send the processed sensor data, then client device responds back to host request with the processed data through the I2C interface. After receiving the data from the client device, the host device displays the data on the terminal window.

Refer to the GitHub code example [UART-I2C Bridge and I2C Host Implementation Using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-and-i2c-host-mplab-mcc) and [UART-I2C Bridge Implementation: I2C Client(Client-1) Implementation Using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-i2c-client1-mplab-mcc) for more details about the implementation and application.

## Related Documentation

- [PIC16F152xx Product Family Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic16f15244?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC16F15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08)
- [PIC16F152xx Family Code Examples on GitHub](https://github.com/orgs/microchip-pic-avr-examples/repositories?q=pic16f152&type=all&language=&sort=) 
- [PIC16F15244 MCU Family Video](https://www.youtube.com/watch?v=nHLv3Th-o-s)
- [PIC16F15244 MCU Product Page](https://www.microchip.com/wwwproducts/en/PIC16F15244?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC16F15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08)
- [Technical Brief - Using the MSSP in I2C Master mode](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1001796)
- [Technical Brief – Using the MSSP in I2C Slave mode](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1001796)
- [Application Note – AN3538 A Simple Water Monitoring System with I2C Communication](https://ww1.microchip.com/downloads/en/Appnotes/A-Simple-Water-Monitoring-System-with%20I2C-Communication-DS00003538A.pdf)

## Description 

In this code example, the PIC16F15244 microcontroller communicates with the Data Visualizer terminal window application, running on a PC, through the USART interface and receive user inputs/commands. Based on the commands received from the user, the PIC16F15244 microcontroller communicates with the I2C client devices and collects the required sensors data and, transmitting to PC for displaying it on the terminal window. This way, the PIC16F15244 microcontroller acts as a EUART-I2C bridge to communicate with the Data Visualizer terminal window application and acts as a I2C host device to communicate with the I2C client devices.

The code example uses two I2C clients, named Client 1 and Client 2 and, they are based on PIC16F15244 microcontroller. Figure 1 shows the block diagram view of the application.

<p align="left">
  <img width=auto height=auto src="images/block diagram.png">
  <br>Figure 1 : Block diagram view of the application<br>
</p>

For demonstration purposes, the pH sensor is interfaced to Client 1 and, temperature and capacitive soil moisture sensors are interfaced to Client 2. Both clients periodically collect data from the sensors, process the acquired data and keep the data ready to transmit to the Host device over the I2C interface. 

The input commands and I2C clients address information have been displayed on the terminal window of the data visualizer. The user needs to enter a client device address from where the sensor data needs to be collected. If the entered client device address is correct, then the next input command, asking the user to enter sensor information from where data needs to be collected, is displayed on the terminal window. After entering the correct sensor information, the host device establishes the I2C communication with the respective client device and requests to send the processed sensor data. The client device responds to the host request with the processed sensor data. Upon receiving the sensor data, the host device transmits data to the Data Visualizer tool through the UART interface, for displaying it on the terminal window. If the user entered the client address or if the sensor input command is incorrect, then the terminal window displays if the supplied client address or if the sensor information is incorrect and requests the user to re-enter details.

## Software Used

- [MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC16F15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08) 6.20 or newer
- [MPLAB® XC8 Compiler](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC16F15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08) 2.50 or newer
- [MPLAB® Code Configurator (MCC)](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC16F15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08) 5.7.1 or newer
- [Microchip PIC16F1xxxx Series Device Support](https://packs.download.microchip.com/) 1.25.389 or newer
- MSSP MCC Melody Core 7.0.1
- ADC MCC Melody Core 3.0.10
- TMR0 MCC Melody Core 4.0.13
- UART MCC Melody Core 1.10.0 

## Hardware Used

- Curiosity Nano Base for Click boards™[AC164162](https://www.microchip.com/en-us/development-tool/AC164162?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_PIC16F15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08)
- PIC16F15244 Curiosity Nano Evaluation Kit [EV09Z19A](https://www.microchip.com/en-us/development-tool/EV09Z19A?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_pic16f15244&utm_content=pic16f15244-uart-i2c-bridge-i2c-client2-mplab-mcc-github&utm_bu=MCU08)
- SHT AN Click [MIKROE-3984](https://www.mikroe.com/sht-an-click)
- PH Sensor [EC-4743](https://www.electronicscomp.com/analog-ph-sensor-kit-for-arduino?gclid=EAIaIQobChMIhfv3t-q58QIVu4NLBR2VKQGWEAYYAyABEgKhdPD_BwE)
- Capacitive Soil Moisture Sensor V2.0 [EC-5092](https://www.electronicscomp.com/capacitive-soil-moisture-sensor-v2?gclid=EAIaIQobChMI3YCgheq58QIVxZVLBR1PZQKPEAQYAiABEgJW9_D_BwE)

## Demo Operation

To know about the demo operation, refer to the GitHub code example [UART-I2C Bridge and I2C Host Implementation using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-and-i2c-host-mplab-mcc)