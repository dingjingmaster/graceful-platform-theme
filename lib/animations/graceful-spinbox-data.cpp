#include "graceful-spinbox-data.h"

namespace Graceful
{

SpinBoxData::SpinBoxData(QObject *parent, QWidget *target, int duration)
    : AnimationData(parent, target)
{
    CT_SYSLOG(LOG_DEBUG, "");
    _upArrowData._hoverAnimation = new Animation(duration, this);
    _downArrowData._hoverAnimation = new Animation(duration, this);
    _upArrowData._pressedAnimation = new Animation(duration, this);
    _downArrowData._pressedAnimation = new Animation(duration, this);
    setupAnimation(upArrowAnimation(), "upArrowOpacity");
    setupAnimation(downArrowAnimation(), "downArrowOpacity");
    setupAnimation(upArrowPressedAnimation(), "upArrowPressed");
    setupAnimation(downArrowPressedAnimation(), "downArrowPressed");
}

bool SpinBoxData::Data::updateState(bool value, bool pressed)
{
    CT_SYSLOG(LOG_DEBUG, "");
    bool change = false;
    if (_hoverState != value) {
        _hoverState = value;
        _hoverAnimation.data()->setDirection((_hoverState) ? Animation::Forward : Animation::Backward);
        if (!_hoverAnimation.data()->isRunning()) {
            _hoverAnimation.data()->start();
        }
        change = true;
    }

    if (_pressedState != pressed) {
        _pressedState = pressed;
        _pressedAnimation.data()->setDirection((_pressedState) ? Animation::Forward : Animation::Backward);
        if (!_pressedAnimation.data()->isRunning()) {
            _pressedAnimation.data()->start();
        }
        change = true;
    }

    return change;
}

}
