#include "newthread.h"
#include "guiwindow.h"
#include "../ExerciseTests.cpp"
#include <QCoreApplication>
#include <QDebug>
#include <QMutex>

newThread::newThread(QObject *parent) : QThread(parent)
{

}

// implementation of run() in order to commence the for loop thread.

void newThread::run() {
    ExerciseTests Tests;

    Tests.Exercise2Setup();

    for(int q=0; q < 19; q++) {

        /* Mutex objects allow for a single thread to use the objects. This is
         * done such that a user doesn't abuse the button 'Run Again' or cause
         * multiple threads to operate on the same object, overloading the system */


        QMutex mutex;
        mutex.lock();

        // Stops the program to look at a certain angle at some point in time
        if(this->pause == true) break;
        mutex.unlock();

        Tests.Exercise2();

        double firstAngle,secondAngle,thirdAngle;

        firstAngle = Tests.Angle[0];
        secondAngle = Tests.Angle[1];
        thirdAngle = Tests.Angle[2];

        emit AngleChanged(firstAngle, secondAngle, thirdAngle);

        qDebug() << firstAngle << " : " << secondAngle << " : " << thirdAngle;

        /* Realistically, this thread timer function isn't meant to be implemented
         * but allows for the user to see the updated angles slowly.
         * Value can be adjusted as required. it is set to millisecs = 1000     */

        this->msleep(1000);

    }
}
