#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Inherits QWidget. This is an upgrade in Qt 5.14
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QPushButton;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
public slots:

private:
    QPushButton *m_button;
    QPushButton *a_button;
    QPushButton *b_button;
    QLabel *label;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
