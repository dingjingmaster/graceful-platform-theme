#include "graceful-style-plugin.h"

#include "csyslog.h"
#include "graceful-style.h"

#include <QApplication>

namespace Graceful {

QStyle* StylePlugin::create(const QString &key)
{
    CT_SYSLOG(LOG_DEBUG, "create style...");
    if (key.toLower() == QStringLiteral("graceful")) {
        return new Style(false);
    }

    if (key.toLower() == QStringLiteral("graceful-dark")) {
        return new Style(true);
    }

    return nullptr;
}

StylePlugin::StylePlugin(QObject *parent) : QStylePlugin(parent)
{

}

StylePlugin::~StylePlugin()
{

}

QStringList StylePlugin::keys() const
{
    return QStringList() << QStringLiteral("graceful") << QStringLiteral("graceful-Dark");
}
} // namespace Graceful
