#include "graceful.h"

#include "animations/graceful-animations.h"

namespace Graceful
{

class StyleOptionsPrivate
{
public:
    explicit StyleOptionsPrivate(const QPalette &palette)
        : mPalette(palette)
    { }
    virtual ~StyleOptionsPrivate()
    { }

    QPalette mPalette;
    QPalette::ColorGroup mColorGroup = QPalette::ColorGroup::Normal;
    QPalette::ColorRole mColorRole = QPalette::ColorRole::Base;
    ColorVariant mColorVariant = ColorVariant::Unknown;
    bool mActive = false;
    bool mFocus = false;
    bool mMouseHover = false;
    qreal mOpacity = AnimationData::OpacityInvalid;
    AnimationMode mAnimationMode = AnimationNone;
    CheckBoxState mCheckboxState = CheckOff;
    QStyle::State mState = QStyle::State_None;
    bool mInMenu = false;
    bool mSunken = false;
};

StyleOptions::StyleOptions(const QPalette &palette)
    : d_ptr(new StyleOptionsPrivate(palette))
{
}

StyleOptions::~StyleOptions()
{
}

QPalette StyleOptions::palette() const
{
    Q_D(const StyleOptions);

    return d->mPalette;
}

void StyleOptions::setColorGroup(QPalette::ColorGroup group)
{
    Q_D(StyleOptions);

    d->mColorGroup = group;
}

QPalette::ColorGroup StyleOptions::colorGroup() const
{
    Q_D(const StyleOptions);

    return d->mColorGroup;
}

void StyleOptions::setColorRole(QPalette::ColorRole role)
{
    Q_D(StyleOptions);

    d->mColorRole = role;
}

QPalette::ColorRole StyleOptions::colorRole() const
{
    Q_D(const StyleOptions);

    return d->mColorRole;
}

void StyleOptions::setColorVariant(ColorVariant variant)
{
    Q_D(StyleOptions);

    d->mColorVariant = variant;
}

ColorVariant StyleOptions::colorVariant() const
{
    Q_D(const StyleOptions);

    return d->mColorVariant;
}

void StyleOptions::setActive(bool active)
{
    Q_D(StyleOptions);

    d->mActive = active;
}

bool StyleOptions::active() const
{
    Q_D(const StyleOptions);

    return d->mActive;
}

void StyleOptions::setHasFocus(bool focus)
{
    Q_D(StyleOptions);

    d->mFocus = focus;
}

bool StyleOptions::hasFocus() const
{
    Q_D(const StyleOptions);

    return d->mFocus;
}

void StyleOptions::setMouseOver(bool mouseOver)
{
    Q_D(StyleOptions);

    d->mMouseHover = mouseOver;
}

bool StyleOptions::mouseOver() const
{
    Q_D(const StyleOptions);

    return d->mMouseHover;
}

void StyleOptions::setOpacity(qreal opacity)
{
    Q_D(StyleOptions);

    d->mOpacity = opacity;
}

qreal StyleOptions::opacity() const
{
    Q_D(const StyleOptions);

    return d->mOpacity;
}

void StyleOptions::setAnimationMode(AnimationMode mode)
{
    Q_D(StyleOptions);

    d->mAnimationMode = mode;
}

AnimationMode StyleOptions::animationMode() const
{
    Q_D(const StyleOptions);

    return d->mAnimationMode;
}

void StyleOptions::setCheckboxState(CheckBoxState state)
{
    Q_D(StyleOptions);

    d->mCheckboxState = state;
}

CheckBoxState StyleOptions::checkboxState() const
{
    Q_D(const StyleOptions);

    return d->mCheckboxState;
}

void StyleOptions::setState(QStyle::State state)
{
    Q_D(StyleOptions);

    d->mState = state;
}

QStyle::State StyleOptions::state() const
{
    Q_D(const StyleOptions);

    return d->mState;
}

void StyleOptions::setInMenu(bool inMenu)
{
    Q_D(StyleOptions);

    d->mInMenu = inMenu;
}

bool StyleOptions::inMenu() const
{
    Q_D(const StyleOptions);

    return d->mInMenu;
}

void StyleOptions::setSunken(bool sunken)
{
    Q_D(StyleOptions);

    d->mSunken = sunken;
}

bool StyleOptions::sunken() const
{
    Q_D(const StyleOptions);

    return d->mSunken;
}

}
