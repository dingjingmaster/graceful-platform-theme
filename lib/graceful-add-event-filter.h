#ifndef GRACEFULADDEVENTFILTER_H
#define GRACEFULADDEVENTFILTER_H
#include <QEvent>
#include <QObject>

#include "graceful-export.h"

namespace Graceful {
class GRACEFUL_EXPORT AddEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit AddEventFilter(QObject *parent = nullptr);
    virtual ~AddEventFilter();

    /**
     * @brief
     *  默认阻塞所有子控件事件
     *
     * @param obj
     * @param event
     *
     * @return bool
     */
    virtual bool eventFilter(QObject* obj, QEvent* event);

};
}

#endif // GRACEFULADDEVENTFILTER_H
