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
        QColor  window_bg(231,231,231),
                window_no_bg(233,233,233),
                base_bg(255,255,255),
                base_no_bg(248, 248, 248),
                font_bg(0,0,0),
                font_br_bg(255,255,255),
                font_di_bg(191,191,191),
                button_bg(217,217,217),
                button_ac_bg(107,142,235),
                button_di_bg(233,233,233),
                highlight_bg(61,107,229),
                tip_bg(248,248,248),
                tip_font(22,22,22),
                alternateBase(248,248,248);

        if (GracefulDark == mColorVariant) {
            window_bg.setRgb(45,46,50);
            window_no_bg.setRgb(48,46,50);
            base_bg.setRgb(31,32,34);
            base_no_bg.setRgb(28,28,30);
            font_bg.setRgb(255,255,255);
            font_bg.setAlphaF(0.9);
            font_br_bg.setRgb(255,255,255);
            font_br_bg.setAlphaF(0.9);
            font_di_bg.setRgb(255,255,255);
            font_di_bg.setAlphaF(0.3);
            button_bg.setRgb(61,61,65);
            button_ac_bg.setRgb(48,48,51);
            button_di_bg.setRgb(48,48,51);
            highlight_bg.setRgb(61,107,229);
            tip_bg.setRgb(61,61,65);
            tip_font.setRgb(232,232,232);
            alternateBase.setRgb(36,35,40);
        }

        mPalette.setBrush(QPalette::Window,window_bg);
        mPalette.setBrush(QPalette::Active,QPalette::Window,window_bg);
        mPalette.setBrush(QPalette::Inactive,QPalette::Window,window_no_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::Window,window_no_bg);
        mPalette.setBrush(QPalette::WindowText,font_bg);
        mPalette.setBrush(QPalette::Active,QPalette::WindowText,font_bg);
        mPalette.setBrush(QPalette::Inactive,QPalette::WindowText,font_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::WindowText,font_di_bg);

        mPalette.setBrush(QPalette::Base,base_bg);
        mPalette.setBrush(QPalette::Active,QPalette::Base,base_bg);
        mPalette.setBrush(QPalette::Inactive,QPalette::Base,base_no_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::Base,base_no_bg);
        mPalette.setBrush(QPalette::Text,font_bg);
        mPalette.setBrush(QPalette::Active,QPalette::Text,font_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::Text,font_di_bg);

        //Cursor placeholder
#if (QT_VERSION >= QT_VERSION_CHECK(5,12,0))
        mPalette.setBrush(QPalette::PlaceholderText,font_di_bg);
#endif

        mPalette.setBrush(QPalette::ToolTipBase,tip_bg);
        mPalette.setBrush(QPalette::ToolTipText,tip_font);

        mPalette.setBrush(QPalette::Highlight,highlight_bg);
        mPalette.setBrush(QPalette::Active,QPalette::Highlight,highlight_bg);
        mPalette.setBrush(QPalette::HighlightedText,font_br_bg);

        mPalette.setBrush(QPalette::BrightText,font_br_bg);
        mPalette.setBrush(QPalette::Active,QPalette::BrightText,font_br_bg);
        mPalette.setBrush(QPalette::Inactive,QPalette::BrightText,font_br_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::BrightText,font_di_bg);

        mPalette.setBrush(QPalette::Button,button_bg);
        mPalette.setBrush(QPalette::Active,QPalette::Button,button_bg);
        mPalette.setBrush(QPalette::Inactive,QPalette::Button,button_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::Button,button_di_bg);
        mPalette.setBrush(QPalette::ButtonText,font_bg);
        mPalette.setBrush(QPalette::Inactive,QPalette::ButtonText,font_bg);
        mPalette.setBrush(QPalette::Disabled,QPalette::ButtonText,font_di_bg);

        mPalette.setBrush(QPalette::AlternateBase,alternateBase);
        mPalette.setBrush(QPalette::Inactive,QPalette::AlternateBase,alternateBase);
        mPalette.setBrush(QPalette::Disabled,QPalette::AlternateBase,button_di_bg);
    }
    virtual ~StyleOptionsPrivate()
    {

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
