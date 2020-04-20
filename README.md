# Yet Another Glove project 

![](Documentation/graphics/logo.png)

## Description 

Yet Another Glove Project is a wearable glove that is capable of supporting the physiotherapy process by aiding the user in completing exercises for improving finger and tendon strength. 
Using Multiple accelerometer/gyro data, from the MPU6050 sensor, the angle between joint on the hand can be determined and the application will provide the user with feedback showing how close they are to the required angles that the exercise requires. 

The exercises used can be found at Documentation/Exercises.pdf

## Build Intructions 

Install QT5, Qwt and wiringPi

```
sudo apt-get install wiringpi
apt-get install qtdeclaratives5-dev-tools
apt-get install libqwt-qt5-dev
```

Clone this repository 

```
git clone https://github.com/A-Juli/RTEP.git
```

To build 
```
```
## Important Notice - COVID19 lockdown
Due to COVID19 the University of Glasgow was closed and  work on the hardware was halted as access to electronics labs have been restricted.
However, before the lockdown various aspects of the hardware and software were completed. 
### Progress of Hardware (before lockdown) 
For the hardware, the design of circuitry and PCBs were completed for the two boards.
Only one board with the MPU6050 had been fully assembled and tested.
This testing involved reading data for the accelerometer from the buffers which would be needed to calculate the angles in the project.

The board with the I2C multiplexer was assembled and tested.
The board was built in the final week before the university was lockdowned and was not working by the time lockdown occured.
Debugging could not be performed due to lack of access to the electronic labs.
Power was provided to the board but no communication over I2C was achieved between the raspberry pi and the main board.
### Progress of Software (before lockdown) 
For the software, programs had been written that allowed the raspberry pi to communicate over I2C and sample data from the MPU6050 registers using a timer. 
Work had been started on the GUI but no significant progress had been made.
### Future Development
When the lockdown ends development and assembly of hardware can be continued.
This would mainly involve the assembly of more MPU6050 boards which is needed to demonstrate a select set of exercises.

## Authors
* richardajordan: Hardware and Software design 
* basel-shehabi: Software design of GUI
* A-Juli
