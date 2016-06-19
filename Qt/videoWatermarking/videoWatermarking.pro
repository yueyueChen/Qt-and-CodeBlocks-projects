#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T10:51:58
#
#-------------------------------------------------

QT       += core gui widgets


TARGET = videoWatermarking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
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
