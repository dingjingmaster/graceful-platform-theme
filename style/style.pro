TEMPLATE            = lib
TARGET              = graceful-style

QT                  += \
    gui                                                     \
    dbus                                                    \
    widgets                                                 \


DEFINES += PROXYSTYLE_LIBRARY


CONFIG              += \
    gnu++11                                                 \
    gnu99                                                   \
    plugin                                                  \
    no_keywords                                             \
    debug_and_release                                       \


INCLUDEPATH         += \
    -I $$PWD/../lib/                                        \


LIBS                += \
    -L $$PWD/../lib/                                        \
    -lgraceful                                              \


HEADERS             += \
    $$PWD/graceful-style.h                                  \
    $$PWD/graceful-helper.h                                 \
    $$PWD/graceful-style-plugin.h                           \


SOURCES             += \
    $$PWD/graceful-style.cpp                                \
    $$PWD/graceful-helper.cpp                               \
    $$PWD/graceful-style-plugin.cpp                         \


OTHER_FILES         += \
    $$PWD/graceful.themerc                                  \


DISTFILES           += \
    $$PWD/graceful.json                                     \


graceful_plugin1.path    = /usr/lib/qt/plugins/styles/
graceful_plugin1.files   = $$OUT_PWD/libgraceful-style.so


INSTALLS            += \
    graceful_plugin1                                        \
