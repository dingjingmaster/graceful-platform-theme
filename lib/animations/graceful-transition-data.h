#ifndef GRACEFUL_TRANSITION_DATA_H
#define GRACEFUL_TRANSITION_DATA_H
#include <QObject>
#include <QWidget>
#include <QElapsedTimer>

#include "graceful-export.h"
#include "graceful-transition-widget.h"


namespace Graceful
{
//* generic data
class GRACEFUL_EXPORT TransitionData : public QObject
{
    Q_OBJECT
public:
    //* constructor
    TransitionData(QObject *parent, QWidget *target, int);

    //* destructor
    virtual ~TransitionData();

    //* enability
    virtual void setEnabled(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _enabled = value;
    }

    //* enability
    virtual bool enabled() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _enabled;
    }

    //* duration
    virtual void setDuration(int duration)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        if (_transition) {
            _transition.data()->setDuration(duration);
        }
    }

    //* max render time
    void setMaxRenderTime(int value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _maxRenderTime = value;
    }

    //* max renderTime
    const int &maxRenderTime() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _maxRenderTime;
    }

    //* start clock
    void startClock()
    {
        CT_SYSLOG(LOG_DEBUG, "");
        if (!_clock.isValid()) {
            _clock.start();
        } else {
            _clock.restart();
        }
    }

    //* check if rendering is two slow
    bool slow() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return !(!_clock.isValid() || _clock.elapsed() <= maxRenderTime());
    }

protected Q_SLOTS:

    //* initialize animation
    virtual bool initializeAnimation() = 0;

    //* animate
    virtual bool animate() = 0;

protected:
    //* returns true if one parent matches given class name
    inline bool hasParent(const QWidget *, const char *) const;

    //* transition widget
    virtual const TransitionWidget::Pointer &transition() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _transition;
    }

    //* used to avoid recursion when grabbing widgets
    void setRecursiveCheck(bool value)
    {
        CT_SYSLOG(LOG_DEBUG, "");
        _recursiveCheck = value;
    }

    //* used to avoid recursion when grabbing widgets
    bool recursiveCheck() const
    {
        CT_SYSLOG(LOG_DEBUG, "");
        return _recursiveCheck;
    }

private:
    //* enability
    bool _enabled = true;

    //* used to avoid recursion when grabbing widgets
    bool _recursiveCheck = false;

    //* timer used to detect slow rendering
    QElapsedTimer _clock;

    //* max render time
    /*! used to detect slow rendering */
    int _maxRenderTime = 200;

    //* animation handling
    TransitionWidget::Pointer _transition;
};

bool TransitionData::hasParent(const QWidget *widget, const char *className) const
{
    CT_SYSLOG(LOG_DEBUG, "");
    if (!widget) {
        return false;
    }

    for (QWidget *parent = widget->parentWidget(); parent; parent = parent->parentWidget()) {
        if (parent->inherits(className)) {
            return true;
        }
    }

    return false;
}

}
#endif
