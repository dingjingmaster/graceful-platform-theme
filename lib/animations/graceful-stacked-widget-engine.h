#ifndef GRACEFUL_STACKEDWIDGET_ENGINE_H
#define GRACEFUL_STACKEDWIDGET_ENGINE_H

#include "graceful-export.h"
#include "graceful-datamap.h"
#include "graceful-base-engine.h"
#include "graceful-stacked-widget-data.h"

namespace Graceful
{
//! used for simple widgets
class GRACEFUL_EXPORT StackedWidgetEngine : public BaseEngine
{
    Q_OBJECT
public:
    //! constructor
    explicit StackedWidgetEngine(QObject *parent)
        : BaseEngine(parent)
    {

    }

    //! destructor
    virtual ~StackedWidgetEngine()
    {

    }

    //! register widget
    virtual bool registerWidget(QStackedWidget *);

    //! duration
    virtual void setEnabled(bool value)
    {

        BaseEngine::setEnabled(value);
        _data.setEnabled(value);
    }

    //! duration
    virtual void setDuration(int value)
    {

        BaseEngine::setDuration(value);
        _data.setDuration(value);
    }

public Q_SLOTS:

    //! remove widget from map
    virtual bool unregisterWidget(QObject *object)
    {

        return _data.unregisterWidget(object);
    }

private:
    //! maps
    DataMap<StackedWidgetData> _data;
};

}

#endif
