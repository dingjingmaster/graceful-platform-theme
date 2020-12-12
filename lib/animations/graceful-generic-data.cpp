#include "graceful-generic-data.h"

#include <QTextStream>

namespace Graceful
{

//______________________________________________
GenericData::GenericData(QObject *parent, QWidget *target, int duration)
    : AnimationData(parent, target)
    , _animation(new Animation(duration, this))
    , _opacity(0)
{
    setupAnimation(_animation, "opacity");
}

}
