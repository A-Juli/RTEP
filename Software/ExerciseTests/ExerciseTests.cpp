#include <iostream>
#include <math.h>
#include "ExerciseTests.h"

#define pie 3.14159265

using namespace std;

double ExerciseTests::Exercise1(void)
{
    
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

    DotProduct = Accel1[0]*Accel2[0] + Accel1[1]*Accel2[1] + Accel1[2]*Accel2[2];
    MagAccel1 = sqrt(Accel1[0]*Accel1[0]+Accel1[1]*Accel1[1]+Accel1[2]*Accel1[2]); 
    MagAccel2 = sqrt(Accel2[0]*Accel2[0]+Accel2[1]*Accel2[1]+Accel2[2]*Accel2[2]);
    Angle = acos(DotProduct/(MagAccel1*MagAccel2));
    Angle = Angle*180/pie;

    return DotProduct;
}

float ExerciseTests::DotProductCalc()
{
    DotProduct = Accel1[0]*Accel2[0] + Accel1[1]*Accel2[1] + Accel1[2]*Accel2[2];
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

ExerciseTests::ExerciseTests()
{
    cout << "Class constructor" << endl; 
}
