#include "graceful-busy-indicator-engine.h"
#include "graceful.h"

#include <QVariant>

namespace Graceful
{

BusyIndicatorEngine::BusyIndicatorEngine(QObject *object) : BaseEngine(object)
{
    CT_SYSLOG(LOG_DEBUG, "");
}

bool BusyIndicatorEngine::registerWidget(QObject *object)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // check widget validity
    if (!object) return false;

    // create new data class
    if (!_data.contains(object)) {
        _data.insert(object, new BusyIndicatorData(this));

        // connect destruction signal
        connect(object, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)), Qt::UniqueConnection);
    }

    return true;
}


bool BusyIndicatorEngine::isAnimated(const QObject *object)
{
    CT_SYSLOG(LOG_DEBUG, "");
    DataMap<BusyIndicatorData>::Value data(BusyIndicatorEngine::data(object));
    return data && data.data()->isAnimated();
}


void BusyIndicatorEngine::setDuration(int value)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (duration() == value) {
        return;
    }

    BaseEngine::setDuration(value);

    // restart timer with specified time
    if (_animation) {
        _animation.data()->setDuration(value);
    }
}


void BusyIndicatorEngine::setAnimated(const QObject *object, bool value)
{
    CT_SYSLOG(LOG_DEBUG, "");
    DataMap<BusyIndicatorData>::Value data(BusyIndicatorEngine::data(object));
    if (data) {
        // update data
        data.data()->setAnimated(value);

        // start timer if needed
        if (value) {
            if (!_animation) {
                // create animation if not already there
                _animation = new Animation(duration(), this);

                // setup
                _animation.data()->setStartValue(0.0);
                _animation.data()->setEndValue(100.0);
                _animation.data()->setTargetObject(this);
                _animation.data()->setPropertyName("value");
                _animation.data()->setLoopCount(-1);
                _animation.data()->setDuration(duration() * 3);
            }

            // start if  not already running
            if (!_animation.data()->isRunning()) {
                _animation.data()->start();
            }
        }
    }

    return;
}

DataMap<BusyIndicatorData>::Value BusyIndicatorEngine::data(const QObject *object)
{
    CT_SYSLOG(LOG_DEBUG, "");
    return _data.find(object).data();
}

void BusyIndicatorEngine::setValue(int value)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // update
    _value = value;

    bool animated(false);

    // loop over objects in map
    for (DataMap<BusyIndicatorData>::iterator iter = _data.begin(); iter != _data.end(); ++iter) {
        if (iter.value().data()->isAnimated()) {
            // update animation flag
            animated = true;

            // emit update signal on object
            if (const_cast<QObject *>(iter.key())->inherits("QQuickStyleItem")) {
                //QtQuickControls "rerender" method is updateItem
                QMetaObject::invokeMethod(const_cast<QObject *>(iter.key()), "updateItem", Qt::QueuedConnection);
            } else {

                QMetaObject::invokeMethod(const_cast<QObject *>(iter.key()), "update", Qt::QueuedConnection);
            }
        }
    }

    if (_animation && !animated) {
        _animation.data()->stop();
        _animation.data()->deleteLater();
        _animation.clear();
    }
}

bool BusyIndicatorEngine::unregisterWidget(QObject *object)
{
    CT_SYSLOG(LOG_DEBUG, "");
    bool removed(_data.unregisterWidget(object));
    if (_animation && _data.isEmpty()) {
        _animation.data()->stop();
        _animation.data()->deleteLater();
        _animation.clear();
    }

    return removed;
}

}
