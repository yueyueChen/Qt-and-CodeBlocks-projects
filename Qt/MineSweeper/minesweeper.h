#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QWidget>

class MineSweeper : public QWidget
{
    Q_OBJECT

public:
    MineSweeper(QWidget *parent = 0);
    ~MineSweeper();
};

#endif // MINESWEEPER_H
