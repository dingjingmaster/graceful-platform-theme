#include "animation-tabwidget-default-slide.h"

#include <QEvent>
#include <QDebug>
#include <QTimer>
#include <QScreen>
#include <QTabBar>
#include <QPainter>
#include <QTabWidget>
#include <QChildEvent>
#include <QStackedWidget>
#include <QGuiApplication>


TabWidget::AnimationTabwidgetDefaultSlide::AnimationTabwidgetDefaultSlide(QObject *parent) : QVariantAnimation (parent)
{
    setDuration(200);
    setEasingCurve(QEasingCurve::OutQuad);
    setStartValue(0.0);
    setEndValue(1.0);
}

bool TabWidget::AnimationTabwidgetDefaultSlide::bindTabWidget(QTabWidget* w)
{
    if (w) {
        mBoundWidget = w;

        w->installEventFilter(this);

        mTmpPage = new QWidget;
        mTmpPage->installEventFilter(this);

        for (auto child : w->children()) {
            if (child->objectName() == "qt_tabwidget_stackedwidget") {
                auto stack = qobject_cast<QStackedWidget*> (child);
                mStack = stack;
                mTmpPage->setParent(mStack);
                mStack->installEventFilter(this);
                break;
            }
        }

        for (int i = 0; i < w->count(); i++) {
            watchSubPage(w->widget(i));
        }

        mPreviousWidget = mBoundWidget->currentWidget();

        connect(w, &QTabWidget::currentChanged, this, [=] (int) {
            this->stop();
            mTmpPage->hide();
            if (mBoundWidget->currentWidget() && mBoundWidget->currentWidget() != mPreviousWidget) {
                mLeftRight = mBoundWidget->currentIndex() > mPervIndex;
                mPervIndex = mBoundWidget->currentIndex();

                QPixmap pixmap(mBoundWidget->currentWidget()->size());
                mBoundWidget->render(&pixmap, QPoint(), QRect(mBoundWidget->currentWidget()->rect().left() + 2,
                                     mBoundWidget->currentWidget()->rect().top() + mBoundWidget->tabBar()->height(),
                                     mBoundWidget->currentWidget()->width(), mBoundWidget->currentWidget()->height()));
                mNextPixmap = pixmap;

                if (qobject_cast<QWidget *>(mPreviousWidget)) {
                    QPixmap previous_pixmap(mPreviousWidget->size());
                    QPalette palette, palette_save;
                    palette = palette_save = mPreviousWidget->palette();
                    palette.setBrush(QPalette::Window, palette.brush(QPalette::Base));
                    mPreviousWidget->setPalette(palette);
                    mPreviousWidget->render(&previous_pixmap);
                    mPreviousWidget->setPalette(palette_save);
                    mPreviousPixmap = previous_pixmap;
                    this->start();
                    mTmpPage->raise();
                    mTmpPage->show();
                }
            }
            mPreviousWidget = mBoundWidget->currentWidget();
        });

        connect(this, &QVariantAnimation::valueChanged, mTmpPage, [=]() {
            mTmpPage->repaint();
        });
        connect(this, &QVariantAnimation::finished, mTmpPage, [=]() {
            mTmpPage->repaint();
        });

        return true;
    }
    return false;
}

bool TabWidget::AnimationTabwidgetDefaultSlide::unboundTabWidget()
{
    clearPixmap();
    if (mBoundWidget) {
        disconnect(mBoundWidget, &QTabWidget::currentChanged, this, nullptr);
        for (auto w : mBoundWidget->children()) {
            w->removeEventFilter(this);
        }

        mTmpPage->removeEventFilter(this);
        mTmpPage->deleteLater();
        mTmpPage = nullptr;
        mPreviousWidget = nullptr;
        mBoundWidget = nullptr;
        this->deleteLater();
        return true;
    }
    return false;
}

QWidget *TabWidget::AnimationTabwidgetDefaultSlide::boundedWidget()
{
     return mBoundWidget;
}

bool TabWidget::AnimationTabwidgetDefaultSlide::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == mTmpPage) {
        return filterTmpPage(obj, e);
    }

    if (obj == mStack) {
        return filterStackedWidget(obj, e);
    }

    if (obj == mBoundWidget) {
        return filterTabWidget(obj, e);
    }

    return filterSubPage(obj, e);
}

