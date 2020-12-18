#ifndef GRACEFUL_GRACEFULSTYLEPLUGIN_H
#define GRACEFUL_GRACEFULSTYLEPLUGIN_H
#include <QStylePlugin>

namespace Graceful {

class StylePlugin : public QStylePlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "graceful.json")
public:

    //* constructor
    explicit StylePlugin(QObject *parent = 0) : QStylePlugin(parent)
    {}

    //* destructor
    ~StylePlugin();

    //* returns list of valid keys
    QStringList keys() const;

    //* create style
    QStyle *create(const QString &key);
};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULSTYLEPLUGIN_H
