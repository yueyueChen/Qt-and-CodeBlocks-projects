#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    ImageWindow(QWidget *parent = 0);
    ~ImageWindow();
};

#endif // IMAGEWINDOW_H
