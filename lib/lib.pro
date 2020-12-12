TEMPLATE        = lib

QT              += \
    core                                        \
    dbus                                        \
    theme_support-private                       \
    widgets                                     \


CONFIG          += \
    c++11                                       \
    staticlib                                   \
    link_pkgconfig                              \
    debug_and_release                           \


CONFIG(debug, debug|release) {
DEFINES         += \
    CSYSLOG_LOG_LEVEL=LOG_DEBUG
} else {
DEFINES         += \
    CSYSLOG_LOG_LEVEL=LOG_INFO
}


PKGCONFIG       += \
    gtk+-3.0                                    \
    adwaita-qt                                  \
    gtk+-x11-3.0                                \


HEADERS         += \
    csyslog.h                                   \
    graceful.h                                  \
    graceful-export.h                           \


SOURCES         += \
    csyslog.cpp                                 \
    graceful.cpp                                \


