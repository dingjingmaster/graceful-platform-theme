#include "graceful-mnemonics.h"
#include "graceful.h"

#include <QWidget>
#include <QKeyEvent>

namespace Graceful {

Mnemonics::Mnemonics(QObject *parent) : QObject(parent), _enabled(true)
{

}

Mnemonics::~Mnemonics()
{


}

void Mnemonics::setMode(int mode)
{

    switch (mode) {
    case Graceful::MN_NEVER:
        qApp->removeEventFilter(this);
        setEnabled(false);
        break;
    case Graceful::MN_ALWAYS:
        qApp->removeEventFilter(this);
        setEnabled(true);
        break;
    case Graceful::MN_AUTO:
        qApp->removeEventFilter(this);
        qApp->installEventFilter(this);
        setEnabled(false);
        break;
    default:
        break;
    }

    return;
}

bool Mnemonics::eventFilter(QObject *, QEvent *event)
{

    switch (event->type()) {
    case QEvent::KeyPress:
        if (static_cast<QKeyEvent *>(event)->key() == Qt::Key_Alt) {
            setEnabled(true);
        }
        break;
    case QEvent::KeyRelease:
        if (static_cast<QKeyEvent *>(event)->key() == Qt::Key_Alt) {
            setEnabled(false);
        }
        break;
    case QEvent::ApplicationStateChange:
        setEnabled(false);
        break;
    default:
        break;
    }

    return false;
}

void Mnemonics::setEnabled(bool value)
{

    if (_enabled == value) {
        return;
    }

    _enabled = value;

    // update all top level widgets
    for (auto widget = qApp->topLevelWidgets().constBegin(); widget != qApp->topLevelWidgets().constEnd(); ++widget) {
        (*widget)->update();
    }
}

} // namespace Graceful
