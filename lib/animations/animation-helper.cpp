#include "animation-helper.h"

#include <QWidget>
#include "animator-iface.h"

AnimationHelper::AnimationHelper(QObject *parent) : QObject(parent)
{
    mAnimators = new QHash<const QWidget*, AnimatorIface*>();
}

AnimationHelper::~AnimationHelper()
{
    if (NULL != mAnimators) {
        delete mAnimators;
    }
}
