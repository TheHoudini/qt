#-------------------------------------------------
#
# Project created by QtCreator 2014-09-17T21:32:09
#
#-------------------------------------------------

QT       += core gui network  webkitwidgets sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = globalUploader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vkwebauth.cpp \
    dbframework.cpp

HEADERS  += mainwindow.h \
    vkwebauth.h \
    dbframework.h

FORMS    += mainwindow.ui \
    vkwebauth.ui
