#ifndef GRACEFUL_DIAL_ENGINE_H
#define GRACEFUL_DIAL_ENGINE_H

#include "graceful-export.h"
#include "graceful-dial-data.h"
#include "graceful-widget-state-engine.h"

namespace Graceful
{
//* stores dial hovered action and timeLine
class GRACEFUL_EXPORT DialEngine : public WidgetStateEngine
{
    Q_OBJECT
public:
    //* constructor
    explicit DialEngine(QObject *parent)
        : WidgetStateEngine(parent)
    {
    }

    //* destructor
    virtual ~DialEngine()
    {
    }

    //* register dial
    virtual bool registerWidget(QWidget *, AnimationModes);

    //* control rect
    virtual void setHandleRect(const QObject *object, const QRect &rect)
    {
        if (DataMap<WidgetStateData>::Value data = this->data(object, AnimationHover)) {
            static_cast<DialData *>(data.data())->setHandleRect(rect);
        }
    }

    //* mouse position
    virtual QPoint position(const QObject *object)
    {
        if (DataMap<WidgetStateData>::Value data = this->data(object, AnimationHover)) {
            return static_cast<const DialData *>(data.data())->position();
        } else {
            return QPoint(-1, -1);
        }
    }
};

}

#endif
