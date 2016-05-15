#ifndef FUNCTIONTEST_H
#define FUNCTIONTEST_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QLabel>

class FunctionTest : public QWidget
{
    Q_OBJECT

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
public:
    FunctionTest(QWidget *parent = 0);
    void setShowedNumber(int num);
    ~FunctionTest();
private:
    QTimer *updateTimer;
    QTimer *finishTimer;
    QVector<qint32> numbers;
};

#endif // FUNCTIONTEST_H
