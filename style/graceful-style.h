#ifndef GRACEFUL_GRACEFULSTYLE_H
#define GRACEFUL_GRACEFULSTYLE_H
#include "graceful.h"
#include "csyslog.h"

#include <QHash>
#include <QIcon>
#include <QWidget>
#include <QDockWidget>
#include <QCommonStyle>
#include <QStyleOption>
#include <QMdiSubWindow>
#include <QAbstractItemView>
#include <QCommandLinkButton>
#include <QAbstractScrollArea>

namespace GracefulPrivate
{
class TabBarData;
}

namespace Graceful
{
class Helper;
class Mnemonics;
class Animations;
class WindowManager;
class WidgetExplorer;
class SplitterFactory;

/**
 * @note
 *  c++11 中的新特性，类似于typedef，用来取别名
 */
using ParentStyleClass = QCommonStyle;

/**
 * @brief
 *  负责绘制所有显示到屏幕上的内容(仅限于使用QT框架的应用)
 *  QCommonStyle 这个抽象类实现了一些小部件的外观，这些外观与Qt中提供的所有GUI样式相同。QCommonStyle继承了QStyle
 *
 * @note
 *  需要实现的方法如下：
 *      1. virtual void drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget = nullptr) const override
 *          使用指定的样式选项，绘制指定的控件，具体控件是：SpinBox、CpmboBox、ScrollBox、Dial、ToolButton、TitleBar
 *
 *      2. virtual void drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *widget = nullptr) const override
 *          绘制给定元素
 *
 *      3. virtual void	drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *widget = nullptr) const override
 *          绘制控件属性，焦点存在与离开 ...
 *
 *      4. virtual QPixmap generatedIconPixmap(QIcon::Mode iconMode, const QPixmap &pixmap, const QStyleOption *opt) const override
 *          根据参数返回 pixmap 的副本
 *
 *      5. virtual QStyle::SubControl hitTestComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, const QPoint &pt, const QWidget *widget = nullptr) const override
 *          返回给定复杂控件中，给定位置的子控件
 *
 *      6. virtual int layoutSpacing(QSizePolicy::ControlType control1, QSizePolicy::ControlType control2, Qt::Orientation orientation, const QStyleOption *option = nullptr, const QWidget *widget = nullptr) const override
 *          返回布局中control1和control2之间应该使用的间距。朝向指定控件是并排放置还是垂直堆叠。option参数可用于传递关于父小部件的额外信息
 *
 *      7. virtual int pixelMetric(QStyle::PixelMetric m, const QStyleOption *opt = nullptr, const QWidget *widget = nullptr) const override
 *          返回给定像素度量的值
 *
 *      8. virtual void polish(QPalette &pal) override
 *          初始化 widget 的外观，此函数在widget创建之后、显示之前调用
 *
 *      9. virtual void polish(QApplication *app) override
 *          给定应用程序对象的延迟初始化
 *
 *      10. virtual void polish(QWidget *widget) override
 *          根据风格对调色板的特定要求(如果有的话)更改调色板。
 *
 *      11. virtual QSize sizeFromContents(QStyle::ContentsType ct, const QStyleOption *opt, const QSize &csz, const QWidget *widget = nullptr) const override
 *          根据提供的contentsSize返回指定选项和类型所描述的元素的大小。
 *
 *      12. virtual QPixmap standardPixmap(QStyle::StandardPixmap sp, const QStyleOption *option = nullptr, const QWidget *widget = nullptr) const override
 *          已过时
 *
 *      13. virtual int styleHint(QStyle::StyleHint sh, const QStyleOption *opt = nullptr, const QWidget *widget = nullptr, QStyleHintReturn *hret = nullptr) const override
 *          返回一个 int，用来表示由提供的样式选项描述的给定widget的样式提示
 *
 *      14. virtual QRect subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QStyle::SubControl sc, const QWidget *widget = nullptr) const override
 *          返回包含给定复杂控件的指定子控件的矩形(样式由选项指定)。矩形是在屏幕坐标中定义的。
 *
 *      15. virtual QRect subElementRect(QStyle::SubElement sr, const QStyleOption *opt, const QWidget *widget = nullptr) const override
 *          返回在所提供的样式选项中描述的给定元素的子区域。返回的矩形是以屏幕坐标定义的。
 *
 *      16. virtual void unpolish(QWidget *widget) override
 *      17. virtual void unpolish(QApplication *application) override
 *          在样式改变时候调用，与 polish 对应，
 */
class Style : public ParentStyleClass
{
    Q_OBJECT

