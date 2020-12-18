TEMPLATE        = app
TARGET          = graceful-demo


QT              += \
    core                                    \
    widgets                                 \


DEFINES         += \
     QT_DEBUG_PLUGINS                       \


HEADERS         += \
    $$PWD/widgetfactory.h                   \
    $$PWD/ui_widgetfactory.h                \


SOURCES         += \
    $$PWD/main.cpp                          \
    $$PWD/widgetfactory.cpp                 \


FORMS           += \
    $$PWD/widgetfactory.ui                  \
