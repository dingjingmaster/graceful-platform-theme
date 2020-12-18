#ifndef GRACEFUL_GRACEFULSPLITTERPROXY_H
#define GRACEFUL_GRACEFULSPLITTERPROXY_H
#include <QMap>
#include <QEvent>
#include <QWidget>
#include <QHoverEvent>
#include <QMainWindow>
#include <QMouseEvent>
#include <QSplitterHandle>

#include "graceful.h"
#include "graceful-add-event-filter.h"

namespace Graceful {

class SplitterProxy;

class GRACEFUL_EXPORT SplitterFactory : public QObject
{
    Q_OBJECT

public:
    //* constructor
    explicit SplitterFactory(QObject *parent);

    //* destructor
    virtual ~SplitterFactory();

    //* enabled state
    void setEnabled(bool);

    //* register widget
    bool registerWidget(QWidget *);

    //* unregister widget
    void unregisterWidget(QWidget *);

private:
    //* enabled state
    bool _enabled;

    //* needed to block ChildAdded events when creating proxy
    AddEventFilter _addEventFilter;

    //* pointer to SplitterProxy
    using SplitterProxyPointer = WeakPointer<SplitterProxy>;

    //* registered widgets
    using WidgetMap = QMap<QWidget *, SplitterProxyPointer>;
    WidgetMap _widgets;
};

class SplitterProxy : public QWidget
{
    Q_OBJECT

public:
    //* constructor
    explicit SplitterProxy(QWidget *, bool = false);

    //* destructor
    virtual ~SplitterProxy();

    //* event filter
    virtual bool eventFilter(QObject *, QEvent *);

    //* enable state
    void setEnabled(bool);

    //* enable state
    bool enabled() const
    {

        return _enabled;
    }

protected:
    //* event handler
    virtual bool event(QEvent *);

protected:
    //* reset 'true' splitter widget
    void clearSplitter();

    //* keep track of 'true' splitter widget
    void setSplitter(QWidget *);

private:
    //* enabled state
    bool _enabled;

    //* splitter object
    WeakPointer<QWidget> _splitter;

    //* hook
    QPoint _hook;

    //* timer id
    int _timerId;
};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULSPLITTERPROXY_H
