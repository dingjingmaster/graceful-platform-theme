#ifndef GRACEFULCOLORS_H
#define GRACEFULCOLORS_H
#include "graceful.h"
#include "graceful-export.h"

#include <QColor>

namespace Graceful {
class GRACEFUL_EXPORT Colors
{
public:
    // Color adjustments
    static QColor alphaColor(QColor color, qreal alpha);
    static QColor darken(const QColor &color, qreal amount = 0.1);
    static QColor lighten(const QColor &color, qreal amount = 0.1);
    static QColor desaturate(const QColor &color, qreal amount = 0.1);
    static QColor transparentize(const QColor &color, qreal amount = 0.1);
    static QColor mix(const QColor &c1, const QColor &c2, qreal bias = 0.5);

    static QPalette disabledPalette(const QPalette &source, qreal ratio);

    static QPalette palette(ColorVariant variant = ColorVariant::Unknown);

    // Generic colors

    /* Relevant options:
       * palette
     */
    static QColor hoverColor(const StyleOptions &options);
    /* Relevant options:
       * palette
     */
    static QColor focusColor(const StyleOptions &options);
    /* Relevant options:
       * palette
     */
    static QColor negativeText(const StyleOptions &options);
    /* Relevant options:
       * palette
     */
    static QColor shadowColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * active
     */
    static QColor titleBarColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * active
     */
    static QColor titleBarTextColor(const StyleOptions &options);

    // Outline colors

    /* Relevant options:
       * palette
       * color role
       * color group
     */
    static QColor arrowOutlineColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * opacity
       * animation mode
       * color variant
     */
    static QColor buttonOutlineColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * opacity
       * animation mode
       * checkbox state
       * color variant
       * in menu
     */
    static QColor indicatorOutlineColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * opacity
       * animation mode
       * color variant
     */
    static QColor frameOutlineColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * opacity
       * animation mode
       * color variant
     */
    static QColor inputOutlineColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * has focus
       * opacity
       * animation mode
     */
    static QColor sidePanelOutlineColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * opacity
       * animation mode
     */
    static QColor sliderOutlineColor(const StyleOptions &options);

    // Background colors

    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * sunken
       * opacity
       * animation mode
       * color variant
     */
    static QColor buttonBackgroundColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * active
       * opacity
       * animation mode
       * color variant
     */
    static QColor checkBoxIndicatorColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * state
     */
    static QColor headerTextColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * sunken
       * opacity
       * animation mode
       * checkbox state
       * color variant
       * in menu
     */
    static QColor indicatorBackgroundColor(const StyleOptions &options);
    /* Relevant options:
       * palette
     */
    static QColor frameBackgroundColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * sunken
       * opacity
       * animation mode
       * color variant
     */
    static QColor scrollBarHandleColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * color variant
     */
    static QColor separatorColor(const StyleOptions &options);
    /* Relevant options:
       * palette
       * mouse over
       * has focus
       * sunken
       * opacity
       * animation mode
     */
    static QColor toolButtonColor(const StyleOptions &options);
    /* Relevant options:
       * palette
     */
    static QColor tabBarColor(const StyleOptions &options);
};
}



#endif // GRACEFULCOLORS_H
