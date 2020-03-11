#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

#include "MPU6050.h"

class MPU6050printCallback: public MPU6050callback {
    virtual void hasSample(float gx,
			    float gy,
			    float gz,
			    float ax,
			    float ay,
			    float az,
			    float temperature) {
				   
	    float mag = 0;
	    
	    
	    mag = sqrt(ax*ax+ay*ay+az*az);
	    printf("Gyro: %f, %f, %f [deg/s]\n", gx, gy, gz);
	    printf("Accel: %f, %f, %f [Gs]\n", ax, ay, az);
	    printf("Accel mag: %f\n", mag);
	    printf("Temp: %f, [C]\n", temperature);
	    printf("\n");
	    
    }
};

int main(int argc, char *argv[]) {
    MPU6050 imu(0x68);
    MPU6050printCallback callback;
    imu.setCallback(&callback);
    imu.begin();
    do {
	sleep(1);
    } while (imu.count != 10);
    imu.end();
    exit(EXIT_SUCCESS);
}
