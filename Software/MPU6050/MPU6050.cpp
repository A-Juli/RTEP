#include <iostream>
#include <time.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "MPU6050.h"
#include "MPU6050Register.h"

using namespace std;

MPU6050::MPU6050(short int addr)
{
    DeviceAdd = addr;
}

uint16_t MPU6050::begin()
{
    Setup();
    uint8_t whoAmI = I2CreadByte(DeviceAdd, WHO_AM_I);
    printf("whoAmI: %i", whoAmI);
    
    if (whoAmI != 0x68) {
	    throw "WhoIAm returns wrong result.";
    }


    uint8_t data;
    data = I2CreadByte(DeviceAdd, 0x6B);
    printf("PWR_MGMT_1: %i\n", data);

    data = I2CreadByte(DeviceAdd, 0x6C);
    printf("PWR_MGMT_2: %i\n", data);
    
    data = I2CreadByte(DeviceAdd, 0x1B);
    printf("Gyro_CONFIG: %i\n", data);
    
    data = I2CreadByte(DeviceAdd, 0x1C);
    printf("Accel_CONFIG: %i\n", data);
    // Gyro initialization stuff:
    //initGyro();    // This will "turn on" the gyro. Setting up interrupts, etc.

    // Accelerometer initialization stuff:
    //initAccel(); // "Turn on" all axes of the accel. Set up interrupts, etc.

    // 20ms => 50Hz
    start(500*1000*1000);
    return whoAmI;
}

void MPU6050::end()
{
    stop();
}

void MPU6050::timerEvent()
{
	readAccel();
	readGyro();
	readTemp();
	count++;
	printf("count: %i\n", count);
	MPU6050Callback->hasSample(
					   calcGyro(gx),
					   calcGyro(gy),
					   calcGyro(gz),
					   calcAccel(ax),
					   calcAccel(ay),
					   calcAccel(az),
					   calcTemp(temperature));
}

void MPU6050::readAccel()
{
	short int temp[6] = {0,0,0,0,0,0};
	
	temp[0] = I2CreadByte(DeviceAdd, OUT_X_accel_m);
	temp[1] = I2CreadByte(DeviceAdd, OUT_X_accel_l);
	temp[2] = I2CreadByte(DeviceAdd, OUT_Y_accel_m);
	temp[3] = I2CreadByte(DeviceAdd, OUT_Y_accel_l);
	temp[4] = I2CreadByte(DeviceAdd, OUT_Z_accel_m);
	temp[5] = I2CreadByte(DeviceAdd, OUT_Z_accel_l);
	
	ax = (temp[0] << 8) | temp[1]; 
        ay = (temp[2] << 8) | temp[3]; 
        az = (temp[4] << 8) | temp[5];
}

float MPU6050::calcAccel(int16_t accel)
{
    return accel/16384.0;
}

void MPU6050::readGyro()
{
	short int temp[6] = {0,0,0,0,0,0};
	
	temp[0] = I2CreadByte(DeviceAdd, OUT_X_gyro_m);
	temp[1] = I2CreadByte(DeviceAdd, OUT_X_gyro_l);
	temp[2] = I2CreadByte(DeviceAdd, OUT_Y_gyro_m);
	temp[3] = I2CreadByte(DeviceAdd, OUT_Y_gyro_l);
	temp[4] = I2CreadByte(DeviceAdd, OUT_Z_gyro_m);
	temp[5] = I2CreadByte(DeviceAdd, OUT_Z_gyro_l);
	
	gx = (temp[0] << 8) | temp[1]; 
        gy = (temp[2] << 8) | temp[3]; 
        gz = (temp[4] << 8) | temp[5];
}

float MPU6050::calcGyro(int16_t gyro)
{
    return gyro/131.0;
}

void MPU6050::readTemp()
{
	uint8_t temp[2] = {0,0};
	
	temp[0] = I2CreadByte(DeviceAdd, OUT_Temp_m);
	temp[1] = I2CreadByte(DeviceAdd, OUT_Temp_l);
	temperature = (temp[0] << 8) | temp[1]; 
}

float MPU6050::calcTemp(int16_t temperature)
{
    return temperature/340+36.53;
}

void MPU6050::initI2C()
{

}

void MPU6050::Setup()
{
    wiringPiSetupGpio();
	
    if ((_fd = wiringPiI2CSetup(DeviceAdd)) < 0)
    {
	cout << "Error" << endl;
    }
    
    close(_fd);
    I2CwriteByte(DeviceAdd, 0x6B,0);
    I2CwriteByte(DeviceAdd, 0x1C,0x0);
    
}


void MPU6050::I2CwriteByte(uint8_t address, uint8_t subAddress, uint8_t data)
{
    _fd = wiringPiI2CSetup(address);
    if (_fd < 0) {
        fprintf(stderr, "Error: I2CSetup failed\n");
        exit(EXIT_FAILURE);
    }
    
    wiringPiI2CWriteReg8(_fd, subAddress, data);
    close(_fd);
}

uint8_t MPU6050::I2CreadByte(uint8_t address, uint8_t subAddress)
{
    _fd = wiringPiI2CSetup(address);
    if (_fd < 0) {
        fprintf(stderr, "Error: I2CSetup failed\n");
        exit(EXIT_FAILURE);
    }
    
    uint8_t data; 
    wiringPiI2CWrite(_fd, subAddress);
    data = wiringPiI2CRead(_fd);                
    close(_fd);
    return data;                           
}
