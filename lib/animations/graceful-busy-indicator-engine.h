#ifndef GRAACEFUL_BUSY_INDICATOR_ENGINE_H
#define GRAACEFUL_BUSY_INDICATOR_ENGINE_H

#include "graceful-export.h"
#include "graceful-datamap.h"
#include "graceful-animation.h"
#include "graceful-base-engine.h"
#include "graceful-busy-indicator-data.h"

namespace Graceful
{
//* handles progress bar animations
class GRACEFUL_EXPORT BusyIndicatorEngine : public BaseEngine
{
    Q_OBJECT

    //* declare opacity property
    Q_PROPERTY(int value READ value WRITE setValue)

public:
    explicit BusyIndicatorEngine(QObject *);

    virtual ~BusyIndicatorEngine()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //*@name accessors
    //@{

    //* true if widget is animated
    virtual bool isAnimated(const QObject *);

    //* value
    virtual int value() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _value;
    }

    //@}

    //*@name modifiers
    //@{

    //* register progressbar
    virtual bool registerWidget(QObject *);

    //* duration
    virtual void setDuration(int);

    //* set object as animated
    virtual void setAnimated(const QObject *, bool);

    //* opacity
    virtual void setValue(int value);

    //@}

public Q_SLOTS:

    //* remove widget from map
    virtual bool unregisterWidget(QObject *);

protected:
    //* returns data associated to widget
    DataMap<BusyIndicatorData>::Value data(const QObject *);

private:
    //* map widgets to progressbar data
    DataMap<BusyIndicatorData> _data;

    //* animation
    Animation::Pointer _animation;

    //* value
    int _value = 0;
};

}

#endif
