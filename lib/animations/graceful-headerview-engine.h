#ifndef GRACEFUL_HEADER_VIEW_ENGINE_H
#define GRACEFUL_HEADER_VIEW_ENGINE_H
#include "graceful-export.h"
#include "graceful-datamap.h"
#include "graceful-base-engine.h"
#include "graceful-headerview-data.h"

namespace Graceful
{
//* stores headerview hovered action and timeLine
class GRACEFUL_EXPORT HeaderViewEngine : public BaseEngine
{
    Q_OBJECT
public:
    //* constructor
    explicit HeaderViewEngine(QObject *parent)
        : BaseEngine(parent)
    {
    }

    //* destructor
    virtual ~HeaderViewEngine()
    {
    }

    //* register headerview
    virtual bool registerWidget(QWidget *);

    //* true if widget hover state is changed
    virtual bool updateState(const QObject *, const QPoint &, bool);

    //* true if widget is animated
    virtual bool isAnimated(const QObject *object, const QPoint &point)
    {
        if (DataMap<HeaderViewData>::Value data = _data.find(object)) {
            if (Animation::Pointer animation = data.data()->animation(point)) {
                return animation.data()->isRunning();
            }
        }

        return false;
    }

    //* animation opacity
    virtual qreal opacity(const QObject *object, const QPoint &point)
    {
        return isAnimated(object, point) ? _data.find(object).data()->opacity(point) : AnimationData::OpacityInvalid;
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
    DataMap<HeaderViewData> _data;
};

}
#endif
