#include "guiwindow.h"
#include "newthread.h"
#include <QApplication>
#include <QThread>

GUIWindow::GUIWindow(QWidget *parent) : QWidget(parent)
{
    // Setup widgets, threads, custom parameters etc..
    setFixedSize(1200,600);
    Thread = new newThread(this);
    QGridLayout *Grid = new QGridLayout;
    Grid->addWidget(firstGroupBox());
    Grid->addWidget(secondGroupBox());
    setLayout(Grid);
    setWindowTitle(tr("Exercise Simulation"));


    // Setup signal and slots connection for buttons and threads

    connect(startButtonOne, SIGNAL (clicked(bool)),
            this, SLOT (slotStartButtonOneClicked(bool)));
    connect(Thread, SIGNAL (AngleChangedOne(double)),
            this, SLOT (onAngleChangedOne(double)));
    connect(pauseButtonOne, SIGNAL (clicked(bool)),
            this, SLOT (slotPauseButtonOneClicked(bool)));


    connect(startButtonTwo, SIGNAL (clicked(bool)),
            this, SLOT (slotStartButtonTwoClicked(bool)));
    connect(Thread, SIGNAL (AngleChanged(double, double, double)),
            this, SLOT (onAngleChanged(double, double, double)));
    connect(pauseButtonTwo, SIGNAL (clicked(bool)),
            this, SLOT (slotPauseButtonTwoClicked(bool)));
}

// Implements the Layout boxes for better UI experience

QGroupBox *GUIWindow::firstGroupBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("First Exercise \n"));
    targetAngleOne_label = new QLabel("Target Angle should be: 90 \n\n");
    ExOneAngle_labelOne = new QLabel("Angle Value");

    startButtonOne = new QPushButton("Start First Exercise", this);
    startButtonOne->setCheckable(true);

    pauseButtonOne = new QPushButton("Pause", this);
    pauseButtonOne->setCheckable(true);

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(targetAngleOne_label);
    vbox->addWidget(ExOneAngle_labelOne);
    vbox->addWidget(startButtonOne, 0);
    vbox->addWidget(pauseButtonOne, 0);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *GUIWindow::secondGroupBox()
{

    QGroupBox *groupBox = new QGroupBox(tr("Second Exercise \n\n"));
    targetAngleTwo_label = new QLabel("Target Angle should be: 0 : 90 : 90 \n\n");
    angle_labelOne = new QLabel("First Angle Value goes here: \n\n");
    angle_labelTwo = new QLabel("Second Angle Value goes here: \n\n");
    angle_labelThree = new QLabel("Third Angle Value goes here: \n\n");

    startButtonTwo = new QPushButton("Start Second Exercise", this);
    startButtonTwo->setCheckable(true);

    pauseButtonTwo = new QPushButton("Pause", this);
    pauseButtonTwo->setCheckable(true);

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(targetAngleTwo_label);
    vbox->addWidget(angle_labelOne);
    vbox->addWidget(angle_labelTwo);
    vbox->addWidget(angle_labelThree);
    vbox->addWidget(startButtonTwo, 0);
    vbox->addWidget(pauseButtonTwo, 0);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

// Allows for thread to speak/communicate to main QWidget/GUI Thread using slots

void GUIWindow::onAngleChangedOne(double ExOneAngleOne) {
    ExOneAngle_labelOne->setNum(ExOneAngleOne);
    startButtonTwo->setEnabled(true);
}

void GUIWindow::onAngleChanged(double angleOne, double angleTwo, double angleThree) {
    angle_labelOne->setNum(angleOne);
    angle_labelTwo->setNum(angleTwo);
    angle_labelThree->setNum(angleThree);
    startButtonTwo->setEnabled(true);
}

// Implementation for button slots to allow for clicking, etc...

void GUIWindow::slotStartButtonOneClicked(bool checked)
{
    if(checked){
        Thread->pause = false;
        Thread->flag = 2;
        Thread->start();
        startButtonOne->setText("Run Again");
    }
}

void GUIWindow::slotPauseButtonOneClicked(bool checked)
{
    if(checked){
        Thread->pause = true;
        pauseButtonOne->setText("Unpause");
    } else {
        Thread->pause = false;
        pauseButtonOne->setText("Pause");
    }
}

void GUIWindow::slotStartButtonTwoClicked(bool checked)
{
    if(checked){
        Thread->pauseTwo = false;
        Thread->flag = 1;
        Thread->start();
        startButtonTwo->setText("Run Again");
    }
}

void GUIWindow::slotPauseButtonTwoClicked(bool checked)
{
    if(checked){
        Thread->pauseTwo = true;
        pauseButtonTwo->setText("Unpause");
    } else {
        Thread->pauseTwo = false;
        pauseButtonTwo->setText("Pause");
    }
}
