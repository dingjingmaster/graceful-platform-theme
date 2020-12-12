#ifndef GRACEFUL_GENERIC_DATA_H
#define GRACEFUL_GENERIC_DATA_H
#include <QObject>
#include <QTextStream>

#include "graceful-export.h"
#include "graceful-animation.h"
#include "graceful-animation-data.h"


namespace Graceful
{
//* generic data
class GRACEFUL_EXPORT GenericData : public AnimationData
{
    Q_OBJECT

    //* declare opacity property
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    //* constructor
    GenericData(QObject *parent, QWidget *widget, int duration);

    //* destructor
    virtual ~GenericData()
    {
    }

    //* return animation object
    virtual const Animation::Pointer &animation() const
    {
        return _animation;
    }

    //* duration
    virtual void setDuration(int duration)
    {
        _animation.data()->setDuration(duration);
    }

    //* opacity
    virtual qreal opacity() const
    {
        return _opacity;
    }

    //* opacity
    virtual void setOpacity(qreal value)
    {
        value = digitize(value);
        if (_opacity == value) {
            return;
        }

        _opacity = value;
        setDirty();
    }

private:
    //* animation handling
    Animation::Pointer _animation;

    //* opacity variable
    qreal _opacity;
};

}

#endif
