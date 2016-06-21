/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *waterMarkBox;
    QLabel *label_5;
    QLineEdit *wordedit;
    QPushButton *okButton;
    QLineEdit *positionxEdit;
    QLabel *label_3;
    QLineEdit *rEdit;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *gEdit;
    QLineEdit *positionyEdit;
    QLineEdit *sizeEdit;
    QLabel *label_7;
    QLineEdit *bEdit;
    QLabel *wordLabel;
    QLabel *positionLabel;
    QLabel *sizeLabel;
    QLabel *label_2;
    QGroupBox *groupBox;
    QPushButton *stopButton;
    QPushButton *startButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1023, 546);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 800, 450));
        waterMarkBox = new QGroupBox(centralWidget);
        waterMarkBox->setObjectName(QStringLiteral("waterMarkBox"));
        waterMarkBox->setGeometry(QRect(800, 0, 221, 301));
        label_5 = new QLabel(waterMarkBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 210, 16, 16));
        wordedit = new QLineEdit(waterMarkBox);
        wordedit->setObjectName(QStringLiteral("wordedit"));
        wordedit->setGeometry(QRect(100, 60, 121, 20));
        okButton = new QPushButton(waterMarkBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(150, 270, 71, 23));
        positionxEdit = new QLineEdit(waterMarkBox);
        positionxEdit->setObjectName(QStringLiteral("positionxEdit"));
        positionxEdit->setGeometry(QRect(120, 110, 41, 20));
        label_3 = new QLabel(waterMarkBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 110, 16, 16));
        rEdit = new QLineEdit(waterMarkBox);
        rEdit->setObjectName(QStringLiteral("rEdit"));
        rEdit->setGeometry(QRect(120, 210, 21, 20));
        sizePolicy.setHeightForWidth(rEdit->sizePolicy().hasHeightForWidth());
        rEdit->setSizePolicy(sizePolicy);
        rEdit->setMaxLength(20);
        label_4 = new QLabel(waterMarkBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 210, 16, 16));
        label_6 = new QLabel(waterMarkBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 210, 16, 16));
        gEdit = new QLineEdit(waterMarkBox);
        gEdit->setObjectName(QStringLiteral("gEdit"));
        gEdit->setGeometry(QRect(160, 210, 21, 20));
        sizePolicy.setHeightForWidth(gEdit->sizePolicy().hasHeightForWidth());
        gEdit->setSizePolicy(sizePolicy);
        gEdit->setMaxLength(20);
        positionyEdit = new QLineEdit(waterMarkBox);
        positionyEdit->setObjectName(QStringLiteral("positionyEdit"));
        positionyEdit->setGeometry(QRect(180, 110, 41, 20));
        sizeEdit = new QLineEdit(waterMarkBox);
        sizeEdit->setObjectName(QStringLiteral("sizeEdit"));
        sizeEdit->setGeometry(QRect(110, 160, 111, 20));
        label_7 = new QLabel(waterMarkBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(167, 109, 16, 16));
        bEdit = new QLineEdit(waterMarkBox);
        bEdit->setObjectName(QStringLiteral("bEdit"));
        bEdit->setGeometry(QRect(200, 210, 21, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bEdit->sizePolicy().hasHeightForWidth());
        bEdit->setSizePolicy(sizePolicy1);
        bEdit->setMaxLength(20);
        wordLabel = new QLabel(waterMarkBox);
        wordLabel->setObjectName(QStringLiteral("wordLabel"));
        wordLabel->setGeometry(QRect(10, 60, 72, 16));
        positionLabel = new QLabel(waterMarkBox);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setGeometry(QRect(1, 113, 90, 16));
        sizeLabel = new QLabel(waterMarkBox);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));
        sizeLabel->setGeometry(QRect(10, 160, 72, 16));
        label_2 = new QLabel(waterMarkBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 210, 78, 16));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(800, 370, 221, 101));
        stopButton = new QPushButton(groupBox);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(80, 50, 75, 23));
        startButton = new QPushButton(groupBox);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(10, 50, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        label->raise();
        waterMarkBox->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1023, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "                   please  open   a    video  file .....", 0));
        waterMarkBox->setTitle(QApplication::translate("MainWindow", "put waterMark...", 0));
        label_5->setText(QApplication::translate("MainWindow", "G:", 0));
        okButton->setText(QApplication::translate("MainWindow", "Apply", 0));
        label_3->setText(QApplication::translate("MainWindow", "x:", 0));
        label_4->setText(QApplication::translate("MainWindow", "R:", 0));
        label_6->setText(QApplication::translate("MainWindow", "B:", 0));
        label_7->setText(QApplication::translate("MainWindow", "y:", 0));
        wordLabel->setText(QApplication::translate("MainWindow", "change Word:", 0));
        positionLabel->setText(QApplication::translate("MainWindow", "change Positon:", 0));
        sizeLabel->setText(QApplication::translate("MainWindow", "change Size:", 0));
        label_2->setText(QApplication::translate("MainWindow", "change Color:", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Capture from the video....", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
