#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include "newthread.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QDialog>
#include <QBoxLayout>


class GUIWindow : public QWidget
{
    Q_OBJECT
public:
    newThread *Thread;
    explicit GUIWindow(QWidget *parent = nullptr);
    QHBoxLayout *HorizontalLayout;
    QVBoxLayout *VerticalLayout;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QLabel *product_label;
    QLabel *angle_labelOne;
    QLabel *angle_labelTwo;
    QLabel *angle_labelThree;

private:
signals:

public slots:
    void onAngleChanged(double, double, double); // Used to update the changed angle to pass onto the GUI

private slots:
    void slotStartButtonClicked(bool checked); // starts the program with a button using custom signal/slot system
    void slotPauseButtonClicked(bool checked); // pauses/stops the program
};

#endif // GUIWINDOW_H
