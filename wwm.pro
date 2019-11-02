# Describes the type to build. It can be an application, a library, or simply subdirectories.
TEMPLATE = app

# The name of the app or the library.
TARGET = wwm

# The following setting is used to indicate what libraries (Qt modules) are being used in this project.
# Usually a small GUI will need QtCore and QtGui.
QT += core
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# The source files for the project.
SOURCES += \
    game.cpp \
    gameconsoleview.cpp \
    gamecontroller.cpp \
    main.cpp \
    model.cpp \
    question.cpp \
    sharedcounter.cpp \
    viewobservable.cpp \
    gameobservable.cpp \
    answer.cpp \
    mainwindow.cpp

# The associated header file of the project.
HEADERS += \
    game.h \
    gameconsoleview.h \
    gamecontroller.h \
    model.h \
    question.h \
    sharedcounter.h \
    sharedqueue.h \
    viewobserver.h \
    viewobservable.h \
    gameobserver.h \
    gameobservable.h \
    answer.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui
