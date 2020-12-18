#ifndef GRACEFUL_GRACEFULHELPER_H
#define GRACEFUL_GRACEFULHELPER_H


#include "graceful.h"
#include "animations/graceful-animation-data.h"
//#include "config-graceful.h"

#include <QStyle>
#include <QWidget>
#include <QWindow>
#include <QPainterPath>


#if GRACEFUL_HAVE_X11
#include <QX11Info>
#include <xcb/xcb.h>
#endif

#include <cmath>

namespace Graceful
{
class Helper
{
public:
    //* constructor
    explicit Helper();

    //* destructor
    virtual ~Helper()
    {
    }

    static bool isWindowActive(const QWidget *widget);

    //*@name rendering utilities
    //@{

    //* debug frame
    void renderDebugFrame(QPainter *painter, const QRect &) const;

    //* focus rect
    void renderFocusRect(QPainter *painter, const QRect &rect, const QColor &, const QColor &outline = QColor(), Sides = 0) const;

    //* focus line
    void renderFocusLine(QPainter *painter, const QRect &rect, const QColor &) const;

    //* generic frame
    void renderFrame(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline = QColor(), bool hasFocus = false) const;

    //* square frame
    void renderSquareFrame(QPainter *painter, const QRect &rect, QColor color, bool hasFocus) const;

    //* generic frame flat on right side
    void renderFlatFrame(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline = QColor(), bool hasFocus = false) const;

    //* side panel frame
    void renderSidePanelFrame(QPainter *painter, const QRect &rect, const QColor &outline, Side) const;

    //* menu frame
    void renderMenuFrame(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, bool roundCorners = true) const;

    //* button frame
    void renderButtonFrame(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, const QColor &shadow, bool focus, bool sunken, bool mouseOver, bool active, bool darkMode = false) const;

    //* checkbox frame
    void renderCheckBoxFrame(QPainter *painter,
                             const QRect &rect,
                             const QColor &color,
                             const QColor &outline,
                             const QColor &shadow,
                             bool focus,
                             bool sunken,
                             bool mouseOver,
                             bool active,
                             CheckBoxState state = CheckOff,
                             bool darkMode = false,
                             bool inMenu = false) const;

    //* button frame
    void renderFlatButtonFrame(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, const QColor &shadow, bool focus, bool sunken, bool mouseOver, bool active) const;

    //* toolbutton frame
    void renderToolButtonFrame(QPainter *painter, const QRect &rect, const QColor &color, bool sunken) const;

    //* toolbutton frame
    void renderToolBoxFrame(QPainter *painter, const QRect &rect, int tabWidth, const QColor &color) const;

    //* tab widget frame
    void renderTabWidgetFrame(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, Corners) const;

    //* selection frame
    void renderSelection(QPainter *painter, const QRect &rect, const QColor &) const;

    //* separator
    void renderSeparator(QPainter *painter, const QRect &rect, const QColor &, bool vertical = false) const;

    //* checkbox
    void renderCheckBoxBackground(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, bool sunken) const;

    //* checkbox
    void renderCheckBox(QPainter *painter,
                        const QRect &rect,
                        const QColor &background,
                        const QColor &outline,
                        const QColor &tickColor,
                        bool sunken,
                        CheckBoxState state,
                        bool mouseOver,
                        qreal animation = AnimationData::OpacityInvalid,
                        bool active = true,
                        bool darkMode = false,
                        bool inMenu = false) const;

    //* radio button
    void renderRadioButtonBackground(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, bool sunken) const;

    //* radio button
    void renderRadioButton(QPainter *painter,
                           const QRect &rect,
                           const QColor &background,
                           const QColor &outline,
                           const QColor &tickColor,
                           bool sunken,
                           bool enabled,
                           RadioButtonState state,
                           qreal animation = AnimationData::OpacityInvalid,
                           bool mouseOver = false,
                           bool darkMode = false,
                           bool inMenu = false) const;

    //* slider groove
    void renderSliderGroove(QPainter *painter, const QRect &rect, const QColor &) const;

