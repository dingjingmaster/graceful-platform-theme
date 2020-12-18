#ifndef GRACEFUL_GRACEFULWIDGETEXPLORER_H
#define GRACEFUL_GRACEFULWIDGETEXPLORER_H
#include "graceful-export.h"

#include <QMap>
#include <QSet>
#include <QEvent>
#include <QObject>
#include <QObject>
#include <QWidget>

namespace Graceful {

class GRACEFUL_EXPORT WidgetExplorer : public QObject
{
Q_OBJECT
public:
    //* constructor
    explicit WidgetExplorer(QObject *parent);

    //* enable
    bool enabled() const;

    //* enable
    void setEnabled(bool);

    //* widget rects
    void setDrawWidgetRects(bool value)
    {

        _drawWidgetRects = value;
    }

    //* event filter
    virtual bool eventFilter(QObject *object, QEvent *event);

protected:
    //* event type
    QString eventType(const QEvent::Type &type) const;

    //* print widget information
    QString widgetInformation(const QWidget *widget) const;

private:
    //* enable state
    bool _enabled;

    //* widget rects
    bool _drawWidgetRects;

    //* map event types to string
    QMap<QEvent::Type, QString> _eventTypes;
};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULWIDGETEXPLORER_H
