#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QThread>

class newThread : public QThread
{
    Q_OBJECT
public:
    explicit newThread(QObject *parent = nullptr);
    void run();
    int flag; // flag that allows which loop to runs in the newThread.cpp
    bool pause;
    bool pauseTwo;
signals:
    void AngleChanged(double, double, double); // used to update every loop iteration
    void AngleChangedOne(double); // likewise but for first exercise

public slots:

};

#endif // NEWTHREAD_H
