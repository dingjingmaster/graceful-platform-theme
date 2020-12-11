#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMenu;
class QListWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void onCheckBoxToggled(bool checked);
    void onComboBoxCurrentIndexChanged(int index);

private:
    Ui::MainWindow*         ui;
    QListWidget*            view;
    QMenu*                  menu;

};

#endif // MAINWINDOW_H
