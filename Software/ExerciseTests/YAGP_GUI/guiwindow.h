#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include "newthread.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QDialog>
#include <QBoxLayout>
#include <QGroupBox>

// Declares QWidget objects etc...
class GUIWindow : public QWidget
{
    Q_OBJECT
public:
    QGroupBox *firstGroupBox();
    QGroupBox *secondGroupBox();

    newThread *Thread;
    explicit GUIWindow(QWidget *parent = nullptr);

    QPushButton *startButtonOne;
    QPushButton *pauseButtonOne;
    QPushButton *startButtonTwo;
    QPushButton *pauseButtonTwo;

    QLabel *targetAngleOne_label;
    QLabel *targetAngleTwo_label;
    QLabel *ExOneAngle_labelOne;
    QLabel *angle_labelOne;
    QLabel *angle_labelTwo;
    QLabel *angle_labelThree;

private:
signals:

public slots:
    void onAngleChanged(double, double, double); // Used to update the changed angle to pass onto the GUI
    void onAngleChangedOne(double); // Used to update first exercise angle to pass onto GUI

private slots:
    void slotStartButtonOneClicked(bool checked); // starts the program with a button using custom signal/slot system
    void slotPauseButtonOneClicked(bool checked); // pauses/stops the program
    void slotStartButtonTwoClicked(bool checked); // starts the program with a button using custom signal/slot system
    void slotPauseButtonTwoClicked(bool checked); // pauses/stops the program
};

#endif // GUIWINDOW_H
