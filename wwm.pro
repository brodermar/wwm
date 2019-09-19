TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    viewobserver.cpp \
    viewobservable.cpp \
    gameobserver.cpp \
    gameobservable.cpp \
    answer.cpp

HEADERS += \
    viewobserver.h \
    viewobservable.h \
    gameobserver.h \
    gameobservable.h \
    answer.h