    //* slider handle
    void renderSliderHandle(QPainter *painter, const QRect &rect, const QColor &, const QColor &outline, const QColor &shadow, bool sunken, bool enabled, Side ticks, qreal angle = 0.0, bool darkMode = false) const;

    //* dial groove
    void renderDialGroove(QPainter *painter, const QRect &rect, const QColor &) const;

    //* dial groove
    void renderDialContents(QPainter *painter, const QRect &rect, const QColor &, qreal first, qreal second) const;

    //* progress bar groove
    void renderProgressBarGroove(QPainter *painter, const QRect &rect, const QColor &, const QColor &) const;

    //* progress bar contents
    void renderProgressBarContents(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline) const
    {
        return renderProgressBarGroove(painter, rect, color, outline);
    }

    //* progress bar contents (animated)
    void renderProgressBarBusyContents(QPainter *painter, const QRect &rect, const QColor &color, const QColor &outline, bool horizontal, bool reverse, int progress) const;

    //* scrollbar groove
    void renderScrollBarGroove(QPainter *painter, const QRect &rect, const QColor &color) const
    {
        return renderScrollBarHandle(painter, rect, color);
    }

    //* scrollbar handle
    void renderScrollBarHandle(QPainter *painter, const QRect &rect, const QColor &) const;

    //* toolbar handle
    void renderToolBarHandle(QPainter *painter, const QRect &rect, const QColor &color) const
    {
        return renderProgressBarGroove(painter, rect, color, Qt::transparent);
    }

    //* tabbar tab
    void renderTabBarTab(QPainter *painter, const QRect &rect, const QColor &background, const QColor &color, const QColor &outline, Corners, bool renderFrame) const;

    //* generic arrow
    void renderArrow(QPainter *painter, const QRect &rect, const QColor &, ArrowOrientation) const;

    //* generic sign (+-)
    void renderSign(QPainter *painter, const QRect &rect, const QColor &color, bool orientation) const;

    //* generic button (for mdi decorations, tabs and dock widgets)
    void renderDecorationButton(QPainter *painter, const QRect &rect, const QColor &, ButtonType, bool inverted) const;

    //@}

    //*@name compositing utilities
    //@{

    //* true if style was compiled for and is running on X11
    static bool isX11(void);

    //* true if running on platform Wayland
    static bool isWayland(void);

    //* returns true if compositing is active
    bool compositingActive(void) const;

    //* returns true if a given widget supports alpha channel
    bool hasAlphaChannel(const QWidget *) const;

    //@}

    //@name high dpi utility functions
    //@{

    //* return dpi-aware pixmap of given size
    virtual QPixmap highDpiPixmap(const QSize &size) const
    {
        return highDpiPixmap(size.width(), size.height());
    }

    //* return dpi-aware pixmap of given size
    virtual QPixmap highDpiPixmap(int width) const
    {
        return highDpiPixmap(width, width);
    }

    //* return dpi-aware pixmap of given size
    virtual QPixmap highDpiPixmap(int width, int height) const;

    //* return device pixel ratio for a given pixmap
    virtual qreal devicePixelRatio(const QPixmap &) const;

    //@}

    //*@name X11 utilities
    //@{

#if GRACEFUL_HAVE_X11

    //* get xcb connection
    static xcb_connection_t *connection(void);

    //* create xcb atom
    xcb_atom_t createAtom(const QString &) const;

#endif

    //@}

    //* frame radius
    qreal frameRadius(qreal bias = 0) const
    {
        return qMax(qreal(Metrics::Frame_FrameRadius) - 0.5 + bias, 0.0);
    }

    void setVariant(QWidget *widget, const QByteArray &variant);

protected:
    //* initialize
    void init(void);

    //* return rectangle for widgets shadow, offset depending on light source
    QRectF shadowRect(const QRectF &) const;

    //* return rounded path in a given rect, with only selected corners rounded, and for a given radius
    QPainterPath roundedPath(const QRectF &, Corners, qreal) const;

private:
#if GRACEFUL_HAVE_X11

    //* atom used for compositing manager
    xcb_atom_t _compositingManagerAtom;

#endif
};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULHELPER_H
