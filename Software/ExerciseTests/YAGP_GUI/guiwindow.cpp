#include "guiwindow.h"
#include "newthread.h"
#include <QApplication>
#include <QThread>

GUIWindow::GUIWindow(QWidget *parent) : QWidget(parent)
{
    // Setup widgets, threads, custom parameters etc..
    setFixedSize(800,400);
    Thread = new newThread(this);

    startButton = new QPushButton("Start Program", this);
    //startButton->setGeometry();
    startButton->setCheckable(true);

    pauseButton = new QPushButton("Pause", this);
    //pauseButton->setGeometry();
    pauseButton->setCheckable(true);

    angle_labelOne = new QLabel(this);
    angle_labelTwo = new QLabel(this);
    angle_labelThree = new QLabel(this);

    angle_labelOne->setText("Angle Values go here: \n\n");
    angle_labelTwo->setText("Angle Values two go here: \n\n");
    angle_labelThree->setText("Angle Values three go here: \n\n");

    // Declare a horizontal layout for first exercise
    VerticalLayout = new QVBoxLayout;
    HorizontalLayout = new QHBoxLayout;
    HorizontalLayout->addWidget(angle_labelOne);
    HorizontalLayout->addWidget(angle_labelTwo);
    HorizontalLayout->addWidget(angle_labelThree);
    HorizontalLayout->addWidget(startButton);
    HorizontalLayout->addWidget(pauseButton);

    setLayout(HorizontalLayout);

    // Setup signals and slots
    connect(startButton, SIGNAL (clicked(bool)),
            this, SLOT (slotStartButtonClicked(bool)));
    connect(Thread, SIGNAL (AngleChanged(double, double, double)),
            this, SLOT (onAngleChanged(double, double, double)));
    connect(pauseButton, SIGNAL (clicked(bool)),
            this, SLOT (slotPauseButtonClicked(bool)));
}

// Allows for thread to speak/communicate to main QWidget/GUI Thread using slots
void GUIWindow::onAngleChanged(double angleOne, double angleTwo, double angleThree) {
    angle_labelOne->setNum(angleOne);
    angle_labelTwo->setNum(angleTwo);
    angle_labelThree->setNum(angleThree);
}


// Implementation for button slots to allow for clicking, etc...

void GUIWindow::slotStartButtonClicked(bool checked)
{
    if(checked){
        Thread->start();
        startButton->setEnabled(true);
        startButton->setText("Run Again");
    }
}

void GUIWindow::slotPauseButtonClicked(bool checked)
{
    if(checked){
        Thread->pause = true;
        pauseButton->setText("Unpause");
    } else {
        Thread->pause = false;
        pauseButton->setText("Pause");
    }
}
