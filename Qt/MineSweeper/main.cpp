#include "minesweeper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MineSweeper w;
    w.setZoom(25);
    w.setFixedSize(w.getZoom() * MAXROW,w.getZoom() * MAXCOL);
    w.show();

    return a.exec();
}
