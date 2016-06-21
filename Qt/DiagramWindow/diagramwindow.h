#ifndef DIAGRAMWINDOW_H
#define DIAGRAMWINDOW_H

#include <QMainWindow>

class DiagramWindow : public QMainWindow
{
    Q_OBJECT

public:
    DiagramWindow();
    ~DiagramWindow();
private slots:
    void addNode();
    void addLink();
    void del();
    void cut();
    void copy();
    void paste();
    void bringToFront();
    void setToBack();
    void properties();
    void updateActions();

private:
    typedef QPair<Node *,Node *>NodePair;

    void createActions();
    void createMenu();
    void createToolBars();
    void setZValue(int z);
    void setupNode(Node *node);
    Node *selectedNode()const;
    Link *selectedLink()const;
    NodePair selectedNodePair() const;

    QMenu *fileMenu;
    QMenu *editMenu;
    QToolBar *editToolBar;
    QACtion *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *addLinkAction;
    QAction *deleteAction;
    QAction *bringToFrontAction;
    QAction *sendToBackAction;
    QAction *propertiesAction;

    QGraphicsScene *scene;
    QGraphicsView *view;

    int minZ;
    int maxZ;
    int seqNumber;
};

#endif // DIAGRAMWINDOW_H
