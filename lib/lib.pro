TEMPLATE = lib
TARGET = qt-style

DEFINES += QT_NO_DEBUG_OUTPUT
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += LIBQT5UKUISTYLE_LIBRARY

CONFIG += c++11 link_pkgconfig
PKGCONFIG += gsettings-qt

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
