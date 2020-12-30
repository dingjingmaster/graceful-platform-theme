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

    }

    //* destructor
    virtual ~BaseEngine()
    {

    }

    //* enability
    virtual void setEnabled(bool value)
    {

        _enabled = value;
    }

    //* enability
    virtual bool enabled() const
    {

        return _enabled;
    }

    //* duration
    virtual void setDuration(int value)
    {

        _duration = value;
    }

    //* duration
    virtual int duration() const
    {

        return _duration;
    }

    //* unregister widget
    virtual bool unregisterWidget(QObject *object) = 0;

    //* list of widgets
    using WidgetList = QSet<QWidget *>;

    //* returns registered widgets
    virtual WidgetList registeredWidgets() const
    {

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
