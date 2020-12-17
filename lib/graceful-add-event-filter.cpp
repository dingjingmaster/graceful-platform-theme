#include "graceful-add-event-filter.h"

namespace Graceful {
AddEventFilter::AddEventFilter(QObject *parent) : QObject(parent)
{
    CT_SYSLOG(LOG_DEBUG, "");

}

AddEventFilter::~AddEventFilter()
{
    CT_SYSLOG(LOG_DEBUG, "");

}

bool Graceful::AddEventFilter::eventFilter(QObject *, QEvent *event)
{
    CT_SYSLOG(LOG_DEBUG, "");
    return event->type() == QEvent::ChildAdded;
}

}
