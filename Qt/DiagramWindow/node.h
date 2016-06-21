#ifndef NODE_H
#define NODE_H

#include <QtWidgets>

class Link;
class QGraphicsItem;

class Node :public QGraphicsItem
{
    Q_DECLARE_TR_FUNCTIONS(Node)

public:
    Node();
    ~Node();
    void setText(const QString &text);
    QString text()const;
    void SetTextColor(const QColor &color);
    QColor textColor()const{return myTextColor;}
    void setOutlineColor(const QColor &color);
    QColor outlineColor()const{return myOutlineColor;}
    void setBackgroundColor(const QColor &color);
    QColor BackgroundColor()const{return myBackgroundColor;}

    void addLink(Link *link);
    void removeLink(Link *link);

    QRectF boundingRect()const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
private:
    QRectF outLineRect()const;
    int roundness(double size)const;

    QSet<Link *> myLinks;
    QString myText;
    QColor myTextColor;
    QColor myBackgroundColor;
    QColor myOutlineColor;
};

#endif // NODE_H
