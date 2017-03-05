#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Tales Bontempo Cunha");
    QCoreApplication::setApplicationName("Black Vector");
    MainWindow w;
    w.show();

    return a.exec();
}
