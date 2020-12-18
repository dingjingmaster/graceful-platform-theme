#include "graceful-animation-data.h"
#include "csyslog.h"

namespace Graceful
{

const qreal AnimationData::OpacityInvalid = -1;
int AnimationData::_steps = 0;

void AnimationData::setupAnimation(const Animation::Pointer &animation, const QByteArray &property)
{

    // setup animation
    animation.data()->setStartValue(0.0);
    animation.data()->setEndValue(1.0);
    animation.data()->setTargetObject(this);
    animation.data()->setPropertyName(property);
}

}
