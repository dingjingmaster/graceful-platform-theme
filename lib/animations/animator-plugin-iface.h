#ifndef ANIMATORPLUGINIFACE_H
#define ANIMATORPLUGINIFACE_H
#include <QString>

class AnimatorPluginIface
{
public:
    enum AnimatorPluginType
    {
        TabWidget,
        StackedWidget,
        PushButton,
        ItemView,
        ScrollBar,
        MenuBar,
        Menu,
        Other
    };

    virtual ~AnimatorPluginIface ();

    virtual bool isParallel () = 0;
    virtual const QString id () = 0;
    virtual const QString brief () = 0;
    virtual const QString inhertKey () = 0;
    virtual const QStringList excludeKeys () = 0;
    virtual AnimatorPluginType pluginType () = 0;
};

#endif // ANIMATORPLUGINIFACE_H
