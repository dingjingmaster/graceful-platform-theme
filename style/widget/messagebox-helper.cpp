#include "messagebox-helper.h"

#include <QMessageBox>
#include <QWidget>

MessageboxHelper::MessageboxHelper(QObject *parent) : QObject(parent)
{

}

void MessageboxHelper::registerWidget(QWidget *widget)
{
    QMessageBox*                messageBox = qobject_cast<QMessageBox*>(widget);
    Qt::WindowFlags             messageBoxFlag = messageBox->windowFlags();

    messageBox->setBackgroundRole(QPalette::Base);
    messageBox->setAutoFillBackground(true);

    messageBox->setWindowFlags(messageBoxFlag | Qt::FramelessWindowHint);

#if 0
    float               mMinWidth       = 380;
    float               mMinHeight      = 142;

    float               mMaxWidth       = 420;
    float               mMaxHeight      = 562;

    float               mMarginTop      = 32;
    float               mMarginRight    = 32;
    float               mMarginBottom   = 24;
    float               mMarginLeft     = 32;
#endif

    messageBox->setMinimumSize(QSize(mMinWidth, mMinHeight));
    messageBox->setMaximumSize(QSize(mMaxWidth, mMaxHeight));



}

void MessageboxHelper::unregisterWidget(QWidget *widget)
{

}
