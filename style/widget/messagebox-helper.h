#ifndef MESSAGEBOXHELPER_H
#define MESSAGEBOXHELPER_H

#include <QObject>

class MessageboxHelper : public QObject
{
    Q_OBJECT
public:
    explicit MessageboxHelper(QObject *parent = nullptr);

    void registerWidget (QWidget* widget);
    void unregisterWidget (QWidget* widget);

    virtual bool eventFilter(QObject *watched, QEvent *event) override;

Q_SIGNALS:

public:

private:
    float               mMinWidth       = 380;
    float               mMinHeight      = 142;

    float               mMaxWidth       = 420;
    float               mMaxHeight      = 562;

    float               mMarginTop      = 32;
    float               mMarginRight    = 32;
    float               mMarginBottom   = 24;
    float               mMarginLeft     = 32;

    float               mPixSize        = 24;

    // qmessage 里包含的控件

};

#endif // MESSAGEBOXHELPER_H
