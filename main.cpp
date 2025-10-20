#include "mainwindow.h"

#include <QApplication>
#include "model/basemodelobject.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
