#include "oventimer.h"
#include <QtWidgets>

const double DegreesPerMinute = 7.0;
const double DegreesPerSecond = DegreesPerMinute / 60;
const int MaxMinutes = 45;
const int MaxSeconds = MaxMinutes * 60;
const int updateInterval = 3;
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
void OvenTimer::setDuration(int secs)
{
    secs = qBound(0,secs,MaxSeconds);
    finishTime = QDateTime::currentDateTime().addSecs(secs);
    if(secs>0)
    {
        updateTimer->start(updateInterval * 1000);
        finishTimer->start(secs * 1000);
    }
    else{
        updateTimer->stop();
        finishTimer->stop();
    }
    update();
}
int OvenTimer::Duration()const
{
    int secs = QDateTime::currentDateTime().secsTo(finishTime);
    if(secs < 0)
        secs = 0;
    return secs;
}
void OvenTimer::mousePressEvent(QMouseEvent *event)
{
    QPointF point = event->pos() - rect().center();
    double thera = std::atan2(-point.x(),-point.y()) * 180.0 /M_PI;
    setDuration(Duration() + int(thera / DegreesPerSecond));
    update();
}
void OvenTimer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    int side = qMin(width(),height());
    painter.setViewport((width() - side)/2,(height()-side)/2,side,side);
    painter.setWindow(-50,-50,100,100);
    draw(&painter);
}
void OvenTimer::draw(QPainter *painter)
{
    QVector<QPoint> points;
    points.push_back(QPoint(-2,-49));
    points.push_back(QPoint(2,-49));
    points.push_back(QPoint(0,-47));
    QColor niceblue(150,150,200);
    QPen thickPen(palette().foreground(),1.5);
    QPen thinPen(palette().foreground(),0.5);

    painter->setPen(thinPen);
    painter->setBrush(palette().foreground());
    painter->drawPolygon(QPolygon(points));

    QConicalGradient circleGradient(0,0,-120.0);
    circleGradient.setColorAt(0.0,Qt::darkGray);
    circleGradient.setColorAt(0.2,niceblue);
    circleGradient.setColorAt(0.8,Qt::white);
    circleGradient.setColorAt(1.0,Qt::darkGray);
    painter->setBrush(circleGradient);
    painter->drawEllipse(-46,-46,92,92);

    QRadialGradient haloGradient(0,0,20,0,0);
    haloGradient.setColorAt(0.0,Qt::lightGray);
    haloGradient.setColorAt(0.8,Qt::darkGray);
    haloGradient.setColorAt(0.9,Qt::white);
    haloGradient.setColorAt(1.0,Qt::black);
    painter->setPen(Qt::NoPen);
    painter->setBrush(haloGradient);
    painter->drawEllipse(-20,-20,40,40);

    QLinearGradient knobGradient(-5,-22,5,-22);
    knobGradient.setColorAt(0.0,Qt::black);
    knobGradient.setColorAt(0.2,niceblue);
    knobGradient.setColorAt(0.3,Qt::lightGray);
    knobGradient.setColorAt(0.8,Qt::white);
    knobGradient.setColorAt(1.0,Qt::black);

    painter->rotate(Duration() * DegreesPerSecond);
    painter->setPen(thinPen);
    painter->setBrush(knobGradient);
    painter->drawRoundRect(-5,-22,10,44,99,49);

    for(int i = 0; i <=MaxMinutes;++i)
    {
        painter->save();
        painter->rotate(-i * DegreesPerMinute);
        if(i%5==0)
        {
            painter->setPen(thickPen);
            painter->drawLine(0,-41,0,-44);
            painter->drawText(-15,-41,30,30,Qt::AlignHCenter|Qt::AlignTop,QString::number(i));
        }
        else{
            painter->setPen(thinPen);
            painter->drawLine(0,-42,0,-44);
        }
        painter->restore();
    }
}
