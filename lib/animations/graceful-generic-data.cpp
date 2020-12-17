#include "graceful-generic-data.h"

#include <QTextStream>

namespace Graceful
{

GenericData::GenericData(QObject *parent, QWidget *target, int duration) : AnimationData(parent, target), _animation(new Animation(duration, this)), _opacity(0)
{
    CT_SYSLOG(LOG_DEBUG, "");
    setupAnimation(_animation, "opacity");
}

}
