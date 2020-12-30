#ifndef GRACEFUL_TABBAR_DATA_H
#define GRACEFUL_TABBAR_DATA_H

#include <QTabBar>

#include "graceful-export.h"
#include "graceful-animation-data.h"


namespace Graceful
{
//* tabbars
class GRACEFUL_EXPORT TabBarData : public AnimationData
{
    Q_OBJECT

    //* declare opacity property
    Q_PROPERTY(qreal currentOpacity READ currentOpacity WRITE setCurrentOpacity)
    Q_PROPERTY(qreal previousOpacity READ previousOpacity WRITE setPreviousOpacity)
public:
    //* constructor
    TabBarData(QObject *parent, QWidget *target, int duration);

    //* destructor
    virtual ~TabBarData()
    {

    }

    //* duration
    void setDuration(int duration)
    {

        currentIndexAnimation().data()->setDuration(duration);
        previousIndexAnimation().data()->setDuration(duration);
    }

    //* update state
    bool updateState(const QPoint &, bool);

    //*@name current index handling
    //@{

    //* current opacity
    virtual qreal currentOpacity() const
    {

        return _current._opacity;
    }

    //* current opacity
    virtual void setCurrentOpacity(qreal value)
    {

        if (_current._opacity == value) {
            return;
        }

        _current._opacity = value;
        setDirty();
    }

    //* current index
    virtual int currentIndex() const
    {

        return _current._index;
    }

    //* current index
    virtual void setCurrentIndex(int index)
    {

        _current._index = index;
    }

    //* current index animation
    virtual const Animation::Pointer &currentIndexAnimation() const
    {

        return _current._animation;
    }

    //@}

    //*@name previous index handling
    //@{

    //* previous opacity
    virtual qreal previousOpacity() const
    {

        return _previous._opacity;
    }

    //* previous opacity
    virtual void setPreviousOpacity(qreal value)
    {

        if (_previous._opacity == value) {
            return;
        }

        _previous._opacity = value;
        setDirty();
    }

    //* previous index
    virtual int previousIndex() const
    {

        return _previous._index;
    }

    //* previous index
    virtual void setPreviousIndex(int index)
    {

        _previous._index = index;
    }

    //* previous index Animation
    virtual const Animation::Pointer &previousIndexAnimation() const
    {

        return _previous._animation;
    }

    //@}

    //* return Animation associated to action at given position, if any
    virtual Animation::Pointer animation(const QPoint &position) const;

    //* return opacity associated to action at given position, if any
    virtual qreal opacity(const QPoint &position) const;

private:
    //* container for needed animation data
    class Data
    {
    public:
        //* default constructor
        Data()
            : _opacity(0)
            , _index(-1)
        {

        }

        Animation::Pointer _animation;
        qreal _opacity;
        int _index;
    };

    //* current tab animation data (for hover enter animations)
    Data _current;

    //* previous tab animations data (for hover leave animations)
    Data _previous;
};

}
#endif
