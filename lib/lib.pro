TEMPLATE            = lib
TARGET              = graceful

QT                  += \
    gui                                                     \
    core                                                    \
    dbus                                                    \
    widgets                                                 \
    gui-private                                             \
    widgets-private                                         \


CONFIG              += \
    gnu++11                                                 \
    gnu99                                                   \
    plugin                                                  \
    no_keywords                                             \
    debug_and_release                                       \


CONFIG(debug, debug|release) {
DEFINES             += \
    CSYSLOG_LOG_LEVEL=LOG_DEBUG
} else {
DEFINES             += \
    CSYSLOG_LOG_LEVEL=LOG_INFO
}


PKGCONFIG           += \
    gtk+-3.0                                                \
    gtk+-x11-3.0                                            \


HEADERS             += \
    $$PWD/csyslog.h                                         \
    $$PWD/graceful.h                                        \
    $$PWD/graceful-colors.h                                 \
    $$PWD/graceful-export.h                                 \
    $$PWD/graceful-mnemonics.h                              \
    $$PWD/graceful-window-manager.h                         \
    $$PWD/graceful-splitter-proxy.h                         \
    $$PWD/graceful-widget-explorer.h                        \
    $$PWD/graceful-add-event-filter.h                       \
    $$PWD/animations/graceful-datamap.h                     \
    $$PWD/animations/graceful-dial-data.h                   \
    $$PWD/animations/graceful-animation.h                   \
    $$PWD/animations/graceful-animations.h                  \
    $$PWD/animations/graceful-tabbar-data.h                 \
    $$PWD/animations/graceful-base-engine.h                 \
    $$PWD/animations/graceful-dial-engine.h                 \
    $$PWD/animations/graceful-enable-data.h                 \
    $$PWD/animations/graceful-generic-data.h                \
    $$PWD/animations/graceful-spinbox-data.h                \
    $$PWD/animations/graceful-tabbar-engine.h               \
    $$PWD/animations/graceful-spinbox-engine.h              \
    $$PWD/animations/graceful-scrollbar-data.h              \
    $$PWD/animations/graceful-animation-data.h              \
    $$PWD/animations/graceful-headerview-data.h             \
    $$PWD/animations/graceful-tool-box-engine.h             \
    $$PWD/animations/graceful-transition-data.h             \
    $$PWD/animations/graceful-scrollbar-engine.h            \
    $$PWD/animations/graceful-widget-state-data.h           \
    $$PWD/animations/graceful-transition-widget.h           \
    $$PWD/animations/graceful-headerview-engine.h           \
    $$PWD/animations/graceful-stacked-widget-data.h         \
    $$PWD/animations/graceful-busy-indicator-data.h         \
    $$PWD/animations/graceful-widget-state-engine.h         \
    $$PWD/animations/graceful-busy-indicator-engine.h       \
    $$PWD/animations/graceful-stacked-widget-engine.h       \


SOURCES             += \
    $$PWD/csyslog.cpp                                       \
    $$PWD/graceful.cpp                                      \
    $$PWD/graceful-colors.cpp                               \
    $$PWD/graceful-mnemonics.cpp                            \
    $$PWD/graceful-splitter-proxy.cpp                       \
    $$PWD/graceful-window-manager.cpp                       \
    $$PWD/graceful-widget-explorer.cpp                      \
    $$PWD/graceful-add-event-filter.cpp                     \
    $$PWD/animations/graceful-dial-data.cpp                 \
    $$PWD/animations/graceful-animation.cpp                 \
    $$PWD/animations/graceful-animations.cpp                \
    $$PWD/animations/graceful-tabbar-data.cpp               \
    $$PWD/animations/graceful-base-engine.cpp               \
    $$PWD/animations/graceful-dial-engine.cpp               \
    $$PWD/animations/graceful-enable-data.cpp               \
    $$PWD/animations/graceful-generic-data.cpp              \
    $$PWD/animations/graceful-spinbox-data.cpp              \
    $$PWD/animations/graceful-tabbar-engine.cpp             \
    $$PWD/animations/graceful-spinbox-engine.cpp            \
    $$PWD/animations/graceful-scrollbar-data.cpp            \
    $$PWD/animations/graceful-animation-data.cpp            \
    $$PWD/animations/graceful-headerview-data.cpp           \
    $$PWD/animations/graceful-tool-box-engine.cpp           \
    $$PWD/animations/graceful-transition-data.cpp           \
    $$PWD/animations/graceful-scrollbar-engine.cpp          \
    $$PWD/animations/graceful-widget-state-data.cpp         \
    $$PWD/animations/graceful-transition-widget.cpp         \
    $$PWD/animations/graceful-headerview-engine.cpp         \
    $$PWD/animations/graceful-stacked-widget-data.cpp       \
    $$PWD/animations/graceful-busy-indicator-data.cpp       \
    $$PWD/animations/graceful-widget-state-engine.cpp       \
    $$PWD/animations/graceful-busy-indicator-engine.cpp     \
    $$PWD/animations/graceful-stacked-widget-engine.cpp     \
