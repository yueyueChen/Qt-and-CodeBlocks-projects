#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T20:23:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageWindow
TEMPLATE = app

CONFIG  += console
SOURCES += main.cpp\
        imagewindow.cpp \
    transactionthread.cpp

HEADERS  += imagewindow.h \
    transactionthread.h

FORMS += \
    resizeimage.ui
