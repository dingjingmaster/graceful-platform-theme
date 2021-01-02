#include "messagebox-helper.h"

#include <QMessageBox>
#include <QWidget>
#include "csyslog.h"

MessageboxHelper::MessageboxHelper(QObject *parent) : QObject(parent)
{

}

void MessageboxHelper::registerWidget(QWidget *widget)
{
    QMessageBox*                messageBox = qobject_cast<QMessageBox*>(widget);
    Qt::WindowFlags             messageBoxFlag = messageBox->windowFlags();

    messageBox->setBackgroundRole(QPalette::Base);
    messageBox->setAutoFillBackground(true);

//    messageBox->setWindowFlags(messageBoxFlag | Qt::FramelessWindowHint);

    messageBox->setMinimumSize(QSize(mMinWidth, mMinHeight));
    messageBox->setMaximumSize(QSize(mMaxWidth, mMaxHeight));

    messageBox->removeEventFilter(this);
    messageBox->installEventFilter(this);


}

void MessageboxHelper::unregisterWidget(QWidget *widget)
{

}

bool MessageboxHelper::eventFilter(QObject *watched, QEvent *event)
{
//    CT_SYSLOG (LOG_ERR, "");

    return false;
}
