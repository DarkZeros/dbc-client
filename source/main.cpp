#include "mainwindow.h"
#include <QApplication>

#include "core/include/dbcore.h"

int main(int argc, char *argv[])
{
    DBC("hi.db");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
