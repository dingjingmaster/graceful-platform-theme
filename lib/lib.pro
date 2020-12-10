TEMPLATE    = lib
TARGET      = qt-style

QT          += widgets concurrent

DEFINES += \
    QT_NO_DEBUG_OUTPUT          \
    QT_DEPRECATED_WARNINGS      \
    LIB_PLATFORM_THEME_LIBRARY

CONFIG += c++11 link_pkgconfig
PKGCONFIG += gsettings-qt

include($$PWD/animations/animations.pri)

HEADERS += \
    lib-global.h

DISTFILES += \
    org.qt.theme.style.gschema.xml

unix {
    target.path = $$[QT_INSTALL_LIBS]
    INSTALLS += target

    gschema.path = /usr/share/glib-2.0/schemas
    gschema.files += $$PWD/settings/org.qt.theme.style.gschema.xml
    INSTALLS += gschema
}
