#include "newthread.h"
#include "guiwindow.h"
#include "../ExerciseTests.cpp"
#include <QCoreApplication>
#include <QDebug>
#include <QMutex>

newThread::newThread(QObject *parent) : QThread(parent)
{

}

// implementation of run() in order to commence the for loop event/thread.

void newThread::run() {
    ExerciseTests Tests;
    Tests.Exercise1Setup();
    Tests.Exercise2Setup();

    // checks which loop to run based on button pressed

    if(this->flag == 1) {

        for(int counterTwo=0; counterTwo < 19; counterTwo++) {

            /* Mutex objects allow for a single thread to use the objects. This is
             * done such that a user doesn't abuse the button 'Run Again' or cause
             * multiple threads to operate on the same object, overloading the system */


            QMutex mutex;
            mutex.lock();

            // Stops the program to look at a certain angle at some point in time
            if(this->pauseTwo == true) break;

            mutex.unlock();

            Tests.Exercise2();

            double firstAngle,secondAngle,thirdAngle;

            firstAngle = Tests.Angle[0];
            secondAngle = Tests.Angle[1];
            thirdAngle = Tests.Angle[2];

            emit AngleChanged(firstAngle, secondAngle, thirdAngle);

            qDebug() << firstAngle << " : " << secondAngle << " : " << thirdAngle;

            /* Realistically, this thread timer function isn't meant to be implemented
             * (because no hardware) but allows for the user to see the updated angles slowly.
             * Value can be adjusted as required. it is set to millisecs = 1000     */

            this->msleep(1000);
        }

    } else if (this->flag == 2) {

        for(int counterOne=0; counterOne < 10; counterOne++) {

            QMutex mutex;
            mutex.lock();

            // Stops the program to look at a certain angle at some point in time
            if(this->pause == true) break;

            mutex.unlock();

            Tests.Exercise1();
            double ExOneFirstAngle;

            ExOneFirstAngle = Tests.Angle[0];
            emit AngleChangedOne(ExOneFirstAngle);

            qDebug() << ExOneFirstAngle;

            this->msleep(1000);
        }

    }

}
