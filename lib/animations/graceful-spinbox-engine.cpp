#include "graceful-spinbox-engine.h"

#include <QEvent>

namespace Graceful
{

//____________________________________________________________
bool SpinBoxEngine::registerWidget(QWidget *widget)
{
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
