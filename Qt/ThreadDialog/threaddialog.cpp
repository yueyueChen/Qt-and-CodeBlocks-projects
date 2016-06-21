#include "threaddialog.h"
#include "thread.h"

#include <QtWidgets>

ThreadDialog::ThreadDialog(QWidget *parent)
    : QDialog(parent)
{
    threadA.setMessage("A");
    threadB.setMessage("B");

    threadButtonA = new QPushButton(tr("ThreadA"));
    threadButtonB = new QPushButton(tr("ThreadB"));
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setDefault(true);

    connect(threadButtonA,SIGNAL(clicked(bool)),this,SLOT(startOrStopThreadA()));
    connect(threadButtonB,SIGNAL(clicked(bool)),this,SLOT(startOrStopThreadB()));
    connect(quitButton,SIGNAL(clicked(bool)),this,SLOT(close()));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(threadButtonA);
    mainLayout->addWidget(threadButtonB);
    mainLayout->addWidget(quitButton);
    setLayout(mainLayout);
    //....
}
void ThreadDialog::startOrStopThreadA()
{
    if(threadA.isRunning()) {
        threadA.stop();
        threadButtonA->setText(tr("Start A"));
    }
    else {
        threadA.start();
        threadButtonA->setText(tr("Stop A"));
    }
}
void ThreadDialog::startOrStopThreadB()
{
    if(threadB.isRunning()) {
        threadB.stop();
        threadButtonB->setText(tr("Start B"));
    }
    else {
        threadB.start();
        threadButtonB->setText(tr("Stop B"));
    }
}
void ThreadDialog::closeEvent(QEvent *event)
{
    threadA.stop();
    threadB.stop();
    threadA.wait();
    threadB.wait();\
    event->accept();
}
