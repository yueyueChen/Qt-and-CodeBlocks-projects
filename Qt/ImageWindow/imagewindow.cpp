#include "imagewindow.h"
#include <QtWidgets>
#include "ui_resizeimage.h"

ImageWindow::ImageWindow(QWidget *parent)
    : QMainWindow(parent)
{
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Dark);
    imageLabel->setAutoFillBackground(true);
    imageLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setCentralWidget(imageLabel);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"),2000);

    connect(&thread,SIGNAL(transactionStarted(const QString &)),statusBar(),
            SLOT(showMessage(QString,int)));
    connect(&thread,SIGNAL(allTransactionsDone()),this,SLOT(allTransactionsDone));
    setCurrentFile("");
    //......
}
void ImageWindow::createActions()
{
    openAction = new QAction(tr("Open"),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("open a new image file."));
    connect(openAction,SIGNAL(triggered(bool)),this,SLOT(open()));

    saveAsAction = new QAction(tr("Save As"),this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("save as ...."));
    saveAsAction->setEnabled(false);
    connect(saveAsAction,SIGNAL(triggered(bool)),this,SLOT(saveAs()));

    saveAction = new QAction(tr("save"),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setEnabled(false);
    connect(saveAction,SIGNAL(triggered(bool)),this,SLOT(save()));

    flipHorizonalAction = new QAction(tr("flip horizonally"),this);
    connect(flipHorizonalAction,SIGNAL(triggered(bool)),this,SLOT(flipHorizontally()));
    flipHorizonalAction->setEnabled(false);

    flipVerticalAction  = new QAction(tr("flip vertivally"),this);
    connect(flipVerticalAction,SIGNAL(triggered(bool)),this,SLOT(flipVertically()));
    flipVerticalAction->setEnabled(false);

    resizeAction = new QAction(tr("resize"),this);
    connect(resizeAction,SIGNAL(triggered(bool)),this,SLOT(resizeImage()));
    resizeAction->setEnabled(false);

    convertTo32Action = new QAction(tr("convertTo32Bit"),this);
    connect(convertTo32Action,SIGNAL(triggered(bool)),this,SLOT(convertTo32Bit()));
    convertTo32Action->setEnabled(false);

    convertTo8Action = new QAction(tr("convertTo8Bit"),this);
    connect(convertTo8Action,SIGNAL(triggered(bool)),this,SLOT(convertTo8Bit()));
    convertTo8Action->setEnabled(false);

    convertTo1Action = new QAction(tr("convertTo1Bit"),this);
    connect(convertTo1Action,SIGNAL(triggered(bool)),this,SLOT(convertTo1Bit()));
    convertTo1Action->setEnabled(false);

    aboutAction = new QAction(tr("about"),this);
    connect(aboutAction,SIGNAL(triggered(bool)),this,SLOT(about()));

    aboutQtAction = new QAction(tr("aboutQt"),this);
    connect(aboutQtAction,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));

}
void ImageWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(flipHorizonalAction);
    editMenu->addAction(flipVerticalAction);
    editMenu->addAction(resizeAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    convertSubMenu = editMenu->addMenu(tr("convert"));
    convertSubMenu->addAction(convertTo1Action);
    convertSubMenu->addAction(convertTo8Action);
    convertSubMenu->addAction(convertTo32Action);
}
bool ImageWindow::okToContinue()
{
    if(isWindowModified())
    {
        int i = QMessageBox::warning(this,tr("ImageWindow"),tr("the image has been modified.\n"
                                                               "Do you want to save your changes?"),
                                     QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(i==QMessageBox::Yes)
        {
            save();
            return false;
        }
        else if(i==QMessageBox::Cancel)
            return false;
    }
    return true;
}

void ImageWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
        loadFile(fileName);
}
void ImageWindow::loadFile(QString fileName)
{
    QImage newImage;

    QApplication::setOverrideCursor(Qt::WaitCursor);
    bool  loaded = newImage.load(fileName);
    QApplication::restoreOverrideCursor();

    if(loaded)
    {
        thread.setImage(newImage);
        imageFormat = QImageReader::imageFormat(fileName);
        imageLabel->setPixmap(QPixmap::fromImage(newImage));
        setCurrentFile(fileName);
        statusBar()->showMessage(tr("File loaded.."),2000);
    }
    else
    {
        QMessageBox::warning(this,tr("ImageWindow"),tr("error when load image."));
        statusBar()->showMessage(tr("laod canceled."),2000);
    }
}
void ImageWindow::save()
{
    if(curFile.isEmpty())
        return saveAs();
    else
        saveFile(curFile);
}
void ImageWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(QFile::exists(fileName))
    {
        int r = QMessageBox::warning(this,tr("imagewindow"),tr("File %1 already exits.overwrite it?")
                                     .arg(fileName),QMessageBox::Yes|QMessageBox::No);
        if(r == QMessageBox::No)
            return;
    }
    if(!fileName.isEmpty())
        saveFile(fileName);
}
void ImageWindow::saveFile(const QString fileName)
{
    QImage image = thread.image();

    QApplication::setOverrideCursor(Qt::WaitCursor);
    bool saved = image.save(fileName,imageFormat);
    QApplication::restoreOverrideCursor();

    if(saved)
    {
        setCurrentFile(fileName);
        statusBar()->showMessage(tr("File saved."),2000);
    }
    else
    {
        QMessageBox::warning(this,tr("imageWIndow"),tr("error save image"));
        statusBar()->showMessage(tr("Saving canceled."),2000);
    }
}
void ImageWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);

    bool hasImage = !curFile.isEmpty();

    if(hasImage)
    {
        setWindowTitle(tr("%1[*] - %2").arg(strippedName(curFile))
                                        .arg(tr("imageWindow")));
    }
    else
        setWindowTitle(tr("ImageWindow"));

    saveAction->setEnabled(hasImage);
    saveAsAction->setEnabled(hasImage);
    flipHorizonalAction->setEnabled(hasImage);
    flipVerticalAction->setEnabled(hasImage);
    convertTo1Action->setEnabled(hasImage);
    convertTo8Action->setEnabled(hasImage);
    convertTo32Action->setEnabled(hasImage);
    resizeAction->setEnabled(hasImage);
}

