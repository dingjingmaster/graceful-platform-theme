#ifndef GRACEFUL_BASE_ENGINE_H
#define GRACEFUL_BASE_ENGINE_H

#include "graceful.h"
#include "graceful-export.h"

#include <QObject>
#include <QSet>

namespace Graceful
{
//* base class for all animation engines
/** it is used to store configuration values used by all animations stored in the engine */
class GRACEFUL_EXPORT BaseEngine : public QObject
{
    Q_OBJECT
public:
    using Pointer = WeakPointer<BaseEngine>;

    explicit BaseEngine(QObject *parent) : QObject(parent), _enabled(true), _duration(200)
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* destructor
    virtual ~BaseEngine()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* enability
    virtual void setEnabled(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _enabled = value;
    }

    //* enability
    virtual bool enabled() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _enabled;
    }

    //* duration
    virtual void setDuration(int value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _duration = value;
    }

    //* duration
    virtual int duration() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _duration;
    }

    //* unregister widget
    virtual bool unregisterWidget(QObject *object) = 0;

    //* list of widgets
    using WidgetList = QSet<QWidget *>;

    //* returns registered widgets
    virtual WidgetList registeredWidgets() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return WidgetList();
    }

private:
    //* engine enability
    bool _enabled;

    //* animation duration
    int _duration;
};

}

#endif
