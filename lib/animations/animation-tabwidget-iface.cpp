#include "animation-tabwidget-iface.h"

AnimationTabwidgetIface::AnimationTabwidgetIface()
{

}

AnimationTabwidgetIface::~AnimationTabwidgetIface()
{

}

bool AnimationTabwidgetIface::bindWidget(QWidget *w)
{
    return bindTabWidget(qobject_cast<QTabWidget *>(w));
}

bool AnimationTabwidgetIface::unboundWidget()
{
    return unboundTabWidget();
}
