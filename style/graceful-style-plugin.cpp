#include "graceful-style-plugin.h"
#include "graceful-style.h"
#include "csyslog.h"

#include <QApplication>

namespace Graceful {

QStyle *StylePlugin::create(const QString &key)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (key.toLower() == QStringLiteral("graceful")) {
        return new Style(false);
    }

    if (key.toLower() == QStringLiteral("graceful-dark")) {
        return new Style(true);
    }

    return nullptr;
}

StylePlugin::~StylePlugin()
{
    CT_SYSLOG(LOG_DEBUG, "");
}

QStringList StylePlugin::keys() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    return QStringList() << QStringLiteral("graceful") << QStringLiteral("graceful-Dark");
}
} // namespace Graceful
