#include "guiwindow.h"
#include "../ExerciseTests.cpp"
#include <QApplication>
#include <QThread>

// Creates own sleeper class inherited from QThread
class Sleeper : public QThread
{
public:
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
};

// Creates widgets, sets window size etc...
GUIWindow::GUIWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1000,500);

    m_button = new QPushButton("Start Program", this);

    m_button->setGeometry(100, 100, 200, 30);
    m_button->setCheckable(true);

    angle_label = new QLabel(this);
    product_label = new QLabel(this);

    angle_label->setText("Angle Values go here: \n\n"); // Yes I know its a poor fix but I'll resize it when I wake up lmao
    product_label->setText("Dot Product Values go here:");

    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotStartButtonClicked(bool)));
}

// Implements the custom slot function in the header file
void GUIWindow::slotStartButtonClicked(bool checked)
{

    if(checked){
        m_button->setText("Stop Program");

        ExerciseTests Test;   //Declare Box1 of type box
        Test.setAccel1(0,0,1);
        Test.setAccel2(0,0,1);

        for(int q=0; q < 10; q++) {
            Test.Exercise1();
            angle_label->setNum(Test.Angle);
            product_label->setNum(Test.DotProduct);
            QWidget::repaint(); // Updates the label field every loop iteration
            Sleeper::msleep(1000); // Updates once every 1 second based on the custom thread timer
        }

    } else {
        m_button->setText("Run again");
    }
}

