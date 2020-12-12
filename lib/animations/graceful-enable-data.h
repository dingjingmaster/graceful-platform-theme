#ifndef GRACEFUL_ENABLE_DATA_H
#define GRACEFUL_ENABLE_DATA_H

#include "graceful-export.h"
#include "graceful-widget-state-data.h"

namespace Graceful
{
//* Enable data
class GRACEFUL_EXPORT EnableData : public WidgetStateData
{
    Q_OBJECT
public:
    //* constructor
    EnableData(QObject *parent, QWidget *target, int duration, bool state = true)
        : WidgetStateData(parent, target, duration, state)
    {
        target->installEventFilter(this);
    }

    //* destructor
    virtual ~EnableData()
    {
    }

    //* event filter
    virtual bool eventFilter(QObject *, QEvent *);
};

}

#endif
