#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QDialog>
#include"thread.h"

class ThreadDialog : public QDialog
{
    Q_OBJECT

public:
    ThreadDialog(QWidget *parent = 0);
protected:
    void closeEvent(QEvent *event);
private slots:
    void startOrStopThreadA();
    void startOrStopThreadB();
private:
    Thread threadA;
    Thread threadB;
    QPushButton *threadButtonA;
    QPushButton *threadButtonB;
    QPushButton *quitButton;
};

#endif // THREADDIALOG_H
