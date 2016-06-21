#include "minesweeper.h"
#include <QtWidgets>

MineSweeper::MineSweeper(QWidget *parent)
: QWidget(parent)
{
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    for(int i = 0 ; i < MAXROW; ++i)
        for(int j = 0; j < MAXCOL ; ++j)
        {
            bomb[i][j] = 0;
            opened[i][j] = 0;
        }
}

MineSweeper::~MineSweeper()
{

}
void MineSweeper::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    for(int i =0; i <= MAXCOL;++i)
        painter.drawLine(zoom * i,0,zoom *i, zoom * MAXROW);
    for(int j = 0; j <= MAXROW; ++j)
        painter.drawLine(0,zoom*j,zoom*MAXROW,zoom*j);


    //draw opened Rects..  waitting..


}
void MineSweeper::setZoom(int newZoom)
{
    zoom = newZoom;
    update();
    updateGeometry();
}
void MineSweeper::mousePressEvent(QMouseEvent *event)
{

}
int MineSweeper::getAroundBombs(int x,int y)
{
   int index = 0;

   if(x>=1&&x<MAXROW-1&&y>=1&&y<MAXCOL-1)
       index =  bomb[x-1][y]+ bomb[x-1][y-1] + bomb[x-1][y+1]
               + bomb[x][y-1] + bomb[x][y+1] + bomb[x+1][y-1]
               + bomb[x+1][y] + bomb[x+1][y+1] ;
   else if(x==0&&y>=1&&y<MAXCOL-1)
       index = bomb[x][y-1] + bomb[x][y+1] + bomb[x+1][y-1]
               + bomb[x+1][y] + bomb[x+1][y+1] ;
   else if(x==MAXROW-1&&y>=1&&y<MAXCOL-1)
       index =  bomb[x-1][y] + bomb[x-1][y-1] + bomb[x-1][y+1]
               + bomb[x][y-1] + bomb[x][y+1] ;
   else if(y==0&&x>=1&&x<MAXROW-1)
       index =  bomb[x-1][y] + bomb[x-1][y+1]
               + bomb[x][y+1] + bomb[x+1][y] + bomb[x+1][y+1] ;
   else if(y==MAXCOL-1&&x>=1&&x<MAXROW-1)
       index =  bomb[x-1][y] + bomb[x-1][y-1] + bomb[x][y-1] +
                bomb[x+1][y-1] + bomb[x+1][y] ;
   else if(x==0&&y==0)
       index =  bomb[1][0] + bomb[0][1] + bomb[1][1];
   else if(x==0&&y==MAXCOL-1)
       index =  bomb[0][MAXCOL-2] + bomb[1][MAXCOL-1] +  bomb[1][MAXCOL-2];
   else if(x==MAXROW-1&&y==0)
       index =  bomb[MAXCOL-1][1] + bomb[MAXCOL-2][0] +  bomb[MAXCOL-2][1];
   else if(x==MAXROW-1&&y==MAXCOL-1)
       index =  bomb[MAXCOL-1][MAXCOL-2] +  bomb[MAXCOL-2][MAXCOL-1] +  bomb[MAXCOL-2][MAXCOL-2];
   else{}

   return index;
}
