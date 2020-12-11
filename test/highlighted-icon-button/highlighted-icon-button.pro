QT          += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG      += c++11

HEADERS     += \
    $$PWD/main-window.h                 \


SOURCES     += \
    $$PWD/main.cpp                      \
    $$PWD/main-window.cpp               \


FORMS       += \
    $$PWD/mainwindow.ui                 \
