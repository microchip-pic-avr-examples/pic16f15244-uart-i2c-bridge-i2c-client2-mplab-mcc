<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# UART-I2C Bridge Implementation: I2C Client(Client#2) Implementation using PIC16F15244 Microcoontroller

In this code example, PIC16F15244 MCU acts as I2C client 2 device and processes periodically acquired sensor data and sends data to the host device through I2C interface. Compatible PIC16F152xx family of MCUs are:PIC16F15214,PIC16F15223,PIC16F15254,PIC16F15276.

Refer GitHub code example [UART-I2C Bridge and I2C Host Implementation using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-and-i2c-host-mplab-mcc) and [UART-I2C Bridge Implementation: I2C Client(Client#1) Implementation using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-i2c-client1-mplab-mcc) for more details about the implementation and application.

## Related Documentation

- [PIC16F15244 Product Family Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic16f15244)
- [PIC16F15244 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=pic16f15244&type=&language=&sort=) 
- [PIC16F15244 MCU Family Video](https://www.youtube.com/watch?v=nHLv3Th-o-s)
- [PIC16F15244 MCU Product Page](https://www.microchip.com/en-us/product/PIC16F15244)
- [Technical Brief - Using the MSSP in I2C Master mode](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1001796)
- [Technical Brief – Using the MSSP in I2C Slave mode](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1001796)
- [Application Note – AN3538 A Simple Water Monitoring System with I2C Communication](https://ww1.microchip.com/downloads/en/Appnotes/A-Simple-Water-Monitoring-System-with%20I2C-Communication-DS00003538A.pdf)

## Description 

In this code example, the PIC16F15244 microcontroller communicate with Data Visualizer terminal window application, running on a PC, through USART interface and receive user inputs/commands. Based on the commands received from the user, the PIC16F15244 microcontroller communicates with the I2C client devices and collect the required sensors data and, transmit to PC for displaying it on the terminal window. This way, the PIC16F15244 microcontroller acts as a EUART-I2C bridge to communicate with Data Visualizer terminal window application and acts as a I2C host device to communicate with the I2C client devices.

The code example uses two I2C clients, named as client 1 and client 2 and, they are based on PIC16F15244 microcontroller. Below Figure 1 shows the block diagram view of the application.

<p align="center">
  <img width=auto height=auto src="images/block diagram.png">
  <br>Figure 1 : Block diagram view of the application<br>
</p>

For the purpose of demonstration, pH sensor is interfaced to client 1 and, temperature and capacitive soil moisture sensors are interfaced to client 2. Both the clients periodically collect data from the sensors, process the acquired data and keep the data ready to transmit to Host device over I2C interface. 

The input commands and clients I2C address information has been displayed on the terminal window of data visualizer. The user needs to enter a client device address from where the sensor data needs to be collected. If the entered client device address is correct, then the next input command, asking the user to enter sensor information from where data needs to be collected, is displayed on the terminal window. After entering the correct sensor information, the host device establishes I2C communication with the respective client device and requests to send the processed sensor data. The client device responds back to host request with the processed sensor data. Upon receiving the sensor data, the host device transmits data to data visualizer tool through UART interface, for displaying it on the terminal window. If the user entered client address or sensor input command is incorrect, then terminal window display the supplied client address or sensor information is incorrect and requests the user to re-enter details.

## Software Used

- [MPLAB® X IDE 5.50 or newer](http://www.microchip.com/mplab/mplab-x-ide)
- [MPLAB® XC8 2.20 or a newer compiler](http://www.microchip.com/mplab/compilers)
- [MPLAB® Code Configurator (MCC) v5.0.3 or newer](https://www.microchip.com/mplab/mplab-code-configurator)
- [MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCU](https://www.microchip.com/mplab/mplab-code-configurator)
- [Microchip PIC16F1xxxx Series Device Support (v1.8.149) or newer](https://packs.download.microchip.com/) 

## Hardware Used

- Curiosity Nano Base for Click boards™[AC164162](https://www.microchip.com/en-us/development-tool/AC164162)
- PIC16F15244 Curiosity Nano Evaluation Kit [EV09Z19A](https://www.microchip.com/en-us/development-tool/EV09Z19A)
- SHT AN Click [MIKROE-3984](https://www.mikroe.com/sht-an-click)
- PH Sensor [EC-4743](https://www.electronicscomp.com/analog-ph-sensor-kit-for-arduino?gclid=EAIaIQobChMIhfv3t-q58QIVu4NLBR2VKQGWEAYYAyABEgKhdPD_BwE)
- Capacitive Soil Moisture Sensor V2.0 [EC-5092](https://www.electronicscomp.com/capacitive-soil-moisture-sensor-v2?gclid=EAIaIQobChMI3YCgheq58QIVxZVLBR1PZQKPEAQYAiABEgJW9_D_BwE)

## Demo Operation

To know about the demo operation, refer GitHub code example [UART-I2C Bridge and I2C Host Implementation using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-and-i2c-host-mplab-mcc)