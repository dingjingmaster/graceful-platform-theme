#ifndef GRACEFUL_H
#define GRACEFUL_H

#include <QColor>
#include <QFlags>
#include <QStyle>
#include <QPalette>
#include <QPointer>
#include <QWeakPointer>
#include <QScopedPointer>

#include "graceful-export.h"

namespace Graceful
{
template<typename T> using WeakPointer      = QPointer<T>;
template<typename T> using ScopedPointer    = QScopedPointer<T, QScopedPointerPodDeleter>;


namespace Settings
{
    const bool  SingleClick {true};
    const bool  ShowIconsInMenuItems {true};
    const bool  ShowIconsOnPushButtons {true};
    const int   ToolButtonStyle {Qt::ToolButtonTextBesideIcon};
}

enum EnumMnemonicsMode
{
    MN_AUTO,
    MN_NEVER,
    MN_ALWAYS
};

enum EnumWindowDragMode
{
    WD_FULL,
    WD_NONE,
    WD_MINIMAL,
};


namespace Config
{
    // Common
    const int ShadowSize {0};
    const int ShadowStrength {0};
    const bool OutlineCloseButton {false};
    const QColor ShadowColor {Qt::transparent};

    // Style
    const int AnimationSteps {100};
    const int AnimationsDuration {180};
    const bool AnimationsEnabled {true};

    const int ScrollBarAddLineButtons {0};
    const int ScrollBarSubLineButtons {0};
    const bool ScrollBarShowOnMouseOver {true};

    const bool ProgressBarAnimated {true};
    const int ProgressBarBusyStepDuration {600};

    const bool ViewDrawTreeBranchLines {true};
    const bool ViewInvertSortIndicator {true};

    const int MnemonicsMode {MN_AUTO};
    const bool ToolBarDrawItemSeparator {0};
    const bool ViewDrawFocusIndicator {true};
    const bool SliderDrawTickMarks {true};
    const bool TabBarDrawCenteredTabs {false};
    const bool TitleWidgetDrawFrame {true};
    const bool DockWidgetDrawFrame {false};
    const bool SidePanelDrawFrame {false};
    const bool MenuItemDrawStrongFocus {true};

    const bool DrawWidgetRects {false};
    const QStringList WindowDragWhiteList;
    const QStringList WindowDragBlackList;

    const int SplitterProxyWidth {3};
    const bool SplitterProxyEnabled {true};

    const int WindowDragMode {0};
    const bool UseWMMoveResize {true};
    const bool WidgetExplorerEnabled {false};
    const bool StackedWidgetTransitionsEnabled {false};
}

namespace PropertyNames
{
    const char noAnimations[]           = "_no_animations";
    const char noWindowGrab[]           = "_no_window_grab";
    const char sidePanelView[]          = "_side_panel_view";
    const char netWMSkipShadow[]        = "_NET_WM_SKIP_SHADOW";
    const char netWMForceShadow[]       = "_NET_WM_FORCE_SHADOW";
    const char alteredBackground[]      = "_altered_background";
    const char toolButtonAlignment[]    = "_toolButton_alignment";
    const char menuTitle[]              = "_toolButton_menutitle";
}


enum Metrics {
    // frames
    Frame_FrameWidth                    = 4,
    Frame_FrameRadius                   = 5,

    // layout
    Layout_DefaultSpacing               = 6,
    Layout_ChildMarginWidth             = 6,
    Layout_TopLevelMarginWidth          = 10,

    // line editors
    LineEdit_MinWidth                   = 80,
    LineEdit_MinHeight                  = 36,
    LineEdit_FrameWidth                 = 3,
    LineEdit_MarginWidth                = 8,
    LineEdit_MarginHeight               = 2,

    // menu items
    Menu_FrameWidth                     = 0,
    MenuItem_MarginWidth                = 4,
    MenuItem_ItemSpacing                = 6,
    MenuItem_AcceleratorSpace           = 16,
    MenuButton_IndicatorWidth           = 20,

    // combobox
    ComboBox_MinWidth                   = 80,
    ComboBox_FrameWidth                 = 4,
    ComboBox_MinHeight                  = 36,
    ComboBox_MarginWidth                = 8,
    ComboBox_MarginHeight               = 4,

    // spinbox
    SpinBox_MinHeight                   = 36,
    SpinBox_MinWidth                    = 80,
    SpinBox_MarginWidth                 = 8,
    SpinBox_MarginHeight                = 4,
    SpinBox_ArrowButtonWidth            = 20,
    SpinBox_FrameWidth                  = LineEdit_FrameWidth,

    // groupbox title margin
    GroupBox_TitleMarginWidth           = 4,

    // buttons
    Button_MinWidth                     = 80,
    Button_MinHeight                    = 36,
    Button_MarginWidth                  = 8,
    Button_ItemSpacing                  = 4,
    Button_MarginHeight                 = 4,

    // tool buttons
    ToolButton_MarginWidth              = 6,
    ToolButton_ItemSpacing              = 4,
    ToolButton_InlineIndicatorWidth     = 12,

    // checkboxes and radio buttons
    CheckBox_Size                       = 22,
    CheckBox_ItemSpacing                = 4,
    CheckBox_FocusMarginWidth           = 3,

    // menubar items
    MenuBarItem_MarginWidth             = 8,
    MenuBarItem_MarginHeight            = 5,

    // scrollbars
    ScrollBar_Extend                    = 14,
    ScrollBar_SliderWidth               = 8,
    ScrollBar_MinSliderHeight           = 24,
    ScrollBar_SingleButtonHeight        = 0,
    ScrollBar_DoubleButtonHeight        = 0,
    ScrollBar_NoButtonHeight            = (ScrollBar_Extend - ScrollBar_SliderWidth) / 2,

