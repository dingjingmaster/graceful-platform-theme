#ifndef ANIMATOR_IFACE_H
#define ANIMATOR_IFACE_H
#include "animator-plugin-iface.h"

#include <QVariant>

class QWidget;

class AnimatorIface
{
public:
    virtual ~AnimatorIface() {}

    virtual bool unboundWidget () {return false;}
    virtual bool bindWidget (QWidget*) {return false;}
    virtual QWidget *boundedWidget () {return nullptr;}

    virtual QVariant value (const QString& property) {return QVariant();}
    virtual bool setAnimatorDuration (const QString& property, int duration) {return false;}
    virtual bool setAnimatorEndValue (const QString& property, const QVariant& value) {return false;}
    virtual bool setAnimatorStartValue (const QString& property, const QVariant& value) {return false;}

    virtual void stopAnimator (const QString& property = nullptr) {}
    virtual void startAnimator (const QString& property = nullptr) {}
    virtual bool isRunning (const QString& property = nullptr) {return false;}
    virtual int currentAnimatorTime (const QString& property = nullptr) {return 0;}
    virtual int totalAnimationDuration (const QString& property = nullptr) {return 0;}
    virtual void setAnimatorDirectionForward (const QString& property = nullptr, bool forward = true) {}
};
#endif // ANIMATOR-IFACE_H