void TabWidget::AnimationTabwidgetDefaultSlide::watchSubPage(QWidget *w)
{
    w->installEventFilter(this);
}

bool TabWidget::AnimationTabwidgetDefaultSlide::filterSubPage(QObject *obj, QEvent *e)
{
    switch (e->type()) {
    case QEvent::Show: {
        return false;
    }
    case QEvent::Hide: {
        this->stop();
        return false;
    }
    case QEvent::Resize: {
        this->stop();
        return false;
    }
    }

    Q_UNUSED(obj);

    return false;
}

bool TabWidget::AnimationTabwidgetDefaultSlide::filterTmpPage(QObject *obj, QEvent *e)
{
    switch (e->type()) {
    case QEvent::Show: {
        return false;
    }
    case QEvent::Paint: {
        QWidget *w = qobject_cast<QWidget *>(obj);
        if (this->state() == QAbstractAnimation::Running) {
            QPainter p(w);
            auto value = this->currentValue().toDouble();
            p.setRenderHints(QPainter::Antialiasing);

            auto prevSrcRect = QRectF(mPreviousPixmap.rect());
            auto prevTargetRect = QRectF(mPreviousPixmap.rect());
            auto nextSrcRect = QRectF(mNextPixmap.rect());
            auto nextTargetRect = QRectF(mNextPixmap.rect());
            if (mLeftRight) {
                prevSrcRect.setX(mPreviousPixmap.width() * value);
                prevSrcRect.setWidth(mPreviousPixmap.width() * (1 - value));
                prevTargetRect.setWidth(mPreviousPixmap.width() * (1 - value));
                p.drawPixmap(prevTargetRect, mPreviousPixmap, prevSrcRect);

                nextSrcRect.setWidth(mNextPixmap.width() * value);
                nextTargetRect.setX(mNextPixmap.width() * (1 - value));
                nextTargetRect.setWidth(mNextPixmap.width() * value);
                p.drawPixmap(nextTargetRect, mNextPixmap, nextSrcRect);
            } else {
                nextSrcRect.setX(mNextPixmap.width() * (1 - value));
                nextSrcRect.setWidth(mNextPixmap.width() * value);
                nextTargetRect.setWidth(mNextPixmap.width() * value);
                p.drawPixmap(nextTargetRect, mNextPixmap, nextSrcRect);

                prevSrcRect.setWidth(mPreviousPixmap.width() * (1 - value));
                prevTargetRect.setX(mPreviousPixmap.width() * value);
                prevTargetRect.setWidth(mPreviousPixmap.width() * (1 - value));
                p.drawPixmap(prevTargetRect, mPreviousPixmap, prevSrcRect);
            }

            return true;
        }
        mTmpPage->hide();
        if (!mNextPixmap.isNull()) {
            mStack->stackUnder(mTmpPage);
        }

        return false;
    }
    default:
        return false;
    }
}

bool TabWidget::AnimationTabwidgetDefaultSlide::filterTabWidget(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::Close) {
        this->unboundTabWidget();
    }

    Q_UNUSED(obj);

    return false;
}

bool TabWidget::AnimationTabwidgetDefaultSlide::filterStackedWidget(QObject *obj, QEvent *e)
{
    switch (e->type()) {
    case QEvent::ChildAdded:
    case QEvent::ChildRemoved: {
        qDebug()<<"added/removed"<<obj;
        if (obj->objectName() == "qt_tabwidget_stackedwidget") {
            QChildEvent *ce = static_cast<QChildEvent *>(e);
            if (!ce->child()->isWidgetType()) {
                return false;
            }

            if (ce->added()) {
                ce->child()->installEventFilter(this);
            } else {
                ce->child()->removeEventFilter(this);
            }
        }

        return false;
    }
    case QEvent::Resize:
        mTabResizing = true;
        return false;
    case QEvent::LayoutRequest: {
        if (mTabResizing) {
            mTmpPage->resize(mStack->size());
            if(mNextPixmap.isNull()) {
                mPervIndex = mBoundWidget->currentIndex();
            }
        }
        mTabResizing = false;

        return false;
    }
    default:
        break;
    }

    return false;
}

void TabWidget::AnimationTabwidgetDefaultSlide::clearPixmap()
{
    mNextPixmap = QPixmap();
    mPreviousPixmap = QPixmap();
}
