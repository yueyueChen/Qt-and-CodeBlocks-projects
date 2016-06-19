#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui = new Ui_MainWindow;
    ui->setupUi(this);

    putmark = false;

    ui->label->setFixedSize(800,450);

    openAction = new QAction(tr("&Open"),this);
    openAction->setStatusTip(tr("open an exited file"));
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction,SIGNAL(triggered(bool)),this,SLOT(open()));

    captureAction = new QAction(tr("&capture"),this);
    captureAction->setStatusTip(tr("capture the video."));
    captureAction->setShortcut(QKeySequence::New);
    connect(captureAction,SIGNAL(triggered(bool)),this,SLOT(captureVideo()));

    aboutAction = new QAction(tr("aboutQt"),this);
    connect(aboutAction,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));

    ui->menuFile->addAction(openAction);
    ui->menuFile->addAction(captureAction);
    ui->menuHelp->addAction(aboutAction);

    connect(ui->okButton,SIGNAL(clicked(bool)),this,SLOT(putWaterMark()));
    connect(ui->startButton,SIGNAL(clicked(bool)),this,SLOT(startSave()));
    connect(ui->stopButton,SIGNAL(clicked(bool)),this,SLOT(stopSave()));
    setEditEnable(false);

    timer = new QTimer ;
    connect(timer,SIGNAL(timeout()),this,SLOT(changeFrame()));

    save = STOP;
}
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("open a video file"),".",
                                                    tr("video files (*.avi *.mp4 *.mp3 *.jpg)"));
    if(!fileName.isEmpty())
    {
        capture.open(fileName.toStdString());
        resize(1023,546);
        setEditEnable(true);
        timer->start(33);
    }
}

void MainWindow::captureVideo()
{
    capture.open(0);
    resize(1023,546);
    setEditEnable(true);
    timer->start(33);
}

void MainWindow::changeFrame()
{
    capture >> img;
    if(putmark&&!ui->wordedit->text().isEmpty())
        cv::putText(img,ui->wordedit->text().toStdString(),cv::Point(ui->positionxEdit->text().toInt(),
                 ui->positionyEdit->text().toInt()),5,ui->sizeEdit->text().toDouble(),
                 cv::Scalar(ui->bEdit->text().toInt(),ui->rEdit->text().toInt(),ui->gEdit->text().toInt()),9);
    if(save == START)
        writer << img;
    if(img.channels() == 3)
    {
        cv::cvtColor(img,img,CV_BGR2RGB);
        curImage = QImage((unsigned char *)img.data,img.cols,img.rows,img.step,QImage::Format_RGB888);
    }
    else
    {
        curImage = QImage((const unsigned char*)img.data,img.cols,img.rows,img.step,
                          QImage::Format_RGB888);
    }
    QImage newImage = curImage.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(QPixmap::fromImage(newImage));
}
void MainWindow::setEditEnable(bool setOrNot)
{
    ui->wordedit->setEnabled(setOrNot);
    ui->positionxEdit->setEnabled(setOrNot);
    ui->positionyEdit->setEnabled(setOrNot);
    ui->sizeEdit->setEnabled(setOrNot);
    ui->gEdit->setEnabled(setOrNot);
    ui->bEdit->setEnabled(setOrNot);
    ui->rEdit->setEnabled(setOrNot);
    ui->okButton->setEnabled(setOrNot);
    ui->startButton->setEnabled(setOrNot);

}

void MainWindow::putWaterMark()
{
    putmark = true;
    ui->okButton->setEnabled(false);
    ui->okButton->setVisible(false);
}
void MainWindow::startSave()
{
    if(save == STOP)
    {
        save = START;
        ui->stopButton->setEnabled(true);
        ui->startButton->setText("pause");
        QString fileName;
        QDateTime time = QDateTime::currentDateTime();
        //qt 不可以直接用QString（int）的用法
        fileName = time.date().toString() + "TIME" +QString::number(time.time().hour(),10)
                + QString::number(time.time().minute(),10) +
                QString::number(time.time().second(),10)+ ".avi";

        std::cout << fileName.toStdString() << std::endl;

        writer.open(fileName.toStdString(),CV_FOURCC('D','I','V','X'),
                    30,cv::Size(getCurImage().width(),getCurImage().height()),1);
    }
    else if(save == PAUSE)
     {
        save = START;
        ui->startButton->setText("pause");
     }
    else if(save == START)
    {
        save = PAUSE;
        ui->startButton->setText("start");
    }
}
void MainWindow::stopSave()
{
    save = STOP;
    ui->startButton->setText("start");
    writer.release();
}
QImage MainWindow::getCurImage()
{
    return curImage;
}
MainWindow::~MainWindow()
{
    delete ui;
}
