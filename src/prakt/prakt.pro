#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T14:28:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prakt
TEMPLATE = app

RC_FILE = myapp.rc

SOURCES += main.cpp\
        mymainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mymainwindow.h \
    qcustomplot.h

RESOURCES += \
    ../../icons.qrc


QT += widgets printsupport
