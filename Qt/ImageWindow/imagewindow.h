#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include "transactionthread.h"

class QLabel;
class QAction;
class QMenu;
class QStatusBar;
class TransactionThread;

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    ImageWindow(QWidget *parent = 0);
    ~ImageWindow();
private slots:


    void allTransactionsDone();

    void flipHorizontally();
    void flipVertically();
    void convertTo1Bit();
    void convertTo8Bit();
    void convertTo32Bit();
    void resizeImage();
    void open();
    void save();
    void saveAs();
    void about();



private :
    void createActions();
    void createMenus();

    void loadFile(const QString);
    void saveFile(const QString);
    QString strippedName(const QString fullName);
    void addTransaction(Transaction *transact);
    bool okToContinue();
    void setCurrentFile(const QString &fileName);

    QLabel *imageLabel;
    TransactionThread thread;
    QByteArray imageFormat;
    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *convertSubMenu;
    QMenu *helpMenu;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *flipHorizonalAction;
    QAction *flipVerticalAction;
    QAction *resizeAction;
    QAction *convertTo32Action;
    QAction *convertTo8Action;
    QAction *convertTo1Action;
    QAction *aboutAction;
    QAction *aboutQtAction;


};

#endif // IMAGEWINDOW_H
