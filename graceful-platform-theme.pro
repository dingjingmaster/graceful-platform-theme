TEMPLATE            = subdirs

SUBDIRS             += \
    lib                                 \
    icon/graceful-icon.pro              \
    theme/graceful-theme.pro            \
    terminator/graceful-terminator.pro  \


#decoration.depends  = common
#theme.depends       = common

equals(QT_MAJOR_VERSION, 5):lessThan(QT_MINOR_VERSION, 12) {
    message("Cannot use Qt $${QT_VERSION}")
    error("Qt 5.12 and newer is required")
}
