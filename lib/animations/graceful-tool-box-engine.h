#ifndef GRACEFUL_TOOLBOX_ENGINE_H
#define GRACEFUL_TOOLBOX_ENGINE_H

#include "graceful-export.h"
#include "graceful-datamap.h"
#include "graceful-base-engine.h"
#include "graceful-widget-state-data.h"

namespace Graceful
{
//* QToolBox animation engine
class GRACEFUL_EXPORT ToolBoxEngine : public BaseEngine
{
    Q_OBJECT

public:
    //* constructor
    explicit ToolBoxEngine(QObject *parent)
        : BaseEngine(parent)
    {
    }

    //* destructor
    virtual ~ToolBoxEngine()
    {
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

    //* register widget
    virtual bool registerWidget(QWidget *);

    //* true if widget hover state is changed
    virtual bool updateState(const QPaintDevice *, bool);

    //* true if widget is animated
    virtual bool isAnimated(const QPaintDevice *);

    //* animation opacity
    virtual qreal opacity(const QPaintDevice *object)
    {
        return isAnimated(object) ? data(object).data()->opacity() : AnimationData::OpacityInvalid;
    }

public Q_SLOTS:

    //* remove widget from map
    virtual bool unregisterWidget(QObject *data)
    {
        if (!data) {
            return false;
        }

        // reinterpret_cast is safe here since only the address is used to find
        // data in the map
        return _data.unregisterWidget(reinterpret_cast<QPaintDevice *>(data));
    }

protected:
    //* returns data associated to widget
    PaintDeviceDataMap<WidgetStateData>::Value data(const QPaintDevice *object)
    {
        return _data.find(object).data();
    }

private:
    //* map
    PaintDeviceDataMap<WidgetStateData> _data;
};

}

#endif
