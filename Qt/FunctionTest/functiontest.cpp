#include "functiontest.h"
#include <QtWidgets>

int j =0;
FunctionTest::FunctionTest(QWidget *parent): QWidget(parent)
{
    resize(600,600);
    updateTimer = new QTimer;
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    finishTimer = new QTimer;
    finishTimer->setSingleShot(true);
    connect(finishTimer,SIGNAL(timeout()),updateTimer,SLOT(stop()));
}

void FunctionTest::setShowedNumber(int num)
{
    for(int i = num; i >= 0;--i)
        numbers.push_back(i);
}
void FunctionTest::mousePressEvent(QMouseEvent *event)
{
    int row = event->pos().x();
    setShowedNumber(row);
    updateTimer->start(1 * 1000);
    finishTimer->start(10 * 1000);
}
void FunctionTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setWindow(0,0,200,200);
    painter.setViewport(200,200,500,500);
    painter.drawLine(QPoint(0,0),QPoint(200,200));
    painter.setPen(QPen(Qt::lightGray,30));
    QFont font;
    font.setPointSize(8);
    painter.setFont(font);
    painter.drawText(10,100,tr("hello"));
    if(numbers.isEmpty())
        painter.drawText(100,100,tr("press anywhere to continue...."));
    else
        painter.drawText(100,100,tr("%1").arg(numbers[j]));
    ++j;
}

FunctionTest::~FunctionTest()
{

}
