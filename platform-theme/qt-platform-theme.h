#ifndef QTPLATFORMTHEME_H
#define QTPLATFORMTHEME_H
#include "qt-platform-theme-global.h"

#include <QFont>
#include <QObject>
#include <qpa/qplatformtheme.h>

#if !defined(QT_NO_DBUS) && defined (QT_DBUS_LIB)
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)) && !defined(QT_NO_SYSTEMTRAYICON)
#define DBUS_TRAY
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
#define GLOBAL_MENU
#endif

#endif

class QPalette;
#ifdef DBUS_TRAY
class QPlatformSystemTrayIcon;
#endif

#ifdef GLOBAL_MENU
class QPlatformMenuBar;
#endif

class QT_PLATFORM_THEME_SHARED_EXPORT QtPlatformTheme : public QObject, public QPlatformTheme
{
    Q_OBJECT
public:
    QtPlatformTheme(const QStringList& args);
    ~QtPlatformTheme();

    virtual QVariant            themeHint   (ThemeHint hint) const override;
    virtual const QFont*        font        (Font type = SystemFont) const override;
    virtual const QPalette*     palette     (Palette type = SystemPalette) const override;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
    virtual bool usePlatformNativeDialog    (DialogType type) const override;
    virtual QPlatformDialogHelper *createPlatformDialogHelper (DialogType type) const override;
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    virtual QIcon fileIcon(const QFileInfo &fileInfo, QPlatformTheme::IconOptions iconOptions = 0) const;
#endif

#ifdef GLOBAL_MENU
    virtual QPlatformMenuBar*   createPlatformMenuBar() const override;
#endif

#ifdef DBUS_TRAY
    QPlatformSystemTrayIcon*    createPlatformSystemTrayIcon() const override;
#endif

private:
    QFont                       mSystemFont;
    QFont                       mFixedFont;
};

#endif // QTPLATFORMTHEME_H
