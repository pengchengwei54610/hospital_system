#include "mainwindow.h"
#include "uidefine.h"
#include <QApplication>
int current_time=0;
int patient_no=1;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
