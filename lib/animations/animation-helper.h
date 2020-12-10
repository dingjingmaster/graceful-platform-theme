#ifndef ANIMATIONHELPER_H
#define ANIMATIONHELPER_H
#include <QObject>

class QWidget;
class AnimatorIface;

class AnimationHelper : public QObject
{
    Q_OBJECT
public:
    explicit AnimationHelper(QObject* parent = nullptr);
    virtual ~AnimationHelper();

public slots:
    virtual bool registerWidget(QWidget*)   {return false;}
    virtual bool unregisterWidget(QWidget*) {return false;}

protected:
    QHash<const QWidget*, AnimatorIface*>*      mAnimators = nullptr;

};

#endif // ANIMATIONHELPER_H
