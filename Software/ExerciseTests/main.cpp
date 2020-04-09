#include <iostream>
#include "ExerciseTests.h"

using namespace std;

int main()
{
    int q = 0;
    ExerciseTests Test;   //Declare Box1 of type box

    //Box1 Specification
    Test.setAccel1(0,0,1);
    Test.setAccel2(0,0,1);

    //Instead of loop us a timer to call whichever Exercise every 50ms
    cout << "beginning of exercise 1" << endl; 
    for(q=0;q < 10;q++)
    {
        Test.Exercise1();
        cout << "Dot Product is : " << Test.DotProduct << endl;
        cout << "Angle between vectors: " << Test.Angle << endl;
    }

    return 0;
}