    /**
     * @note
     *  这告诉kde应用程序，使用kstyle机制支持定制样式元素
     */
    Q_CLASSINFO("X-KDE-CustomElements", "true")

public:
    explicit Style(bool dark);
    virtual ~Style(void);

    using ParentStyleClass::polish;
    using ParentStyleClass::unpolish;

    /**
     * @brief
     *  每个 widget 创建之后，显示之前调用
     */
    virtual void polish(QWidget *widget);

    /**
     * @brief
     *  与 polish 对应
     */
    virtual void unpolish(QWidget *widget);

    virtual void polish(QPalette &palette);

    virtual QPalette standardPalette() const;

    virtual int pixelMetric(PixelMetric metric, const QStyleOption *option = nullptr, const QWidget *widget = nullptr) const;

    /**
     * @brief
     */
    virtual int styleHint(StyleHint hint, const QStyleOption *option = nullptr, const QWidget *widget = nullptr, QStyleHintReturn *returnData = nullptr) const;
    virtual QRect subElementRect(SubElement element, const QStyleOption *option, const QWidget *widget) const;
    virtual QRect subControlRect(ComplexControl element, const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    virtual bool eventFilter(QObject *object, QEvent *event);
    virtual void drawItemText(QPainter *painter, const QRect &rect, int alignment, const QPalette &palette, bool enabled, const QString &text, QPalette::ColorRole textRole = QPalette::NoRole) const;

    void addEventFilter(QObject *object);
    void polishScrollArea(QAbstractScrollArea *scrollArea);
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    QSize sizeFromContents(ContentsType element, const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    void drawComplexControl(ComplexControl element, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    SubControl hitTestComplexControl(ComplexControl control, const QStyleOptionComplex *option , const QPoint &point, const QWidget *widget) const;

    bool eventFilterScrollArea(QWidget *widget, QEvent *event);
    bool eventFilterComboBoxContainer(QWidget *widget, QEvent *event);
    bool eventFilterDockWidget(QDockWidget *dockWidget, QEvent *event);
    bool eventFilterMdiSubWindow(QMdiSubWindow *subWindow, QEvent *event);
    bool eventFilterCommandLinkButton(QCommandLinkButton *button, QEvent *event);

protected Q_SLOTS:
    /**
     * @brief
     *  调色板等改变的时候调用
     */
    void configurationChanged(void);
    virtual QIcon standardIconImplementation(StandardPixmap standardPixmap, const QStyleOption *option, const QWidget *widget) const;

protected:
    //* standard icons
    virtual QIcon standardIcon(StandardPixmap pixmap, const QStyleOption *option = nullptr, const QWidget *widget = nullptr) const;

    /**
     * @brief 读取配置
     */
    void loadConfiguration();

    //* default implementation. Does not change anything
    QRect defaultSubElementRect(const QStyleOption *option, const QWidget *widget) const;
    QRect pushButtonContentsRect(const QStyleOption *option, const QWidget *widget) const;
    QRect pushButtonFocusRect(const QStyleOption *option, const QWidget *widget) const;
    QRect checkBoxContentsRect(const QStyleOption *option, const QWidget *widget) const;
    QRect checkBoxIndicatorRect(const QStyleOption *option, const QWidget *widget) const;
    QRect checkBoxFocusRect(const QStyleOption *option, const QWidget *widget) const;
    QRect lineEditContentsRect(const QStyleOption *option, const QWidget *widget) const;
    QRect progressBarGrooveRect(const QStyleOption *option, const QWidget *widget) const;
    QRect progressBarContentsRect(const QStyleOption *option, const QWidget *widget) const;
    QRect progressBarLabelRect(const QStyleOption *option, const QWidget *widget) const;
    QRect headerArrowRect(const QStyleOption *option, const QWidget *widget) const;
    QRect headerLabelRect(const QStyleOption *option, const QWidget *widget) const;
    QRect sliderFocusRect(const QStyleOption *option, const QWidget *widget) const;
    QRect tabBarTabLeftButtonRect(const QStyleOption *option, const QWidget *widget) const;
    QRect tabBarTabRightButtonRect(const QStyleOption *option, const QWidget *widget) const;
    QRect tabWidgetTabBarRect(const QStyleOption *option, const QWidget *widget) const;
    QRect tabWidgetTabContentsRect(const QStyleOption *option, const QWidget *widget) const;
    QRect tabWidgetTabPaneRect(const QStyleOption *option, const QWidget *widget) const;
    QRect tabWidgetCornerRect(SubElement element, const QStyleOption *option, const QWidget *widget) const;
    QRect toolBoxTabContentsRect(const QStyleOption *option, const QWidget *widget) const;
    QRect genericLayoutItemRect(const QStyleOption *option, const QWidget *widget) const;

    QRect groupBoxSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    QRect toolButtonSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    QRect comboBoxSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    QRect spinBoxSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    QRect scrollBarInternalSubControlRect(const QStyleOptionComplex *option, SubControl subControl) const;
    QRect scrollBarSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    QRect dialSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;
    QRect sliderSubControlRect(const QStyleOptionComplex *option, SubControl subControl, const QWidget *widget) const;

    QSize defaultSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;

    QSize checkBoxSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize lineEditSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize comboBoxSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize spinBoxSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize sliderSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize pushButtonSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize toolButtonSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize menuBarItemSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize menuItemSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize progressBarSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize tabWidgetSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize tabBarTabSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize headerSectionSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QSize itemViewItemSizeFromContents(const QStyleOption *option, const QSize &size, const QWidget *widget) const;

    bool emptyPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    bool drawFramePrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameLineEditPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameFocusRectPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameMenuPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameGroupBoxPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameTabWidgetPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameTabBarBasePrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawFrameWindowPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    bool drawIndicatorArrowUpPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorArrowDownPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorArrowLeftPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorArrowRightPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    bool drawIndicatorArrowPrimitive(ArrowOrientation orientation, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorHeaderArrowPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelButtonCommandPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelButtonToolPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawTabBarPanelButtonToolPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelScrollAreaCornerPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelMenuPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelTipLabelPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelItemViewRowPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawPanelItemViewItemPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorCheckBoxPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorRadioButtonPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorButtonDropDownPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorTabClosePrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorTabTearPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorToolBarHandlePrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorToolBarSeparatorPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    bool drawIndicatorBranchPrimitive(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    bool emptyControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    virtual bool drawPushButtonLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawToolButtonLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawCheckBoxLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawComboBoxLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawItemViewItemControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawMenuBarEmptyArea(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawMenuBarItemControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawMenuItemControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawProgressBarControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawProgressBarContentsControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawProgressBarGrooveControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawProgressBarLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawScrollBarSliderControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawScrollBarAddLineControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawScrollBarSubLineControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawShapedFrameControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawRubberBandControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawHeaderSectionControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawHeaderLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawHeaderEmptyAreaControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawTabBarTabLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawTabBarTabShapeControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawToolBoxTabLabelControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawToolBoxTabShapeControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    virtual bool drawDockWidgetTitleControl(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    bool drawGroupBoxComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawToolButtonComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawComboBoxComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawSpinBoxComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawSliderComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawDialComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawScrollBarComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;
    bool drawTitleBarComplexControl(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;

    //* spinbox arrows
    void renderSpinBoxArrow(const SubControl &subControl, const QStyleOptionSpinBox *option, QPainter *painter, const QWidget *widget) const;

    //* menu title
    void renderMenuTitle(const QStyleOptionToolButton *option, QPainter *painter, const QWidget *widget) const;

    //* return dial angle based on option and value
    qreal dialAngle(const QStyleOptionSlider *sliderOption, int value) const;

    //* returns relevant scrollbar parent
    /** needed to detect parent focus */
    const QWidget *scrollBarParent(const QWidget *widget) const;

    //* returns true if given scrollbar arrow is animated
    QColor scrollBarArrowColor(const QStyleOptionSlider *option, const SubControl &control, const QWidget *widget) const;

    //* scrollbar buttons
    enum ScrollBarButtonType
    {
        NoButton,
        SingleButton,
        DoubleButton
    };

    //* returns height for scrollbar buttons depending of button types
    int scrollBarButtonHeight(const ScrollBarButtonType &type) const;

    //* translucent background
    void setTranslucentBackground(QWidget *widget) const;

    /**
    separator can have a title and an icon
    in that case they are rendered as sunken flat toolbuttons
    return toolbutton option that matches named separator menu items
    */
    QStyleOptionToolButton separatorMenuItemOption(const QStyleOptionMenuItem *menuItemOption, const QWidget *widget) const;

    //* create toolbar extension icon
    QIcon toolBarExtensionIcon(StandardPixmap, const QStyleOption *option, const QWidget *widget) const;

    //* create title bar button icon
    QIcon titleBarButtonIcon(StandardPixmap, const QStyleOption *option, const QWidget *widget) const;

    //* returns item view parent if any
    /** needed to have correct color on focused checkboxes and radiobuttons */
    const QAbstractItemView *itemViewParent(const QWidget *widget) const;

    //* returns true if a given widget is a selected item in a focused list
    /**
    This is necessary to have the correct colors used for e.g. checkboxes and radiobuttons in lists
    @param widget The widget to be checked
    @param position Used to find the relevant QModelIndex
    */
    bool isSelectedItem(const QWidget *widget, const QPoint &localPosition) const;

    //* return true if option corresponds to QtQuick control
    bool isQtQuickControl(const QStyleOption *option, const QWidget *widget) const;

    //* adjust rect based on provided margins
    QRect insideMargin(const QRect &r, int margin) const;

    //* adjust rect based on provided margins
    QRect insideMargin(const QRect &r, int marginWidth, int marginHeight) const;

    //* expand size based on margins
    QSize expandSize(const QSize &size, int margin) const;

    //* expand size based on margins
    QSize expandSize(const QSize &size, int marginWidth, int marginHeight) const;

    //* returns true for vertical tabs
    bool isVerticalTab(const QStyleOptionTab *option) const;

    bool isVerticalTab(const QTabBar::Shape &shape) const;

    //* right to left alignment handling
    using ParentStyleClass::visualRect;
    QRect visualRect(const QStyleOption *opt, const QRect &subRect) const;

    //* centering
    QRect centerRect(const QRect &rect, const QSize &size) const;

    QRect centerRect(const QRect &rect, int width, int height) const;

    /*
    Checks whether the point is before the bound rect for bound of given orientation.
    This is needed to implement custom number of buttons in scrollbars,
    as well as proper mouse-hover
    */
    inline bool preceeds(const QPoint &point, const QRect &bound, const QStyleOption *option) const;

    //* return which arrow button is hit by point for scrollbar double buttons
    inline QStyle::SubControl scrollBarHitTest(const QRect &rect, const QPoint &point, const QStyleOption *option) const;

    //! return true if one of the widget's parent inherits requested type
    inline bool hasParent(const QWidget *widget, const char *className) const;

    //* return true if one of the widget's parent inherits requested type
    template<typename T> bool hasParent(const QWidget *widget) const;

    //* return true if icons should be shown in menus
    bool showIconsInMenuItems(void) const;

    //* return true if icons should be shown on buttons
    bool showIconsOnPushButtons(void) const;

    //* return true if passed widget is a menu title (KMenu::addTitle)
    bool isMenuTitle(const QWidget *widget) const;

    //* return true if passed widget is a menu title (KMenu::addTitle)
    bool hasAlteredBackground(const QWidget *widget) const;

private:

    //*@name scrollbar button types (for addLine and subLine )
    //@{
    ScrollBarButtonType _addLineButtons;
    ScrollBarButtonType _subLineButtons;
    //@}

    //* helper
    Helper *_helper;

    //* animations
    Animations *_animations;

    //* keyboard accelerators
    Mnemonics *_mnemonics;

    //* window manager
    WindowManager *_windowManager;

    //* splitter Factory, to extend splitters hit area
    SplitterFactory *_splitterFactory;

    //* widget explorer
    WidgetExplorer *_widgetExplorer;

    //* tabbar data
    GracefulPrivate::TabBarData *_tabBarData;

    //* icon hash
    using IconCache = QHash<StandardPixmap, QIcon>;
    IconCache _iconCache;

    //* pointer to primitive specialized function
    using StylePrimitive = bool(Style::*)(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    StylePrimitive _frameFocusPrimitive = nullptr;

    //* pointer to control specialized function
    using StyleControl = bool (Style::*)(const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    //* pointer to control specialized function
    using StyleComplexControl = bool (Style::*)(const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const;

    //*@name custom elements
    //@{

    //* use Argb Drag and Drop Window
    QStyle::StyleHint SH_ArgbDndWindow;

    //! styled painting for KCapacityBar
    QStyle::ControlElement CE_CapacityBar;

    bool _dark      = false;
    bool _isKDE     = false;
    bool _isGNOME   = false;
};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULSTYLE_H
