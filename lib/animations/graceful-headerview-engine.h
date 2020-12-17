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
    explicit HeaderViewEngine(QObject *parent) : BaseEngine(parent)
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* destructor
    virtual ~HeaderViewEngine()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* register headerview
    virtual bool registerWidget(QWidget *);

    //* true if widget hover state is changed
    virtual bool updateState(const QObject *, const QPoint &, bool);

    //* true if widget is animated
    virtual bool isAnimated(const QObject *object, const QPoint &point)
    {
        CT_SYSLOG(LOG_DEBUG, "");
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
        CT_SYSLOG(LOG_DEBUG, "");
        return isAnimated(object, point) ? _data.find(object).data()->opacity(point) : AnimationData::OpacityInvalid;
    }

    //* enability
    virtual void setEnabled(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        BaseEngine::setEnabled(value);
        _data.setEnabled(value);
    }

    //* duration
    virtual void setDuration(int value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        BaseEngine::setDuration(value);
        _data.setDuration(value);
    }

public Q_SLOTS:

    //* remove widget from map
    virtual bool unregisterWidget(QObject *object)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _data.unregisterWidget(object);
    }

private:
    //* data map
    DataMap<HeaderViewData> _data;
};

}
#endif
