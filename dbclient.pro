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

INCLUDEPATH += $$PWD/core
DEPENDPATH += $$PWD/core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/core/release/libdbcore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/core/debug/libdbcore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/core/release/dbcore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/core/debug


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/core/cryptopp/release/ -lcryptopp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/core/cryptopp/debug/ -lcryptopp
else:unix: LIBS += -L$$PWD/core/cryptopp/ -lcryptopp

INCLUDEPATH += $$PWD/core/cryptopp
DEPENDPATH += $$PWD/core/cryptopp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/core/cryptopp/release/libcryptopp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/core/cryptopp/debug/libcryptopp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/core/cryptopp/release/cryptopp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/core/cryptopp/debug/cryptopp.lib
else:unix: PRE_TARGETDEPS += $$PWD/core/cryptopp/libcryptopp.a


#For Static lib
LIBS += -ldl
LIBS += -lprotobuf
