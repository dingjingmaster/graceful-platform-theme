#include "graceful-transition-data.h"

namespace Graceful
{

TransitionData::TransitionData(QObject *parent, QWidget *target, int duration)
    : QObject(parent)
    , _transition(new TransitionWidget(target, duration))
{
    CT_SYSLOG(LOG_DEBUG, "");
    _transition.data()->hide();
}

TransitionData::~TransitionData()
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (_transition) {
        _transition.data()->deleteLater();
    }
}

}
