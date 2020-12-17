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
    explicit BusyIndicatorData(QObject *parent) : QObject(parent), _animated(false)
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* destructor
    virtual ~BusyIndicatorData()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //*@name accessors
    //@{

    //* animated
    bool isAnimated() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _animated;
    }

    //@}

    //*@name modifiers
    //@{

    //* enabled
    void setEnabled(bool)
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* enabled
    void setDuration(int)
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* animated
    void setAnimated(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _animated = value;
    }

    //@}

private:
    //* animated
    bool _animated;
};

}

#endif
