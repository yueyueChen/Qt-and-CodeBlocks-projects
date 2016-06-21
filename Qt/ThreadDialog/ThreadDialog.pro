TEMPLATE      = app
HEADERS       = thread.h \
                threaddialog.h
SOURCES       = main.cpp \
                thread.cpp \
                threaddialog.cpp
QT += gui core widgets
CONFIG  +=console
CONFIG  -=app_bundle
