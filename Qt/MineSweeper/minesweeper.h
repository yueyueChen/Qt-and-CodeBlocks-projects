#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#define MAXROW 16
#define MAXCOL 16

#include <QWidget>
class BombMatrix;

class MineSweeper : public QWidget
{
    Q_OBJECT

public:
    MineSweeper(QWidget *parent = 0);
    ~MineSweeper();
    QRect pixelRect(int x,int y);
    void setZoom(int newZoom);
    int getZoom()const{return zoom;}
    int getAroundBombs(int x ,int y);
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    int zoom;
    bool bomb[MAXROW][MAXCOL];
    bool opened[MAXROW][MAXCOL];
    //直接用数组表示其值  一个数组为是否是炸弹   另一个为是否被打开过 方便paintevent选择
};

#endif // MINESWEEPER_H
