#include "glcontrollertest.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLControllerTest w;
    w.show();

    return a.exec();
}
