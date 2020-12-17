#include "graceful-stacked-widget-engine.h"

namespace Graceful
{

bool StackedWidgetEngine::registerWidget(QStackedWidget *widget)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (!widget) {
        return false;
    }

    if (!_data.contains(widget)) {
        _data.insert(widget, new StackedWidgetData(this, widget, duration()), enabled());
    }

    // connect destruction signal
    disconnect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)));
    connect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)));

    return true;
}

}
