#include <QApplication>

#include "widgetfactory.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qputenv("QT_STYLE_OVERRIDE", 0);
    WidgetFactory fact;
    fact.show();
    return app.exec();
}
