#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QThread>

class newThread : public QThread
{
    Q_OBJECT
public:
    explicit newThread(QObject *parent = nullptr);
    void run();
    bool pause;
signals:
    void AngleChanged(double, double, double); // used to update every loop iteration

public slots:

};

#endif // NEWTHREAD_H
