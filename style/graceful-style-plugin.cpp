#include "graceful-style-plugin.h"
#include "graceful-style.h"
#include "csyslog.h"

#include <QApplication>

namespace Graceful {

QStyle *StylePlugin::create(const QString &key)
{
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

}

QStringList StylePlugin::keys() const
{
    return QStringList() << QStringLiteral("graceful") << QStringLiteral("graceful-Dark");
}
} // namespace Graceful
