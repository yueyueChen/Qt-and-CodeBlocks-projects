#-------------------------------------------------
#
# Project created by QtCreator 2016-06-05T16:31:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET       = OpencvTest
TEMPLATE     = app
QT          += multimedia

SOURCES     += main.cpp\
            mainwindow.cpp

HEADERS     += mainwindow.h

INCLUDEPATH += D:\Qt\opencv\include\

LIBS        +=D:\Qt\opencv\lib\libopencv_highgui300.dll.a\
             D:\Qt\opencv\lib\libopencv_photo300.dll.a\
              D:\Qt\opencv\lib\libopencv_calib3d300.dll.a\
              D:\Qt\opencv\lib\libopencv_core300.dll.a\
              D:\Qt\opencv\lib\libopencv_flann300.dll.a\
             D:\Qt\opencv\lib\libopencv_imgcodecs300.dll.a\
              D:\Qt\opencv\lib\libopencv_imgproc300.dll.a\
             D:\Qt\opencv\lib\libopencv_ml300.dll.a\
             D:\Qt\opencv\lib\libopencv_objdetect300.dll.a\
             D:\Qt\opencv\lib\libopencv_shape300.dll.a\
            D:\Qt\opencv\lib\libopencv_stitching300.dll.a\
             D:\Qt\opencv\lib\libopencv_superres300.dll.a\
              D:\Qt\opencv\lib\libopencv_video300.dll.a\
             D:\Qt\opencv\lib\libopencv_videoio300.dll.a\
             D:\Qt\opencv\lib\libopencv_videostab300.dll.a\

RESOURCES += \
    image.qrc

FORMS += \
    mainwindow.ui
