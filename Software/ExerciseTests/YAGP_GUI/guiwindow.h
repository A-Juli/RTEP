#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>


class GUIWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GUIWindow(QWidget *parent = nullptr);
private:
    QPushButton *m_button;
    QLabel *product_label;
    QLabel *angle_label;

signals:

private slots:
    void slotStartButtonClicked(bool checked); // starts the program with a button using custom signal/slot system
};

#endif // GUIWINDOW_H
