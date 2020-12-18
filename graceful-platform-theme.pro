TEMPLATE            = subdirs

SUBDIRS             += \
    lib                                 \
    data                                \
    demo                                \
    style                               \


style.depends = lib
demo.dedpends = style


OTHER_FILES         += \
    $$PWD/PKGBUILD                      \
    $$PWD/README.md                     \


equals(QT_MAJOR_VERSION, 5):lessThan(QT_MINOR_VERSION, 12) {
    message("Cannot use Qt $${QT_VERSION}")
    error("Qt 5.12 and newer is required")
}
