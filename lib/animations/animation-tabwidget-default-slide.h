#ifndef ANIMATIONTABWIDGETDEFAULTSLIDE_H
#define ANIMATIONTABWIDGETDEFAULTSLIDE_H
#include <QObject>
#include <QPixmap>
#include <QStackedWidget>
#include <QVariantAnimation>

#include "animation-tabwidget-iface.h"

namespace TabWidget {
class AnimationTabwidgetDefaultSlide : public QVariantAnimation, public AnimationTabwidgetIface
{
    Q_OBJECT
public:
    explicit AnimationTabwidgetDefaultSlide (QObject *parent = nullptr);

    bool unboundTabWidget ();
    QWidget* boundedWidget ();
    bool bindTabWidget (QTabWidget* w);

    bool eventFilter(QObject* obj, QEvent* e);

protected:
    void watchSubPage(QWidget* w);
    bool filterSubPage(QObject* obj, QEvent* e);
    bool filterTmpPage(QObject* obj, QEvent* e);
    bool filterTabWidget(QObject* obj, QEvent* e);
    bool filterStackedWidget(QObject* obj, QEvent* e);

    void clearPixmap();

private:
    QList<QWidget*>         mChildren;
    QStackedWidget*         mStack = nullptr;
    QTabWidget*             mBoundWidget = nullptr;

    QPixmap                 mNextPixmap;
    QPixmap                 mPreviousPixmap;

    QWidget*                mTmpPage = nullptr;

    int                     mPervIndex = -1;
    bool                    mLeftRight = true;
    bool                    mTabResizing = false;
    QWidget*                mPreviousWidget = nullptr;
};
}

#endif // ANIMATIONTABWIDGETDEFAULTSLIDE_H
