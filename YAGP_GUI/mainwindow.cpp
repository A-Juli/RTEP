#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Set size of window
    setFixedSize(500, 500);

    // Create and Position button declared in MainWindow.h
    m_button = new QPushButton("Start Caliberation", this);
    a_button = new QPushButton("End Caliberation", this);
    b_button = new QPushButton("Close", this);

    m_button -> setGeometry(10, 10, 120, 30);
    a_button -> setGeometry(10, 40, 120, 30);
    b_button -> setGeometry(10, 450, 120, 30);

    /* Attaches event handler to close window once the close button is pressed
     * More info on event handlers can be found in documentation. Use it as a
     * reference in order to generate animations, etc... it uses the signal
     * slot system which is based on the observer pattern */
    connect(b_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));

    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
}

