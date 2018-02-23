#include "mainwindow.h"
#include <QApplication>

#include "core/source/core.h"

int main(int argc, char *argv[])
{
    DBC::Core dbc;
    //dbc.checkPoW();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
