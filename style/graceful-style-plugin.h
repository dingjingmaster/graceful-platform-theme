#ifndef GRACEFUL_GRACEFULSTYLEPLUGIN_H
#define GRACEFUL_GRACEFULSTYLEPLUGIN_H
#include <QStylePlugin>

namespace Graceful {

/**
 * @brief style 插件的入口
 */
class StylePlugin : public QStylePlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "graceful.json")
public:
    explicit StylePlugin(QObject *parent = 0);
    ~StylePlugin();

    QStringList keys() const;
    QStyle *create(const QString &key);
};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULSTYLEPLUGIN_H
