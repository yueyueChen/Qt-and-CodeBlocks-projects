#include<QtWidgets>


#include <QApplication>

#include <QMediaPlayer>

#include <QVideoWidget>

#include "functiontest.h"

int main (int argc,char *argv[]) {
    QApplication a(argc,argv);
    QWidget *w = new QWidget;
    w->resize(QSize(400,300));

    QVideoWidget *video = new QVideoWidget();
    QMediaPlayer *player = new QMediaPlayer;
    player->setVideoOutput(video);
    player->setMedia(QUrl::fromLocalFile("D:/File/Mv/Get Jinxed 1080P.MP4"));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(video);
    w->setLayout(layout);
    w->show();
    player->play();
    return a.exec();
}
