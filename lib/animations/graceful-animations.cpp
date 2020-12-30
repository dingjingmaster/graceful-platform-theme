#include "graceful-animations.h"

#include <QDial>
#include <QSpinBox>
#include <QToolBox>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QGroupBox>
#include <QLineEdit>
#include <QScrollBar>
#include <QHeaderView>
#include <QToolButton>
#include <QProgressBar>
#include <QRadioButton>
#include <QAbstractItemView>

namespace Graceful
{
Animations::Animations(QObject *parent) : QObject(parent)
{

    _widgetEnabilityEngine = new WidgetStateEngine(this);
    _busyIndicatorEngine = new BusyIndicatorEngine(this);
    _comboBoxEngine = new WidgetStateEngine(this);
    _toolButtonEngine = new WidgetStateEngine(this);
    _spinBoxEngine = new SpinBoxEngine(this);
    _toolBoxEngine = new ToolBoxEngine(this);

    registerEngine(_headerViewEngine = new HeaderViewEngine(this));
    registerEngine(_widgetStateEngine = new WidgetStateEngine(this));
    registerEngine(_inputWidgetEngine = new WidgetStateEngine(this));
    registerEngine(_scrollBarEngine = new ScrollBarEngine(this));
    registerEngine(_stackedWidgetEngine = new StackedWidgetEngine(this));
    registerEngine(_tabBarEngine = new TabBarEngine(this));
    registerEngine(_dialEngine = new DialEngine(this));
}

void Animations::setupEngines()
{

    // animation steps
    AnimationData::setSteps(Graceful::Config::AnimationSteps);

    bool animationsEnabled(Graceful::Config::AnimationsEnabled);
    int animationsDuration(Graceful::Config::AnimationsDuration);

    _widgetEnabilityEngine->setEnabled(animationsEnabled);
    _comboBoxEngine->setEnabled(animationsEnabled);
    _toolButtonEngine->setEnabled(animationsEnabled);
    _spinBoxEngine->setEnabled(animationsEnabled);
    _toolBoxEngine->setEnabled(animationsEnabled);

    _widgetEnabilityEngine->setDuration(animationsDuration);
    _comboBoxEngine->setDuration(animationsDuration);
    _toolButtonEngine->setDuration(animationsDuration);
    _spinBoxEngine->setDuration(animationsDuration);
    _stackedWidgetEngine->setDuration(animationsDuration);
    _toolBoxEngine->setDuration(animationsDuration);

    // registered engines
    for (auto engine = _engines.constBegin(); engine != _engines.constEnd(); ++engine) {
        engine->data()->setEnabled(animationsEnabled);
        engine->data()->setDuration(animationsDuration);
    }

    // stacked widget transition has an extra flag for animations
    _stackedWidgetEngine->setEnabled(animationsEnabled && Graceful::Config::StackedWidgetTransitionsEnabled);

    // busy indicator
    _busyIndicatorEngine->setEnabled(Graceful::Config::ProgressBarAnimated);
    _busyIndicatorEngine->setDuration(Graceful::Config::ProgressBarBusyStepDuration);
}

void Animations::registerWidget(QWidget *widget) const
{

    if (!widget) {
        return;
    }

    // check against noAnimations propery
    QVariant propertyValue(widget->property(PropertyNames::noAnimations));
    if (propertyValue.isValid() && propertyValue.toBool()) {
        return;
    }

    // all widgets are registered to the enability engine.
    _widgetEnabilityEngine->registerWidget(widget, AnimationEnable);

    // install animation timers
    // for optimization, one should put with most used widgets here first

    // buttons
    if (qobject_cast<QToolButton *>(widget)) {
        _toolButtonEngine->registerWidget(widget, AnimationHover | AnimationPressed);
        _widgetStateEngine->registerWidget(widget, AnimationHover | AnimationPressed);
    } else if (qobject_cast<QCheckBox *>(widget) || qobject_cast<QRadioButton *>(widget)) {
        _widgetStateEngine->registerWidget(widget, AnimationHover | AnimationFocus | AnimationPressed);
    } else if (qobject_cast<QAbstractButton *>(widget)) {
        // register to toolbox engine if needed
        if (qobject_cast<QToolBox *>(widget->parent())) {
            _toolBoxEngine->registerWidget(widget);
        }

        _widgetStateEngine->registerWidget(widget, AnimationHover | AnimationPressed);
    // groupboxes
    } else if (QGroupBox *groupBox = qobject_cast<QGroupBox *>(widget)) {
        if (groupBox->isCheckable()) {
            _widgetStateEngine->registerWidget(widget, AnimationHover | AnimationFocus);
        }
    // sliders
    } else if (qobject_cast<QScrollBar *>(widget)) {
        _scrollBarEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    } else if (qobject_cast<QSlider *>(widget)) {
        _widgetStateEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    } else if (qobject_cast<QDial *>(widget)) {
        _dialEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    // progress bar
    } else if (qobject_cast<QProgressBar *>(widget)) {
        _busyIndicatorEngine->registerWidget(widget);
    // combo box
    } else if (qobject_cast<QComboBox *>(widget)) {
        _comboBoxEngine->registerWidget(widget, AnimationHover | AnimationPressed);
        _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus | AnimationPressed);
    // spinbox
    } else if (qobject_cast<QAbstractSpinBox *>(widget)) {
        _spinBoxEngine->registerWidget(widget);
        _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus | AnimationPressed);
    // editors
    } else if (qobject_cast<QLineEdit *>(widget)) {
        _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    } else if (qobject_cast<QTextEdit *>(widget)) {
        _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    } else if (widget->inherits("KTextEditor::View")) {
        _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    // header views
    // need to come before abstract item view, otherwise is skipped
    } else if (qobject_cast<QHeaderView *>(widget)) {
        _headerViewEngine->registerWidget(widget);
    // lists
    } else if (qobject_cast<QAbstractItemView *>(widget)) {
        _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus);
    // tabbar
    } else if (qobject_cast<QTabBar *>(widget)) {
        _tabBarEngine->registerWidget(widget);
    // scrollarea
    } else if (QAbstractScrollArea *scrollArea = qobject_cast<QAbstractScrollArea *>(widget)) {
        if (scrollArea->frameShadow() == QFrame::Sunken && (widget->focusPolicy()&Qt::StrongFocus)) {
            _inputWidgetEngine->registerWidget(widget, AnimationHover | AnimationFocus);
        }
    }

    // stacked widgets
    if (QStackedWidget *stack = qobject_cast<QStackedWidget *>(widget)) {
        _stackedWidgetEngine->registerWidget(stack);
    }

    return;
}

void Animations::unregisterWidget(QWidget *widget) const
{

    if (!widget) {
        return;
    }

    _widgetEnabilityEngine->unregisterWidget(widget);
    _spinBoxEngine->unregisterWidget(widget);
    _comboBoxEngine->unregisterWidget(widget);
    _busyIndicatorEngine->registerWidget(widget);

    // the following allows some optimization of widget unregistration
    // it assumes that a widget can be registered atmost in one of the
    // engines stored in the list.
    for (auto engine = _engines.constBegin(); engine != _engines.constEnd(); ++engine) {
        if (*engine && engine->data()->unregisterWidget(widget)) {
            break;
        }
    }
}

void Animations::unregisterEngine(QObject *object)
{

    int index(_engines.indexOf(qobject_cast<BaseEngine *>(object)));
    if (index >= 0) {
        _engines.removeAt(index);
    }
}

void Animations::registerEngine(BaseEngine *engine)
{

    _engines.append(engine);
    connect(engine, SIGNAL(destroyed(QObject *)), this, SLOT(unregisterEngine(QObject *)));
}

}