    // toolbars
    ToolBar_FrameWidth                  = 2,
    ToolBar_HandleWidth                 = 6,
    ToolBar_ItemSpacing                 = 0,
    ToolBar_HandleExtent                = 10,
    ToolBar_SeparatorWidth              = 8,
    ToolBar_ExtensionWidth              = 20,

    // progressbars
    ProgressBar_Thickness               = 3,
    ProgressBar_ItemSpacing             = 3,
    ProgressBar_BusyIndicatorSize       = 24,

    // mdi title bar
    TitleBar_MarginWidth                = 4,

    // sliders
    Slider_TickLength                   = 4,
    Slider_TickMarginWidth              = 6,
    Slider_GrooveThickness              = 3,
    Slider_ControlThickness             = 24,

    // tabbar
    TabBar_TabOverlap                   = 1,
    TabBar_TabMinWidth                  = 80,
    TabBar_BaseOverlap                  = 0,
    TabBar_TabMinHeight                 = 36,
    TabBar_TabMarginWidth               = 8,
    TabBar_TabItemSpacing               = 8,
    TabBar_TabMarginHeight              = 9,

    // tab widget
    TabWidget_MarginWidth               = 4,

    // toolbox
    ToolBox_TabMinWidth                 = 80,
    ToolBox_TabItemSpacing              = 4,
    ToolBox_TabMarginWidth              = 8,

    // tooltips
    ToolTip_FrameWidth                  = 3,

    // scroll areas
    ScrollArea_FrameWidth               = 2,

    // list headers
    Header_ArrowSize                    = 10,
    Header_MarginWidth                  = 3,
    Header_ItemSpacing                  = 2,

    // tree view
    ItemView_ArrowSize                  = 10,
    ItemView_ItemMarginWidth            = 3,
    SidePanel_ItemMarginWidth           = 4,

    // splitter
    Splitter_SplitterWidth              = 1,

    // shadow dimensions
    Shadow_Overlap                      = 0

};

//* animation mode
enum AnimationMode
{
    AnimationNone                       = 0,
    AnimationHover                      = 0x1,
    AnimationFocus                      = 0x2,
    AnimationEnable                     = 0x4,
    AnimationPressed                    = 0x8
};
Q_DECLARE_FLAGS(AnimationModes, AnimationMode)

//* corners
enum Corner {
    CornerTopLeft                       = 0x1,
    CornerTopRight                      = 0x2,
    CornerBottomLeft                    = 0x4,
    CornerBottomRight                   = 0x8,
    CornersTop                          = CornerTopLeft | CornerTopRight,
    CornersLeft                         = CornerTopLeft | CornerBottomLeft,
    CornersRight                        = CornerTopRight | CornerBottomRight,
    CornersBottom                       = CornerBottomLeft | CornerBottomRight,
    AllCorners                          = CornerTopLeft | CornerTopRight | CornerBottomLeft | CornerBottomRight
};
Q_DECLARE_FLAGS(Corners, Corner)

//* sides
enum Side
{
    SideNone                            = 0x0,
    SideLeft                            = 0x1,
    SideTop                             = 0x2,
    SideRight                           = 0x4,
    SideBottom                          = 0x8,
    AllSides                            = SideLeft | SideTop | SideRight | SideBottom
};
Q_DECLARE_FLAGS(Sides, Side)

//* checkbox state
enum CheckBoxState
{
    CheckOn,
    CheckOff,
    CheckPartial,
    CheckAnimated
};

//* radio button state
enum RadioButtonState
{
    RadioOn,
    RadioOff,
    RadioAnimated
};

//* arrow orientation
enum ArrowOrientation
{
    ArrowUp,
    ArrowNone,
    ArrowDown,
    ArrowLeft,
    ArrowRight
};

//* button type
enum ButtonType
{
    ButtonClose,
    ButtonRestore,
    ButtonMaximize,
    ButtonMinimize,
};

// fixme:// DJ-
enum ColorVariant
{
    Unknown,
    Adwaita,
    AdwaitaDark,
    AdwaitaHighcontrast
};

class StyleOptionsPrivate;

class GRACEFUL_EXPORT StyleOptions
{
public:
    explicit StyleOptions(const QPalette &palette);
    virtual ~StyleOptions();

    QPalette palette() const;

    void setColorGroup(QPalette::ColorGroup group);
    QPalette::ColorGroup colorGroup() const;

    void setColorRole(QPalette::ColorRole role);
    QPalette::ColorRole colorRole() const;

    void setColorVariant(ColorVariant variant);
    ColorVariant colorVariant() const;

    void setActive(bool active);
    bool active() const;

    void setHasFocus(bool focus);
    bool hasFocus() const;

    void setMouseOver(bool mouseOver);
    bool mouseOver() const;

    void setOpacity(qreal opacity);
    qreal opacity() const;

    void setAnimationMode(AnimationMode mode);
    AnimationMode animationMode() const;

    void setCheckboxState(CheckBoxState state);
    CheckBoxState checkboxState() const;

    void setState(QStyle::State state);
    QStyle::State state() const;

    void setInMenu(bool inMenu);
    bool inMenu() const;

    void setSunken(bool sunken);
    bool sunken() const;

private:
    Q_DECLARE_PRIVATE(StyleOptions)

    const QScopedPointer<StyleOptionsPrivate> d_ptr;
};
}

Q_DECLARE_OPERATORS_FOR_FLAGS(Graceful::Sides)
Q_DECLARE_OPERATORS_FOR_FLAGS(Graceful::Corners)
Q_DECLARE_OPERATORS_FOR_FLAGS(Graceful::AnimationModes)


#endif // GRACEFUL_H
