#include "graceful-widget-state-engine.h"

#include "graceful-enable-data.h"

namespace Graceful
{

//____________________________________________________________
bool WidgetStateEngine::registerWidget(QWidget *widget, AnimationModes mode)
{
    if (!widget) {
        return false;
    }

    if (mode & AnimationHover && !_hoverData.contains(widget)) {
        _hoverData.insert(widget, new WidgetStateData(this, widget, duration()), enabled());
    }
    if (mode & AnimationFocus && !_focusData.contains(widget)) {
        _focusData.insert(widget, new WidgetStateData(this, widget, duration()), enabled());
    }
    if (mode & AnimationEnable && !_enableData.contains(widget)) {
        _enableData.insert(widget, new EnableData(this, widget, duration()), enabled());
    }
    if (mode & AnimationPressed && !_pressedData.contains(widget)) {
        _pressedData.insert(widget, new WidgetStateData(this, widget, duration()), enabled());
    }

    // connect destruction signal
    connect(widget, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterWidget(QObject *)), Qt::UniqueConnection);

    return true;
}

//____________________________________________________________
BaseEngine::WidgetList WidgetStateEngine::registeredWidgets(AnimationModes mode) const
{
    WidgetList out;

    using Value = DataMap<WidgetStateData>::Value;

    if (mode & AnimationHover) {
        for (auto value = _hoverData.constBegin(); value != _hoverData.constEnd(); ++value) {
            if (*value) out.insert(value->data()->target().data());
        }
    }

    if (mode & AnimationFocus) {
        for (auto value = _focusData.constBegin(); value != _focusData.constEnd(); ++value) {
            if (*value) out.insert(value->data()->target().data());
        }
    }

    if (mode & AnimationEnable) {
        for (auto value = _enableData.constBegin(); value != _enableData.constEnd(); ++value) {
            if (*value) out.insert(value->data()->target().data());
        }
    }

    if (mode & AnimationPressed) {
        for (auto value = _pressedData.constBegin(); value != _pressedData.constEnd(); ++value) {
            if (*value) out.insert(value->data()->target().data());
        }
    }

    return out;
}

//____________________________________________________________
bool WidgetStateEngine::updateState(const QObject *object, AnimationMode mode, bool value)
{
    DataMap<WidgetStateData>::Value data(WidgetStateEngine::data(object, mode));
    return (data && data.data()->updateState(value));
}

//____________________________________________________________
bool WidgetStateEngine::isAnimated(const QObject *object, AnimationMode mode)
{
    DataMap<WidgetStateData>::Value data(WidgetStateEngine::data(object, mode));
    return (data && data.data()->animation() && data.data()->animation().data()->isRunning());
}

//____________________________________________________________
DataMap<WidgetStateData>::Value WidgetStateEngine::data(const QObject *object, AnimationMode mode)
{
    switch (mode) {
    case AnimationHover:
        return _hoverData.find(object).data();
    case AnimationFocus:
        return _focusData.find(object).data();
    case AnimationEnable:
        return _enableData.find(object).data();
    case AnimationPressed:
        return _pressedData.find(object).data();
    default:
        return DataMap<WidgetStateData>::Value();
    }
}

//____________________________________________________________
DataMap<WidgetStateData> &WidgetStateEngine::dataMap(AnimationMode mode)
{

    switch (mode) {
    default:
    case AnimationHover:
        return _hoverData;
    case AnimationFocus:
        return _focusData;
    case AnimationEnable:
        return _enableData;
    case AnimationPressed:
        return _pressedData;
    }
}

}
