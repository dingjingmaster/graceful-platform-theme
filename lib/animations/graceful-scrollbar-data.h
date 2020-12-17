#ifndef GRACEFUL_SCROLLBAR_DATA_H
#define GRACEFUL_SCROLLBAR_DATA_H
#include <QStyle>

#include "graceful-export.h"
#include "graceful-widget-state-data.h"


namespace Graceful
{
//* scrollbar data
class GRACEFUL_EXPORT ScrollBarData : public WidgetStateData
{
    Q_OBJECT
    Q_PROPERTY(qreal addLineOpacity READ addLineOpacity WRITE setAddLineOpacity)
    Q_PROPERTY(qreal subLineOpacity READ subLineOpacity WRITE setSubLineOpacity)
    Q_PROPERTY(qreal grooveOpacity READ grooveOpacity WRITE setGrooveOpacity)
public:
    //* constructor
    ScrollBarData(QObject *parent, QWidget *target, int);

    //* destructor
    virtual ~ScrollBarData()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

    //* event filter
    virtual bool eventFilter(QObject *, QEvent *);

    //* needed to avoid warning about virtual function being hidden
    using WidgetStateData::animation;
    using WidgetStateData::opacity;

    //* return animation for a given subcontrol
    virtual const Animation::Pointer &animation(QStyle::SubControl) const;

    //* return default opacity for a given subcontrol
    virtual qreal opacity(QStyle::SubControl) const;

    //* return default opacity for a given subcontrol
    virtual bool isHovered(QStyle::SubControl control) const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        switch (control) {
        case QStyle::SC_ScrollBarAddLine:
            return addLineArrowHovered();
        case QStyle::SC_ScrollBarSubLine:
            return subLineArrowHovered();
        case QStyle::SC_ScrollBarGroove:
            return grooveHovered();
        default:
            return false;
        }
    }

    //* subControlRect
    virtual QRect subControlRect(QStyle::SubControl control) const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        switch (control) {
        case QStyle::SC_ScrollBarAddLine:
            return _addLineData._rect;
        case QStyle::SC_ScrollBarSubLine:
            return _subLineData._rect;
        default:
            return QRect();
        }
    }

    //* subcontrol rect
    virtual void setSubControlRect(QStyle::SubControl control, const QRect &rect)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        switch (control) {
        case QStyle::SC_ScrollBarAddLine:
            _addLineData._rect = rect;
            break;
        case QStyle::SC_ScrollBarSubLine:
            _subLineData._rect = rect;
            break;
        default:
            break;
        }
    }

    //* duration
    virtual void setDuration(int duration)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        WidgetStateData::setDuration(duration);
        addLineAnimation().data()->setDuration(duration);
        subLineAnimation().data()->setDuration(duration);
        grooveAnimation().data()->setDuration(duration);
    }

    //* addLine opacity
    virtual void setAddLineOpacity(qreal value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        value = digitize(value);
        if (_addLineData._opacity == value) {
            return;
        }
        _addLineData._opacity = value;
        setDirty();
    }

    //* addLine opacity
    virtual qreal addLineOpacity() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _addLineData._opacity;
    }

    //* subLine opacity
    virtual void setSubLineOpacity(qreal value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        value = digitize(value);
        if (_subLineData._opacity == value) {
            return;
        }
        _subLineData._opacity = value;
        setDirty();
    }

    //* subLine opacity
    virtual qreal subLineOpacity() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _subLineData._opacity;
    }

    //* groove opacity
    virtual void setGrooveOpacity(qreal value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        value = digitize(value);
        if (_grooveData._opacity == value) {
            return;
        }
        _grooveData._opacity = value;
        setDirty();
    }

    //* groove opacity
    virtual qreal grooveOpacity() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _grooveData._opacity;
    }

    //* mouse position
    QPoint position() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _position;
    }

protected Q_SLOTS:

    //* clear addLineRect
    void clearAddLineRect()
    {
        CT_SYSLOG(LOG_DEBUG, "");
        if (addLineAnimation().data()->direction() == Animation::Backward) {
            _addLineData._rect = QRect();
        }
    }

    //* clear subLineRect
    void clearSubLineRect()
    {
        CT_SYSLOG(LOG_DEBUG, "");
        if (subLineAnimation().data()->direction() == Animation::Backward) {
            _subLineData._rect = QRect();
        }
    }

protected:
    //* hoverMoveEvent
    virtual void hoverMoveEvent(QObject *, QEvent *);

    //* hoverMoveEvent
    virtual void hoverLeaveEvent(QObject *, QEvent *);

    //*@name hover flags
    //@{

    virtual bool addLineArrowHovered() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _addLineData._hovered;
    }

    virtual void setAddLineArrowHovered(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _addLineData._hovered = value;
    }

    virtual bool subLineArrowHovered() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _subLineData._hovered;
    }

    virtual void setSubLineArrowHovered(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _subLineData._hovered = value;
    }

    virtual bool grooveHovered() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _grooveData._hovered;
    }

    virtual void setGrooveHovered(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _grooveData._hovered = value;
    }

    //@}

    //* update add line arrow
    virtual void updateAddLineArrow(QStyle::SubControl);

    //* update sub line arrow
    virtual void updateSubLineArrow(QStyle::SubControl);

    //*@name timelines
    //@{

    virtual const Animation::Pointer &addLineAnimation() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _addLineData._animation;
    }

    virtual const Animation::Pointer &subLineAnimation() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _subLineData._animation;
    }

    virtual const Animation::Pointer &grooveAnimation() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _grooveData._animation;
    }

private:
    //* stores sub control data
    class Data
    {
    public:
        //* constructor
        Data()
            : _hovered(false)
            , _opacity(AnimationData::OpacityInvalid)
        {
            CT_SYSLOG(LOG_DEBUG, "");
        }

        //* true if hovered
        bool _hovered;

        //* animation
        Animation::Pointer _animation;

        //* opacity
        qreal _opacity;

        //* rect
        QRect _rect;
    };

    //* add line data (down arrow)
    Data _addLineData;

    //* subtract line data (up arrow)
    Data _subLineData;

    //* groove data
    Data _grooveData;

    //* mouse position
    QPoint _position;
};

}

#endif
