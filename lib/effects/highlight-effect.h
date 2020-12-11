#ifndef HIGHLIGHTEFFECT_H
#define HIGHLIGHTEFFECT_H

#include <QObject>
#include <QStyleOption>

class QMenu;
class QAbstractButton;
class QAbstractItemView;

class HighlightEffect : public QObject
{
    Q_OBJECT
public:
    enum HighLightMode
    {
        skipHighlight = 0x0,
        HighLightEffect = 0x1,
        ordinaryHighLight = 0x2,
        hoverHighLight = 0x4,
        defaultHighLight = 0x8,
        filledSymbolicColorHighLight = 0x10,
    };

    enum EffectMode
    {
        HighlightOnly,
        BothDefaultAndHighlit
    };

    Q_ENUM(EffectMode)

    static bool isPixmapPureColor(const QPixmap &pixmap);
    static void setSkipEffect(QWidget *w, bool skip = true);
    static HighLightMode isWidgetIconUseHighlightEffect(const QWidget *w);
    static bool setMenuIconHighlightEffect(QMenu *menu, HighLightMode hlmode = skipHighlight, EffectMode mode = HighlightOnly);
    static bool setButtonIconHighlightEffect(QAbstractButton *button, HighLightMode hlmode = skipHighlight, EffectMode mode = HighlightOnly);
    static bool setViewItemIconHighlightEffect(QAbstractItemView *view, HighLightMode hlmode = skipHighlight, EffectMode mode = HighlightOnly);

    static void setSymoblicColor(const QColor &color);
    static void setWidgetIconFillSymbolicColor(QWidget *widget, bool fill);

    static const QColor defaultStyleDark();
    static const QColor getCurrentSymbolicColor();

    static QPixmap hoverGeneratePixmap(const QPixmap &pixmap, const QStyleOption *option, const QWidget *widget = nullptr);
    static QPixmap ordinaryGeneratePixmap(const QPixmap &pixmap, const QStyleOption *option, const QWidget *widget = nullptr, EffectMode mode = HighlightOnly);
    static QPixmap generatePixmap(const QPixmap &pixmap, const QStyleOption *option, const QWidget *widget = nullptr, bool force = false, EffectMode mode = HighlightOnly);
    static QPixmap bothOrdinaryAndHoverGeneratePixmap(const QPixmap &pixmap, const QStyleOption *option, const QWidget *widget = nullptr, EffectMode mode = HighlightOnly);
    static QPixmap filledSymbolicColoredGeneratePixmap(const QPixmap &pixmap, const QStyleOption *option, const QWidget *widget = nullptr, EffectMode mode = HighlightOnly);

private:
    explicit HighlightEffect(QObject *parent = nullptr);
    static QPixmap filledSymbolicColoredPixmap(const QPixmap &source, const QColor &baseColor);
};

#endif // HIGHLIGHTEFFECT_H
