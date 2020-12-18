#include "graceful-widget-state-data.h"

namespace Graceful
{

bool WidgetStateData::updateState(bool value)
{

    if (!_initialized) {
        _state = value;
        _initialized = true;
        return false;
    } else if (_state == value) {
        return false;
    } else {
        _state = value;
        animation().data()->setDirection(_state ? Animation::Forward : Animation::Backward);
        if (!animation().data()->isRunning()) {
            animation().data()->start();
        }
        return true;
    }
}

}
