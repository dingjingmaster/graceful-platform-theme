#include "graceful-tool-box-engine.h"

namespace Graceful
{

bool ToolBoxEngine::registerWidget(QWidget *widget)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (!widget) {
        return false;
    }

    if (!_data.contains(widget)) {
        _data.insert(widget, new WidgetStateData(this, widget, duration()), enabled());
    }

    // connect destruction signal
    connect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)), Qt::UniqueConnection);
    return true;
}

bool ToolBoxEngine::updateState(const QPaintDevice *object, bool value)
{
    CT_SYSLOG(LOG_DEBUG, "");
    PaintDeviceDataMap<WidgetStateData>::Value data(ToolBoxEngine::data(object));
    return (data && data.data()->updateState(value));
}

bool ToolBoxEngine::isAnimated(const QPaintDevice *object)
{
    CT_SYSLOG(LOG_DEBUG, "");
    PaintDeviceDataMap<WidgetStateData>::Value data(ToolBoxEngine::data(object));
    return (data && data.data()->animation() && data.data()->animation().data()->isRunning());
}

}
