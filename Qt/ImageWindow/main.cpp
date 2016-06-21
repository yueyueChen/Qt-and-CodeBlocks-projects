#include "imagewindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageWindow w;
    w.resize(QSize(400,320));
    w.show();
    return a.exec();
}
