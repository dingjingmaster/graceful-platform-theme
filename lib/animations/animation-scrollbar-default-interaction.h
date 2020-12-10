#ifndef ANIMATIONSCROLLBARDEFAULTINTERACTION_H
#define ANIMATIONSCROLLBARDEFAULTINTERACTION_H

#include "animator-iface.h"

#include <QParallelAnimationGroup>

class QVariantAnimation;

namespace ScrollBar {

class AnimationScrollbarDefaultInteraction : public QParallelAnimationGroup, public AnimatorIface
{
    Q_OBJECT
public:
    explicit AnimationScrollbarDefaultInteraction (QObject* parent = nullptr);

    bool unboundWidget();
    bool bindWidget(QWidget*);
    QWidget* boundedWidget();

    QVariant value(const QString &property);
    bool isRunning(const QString &property = nullptr);
    bool setAnimatorStartValue(const QString &property, const QVariant &value);
    bool setAnimatorEndValue(const QString &property, const QVariant &value);

    int totalAnimationDuration(const QString &property);
    void stopAnimator(const QString &property = nullptr);
    void startAnimator(const QString &property = nullptr);
    int currentAnimatorTime(const QString &property = nullptr);
    bool setAnimatorDuration(const QString &property, int duration);
    void setAnimatorDirectionForward(const QString &property = nullptr, bool forward = true);

private:
    QWidget*                    mWidget = nullptr;

    QVariantAnimation*          mGrooveWidth;
    QVariantAnimation*          mSliderOpacity;
    QVariantAnimation*          mSunkenSilderAdditionalOpacity;
};
}


#endif // ANIMATIONSCROLLBARDEFAULTINTERACTION_H
