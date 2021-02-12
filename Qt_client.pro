QT       += core gui network mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

HEADERS = \
   $$PWD/mainwindow.h

SOURCES = \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp

FORMS = \
   $$PWD/mainwindow.ui


INCLUDEPATH = \
    $$PWD/.

#DEFINES = 

