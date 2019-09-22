TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    game.cpp \
    gameconsoleview.cpp \
    gamecontroller.cpp \
    main.cpp \
    model.cpp \
    question.cpp \
    viewobserver.cpp \
    viewobservable.cpp \
    gameobserver.cpp \
    gameobservable.cpp \
    answer.cpp

HEADERS += \
    game.h \
    gameconsoleview.h \
    gamecontroller.h \
    model.h \
    question.h \
    viewobserver.h \
    viewobservable.h \
    gameobserver.h \
    gameobservable.h \
    answer.h
