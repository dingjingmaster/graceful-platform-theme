#ifndef ANIMATIONTABWIDGETIFACE_H
#define ANIMATIONTABWIDGETIFACE_H
#include "animator-iface.h"

#include <QTabWidget>

class AnimationTabwidgetIface : public AnimatorIface
{
public:
    AnimationTabwidgetIface();
    virtual ~AnimationTabwidgetIface();

    virtual bool unboundWidget ();
    virtual bool bindWidget (QWidget* w);
    virtual bool unboundTabWidget () = 0;
    virtual bool bindTabWidget (QTabWidget *w) = 0;
};

#endif // ANIMATIONTABWIDGETIFACE_H
