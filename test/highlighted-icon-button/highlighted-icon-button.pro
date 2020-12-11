QT          += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG      += \
    c++11


DEFINES     += \
    QT_DEPRECATED_WARNINGS


HEADERS     += \
    $$PWD/main-window.h                 \


SOURCES     += \
    $$PWD/main.c                        \
    $$PWD/main-window.cpp               \


FORMS       += \
    $$PWD/mainwindow.ui                 \
