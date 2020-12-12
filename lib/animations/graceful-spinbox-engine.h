#ifndef GRACEFUL_SPINBOX_ENGINE_H
#define GRACEFUL_SPINBOX_ENGINE_H

#include "graceful-export.h"
#include "graceful-datamap.h"
#include "graceful-base-engine.h"
#include "graceful-spinbox-data.h"

namespace Graceful
{
//* handle spinbox arrows hover effect
class GRACEFUL_EXPORT SpinBoxEngine : public BaseEngine
{
    Q_OBJECT
public:
    //* constructor
    explicit SpinBoxEngine(QObject *parent)
        : BaseEngine(parent)
    {
    }

    //* destructor
    virtual ~SpinBoxEngine()
    {
    }

    //* register widget
    virtual bool registerWidget(QWidget *);

    //* state
    virtual bool updateState(const QObject *object, QStyle::SubControl subControl, bool value, bool pressed)
    {
        if (DataMap<SpinBoxData>::Value data = _data.find(object)) {
            return data.data()->updateState(subControl, value, pressed);
        } else {
            return false;
        }
    }

    //* true if widget is animated
    virtual bool isAnimated(const QObject *object, QStyle::SubControl subControl)
    {
        if (DataMap<SpinBoxData>::Value data = _data.find(object)) {
            return data.data()->isAnimated(subControl);
        } else {
            return false;
        }
    }

    //* animation opacity
    virtual qreal opacity(const QObject *object, QStyle::SubControl subControl)
    {
        if (DataMap<SpinBoxData>::Value data = _data.find(object)) {
            return data.data()->opacity(subControl);
        } else {
            return AnimationData::OpacityInvalid;
        }
    }

    //* animation opacity
    virtual qreal pressed(const QObject *object, QStyle::SubControl subControl)
    {
        if (DataMap<SpinBoxData>::Value data = _data.find(object)) {
            return data.data()->pressed(subControl);
        } else {
            return AnimationData::OpacityInvalid;
        }
    }

    //* enability
    virtual void setEnabled(bool value)
    {
        BaseEngine::setEnabled(value);
        _data.setEnabled(value);
    }

    //* duration
    virtual void setDuration(int value)
    {
        BaseEngine::setDuration(value);
        _data.setDuration(value);
    }

public Q_SLOTS:

    //* remove widget from map
    virtual bool unregisterWidget(QObject *object)
    {
        return _data.unregisterWidget(object);
    }

private:
    //* data map
    DataMap<SpinBoxData> _data;
};

}

#endif
