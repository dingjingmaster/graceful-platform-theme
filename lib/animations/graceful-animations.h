#ifndef GRACEFUL_ANIMATIONS_H
#define GRACEFUL_ANIMATIONS_H

#include <QList>
#include <QObject>

#include "graceful-export.h"
#include "graceful-dial-engine.h"
#include "graceful-tabbar-engine.h"
#include "graceful-spinbox-engine.h"
#include "graceful-tool-box-engine.h"
#include "graceful-scrollbar-engine.h"
#include "graceful-headerview-engine.h"
#include "graceful-widget-state-engine.h"
#include "graceful-busy-indicator-engine.h"
#include "graceful-stacked-widget-engine.h"


namespace Graceful
{
//* stores engines
class GRACEFUL_EXPORT Animations : public QObject
{
    Q_OBJECT

public:
    //* constructor
    explicit Animations(QObject *);

    //* destructor
    virtual ~Animations()
    {
    }

    //* register animations corresponding to given widget, depending on its type.
    void registerWidget(QWidget *widget) const;

    /** unregister all animations associated to a widget */
    void unregisterWidget(QWidget *widget) const;

    //* enability engine
    WidgetStateEngine &widgetEnabilityEngine() const
    {
        return *_widgetEnabilityEngine;
    }

    //* abstractButton engine
    WidgetStateEngine &widgetStateEngine() const
    {
        return *_widgetStateEngine;
    }

    //* editable combobox arrow hover engine
    WidgetStateEngine &comboBoxEngine() const
    {
        return *_comboBoxEngine;
    }

    //! Tool buttons arrow hover engine
    WidgetStateEngine &toolButtonEngine() const
    {
        return *_toolButtonEngine;
    }

    //! item view engine
    WidgetStateEngine &inputWidgetEngine() const
    {
        return *_inputWidgetEngine;
    }

    //* busy indicator
    BusyIndicatorEngine &busyIndicatorEngine() const
    {
        return *_busyIndicatorEngine;
    }

    //* header view engine
    HeaderViewEngine &headerViewEngine() const
    {
        return *_headerViewEngine;
    }

    //* scrollbar engine
    ScrollBarEngine &scrollBarEngine() const
    {
        return *_scrollBarEngine;
    }

    //* dial engine
    DialEngine &dialEngine() const
    {
        return *_dialEngine;
    }

    //* spinbox engine
    SpinBoxEngine &spinBoxEngine() const
    {
        return *_spinBoxEngine;
    }

    //* tabbar
    TabBarEngine &tabBarEngine() const
    {
        return *_tabBarEngine;
    }

    //* toolbox
    ToolBoxEngine &toolBoxEngine() const
    {
        return *_toolBoxEngine;
    }

    //* setup engines
    void setupEngines();

protected Q_SLOTS:

    //* enregister engine
    void unregisterEngine(QObject *);

private:
    //* register new engine
    void registerEngine(BaseEngine *engine);

    //* busy indicator
    BusyIndicatorEngine *_busyIndicatorEngine;

    //* headerview hover effect
    HeaderViewEngine *_headerViewEngine;

    //* widget enability engine
    WidgetStateEngine *_widgetEnabilityEngine;

    //* abstract button engine
    WidgetStateEngine *_widgetStateEngine;

    //* editable combobox arrow hover effect
    WidgetStateEngine *_comboBoxEngine;

    //! mennu toolbutton arrow hover effect
    WidgetStateEngine *_toolButtonEngine;

    //! item view engine
    WidgetStateEngine *_inputWidgetEngine;

    //* scrollbar engine
    ScrollBarEngine *_scrollBarEngine;

    //* dial engine
    DialEngine *_dialEngine;

    //* spinbox engine
    SpinBoxEngine *_spinBoxEngine;

    //* stacked widget engine
    StackedWidgetEngine *_stackedWidgetEngine;

    //* tabbar engine
    TabBarEngine *_tabBarEngine;

    //* toolbar engine
    ToolBoxEngine *_toolBoxEngine;

    //* keep list of existing engines
    QList<BaseEngine::Pointer> _engines;
};

} // namespace Adwaita

#endif // ADWAITA_ANIMATIONS_H
