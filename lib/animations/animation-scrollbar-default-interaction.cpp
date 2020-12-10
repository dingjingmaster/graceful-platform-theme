#include "animation-scrollbar-default-interaction.h"

#include <QScrollBar>
#include <QVariantAnimation>
#include <QWidget>

ScrollBar::AnimationScrollbarDefaultInteraction::AnimationScrollbarDefaultInteraction(QObject *parent) : QParallelAnimationGroup (parent)
{

}

bool ScrollBar::AnimationScrollbarDefaultInteraction::unboundWidget()
{
    stop();
    setDirection(QAbstractAnimation::Forward);
    mSunkenSilderAdditionalOpacity->deleteLater();

    mGrooveWidth->deleteLater();
    mSliderOpacity->deleteLater();

    if (mWidget) {
        this->setParent(nullptr);
        return true;
    }

    return false;
}

bool ScrollBar::AnimationScrollbarDefaultInteraction::bindWidget(QWidget* w)
{
    if (w->property("doNotAnimate").toBool()) {
        return false;
    }

    if (qobject_cast<QScrollBar*>(w)) {
        mWidget = w;
    } else {
        return false;
    }

    mGrooveWidth = new QVariantAnimation(this);
    mGrooveWidth->setStartValue(0.0);
    mGrooveWidth->setEndValue(1.0);
    mGrooveWidth->setDuration(150);
    addAnimation(mGrooveWidth);

    mSliderOpacity = new QVariantAnimation(this);
    mSliderOpacity->setStartValue(0.2);
    mSliderOpacity->setEndValue(0.35);
    mSliderOpacity->setDuration(150);
    addAnimation(mSliderOpacity);

    mSunkenSilderAdditionalOpacity = new QVariantAnimation(this);
    mSunkenSilderAdditionalOpacity->setStartValue(0.0);
    mSunkenSilderAdditionalOpacity->setEndValue(0.15);
    mSunkenSilderAdditionalOpacity->setDuration(150);
    addAnimation(mSunkenSilderAdditionalOpacity);

    setObjectName("animator_scrollbar_default_interactior");

    connect(mGrooveWidth, &QVariantAnimation::valueChanged, w, [=] () {
        w->repaint();
    });
    connect(mSliderOpacity, &QVariantAnimation::valueChanged, w, [=] () {
        w->repaint();
    });
    connect(mSunkenSilderAdditionalOpacity, &QVariantAnimation::valueChanged, w, [=] () {
        w->repaint();
    });
    connect(mGrooveWidth, &QVariantAnimation::finished, w, [=] () {
        w->repaint();
    });
    connect(mSliderOpacity, &QVariantAnimation::finished, w, [=] () {
        w->repaint();
    });
    connect(mSunkenSilderAdditionalOpacity, &QVariantAnimation::finished, w, [=] () {
        w->repaint();
    });

    return true;
}

QWidget* ScrollBar::AnimationScrollbarDefaultInteraction::boundedWidget()
{
    return mWidget;
}

QVariant ScrollBar::AnimationScrollbarDefaultInteraction::value(const QString &property)
{
    if (property == "groove_width") {
        return mGrooveWidth->currentValue();
    } else if (property == "slider_opacity") {
        return mSliderOpacity->currentValue();
    } else if (property == "additional_opacity") {
        return mSunkenSilderAdditionalOpacity->currentValue();
    } else {
        return QVariant();
    }
}

bool ScrollBar::AnimationScrollbarDefaultInteraction::isRunning(const QString &property)
{
    if (property == "groove_width") {
        return mGrooveWidth->state() == Running;
    } else if (property == "slider_opacity") {
        return mSliderOpacity->state() == Running;
    } else if (property == "additional_opacity") {
        return mSunkenSilderAdditionalOpacity->state() == Running;
    } else {
        return this->state() == Running;
    }
}

bool ScrollBar::AnimationScrollbarDefaultInteraction::setAnimatorStartValue(const QString &property, const QVariant &value)
{
    if (property == "groove_width") {
        mGrooveWidth->setStartValue(value);
        return true;
    } else if (property == "slider_opacity") {
        mSliderOpacity->setStartValue(value);
        return true;
    } else if (property == "additional_opacity") {
        mSunkenSilderAdditionalOpacity->setStartValue(value);
        return true;
    } else {
        return false;
    }
}

bool ScrollBar::AnimationScrollbarDefaultInteraction::setAnimatorEndValue(const QString &property, const QVariant &value)
{
    if (property == "groove_width") {
        mGrooveWidth->setEndValue(value);
        return true;
    } else if (property == "slider_opacity") {
        mSliderOpacity->setEndValue(value);
        return true;
    } else if (property == "additional_opacity") {
        mSunkenSilderAdditionalOpacity->setEndValue(value);
        return true;
    } else {
        return false;
    }
}

int ScrollBar::AnimationScrollbarDefaultInteraction::totalAnimationDuration(const QString &property)
{
    if (property == "groove_width") {
        return mGrooveWidth->duration();
    } else if (property == "slider_opacity") {
        return mSliderOpacity->duration();
    } else if (property == "additional_opacity") {
        return mSunkenSilderAdditionalOpacity->duration();
    } else {
        return this->duration();
    }
}

void ScrollBar::AnimationScrollbarDefaultInteraction::stopAnimator(const QString &property)
{
    if (property == "groove_width") {
        mGrooveWidth->stop();
    } else if (property == "slider_opacity") {
        mSliderOpacity->stop();
    } else if (property == "additional_opacity") {
        mSunkenSilderAdditionalOpacity->stop();
    } else {
        this->stop();
    }
}

void ScrollBar::AnimationScrollbarDefaultInteraction::startAnimator(const QString &property)
{
    if (property == "groove_width") {
        mGrooveWidth->start();
    } else if (property == "slider_opacity") {
        mSliderOpacity->start();
    } else if (property == "additional_opacity") {
        mSunkenSilderAdditionalOpacity->start();
    } else {
        this->start();
    }
}

int ScrollBar::AnimationScrollbarDefaultInteraction::currentAnimatorTime(const QString &property)
{
    if (property == "groove_width") {
        return mGrooveWidth->currentTime();
    } else if (property == "slider_opacity") {
        return mSliderOpacity->currentTime();
    } else if (property == "additional_opacity") {
        return mSunkenSilderAdditionalOpacity->currentTime();
    } else {
        return this->currentTime();
    }
}

bool ScrollBar::AnimationScrollbarDefaultInteraction::setAnimatorDuration(const QString &property, int duration)
{
    if (property == "groove_width") {
        mGrooveWidth->setDuration(duration);
        return true;
    } else if (property == "slider_opacity") {
        mGrooveWidth->setDuration(duration);
        return true;
    } else if (property == "additional_opacity") {
        mSunkenSilderAdditionalOpacity->setDuration(duration);
        return true;
    } else {
        return false;
    }
}

void ScrollBar::AnimationScrollbarDefaultInteraction::setAnimatorDirectionForward(const QString &property, bool forward)
{
    auto d = forward? QAbstractAnimation::Forward: QAbstractAnimation::Backward;
    if (property == "groove_width") {
        mGrooveWidth->setDirection(d);
    } else if (property == "slider_opacity") {
        mSliderOpacity->setDirection(d);
    } else if (property == "additional_opacity") {
        mSunkenSilderAdditionalOpacity->setDirection(d);
    } else {
        return;
    }
}
