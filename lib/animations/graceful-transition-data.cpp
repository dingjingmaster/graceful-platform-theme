#include "graceful-transition-data.h"

namespace Graceful
{

//_________________________________________________________________
TransitionData::TransitionData(QObject *parent, QWidget *target, int duration)
    : QObject(parent)
    , _transition(new TransitionWidget(target, duration))
{
    _transition.data()->hide();
}

//_________________________________________________________________
TransitionData::~TransitionData()
{
    if (_transition) {
        _transition.data()->deleteLater();
    }
}

}
