TEMPLATE        = lib
TARGET          = qt-platform-theme

QT              += widgets dbus gui-private widgets-private

greaterThan(QT_MAJOR_VERSION, 5) | greaterThan(QT_MINOR_VERSION, 7): \
    QT          += theme_support-private
else: \
    QT          += platformsupport-private

CONFIG          += plugin
CONFIG          += c++11 link_pkgconfig

DEFINES         += QT_NO_DEBUG_OUTPUT
DEFINES         += QT_DEPRECATED_WARNINGS
DEFINES         += QT_PLATFORM_THEME_LIBRARY

PKGCONFIG       += gsettings-qt

SOURCES         += \
    $PWD/main.cpp \
    qt-platform-theme.cpp

DISTFILES       += \
    $PWD/platfrom-theme.json

unix {
    target.path = $$[QT_INSTALL_PLUGINS]/platformthemes
    INSTALLS    += target
}

HEADERS += \
    qt-platform-theme-global.h \
    qt-platform-theme.h
