#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QWidget>
#include <QDateTime>
class QTimer;

class OvenTimer : public QWidget
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
signals:
    void timeout();
public:
    OvenTimer(QWidget *parent = 0);
    void draw(QPainter *painter);
    void setDuration(int secs);
    int Duration()const;
private:
    QDateTime finishTime;
    QTimer *   updateTimer;
    QTimer *finishTimer;
};

#endif // OVENTIMER_H
