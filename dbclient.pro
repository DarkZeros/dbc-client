#-------------------------------------------------
#
# Project created by QtCreator 2018-02-13T23:39:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dbc-client
TEMPLATE = app

CONFIG += c++11

SOURCES += source/main.cpp \
    source/mainwindow.cpp

HEADERS  += mainwindow.h \
    source/mainwindow.h

FORMS    += ui/mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/core/release/ -ldbcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/core/debug/ -ldbcore
else:unix: LIBS += -L$$OUT_PWD/core/ -ldbcore

#For Static lib
LIBS += -ldl

INCLUDEPATH += $$PWD/core
DEPENDPATH += $$PWD/core
