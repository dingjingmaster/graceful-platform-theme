#ifndef GRACEFUL_WIDGET_STATE_DATA_H
#define GRACEFUL_WIDGET_STATE_DATA_H

#include "graceful-export.h"
#include "graceful-generic-data.h"

namespace Graceful
{
//* handle widget state (hover/focus/enable) changes
class GRACEFUL_EXPORT WidgetStateData : public GenericData
{
    Q_OBJECT
public:
    //* constructor
    WidgetStateData(QObject *parent, QWidget *target, int duration, bool state = false)
        : GenericData(parent, target, duration)
        , _initialized(false)
        , _state(state)
    {

    }

    //* destructor
    virtual ~WidgetStateData()
    {

    }

    /**
    returns true if hover has Changed
    and starts timer accordingly
    */
    virtual bool updateState(bool value);

private:
    bool _initialized;
    bool _state;
};

}
#endif
