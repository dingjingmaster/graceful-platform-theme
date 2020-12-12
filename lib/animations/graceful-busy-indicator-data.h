#ifndef GRACEFUL_BUSY_INDICATOR_DATA_
#define GRACEFUL_BUSY_INDICATOR_DATA_
#include <QObject>

#include "graceful-export.h"


namespace Graceful
{
class Q_DECL_EXPORT BusyIndicatorData : public QObject
{
    Q_OBJECT
public:
    //* constructor
    explicit BusyIndicatorData(QObject *parent)
        : QObject(parent)
        , _animated(false)
    {
    }

    //* destructor
    virtual ~BusyIndicatorData()
    {
    }

    //*@name accessors
    //@{

    //* animated
    bool isAnimated() const
    {
        return _animated;
    }

    //@}

    //*@name modifiers
    //@{

    //* enabled
    void setEnabled(bool)
    {
    }

    //* enabled
    void setDuration(int)
    {
    }

    //* animated
    void setAnimated(bool value)
    {
        _animated = value;
    }

    //@}

private:
    //* animated
    bool _animated;
};

}

#endif
