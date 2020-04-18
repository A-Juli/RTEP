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

         double Angle[10] = {0,0,0,0,0,0,0,0,0,0};
         double DotProduct[10] = {0,0,0,0,0,0,0,0,0,0};
         double TargetAngle[10] = {0,0,0,0,0,0,0,0,0,0};
         double NumAccel = 0;

         ExerciseTests(void);
         double Exercise1(void); 
         double Exercise2(void);

         void Exercise1Setup(void);
         void Exercise2Setup(void);

         void setAccel1(float x, float y,float z);
         void setAccel2(float x, float y,float z);
         void setAccel3(float x, float y,float z);
         void setAccel4(float x, float y,float z);

     private:
        float DotProductCalc(void);
 };