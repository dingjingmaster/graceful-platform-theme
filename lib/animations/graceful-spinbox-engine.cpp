#include "graceful-spinbox-engine.h"

#include <QEvent>

namespace Graceful
{

bool SpinBoxEngine::registerWidget(QWidget *widget)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (!widget) {
        return false;
    }

    // create new data class
    if (!_data.contains(widget)) {
        _data.insert(widget, new SpinBoxData(this, widget, duration()), enabled());
    }

    // connect destruction signal
    connect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)), Qt::UniqueConnection);
    return true;
}

}
