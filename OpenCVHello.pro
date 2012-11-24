#-------------------------------------------------
#
# Project created by QtCreator 2012-11-24T18:53:59
#
#-------------------------------------------------

QT       += core gui

TARGET = OpenCVHello
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS+=`pkg-config opencv --cflags --libs`



INCLUDEPATH+=\usr\local\lib\include\

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopencv_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopencv_core
else:symbian: LIBS += -lopencv_core
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_core



INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include
