#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <QMainWindow>

class WidgetFactory : public QMainWindow
{
    Q_OBJECT
public:
    WidgetFactory(QWidget *parent = nullptr);
    ~WidgetFactory();

private:
    class Private;
    Private *d;
};

#endif // WIDGETFACTORY_H
