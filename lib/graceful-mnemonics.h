#ifndef GRACEFUL_GRACEFULMNEMONICS_H
#define GRACEFUL_GRACEFULMNEMONICS_H
#include "graceful-export.h"

#include <QEvent>
#include <QObject>
#include <QApplication>

namespace Graceful {

class GRACEFUL_EXPORT Mnemonics : public QObject
{
    Q_OBJECT
public:
    explicit Mnemonics(QObject *parent);
    virtual ~Mnemonics();

    //* set mode
    void setMode(int);

    //* event filter
    virtual bool eventFilter(QObject *, QEvent *);

    //* true if mnemonics are enabled
    const bool &enabled() const
    {

        return _enabled;
    }

    //* alignment flag
    int textFlags() const
    {

        return _enabled ? Qt::TextShowMnemonic : Qt::TextHideMnemonic;
    }

protected:
    //* set enable state
    void setEnabled(bool);

private:
    //* enable state
    bool _enabled;

};

} // namespace Graceful

#endif // GRACEFUL_GRACEFULMNEMONICS_H
