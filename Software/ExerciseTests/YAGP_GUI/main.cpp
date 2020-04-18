#include "guiwindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication YAGP_GUI(argc, argv);

    GUIWindow window;
    window.show();

    return YAGP_GUI.exec();
}
