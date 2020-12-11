#ifndef ANIMATIONTABWIDGETPLUGINIFACE_H
#define ANIMATIONTABWIDGETPLUGINIFACE_H
#include "animator-plugin-iface.h"
#include "animation-tabwidget-iface.h"

#include <QString>

#define AnimatorTabWidgetPluginIface_iid        "org.dingjingmaster.style.animatons.TabWidgetPluginIface"

class AnimationTabwidgetPluginIface : public AnimatorPluginIface
{
public:
    AnimationTabwidgetPluginIface();
    virtual ~AnimationTabwidgetPluginIface() {}

    virtual const QString key() = 0;
    virtual const QString description() = 0;

    virtual AnimationTabwidgetPluginIface* createAnimator() = 0;
};

Q_DECLARE_INTERFACE(AnimationTabwidgetPluginIface, AnimatorTabWidgetPluginIface_iid)

#endif // ANIMATIONTABWIDGETPLUGINIFACE_H
