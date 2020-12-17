#include "graceful-dial-data.h"

#include <QDial>
#include <QHoverEvent>

namespace Graceful
{

DialData::DialData(QObject *parent, QWidget *target, int duration) : WidgetStateData(parent, target, duration), _position(-1, -1)
{
    CT_SYSLOG(LOG_DEBUG, "");
    target->installEventFilter(this);
}


bool DialData::eventFilter(QObject *object, QEvent *event)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (object != target().data()) {
        return WidgetStateData::eventFilter(object, event);
    }

    // check event type
    switch (event->type()) {
    case QEvent::HoverEnter:
    case QEvent::HoverMove:
        hoverMoveEvent(object, event);
        break;
    case QEvent::HoverLeave:
        hoverLeaveEvent(object, event);
        break;
    default:
        break;
    }

    return WidgetStateData::eventFilter(object, event);
}

void DialData::hoverMoveEvent(QObject *object, QEvent *event)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // try cast object to dial
    QDial *scrollBar(qobject_cast<QDial *>(object));
    if (!scrollBar || scrollBar->isSliderDown()) {
        return;
    }

    // cast event
    QHoverEvent *hoverEvent = static_cast<QHoverEvent *>(event);

    // store position
    _position = hoverEvent->pos();

    // trigger animation if position match handle rect
    updateState(_handleRect.contains(_position));
}

void DialData::hoverLeaveEvent(QObject *, QEvent *)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // reset hover state
    updateState(false);

    // reset mouse position
    _position = QPoint(-1, -1);
}

}
