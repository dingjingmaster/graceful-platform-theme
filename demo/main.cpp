#include <QApplication>
#include <QMessageBox>

#include "widgetfactory.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qputenv("QT_STYLE_OVERRIDE", 0);
//    WidgetFactory fact;
//    fact.show();

#if 1
    //
    QMessageBox w(QMessageBox::NoIcon, "title", "text sssssddddddddddddddddddddfsdf ddddsdfs sfsdfssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
                   QMessageBox::Ok | QMessageBox::No);
#endif

#if 0
    QMessageBox w(QMessageBox::NoIcon, "title", "text ssssss", QMessageBox::Ok | QMessageBox::RestoreDefaults | QMessageBox::Save
                  | QMessageBox::SaveAll | QMessageBox::Open | QMessageBox::Yes | QMessageBox::YesToAll | QMessageBox::No
                  | QMessageBox::NoToAll | QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore | QMessageBox::Close
                  | QMessageBox::Cancel | QMessageBox::Discard | QMessageBox::Help | QMessageBox::Apply | QMessageBox::Reset);
#endif

    w.show();
    return app.exec();
}
