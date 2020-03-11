#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <thread>
#include "CppTimer.h"
#include "MPU6050Register.h"

using namespace std;


class MPU6050callback {
public:
        /**
         * Called after a sample has arrived.
         **/
        virtual void hasSample(float gx,
			       float gy,
			       float gz,
			       float ax,
			       float ay,
			       float az,
			       float temperature) = 0;
};

class MPU6050: public CppTimer
{
public:

	int count = 0;
	int16_t ax;
	int16_t ay;
	int16_t az;
	int16_t gx;
	int16_t gy;
	int16_t gz;
	int16_t temperature;
	short int whoAmI;
	
	int DeviceAdd; 
	

	MPU6050(short int addr);
	
	void readAccel();
	void readGyro();
	void readTemp();
	
	float calcGyro(int16_t gyro);
	float calcAccel(int16_t accel);
	float calcTemp(int16_t temperature);
	
	void Setup();
	uint16_t begin();
	void end();
	
	void setCallback(MPU6050callback* cb) {
		MPU6050Callback = cb;
	}
	
protected:
	int _fd;
	
	void initAccel();
	
	void initI2C();
    
	// I2CwriteByte() -- Write a byte out of I2C to a register in the device
	// Input:
	//    - address = The 7-bit I2C address of the slave device.
	//    - subAddress = The register to be written to.
	//    - data = Byte to be written to the register.
	void I2CwriteByte(uint8_t address, uint8_t subAddress, uint8_t data);
    
	// I2CreadByte() -- Read a single byte from a register over I2C.
	// Input:
	//    - address = The 7-bit I2C address of the slave device.
	//    - subAddress = The register to be read from.
	// Output:
	//    - The byte read from the requested address.
	uint8_t I2CreadByte(uint8_t address, uint8_t subAddress);
	
	MPU6050callback* MPU6050Callback = NULL;
	void timerEvent();
};
