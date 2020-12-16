TEMPLATE        = lib
TARGET          = graceful

QT              += \
    core                                                    \
    dbus                                                    \
    widgets                                                 \
    theme_support-private                                   \


CONFIG          += \
    gnu++11                                                 \
    gnu99                                                   \
    plugin                                                  \
    no_keywords                                             \
    link_pkgconfig                                          \
    debug_and_release                                       \


CONFIG(debug, debug|release) {
DEFINES         += \
    CSYSLOG_LOG_LEVEL=LOG_DEBUG
} else {
DEFINES         += \
    CSYSLOG_LOG_LEVEL=LOG_INFO
}


PKGCONFIG       += \
    gtk+-3.0                                                \
    gtk+-x11-3.0                                            \


HEADERS         += \
    csyslog.h                                               \
    graceful.h                                              \
    graceful-colors.h                                       \
    graceful-export.h                                       \
    graceful-mnemonics.h                                    \
    graceful-window-manager.h                               \
    graceful-splitter-proxy.h                               \
    graceful-widget-explorer.h                              \
    graceful-add-event-filter.h                             \
    animations/graceful-datamap.h                           \
    animations/graceful-dial-data.h                         \
    animations/graceful-animation.h                         \
    animations/graceful-animations.h                        \
    animations/graceful-tabbar-data.h                       \
    animations/graceful-base-engine.h                       \
    animations/graceful-dial-engine.h                       \
    animations/graceful-enable-data.h                       \
    animations/graceful-generic-data.h                      \
    animations/graceful-spinbox-data.h                      \
    animations/graceful-tabbar-engine.h                     \
    animations/graceful-spinbox-engine.h                    \
    animations/graceful-scrollbar-data.h                    \
    animations/graceful-animation-data.h                    \
    animations/graceful-headerview-data.h                   \
    animations/graceful-tool-box-engine.h                   \
    animations/graceful-transition-data.h                   \
    animations/graceful-scrollbar-engine.h                  \
    animations/graceful-widget-state-data.h                 \
    animations/graceful-transition-widget.h                 \
    animations/graceful-headerview-engine.h                 \
    animations/graceful-stacked-widget-data.h               \
    animations/graceful-busy-indicator-data.h               \
    animations/graceful-widget-state-engine.h               \
    animations/graceful-busy-indicator-engine.h             \
    animations/graceful-stacked-widget-engine.h             \


SOURCES         += \
    csyslog.cpp                                             \
    graceful.cpp                                            \
    graceful-colors.cpp                                     \
    graceful-mnemonics.cpp                                  \
    graceful-splitter-proxy.cpp                             \
    graceful-window-manager.cpp                             \
    graceful-widget-explorer.cpp                            \
    graceful-add-event-filter.cpp                           \
    animations/graceful-dial-data.cpp                       \
    animations/graceful-animation.cpp                       \
    animations/graceful-animations.cpp                      \
    animations/graceful-tabbar-data.cpp                     \
    animations/graceful-base-engine.cpp                     \
    animations/graceful-dial-engine.cpp                     \
    animations/graceful-enable-data.cpp                     \
    animations/graceful-generic-data.cpp                    \
    animations/graceful-spinbox-data.cpp                    \
    animations/graceful-tabbar-engine.cpp                   \
    animations/graceful-spinbox-engine.cpp                  \
    animations/graceful-scrollbar-data.cpp                  \
    animations/graceful-animation-data.cpp                  \
    animations/graceful-headerview-data.cpp                 \
    animations/graceful-tool-box-engine.cpp                 \
    animations/graceful-transition-data.cpp                 \
    animations/graceful-scrollbar-engine.cpp                \
    animations/graceful-widget-state-data.cpp               \
    animations/graceful-transition-widget.cpp               \
    animations/graceful-headerview-engine.cpp               \
    animations/graceful-stacked-widget-data.cpp             \
    animations/graceful-busy-indicator-data.cpp             \
    animations/graceful-widget-state-engine.cpp             \
    animations/graceful-busy-indicator-engine.cpp           \
    animations/graceful-stacked-widget-engine.cpp           \


graceful_plugin1.path    = /usr/lib/qt/plugins/styles/
graceful_plugin1.files   = $$OUT_PWD/*.so


INSTALLS        += \
    graceful_plugin1                                        \
