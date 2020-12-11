TEMPLATE        = lib
TARGET = gracefulplatformtheme

lessThan(QT_MINOR_VERSION, 9): error("Qt 5.9 and newer is required.")


QT              += \
    core                                                                \
    gui                                                                 \
    waylandclient-private                                               \
    widgets                                                             \


QMAKE_USE       += \
    wayland-client


QMAKE_LIBDIR    += \
    $$PWD/../common                                                     \


CONFIG          += \
    plugin                                                              \
    c++11                                                               \
    link_pkgconfig                                                      \


INCLUDEPATH     += \
    $$PWD/../common                                                     \


LIBS            += \
    -lcommon                                                            \


PKGCONFIG       += \
    adwaita-qt                                                          \
    gtk+-3.0                                                            \


HEADERS         += \
    decorationplugin.h                                                  \
    qgnomeplatformdecoration.h                                          \


SOURCES         += \
    decorationplugin.cpp                                                \
    qgnomeplatformdecoration.cpp                                        \


target.path     += \
    $$[QT_INSTALL_PLUGINS]/wayland-decoration-client                    \


INSTALLS        += \
    target


