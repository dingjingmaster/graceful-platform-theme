#ifndef GRACEFUL_ANIMATION_DATA_H
#define GRACEFUL_ANIMATION_DATA_H
#include <cmath>
#include <QEvent>
#include <QObject>
#include <QWidget>

#include "graceful-export.h"
#include "graceful-animation.h"


namespace Graceful
{
//* base class
class GRACEFUL_EXPORT AnimationData : public QObject
{
    Q_OBJECT
public:
    //* constructor
    AnimationData(QObject *parent, QWidget *target)
        : QObject(parent)
        , _target(target)
        , _enabled(true)
    {
        Q_ASSERT(_target);
    }

    //* destructor
    virtual ~AnimationData()
    {
    }

    //* duration
    virtual void setDuration(int) = 0;

    //* steps
    static void setSteps(int value)
    {
        _steps = value;
    }

    //* enability
    virtual bool enabled() const
    {
        return _enabled;
    }

    //* enability
    virtual void setEnabled(bool value)
    {
        _enabled = value;
    }

    //* target
    const WeakPointer<QWidget> &target() const
    {
        return _target;
    }

    //* invalid opacity
    static const qreal OpacityInvalid;

protected:
    //* setup animation
    virtual void setupAnimation(const Animation::Pointer &animation, const QByteArray &property);

    //* apply step
    virtual qreal digitize(const qreal &value) const
    {
        if (_steps > 0) {
            return std::floor(value * _steps) / _steps;
        } else {
            return value;
        }
    }

    //* trigger target update
    virtual void setDirty() const
    {
        if (_target) {
            _target.data()->update();
        }
    }

private:
    //* guarded target
    WeakPointer<QWidget> _target;

    //* enability
    bool _enabled;

    //* steps
    static int _steps;
};

}

#endif
