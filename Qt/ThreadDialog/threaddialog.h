#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QDialog>

class ThreadDialog : public QDialog
{
    Q_OBJECT

public:
    ThreadDialog(QWidget *parent = 0);
    ~ThreadDialog();
};

#endif // THREADDIALOG_H
