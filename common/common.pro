
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


PKGCONFIG       += \
    gtk+-3.0                                    \
    adwaita-qt                                  \
    gtk+-x11-3.0                                \


HEADERS         += \
    gnomehintssettings.h                        \
    qgtk3dialoghelpers.h                        \
    qxdgdesktopportalfiledialog_p.h             \


SOURCES         += \
    gnomehintssettings.cpp                      \
    qgtk3dialoghelpers.cpp                      \
    qxdgdesktopportalfiledialog.cpp             \


