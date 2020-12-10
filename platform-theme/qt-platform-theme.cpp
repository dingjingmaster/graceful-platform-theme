#include "qt-platform-theme.h"

#include <QDebug>
#include <QTimer>
#include <QWidget>
#include <QVariant>
#include <QApplication>
#include <QApplication>
#include <QFontDatabase>
#include <QStandardPaths>
#include <private/qgenericunixthemes_p.h>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
#include <QFileInfo>
#include <QIcon>
#endif


QtPlatformTheme::QtPlatformTheme(const QStringList &args)
{

}

QtPlatformTheme::~QtPlatformTheme()
{

}

QVariant QtPlatformTheme::themeHint(QPlatformTheme::ThemeHint hint) const
{

}

const QFont *QtPlatformTheme::font(QPlatformTheme::Font type) const
{

}

const QPalette *QtPlatformTheme::palette(QPlatformTheme::Palette type) const
{

}
