#include "graceful-transition-data.h"

namespace Graceful
{

TransitionData::TransitionData(QObject *parent, QWidget *target, int duration)
    : QObject(parent)
    , _transition(new TransitionWidget(target, duration))
{

    _transition.data()->hide();
}

TransitionData::~TransitionData()
{

    if (_transition) {
        _transition.data()->deleteLater();
    }
}

}