QString ImageWindow::strippedName(const QString fullName)
{
    return QFileInfo(fullName).fileName();
}

void ImageWindow::flipHorizontally()
{
    thread.addTransaction(new FlipTransaction(Qt::Horizontal));
}
void ImageWindow::flipVertically()
{
    addTransaction(new FlipTransaction(Qt::Vertical));
}
void ImageWindow::convertTo32Bit()
{
    addTransaction(new ConvertDepthTransaction(32));
}

void ImageWindow::convertTo8Bit()
{
    addTransaction(new ConvertDepthTransaction(8));
}

void ImageWindow::convertTo1Bit()
{
    addTransaction(new ConvertDepthTransaction(1));
}
void ImageWindow::resizeImage()
{
    QDialog dialog;
    Ui_Dialog ui;
    ui.setupUi(&dialog);
    ui.widthSpinBox->setValue(imageLabel->pixmap()->width());
    ui.heightSpinBox->setValue(imageLabel->pixmap()->height());
    if(dialog.exec())
    {
        QSize newSize(ui.widthSpinBox->value(),ui.heightSpinBox->value());
        addTransaction(new ResizeTransaction(newSize));
    }
}

void ImageWindow::addTransaction(Transaction *transact)
{
    thread.addTransaction(transact);
    openAction->setEnabled(false);
    saveAction->setEnabled(false);
    saveAsAction->setEnabled(false);
}
void ImageWindow::about()
{
    QMessageBox::about(this, tr("About Image Pro"),
            tr("<h2>Image Pro 1.1</h2>"
               "<p>Copyright &copy; 2008 Software Inc."
               "<p>Image Pro is a small application that demonstrates "
               "signal-slot connections across threads."));
}

ImageWindow::~ImageWindow()
{

}
void ImageWindow::allTransactionsDone()
{
    openAction->setEnabled(true);
    saveAction->setEnabled(true);
    saveAsAction->setEnabled(true);
    imageLabel->setPixmap(QPixmap::fromImage(thread.image()));
    setWindowModified(true);
    statusBar()->showMessage(tr("Ready"), 2000);
}
