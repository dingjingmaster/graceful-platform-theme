#include <QApplication>

#include <QDebug>
#include <QStyleFactory>
#include "widgetfactory.h"

int main(int argc, char *argv[])
{
    QApplication            app(argc, argv);

    QApplication::setStyle(QStyleFactory::create("graceful"));

    WidgetFactory fact;
    fact.show();
    return app.exec();
}
