#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T12:34:35
#
#-------------------------------------------------

QT       += core gui widgets
QT          += multimedia
TARGET       = FunctionTest

TEMPLATE     = app
CONFIG      -= app_bundle
QT          += multimediawidgets

SOURCES += main.cpp\
        functiontest.cpp

HEADERS  += functiontest.h

RESOURCES += \
    functiontest.qrc

INCLUDEPATH += D:\Qt\opencv\include\

LIBS +=D:\Qt\opencv\lib\libopencv_highgui300.dll.a\
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

