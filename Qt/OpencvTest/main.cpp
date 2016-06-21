#include <QApplication>

#include "mainwindow.h"
#include <QProcess>


int main (int argc,char *argv[])
{
    QApplication a(argc,argv);
    MainWindow *w = new MainWindow ;
    qDebug("initial test...");
    w->show();

    return a.exec();
}
