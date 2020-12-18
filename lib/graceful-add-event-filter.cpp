#include "graceful-add-event-filter.h"

namespace Graceful {
AddEventFilter::AddEventFilter(QObject *parent) : QObject(parent)
{


}

AddEventFilter::~AddEventFilter()
{


}

bool Graceful::AddEventFilter::eventFilter(QObject *, QEvent *event)
{

    return event->type() == QEvent::ChildAdded;
}

}
