#ifndef PLOTTERSETTINGS_H
#define PLOTTERSETTINGS_H


class PlotterSettings
{
public:
    PlotterSettings();
    void scroll(int dx,int dy);
    void adjust();
    double spanX()const{return maxX - minX;}
    double spanY()const{return maxY - minY;}

    double minX;
    double minY;
    double maxX;
    double maxY;
    int numXTicks;
    int numYTicks;
private:
    static void adjustAxis(double &min,double&max,int &numTicks);
};

#endif // PLOTTERSETTINGS_H
