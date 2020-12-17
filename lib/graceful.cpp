#include "graceful.h"

#include "animations/graceful-animations.h"

namespace Graceful
{

class StyleOptionsPrivate
{
public:
    explicit StyleOptionsPrivate(const QPalette &palette)
        : mPalette(palette)
    {

        CT_SYSLOG(LOG_DEBUG, "");
    }
    virtual ~StyleOptionsPrivate()
    {

        CT_SYSLOG(LOG_DEBUG, "");
    }

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
    CT_SYSLOG(LOG_DEBUG, "");
}

StyleOptions::~StyleOptions()
{
    CT_SYSLOG(LOG_DEBUG, "");
}

QPalette StyleOptions::palette() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mPalette;
}

void StyleOptions::setColorGroup(QPalette::ColorGroup group)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mColorGroup = group;
}

QPalette::ColorGroup StyleOptions::colorGroup() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mColorGroup;
}

void StyleOptions::setColorRole(QPalette::ColorRole role)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mColorRole = role;
}

QPalette::ColorRole StyleOptions::colorRole() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mColorRole;
}

void StyleOptions::setColorVariant(ColorVariant variant)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mColorVariant = variant;
}

ColorVariant StyleOptions::colorVariant() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mColorVariant;
}

void StyleOptions::setActive(bool active)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mActive = active;
}

bool StyleOptions::active() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mActive;
}

void StyleOptions::setHasFocus(bool focus)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mFocus = focus;
}

bool StyleOptions::hasFocus() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mFocus;
}

void StyleOptions::setMouseOver(bool mouseOver)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mMouseHover = mouseOver;
}

bool StyleOptions::mouseOver() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mMouseHover;
}

void StyleOptions::setOpacity(qreal opacity)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mOpacity = opacity;
}

qreal StyleOptions::opacity() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mOpacity;
}

void StyleOptions::setAnimationMode(AnimationMode mode)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mAnimationMode = mode;
}

AnimationMode StyleOptions::animationMode() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mAnimationMode;
}

void StyleOptions::setCheckboxState(CheckBoxState state)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mCheckboxState = state;
}

CheckBoxState StyleOptions::checkboxState() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mCheckboxState;
}

void StyleOptions::setState(QStyle::State state)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mState = state;
}

QStyle::State StyleOptions::state() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mState;
}

void StyleOptions::setInMenu(bool inMenu)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mInMenu = inMenu;
}

bool StyleOptions::inMenu() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mInMenu;
}

void StyleOptions::setSunken(bool sunken)
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(StyleOptions);

    d->mSunken = sunken;
}

bool StyleOptions::sunken() const
{
    CT_SYSLOG(LOG_DEBUG, "");
    Q_D(const StyleOptions);

    return d->mSunken;
}

}
