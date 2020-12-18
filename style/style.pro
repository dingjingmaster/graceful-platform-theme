TEMPLATE            = lib
TARGET              = graceful

QT                  += \
    gui                                                     \
    core                                                    \
    dbus                                                    \
    widgets                                                 \
    gui-private                                             \
    widgets-private                                         \
    theme_support-private                                   \


DEFINES += PROXYSTYLE_LIBRARY


CONFIG(debug, debug|release) {
DEFINES             += \
    CSYSLOG_LOG_LEVEL=LOG_DEBUG
} else {
DEFINES             += \
    CSYSLOG_LOG_LEVEL=LOG_INFO
}


CONFIG              += \
    gnu++11                                                 \
    gnu99                                                   \
    plugin                                                  \
    no_keywords                                             \
    link_pkgconfig                                          \
    debug_and_release                                       \


PKGCONFIG           += \
    gtk+-3.0                                                \
    gtk+-x11-3.0                                            \


include($$PWD/../lib/lib.pri)


OTHER_FILES         += \
    $$PWD/graceful.themerc                                  \


DISTFILES           += \
    $$PWD/graceful.json                                     \


graceful_plugin1.path    = /usr/lib/qt/plugins/styles/
graceful_plugin1.files   = $$OUT_PWD/*.so


INSTALLS        += \
    graceful_plugin1                                        \
