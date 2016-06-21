#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QtMultimedia/QMultimedia>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    putmark = false;

    openAction = new QAction(tr("&Open"),this);
    openAction->setStatusTip(tr("open an exited file"));
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction,SIGNAL(triggered(bool)),this,SLOT(open()));

    captureAction = new QAction(tr("&capture"),this);
    captureAction->setStatusTip(tr("capture the video."));
    captureAction->setShortcut(QKeySequence::New);
    connect(captureAction,SIGNAL(triggered(bool)),this,SLOT(capturevideo()));

    aboutAction = new QAction(tr("aboutQt"),this);
    connect(aboutAction,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(putWaterMark()));

    ui->fileMenu->addAction(openAction);
    ui->fileMenu->addAction(captureAction);
    ui->helpMenu->addAction(aboutAction);
    setEditEnable(false);
}
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("open a video file"),".",
                                                    tr("video files (*.avi *.mp4)"));
    setEditEnable(!fileName.isEmpty());
    if(!fileName.isEmpty())
    {
        openAction->setEnabled(false);
        captureAction->setEnabled(false);
        capture.open(fileName.toStdString());
        while(capture.read(frame))
         {
            if(putmark&&!ui->wordedit->text().isEmpty())
                cv::putText(frame,ui->wordedit->text().toStdString(),cv::Point(ui->positionxEdit->text().toInt(),
                         ui->positionyEdit->text().toInt()),5,ui->sizeEdit->text().toDouble(),
                         cv::Scalar(ui->bEdit->text().toInt(),ui->rEdit->text().toInt(),ui->gEdit->text().toInt()),9);
            imshow("video play...",frame);
            cv::waitKey(30);
        }
    }
    openAction->setEnabled(true);
    captureAction->setEnabled(true);
}
void MainWindow::capturevideo()
{
    capture.open(0);
    setEditEnable(true);

    writer.open("test.avi",CV_FOURCC('D','I','V','X'),30,cv::Size(640,480),1);
    cv::namedWindow("video",1);
    while(capture.read(frame))
     {
        if(putmark&&!ui->wordedit->text().isEmpty())
            cv::putText(frame,ui->wordedit->text().toStdString(),cv::Point(ui->positionxEdit->text().toInt(),
                     ui->positionyEdit->text().toInt()),5,ui->sizeEdit->text().toDouble(),
                     cv::Scalar(ui->bEdit->text().toInt(),ui->rEdit->text().toInt(),ui->gEdit->text().toInt()),9);
        imshow("video play...",frame);
        writer.write(frame);
        char c = cv::waitKey(30);
        if(c == 27)
        {
            capture.release();
            break;
        }
    }

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
    ui->pushButton->setEnabled(setOrNot);
}

void MainWindow::putWaterMark()
{
    putmark = true;
    ui->pushButton->setEnabled(false);
    ui->pushButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
