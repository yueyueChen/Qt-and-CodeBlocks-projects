#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>


namespace Ui {
class MainWindow;
}

class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setEditEnable(bool setOrNot);
private:
    Ui::MainWindow *ui;

    cv::VideoCapture capture;
    cv::Mat frame;
    cv::VideoWriter writer;

    QAction *openAction;
    QAction *captureAction;
    QAction *aboutAction;
    bool putmark;
private slots:
    void putWaterMark();
    void open();
    void capturevideo();
};

#endif // MAINWINDOW_H
