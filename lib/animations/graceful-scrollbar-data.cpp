#include "graceful-scrollbar-data.h"

#include <QScrollBar>
#include <QHoverEvent>
#include <QStyleOptionSlider>

Q_GUI_EXPORT QStyleOptionSlider qt_qscrollbarStyleOption(QScrollBar *);

namespace Graceful
{

ScrollBarData::ScrollBarData(QObject *parent, QWidget *target, int duration) : WidgetStateData(parent, target, duration), _position(-1, -1)
{
    CT_SYSLOG(LOG_DEBUG, "");
    target->installEventFilter(this);

    _addLineData._animation = new Animation(duration, this);
    _subLineData._animation = new Animation(duration, this);
    _grooveData._animation = new Animation(duration, this);

    connect(addLineAnimation().data(), SIGNAL(finished()), SLOT(clearAddLineRect()));
    connect(subLineAnimation().data(), SIGNAL(finished()), SLOT(clearSubLineRect()));

    // setup animation
    setupAnimation(addLineAnimation(), "addLineOpacity");
    setupAnimation(subLineAnimation(), "subLineOpacity");
    setupAnimation(grooveAnimation(), "grooveOpacity");
}

bool ScrollBarData::eventFilter(QObject *object, QEvent *event)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (object != target().data()) {
        return WidgetStateData::eventFilter(object, event);
    }

    // check event type
    switch (event->type()) {
    case QEvent::HoverEnter:
        setGrooveHovered(true);
        grooveAnimation().data()->setDirection(Animation::Forward);
        if (!grooveAnimation().data()->isRunning()) {
            grooveAnimation().data()->start();
        }
    case QEvent::HoverMove:
        hoverMoveEvent(object, event);
        break;
    case QEvent::HoverLeave:
        setGrooveHovered(false);
        grooveAnimation().data()->setDirection(Animation::Backward);
        if (!grooveAnimation().data()->isRunning()) {
            grooveAnimation().data()->start();
        }
        hoverLeaveEvent(object, event);

        break;
    default:
        break;
    }

    return WidgetStateData::eventFilter(object, event);
}

const Animation::Pointer &ScrollBarData::animation(QStyle::SubControl subcontrol) const
{
    CT_SYSLOG(LOG_DEBUG, "");
    switch (subcontrol) {
    case QStyle::SC_ScrollBarSlider:
        return animation();
    case QStyle::SC_ScrollBarAddLine:
        return addLineAnimation();
    case QStyle::SC_ScrollBarSubLine:
        return subLineAnimation();
    case QStyle::SC_ScrollBarGroove:
        return grooveAnimation();
    }

    return animation();
}

qreal ScrollBarData::opacity(QStyle::SubControl subcontrol) const
{
    CT_SYSLOG(LOG_DEBUG, "");
    switch (subcontrol) {
    case QStyle::SC_ScrollBarSlider:
        return opacity();
    case QStyle::SC_ScrollBarAddLine:
        return addLineOpacity();
    case QStyle::SC_ScrollBarSubLine:
        return subLineOpacity();
    case QStyle::SC_ScrollBarGroove:
        return grooveOpacity();
    }

    return 0;
}

void ScrollBarData::hoverMoveEvent(QObject *object, QEvent *event)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // try cast object to scrollbar
    QScrollBar *scrollBar(qobject_cast<QScrollBar *>(object));
    if (!scrollBar || scrollBar->isSliderDown()) {
        return;
    }

    // retrieve scrollbar option
    QStyleOptionSlider opt(qt_qscrollbarStyleOption(scrollBar));

    // cast event
    QHoverEvent *hoverEvent = static_cast<QHoverEvent *>(event);
    QStyle::SubControl hoverControl = scrollBar->style()->hitTestComplexControl(QStyle::CC_ScrollBar, &opt, hoverEvent->pos(), scrollBar);

    // update hover state
    updateAddLineArrow(hoverControl);
    updateSubLineArrow(hoverControl);

    // store position
    _position = hoverEvent->pos();
}

void ScrollBarData::hoverLeaveEvent(QObject *, QEvent *)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // reset hover state
    updateSubLineArrow(QStyle::SC_None);
    updateAddLineArrow(QStyle::SC_None);

    // reset mouse position
    _position = QPoint(-1, -1);
}

void ScrollBarData::updateSubLineArrow(QStyle::SubControl hoverControl)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (hoverControl == QStyle::SC_ScrollBarSubLine) {
        if (!subLineArrowHovered()) {
            setSubLineArrowHovered(true);
            if (enabled()) {
                subLineAnimation().data()->setDirection(Animation::Forward);
                if (!subLineAnimation().data()->isRunning()) {
                    subLineAnimation().data()->start();
                }
            } else {
                setDirty();
            }
        }
    } else {
        if (subLineArrowHovered()) {
            setSubLineArrowHovered(false);
            if (enabled()) {
                subLineAnimation().data()->setDirection(Animation::Backward);
                if (!subLineAnimation().data()->isRunning()) {
                    subLineAnimation().data()->start();
                }
            } else {
                setDirty();
            }
        }
    }
}

void ScrollBarData::updateAddLineArrow(QStyle::SubControl hoverControl)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (hoverControl == QStyle::SC_ScrollBarAddLine) {
        if (!addLineArrowHovered()) {
            setAddLineArrowHovered(true);
            if (enabled()) {
                addLineAnimation().data()->setDirection(Animation::Forward);
                if (!addLineAnimation().data()->isRunning()) {
                    addLineAnimation().data()->start();
                }
            } else {
                setDirty();
            }
        }
    } else {
        if (addLineArrowHovered()) {
            setAddLineArrowHovered(false);
            if (enabled()) {
                addLineAnimation().data()->setDirection(Animation::Backward);
                if (!addLineAnimation().data()->isRunning()) {
                    addLineAnimation().data()->start();
                }
            } else {
                setDirty();
            }
        }
    }
}

}
