#include "graceful-enable-data.h"

namespace Graceful
{

bool EnableData::eventFilter(QObject *object, QEvent *event)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (!enabled()) {
        return WidgetStateData::eventFilter(object, event);
    }

    // check event type
    switch (event->type()) {
    // enter event
    case QEvent::EnabledChange: {
        if (QWidget *widget = qobject_cast<QWidget *>(object)) {
            updateState(widget->isEnabled());
        }
        break;
    }
    default:
        break;
    }

    return WidgetStateData::eventFilter(object, event);
}

}
