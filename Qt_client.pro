QT       += core gui network mqtt sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

HEADERS = \
   $$PWD/mainwindow.h \
   $$PWD/loginwindow.h \
   database.h \
   editaccountdetailswindow.h \
   registerwindow.h \
   topic.h \
   user.h

SOURCES = \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
   $$PWD/loginwindow.cpp \
   database.cpp \
   editaccountdetailswindow.cpp \
   registerwindow.cpp \
   topic.cpp \
   user.cpp

FORMS = \
   $$PWD/mainwindow.ui \
   $$PWD/loginwindow.ui \
   editaccountdetailswindow.ui \
   registerwindow.ui


INCLUDEPATH = \
    $$PWD/.

#DEFINES = 

RESOURCES += \
    images.qrc

DISTFILES +=

