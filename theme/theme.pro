TEMPLATE        = lib
TARGET          = gracefulplatform
lessThan(QT_MINOR_VERSION, 9): error("Qt 5.9 and newer is required.")


QT              += \
    core-private                                            \
    dbus                                                    \
    gui-private                                             \
    theme_support-private                                   \
    widgets


QMAKE_LIBDIR    += \
    $$PWD/../common                                         \


INCLUDEPATH     += \
    $$PWD/../common                                         \


CONFIG          += \
    plugin                                                  \
    c++11                                                   \
    link_pkgconfig                                          \


LIBS            += \
    -lcommon


PKGCONFIG       += \
    adwaita-qt                                              \
    gtk+-3.0                                                \
    gtk+-x11-3.0                                            \


HEADERS         += \
    platformplugin.h                                        \
    qgnomeplatformtheme.h                                   \


SOURCES         += \
    platformplugin.cpp                                      \
    qgnomeplatformtheme.cpp                                 \


target.path     += \
    $$[QT_INSTALL_PLUGINS]/platformthemes                   \


INSTALLS        += \
    target                                                  \

