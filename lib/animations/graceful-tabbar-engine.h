#ifndef GRACEFUL_TABBAR_ENGINE_H
#define GRACEFUL_TABBAR_ENGINE_H

#include "graceful.h"
#include "graceful-export.h"
#include "graceful-datamap.h"
#include "graceful-base-engine.h"
#include "graceful-tabbar-data.h"

namespace Graceful
{
//* stores tabbar hovered action and timeLine
class GRACEFUL_EXPORT TabBarEngine : public BaseEngine
{
    Q_OBJECT
public:
    //* constructor
    explicit TabBarEngine(QObject *parent)
        : BaseEngine(parent)
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* destructor
    virtual ~TabBarEngine()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* register tabbar
    virtual bool registerWidget(QWidget *);

    //* true if widget hover state is changed
    virtual bool updateState(const QObject *, const QPoint &, AnimationMode, bool);

    //* true if widget is animated
    virtual bool isAnimated(const QObject *object, const QPoint &point, AnimationMode);

    //* animation opacity
    virtual qreal opacity(const QObject *object, const QPoint &point, AnimationMode mode)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return isAnimated(object, point, mode) ? data(object, mode).data()->opacity(point) : AnimationData::OpacityInvalid;
    }

    //* enability
    virtual void setEnabled(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        BaseEngine::setEnabled(value);
        _hoverData.setEnabled(value);
        _focusData.setEnabled(value);
    }

    //* duration
    virtual void setDuration(int value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        BaseEngine::setDuration(value);
        _hoverData.setDuration(value);
        _focusData.setDuration(value);
    }

public Q_SLOTS:

    //* remove widget from map
    virtual bool unregisterWidget(QObject *object)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        if (!object) {
            return false;
        }

        bool found = false;
        if (_hoverData.unregisterWidget(object)) {
            found = true;
        }

        if (_focusData.unregisterWidget(object)) {
            found = true;
        }

        return found;
    }

private:
    //* returns data associated to widget
    DataMap<TabBarData>::Value data(const QObject *, AnimationMode);

    //* data map
    DataMap<TabBarData> _hoverData;
    DataMap<TabBarData> _focusData;
};

}

#endif
