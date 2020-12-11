#ifndef ANIMATIONTABWIDGETDEFAULTSLIDEFACTORY_H
#define ANIMATIONTABWIDGETDEFAULTSLIDEFACTORY_H
#include "animation-tabwidget-plugin-iface.h"

#include <QObject>

namespace TabWidget {
class AnimationTabwidgetDefaultSlideFactory : public QObject, public AnimationTabwidgetPluginIface
{
    Q_OBJECT
public:
    explicit AnimationTabwidgetDefaultSlideFactory(QObject* parent = nullptr);

    const QString id () {return tr("Default Slide");}
    const QString brief () {return tr("Let tab widget switch with a slide animation.");}

    const QString key () {return "tab_slide";}
    const QString description () {return brief();}
    AnimatorPluginType pluginType () {return TabWidget;}

    const QString inhertKey () {return "QTabWidget";}
    const QStringList excludeKeys () {return QStringList()<<"DirectoryWidget";}
    bool isParallel () {return false;}

    AnimationTabwidgetPluginIface* createAnimator ();
};
}

#endif // ANIMATIONTABWIDGETDEFAULTSLIDEFACTORY_H
