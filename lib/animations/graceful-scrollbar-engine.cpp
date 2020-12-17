#include "graceful-scrollbar-engine.h"

#include <QEvent>

namespace Graceful
{

bool ScrollBarEngine::registerWidget(QWidget *widget, AnimationModes mode)
{
    CT_SYSLOG(LOG_DEBUG, "");
    // check widget
    if (!widget) return false;

    // only handle hover and focus
    if (mode & AnimationHover && !dataMap(AnimationHover).contains(widget)) {
        dataMap(AnimationHover).insert(widget, new ScrollBarData(this, widget, duration()), enabled());
    }
    if (mode & AnimationFocus && !dataMap(AnimationFocus).contains(widget)) {
        dataMap(AnimationFocus).insert(widget, new WidgetStateData(this, widget, duration()), enabled());
    }

    // connect destruction signal
    connect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)), Qt::UniqueConnection);

    return true;
}

bool ScrollBarEngine::isAnimated(const QObject *object, AnimationMode mode, QStyle::SubControl control)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (mode == AnimationHover) {
        if (DataMap<WidgetStateData>::Value data = this->data(object, AnimationHover)) {
            const ScrollBarData *scrollBarData(static_cast<const ScrollBarData *>(data.data()));
            Animation::Pointer animation = scrollBarData->animation(control);
            return animation.data()->isRunning();
        } else {
            return false;
        }
    } else if (control == QStyle::SC_ScrollBarSlider) {
        return WidgetStateEngine::isAnimated(object, mode);
    } else {
        return false;
    }
}

AnimationMode ScrollBarEngine::animationMode(const QObject *object, QStyle::SubControl control)
{
    CT_SYSLOG(LOG_DEBUG, "");

    // enable state
    if (isAnimated(object, AnimationHover, control)) {
        return AnimationHover;
    } else if (isAnimated(object, AnimationFocus, control)) {
        return AnimationFocus;
    } else if (isAnimated(object, AnimationPressed, control)) {
        return AnimationPressed;
    } else {
        return AnimationNone;
    }
}

qreal ScrollBarEngine::opacity(const QObject *object, QStyle::SubControl control)
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (isAnimated(object, AnimationHover, control)) {
        return static_cast<const ScrollBarData *>(data(object, AnimationHover).data())->opacity(control);
    } else if (control == QStyle::SC_ScrollBarSlider) {
        return WidgetStateEngine::buttonOpacity(object);
    }
    return AnimationData::OpacityInvalid;
}

}
