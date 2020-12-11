#include "animation-tabwidget-default-slide-factory.h"

using namespace TabWidget;

TabWidget::AnimationTabwidgetDefaultSlideFactory::AnimationTabwidgetDefaultSlideFactory(QObject *parent) : QObject(parent)
{

}

AnimationTabwidgetPluginIface* TabWidget::AnimationTabwidgetDefaultSlideFactory::createAnimator()
{
    return new AnimationTabwidgetDefaultSlideFactory;
}
