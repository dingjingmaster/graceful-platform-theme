#ifndef GRACEFUL_STACKEDWIDGET_DATA_H
#define GRACEFUL_STACKEDWIDGET_DATA_H
#include <QStackedWidget>

#include "graceful-export.h"
#include "graceful-transition-data.h"


namespace Graceful
{
//! generic data
class GRACEFUL_EXPORT StackedWidgetData : public TransitionData
{
    Q_OBJECT

public:
    //! constructor
    StackedWidgetData(QObject *, QStackedWidget *, int);

    //! destructor
    virtual ~StackedWidgetData()
    {
        CT_SYSLOG(LOG_DEBUG, "");
    }

protected Q_SLOTS:

    //! initialize animation
    virtual bool initializeAnimation();

    //! animate
    virtual bool animate();

    //! finish animation
    virtual void finishAnimation();

    //! called when target is destroyed
    virtual void targetDestroyed();

private:
    //! target
    WeakPointer<QStackedWidget> _target;

    //! current index
    int _index;
};

}

#endif
