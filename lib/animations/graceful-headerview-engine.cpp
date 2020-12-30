#include "graceful-headerview-engine.h"

#include <QEvent>

namespace Graceful
{

bool HeaderViewEngine::registerWidget(QWidget *widget)
{

    if (!widget) {
        return false;
    }

    // create new data class
    if (!_data.contains(widget)) {
        _data.insert(widget, new HeaderViewData(this, widget, duration()), enabled());
    }

    // connect destruction signal
    connect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)), Qt::UniqueConnection);
    return true;
}

bool HeaderViewEngine::updateState(const QObject *object, const QPoint &position, bool value)
{

    DataMap<HeaderViewData>::Value data(_data.find(object));
    return (data && data.data()->updateState(position, value));
}

}
