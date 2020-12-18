#ifndef GRACEFUL_SPINBOX_DATA_H
#define GRACEFUL_SPINBOX_DATA_H
#include <QStyle>

#include "graceful-export.h"
#include "graceful-animation-data.h"


namespace Graceful
{
//* handles spinbox arrows hover
class GRACEFUL_EXPORT SpinBoxData : public AnimationData
{
    Q_OBJECT
    Q_PROPERTY(qreal upArrowOpacity READ upArrowOpacity WRITE setUpArrowOpacity)
    Q_PROPERTY(qreal downArrowOpacity READ downArrowOpacity WRITE setDownArrowOpacity)
    Q_PROPERTY(qreal upArrowPressed READ upArrowPressed WRITE setUpArrowPressed)
    Q_PROPERTY(qreal downArrowPressed READ downArrowPressed WRITE setDownArrowPressed)
public:
    //* constructor
    SpinBoxData(QObject *, QWidget *, int);

    //* destructor
    virtual ~SpinBoxData()
    {

    }

    //* animation state
    virtual bool updateState(QStyle::SubControl subControl, bool value, bool pressed)
    {

        if (subControl == QStyle::SC_SpinBoxUp) {
            return _upArrowData.updateState(value, pressed);
        } else if (subControl == QStyle::SC_SpinBoxDown) {
            return _downArrowData.updateState(value, pressed);
        } else {
            return false;
        }
    }

    //* animation state
    virtual bool isAnimated(QStyle::SubControl subControl) const
    {

        return ((subControl == QStyle::SC_SpinBoxUp && upArrowAnimation().data()->isRunning()) || (subControl == QStyle::SC_SpinBoxDown && downArrowAnimation().data()->isRunning()));
    }

    //* opacity
    virtual qreal opacity(QStyle::SubControl subControl) const
    {

        if (subControl == QStyle::SC_SpinBoxUp) {
            return upArrowOpacity();
        } else if (subControl == QStyle::SC_SpinBoxDown) {
            return downArrowOpacity();
        } else {
            return OpacityInvalid;
        }
    }

    //* opacity
    virtual qreal pressed(QStyle::SubControl subControl) const
    {

        if (subControl == QStyle::SC_SpinBoxUp) {
            return upArrowPressed();
        } else if (subControl == QStyle::SC_SpinBoxDown) {
            return downArrowPressed();
        } else {
            return OpacityInvalid;
        }
    }

    //* duration
    virtual void setDuration(int duration)
    {

        upArrowAnimation().data()->setDuration(duration);
        downArrowAnimation().data()->setDuration(duration);
    }

    //*@name up arrow animation
    //@{

    //* opacity
    qreal upArrowOpacity() const
    {

        return _upArrowData._opacity;
    }

    //* opacity
    void setUpArrowOpacity(qreal value)
    {

        value = digitize(value);
        if (_upArrowData._opacity == value) {
            return;
        }
        _upArrowData._opacity = value;
        setDirty();
    }

    //* animation
    Animation::Pointer upArrowAnimation() const
    {

        return _upArrowData._hoverAnimation;
    }

    //@}

    //*@name down arrow animation
    //@{

    //* opacity
    qreal downArrowOpacity() const
    {

        return _downArrowData._opacity;
    }

    //* opacity
    void setDownArrowOpacity(qreal value)
    {

        value = digitize(value);
        if (_downArrowData._opacity == value) {
            return;
        }

        _downArrowData._opacity = value;
        setDirty();
    }

    //* animation
    Animation::Pointer downArrowAnimation() const
    {

        return _downArrowData._hoverAnimation;
    }

    //*@name up arrow pressed animation
    //@{

    //* opacity
    qreal upArrowPressed() const
    {

        return _upArrowData._pressed;
    }

    //* opacity
    void setUpArrowPressed(qreal value)
    {

        value = digitize(value);
        if (_upArrowData._pressed == value) {
            return;
        }
        _upArrowData._pressed = value;
        setDirty();
    }

    //* animation
    Animation::Pointer upArrowPressedAnimation() const
    {

        return _upArrowData._pressedAnimation;
    }

    //*@name down arrow pressed animation
    //@{

    //* opacity
    qreal downArrowPressed() const
    {

        return _downArrowData._pressed;
    }

    //* opacity
    void setDownArrowPressed(qreal value)
    {

        value = digitize(value);
        if (_downArrowData._pressed == value) {
            return;
        }

        _downArrowData._pressed = value;
        setDirty();
    }

    //* animation
    Animation::Pointer downArrowPressedAnimation() const
    {

        return _downArrowData._pressedAnimation;
    }

    //@}

private:
    //* container for needed animation data
    class GRACEFUL_EXPORT Data
    {
    public:
        //* default constructor
        Data()
            : _hoverState(false)
            , _pressedState(false)
            , _opacity(0)
            , _pressed(0)
        {

        }

        //* state
        bool updateState(bool, bool);

        //* arrow state
        bool _hoverState;
        bool _pressedState;

        //* animation
        Animation::Pointer _hoverAnimation;
        Animation::Pointer _pressedAnimation;

        //* opacity
        qreal _opacity;
        qreal _pressed;
    };

    //* up arrow data
    Data _upArrowData;

    //* down arrow data
    Data _downArrowData;
};

}

#endif
