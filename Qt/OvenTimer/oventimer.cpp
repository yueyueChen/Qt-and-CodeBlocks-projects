#include "oventimer.h"
#include <QtWidgets>

const double DegreesPerMinute = 7.0;
const double DegreesPerSecond = DegreesPerMinute / 60;
const int MaxMinutes = 45;
const int MaxSeconds = MaxMinutes * 60;
const int updateInterval = 5;
OvenTimer::OvenTimer(QWidget *parent)
    : QWidget(parent)
{
    finishTime = QDateTime::currentDateTime();

    updateTimer = new QTimer;
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));

    finishTimer = new QTimer;
    finishTimer->setSingleShot(true);
    connect(finishTimer,SIGNAL(timeout()),this,SIGNAL(timeout()));
    connect(finishTimer,SIGNAL(timeout()),updateTimer,SLOT(stop()));

    QFont font;
    font.setPointSize(8);
    setFont(font);
}
int OvenTimer::setDuration(int secs)
{
    secs = qBound(0,secs,MaxMinutes);
    finishTime = currentDateTime().addSecs(secs);
    if(secs>0)
    {
        updateTimer->start(updateInterval * 1000);
        finishTimer->start();
    }
    else{
        updateTimer->stop();
        finishTimer->stop();
    }
    update();
}
void OvenTimer::Duration()const
{
    int secs = QDateTime::currentDateTime().secsTo(finishTime);
    if(secs < 0)
        secs = 0;
}
