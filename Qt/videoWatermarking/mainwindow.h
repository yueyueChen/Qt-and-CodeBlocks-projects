#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>

class Ui_MainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void setEditEnable(bool setOrNot);
    QImage getCurImage();

    ~MainWindow();

    Ui_MainWindow *ui;

private slots:
    void changeFrame();
    void captureVideo();
    void open();
    void putWaterMark();
    void startSave();
    void stopSave();

private:
    QAction *openAction;
    QAction *captureAction;
    QAction *aboutAction;

    QTimer *timer;
    QImage curImage;

    cv::VideoCapture capture;
    cv::Mat img;
    cv::VideoWriter writer;

    enum saveControl {
        START,PAUSE,STOP
    };
    saveControl save;
    bool putmark;
};

#endif // MAINWINDOW_H
