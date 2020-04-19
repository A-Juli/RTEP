# Hardware

This project contains three main pieces of hardware.
The Raspberry Pi model B+, a 6D sensor board design are the MPU6050 and a main board with I2C muiltiplexers.

## Overview
This folder contains:
*The main board which is based around the PCA9546AD I2C multiplexer
*The MPU6050 (gyro/accelerometer) board 

## Description 
### MMPU6050 Board

MPU6050 board was designed so that it was physically small enough to fit on the joints of the fingers.
The board connects to one of the 4 pin headers located on the main board which provide 5V, ground, SDA and SCL. 

### Main Board

the main board was designed around two PCA9546AD I2C multiplexers, each providing 4 channels. 
This gives 8 different I2C channels and so 16 MPU6050 boards can be accessed by the raspberry pi. The header on the main board takes 5V, GND, SDA and SCL from the raspberry pi.
