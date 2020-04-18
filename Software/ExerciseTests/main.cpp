#include <iostream>
#include <math.h>
#include "ExerciseTests.h"


using namespace std;

int main()
{
    int q = 0;
    ExerciseTests Test;
    
    // Exercise One

    //Test.setAccel1(0,0,1);
    //Test.setAccel2(0,0,1);

    //Instead of loop us a timer to call whichever Exercise every 50ms
    cout << "Beginning of Exercise 1" << endl; 
    Test.Exercise1Setup();
    cout << "Target Angle: " << Test.TargetAngle[0] << endl;

    for(q=0;q < 10;q++)
    {
        Test.Exercise1();
        cout << "Angle between vectors: " << Test.Angle[0] << endl;
    }

    //Exercise 2

    //Test.setAccel1(0,0,1);
    //Test.setAccel2(0,0,1);
    //Test.setAccel3(0,0,1);
    //Test.setAccel4(0,0,1);

    cout << "Beginning of Exercise 2" << endl;
    Test.Exercise2Setup();
    cout << "Target Angle: " << Test.TargetAngle[0] << " : " << Test.TargetAngle[1] << " : " << Test.TargetAngle[2] << " : " << endl;

    for(q=0;q < 19;q++)
    {
        Test.Exercise2();
        cout << "Angle between vectors: " << Test.Angle[0] << " : " << Test.Angle[1] << " : " << Test.Angle[2] <<  endl;
        //cout << "Dot Product" << Test.DotProduct[0] << " : " << Test.DotProduct[1] << " : " << Test.DotProduct[2] << endl;
    }
}

