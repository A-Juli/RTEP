#include <iostream>
#include <math.h>
#include "ExerciseTests.h"

#define pie 3.14159265

using namespace std;

void ExerciseTests::Exercise1Setup(void)
{
    TargetAngle[0] = 90;
    NumAccel = 2;
}

void ExerciseTests::Exercise2Setup(void)
{
    TargetAngle[0] = 0;
    TargetAngle[1] = 90;
    TargetAngle[2] = 90;
    NumAccel = 4;
}

double ExerciseTests::Exercise1(void)
{
    //Two MPU6050 needed for this exercise
    float MagAccel1;
    float MagAccel2;

    Accel1[1] = Accel1[1] + 0.1;
    Accel1[2] = Accel1[2] - 0.1;

    if(Accel1[1] > 1)
    {
        Accel1[1] = 0;
        Accel1[2] = 1;
        cout << Accel1[1] << endl;
    }    

    DotProduct[0] = Accel1[0]*Accel2[0] + Accel1[1]*Accel2[1] + Accel1[2]*Accel2[2];
    MagAccel1 = sqrt(Accel1[0]*Accel1[0]+Accel1[1]*Accel1[1]+Accel1[2]*Accel1[2]); 
    MagAccel2 = sqrt(Accel2[0]*Accel2[0]+Accel2[1]*Accel2[1]+Accel2[2]*Accel2[2]);
<<<<<<< HEAD
    Angle = acos(DotProduct/(MagAccel1*MagAccel2));
    Angle = Angle*180/pie;
=======
    Angle[0] = acos(DotProduct[0]/(MagAccel1*MagAccel2));
    Angle[0] = Angle[0]*180/pi;
>>>>>>> master

    return DotProduct[0];
}

double ExerciseTests::Exercise2(void)
{
    //Four MPU6050 circuits boards needed for this exercise 
    float MagAccel1;
    float MagAccel2;
    float MagAccel3;
    float MagAccel4;
    int i = 0;


    if(Accel3[2]>0.1)
    {
        Accel4[1] = Accel4[1] + 0.1;
        Accel4[2] = Accel4[2] - 0.1;
        Accel3[1] = Accel3[1] + 0.1;
        Accel3[2] = Accel3[2] - 0.1;
    }
    
    if(Accel3[2] <0.1)
    {   
        Accel4[1] = Accel4[1] - 0.1;
        Accel4[2] = Accel4[2] - 0.1;
    }

    DotProduct[0] = Accel1[0]*Accel2[0] + Accel1[1]*Accel2[1] + Accel1[2]*Accel2[2];
    DotProduct[1] = Accel3[0]*Accel2[0] + Accel3[1]*Accel2[1] + Accel3[2]*Accel2[2];
    DotProduct[2] = Accel3[0]*Accel4[0] + Accel3[1]*Accel4[1] + Accel3[2]*Accel4[2];

    MagAccel1 = sqrt(Accel1[0]*Accel1[0]+Accel1[1]*Accel1[1]+Accel1[2]*Accel1[2]); 
    MagAccel2 = sqrt(Accel2[0]*Accel2[0]+Accel2[1]*Accel2[1]+Accel2[2]*Accel2[2]);
    MagAccel3 = sqrt(Accel3[0]*Accel3[0]+Accel3[1]*Accel3[1]+Accel3[2]*Accel3[2]); 
    MagAccel4 = sqrt(Accel4[0]*Accel4[0]+Accel4[1]*Accel4[1]+Accel4[2]*Accel4[2]);

    Angle[0] = acos(DotProduct[0]/(MagAccel1*MagAccel2));
    Angle[1] = acos(DotProduct[1]/(MagAccel1*MagAccel2));
    Angle[2] = acos(DotProduct[2]/(MagAccel1*MagAccel2));

    Angle[0] = Angle[0]*180/pi;
    Angle[1] = Angle[1]*180/pi;
    Angle[2] = Angle[2]*180/pi;

    return DotProduct[0];
}

void ExerciseTests::setAccel1(float x, float y, float z)
{
    Accel1[0] = x;
    Accel1[1] = y;
    Accel1[2] = z;
}

void ExerciseTests::setAccel2(float x, float y,float z)
{
    Accel2[0] = x;
    Accel2[1] = y;
    Accel2[2] = z;
}

void ExerciseTests::setAccel3(float x, float y,float z)
{
    Accel3[0] = x;
    Accel3[1] = y;
    Accel3[2] = z;
}

void ExerciseTests::setAccel4(float x, float y,float z)
{
    Accel3[0] = x;
    Accel3[1] = y;
    Accel3[2] = z;
}

ExerciseTests::ExerciseTests()
{
    cout << "Class constructor" << endl; 
}
