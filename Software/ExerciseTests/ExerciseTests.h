#include <iostream>
#include <math.h>
 
 class ExerciseTests
 {
     public:
        //Storage of Accelerometer data for unit test
        double Accel1[3];
        double Accel2[3];
        double Accel3[3];
        double Accel4[3];

        double Angle;
        double DotProduct;

        ExerciseTests(void);
        double Exercise1(void); 
        void setAccel1(float x, float y,float z);
        void setAccel2(float x, float y,float z);
       

     private:
        float DotProductCalc(void);

 };