#include "main-window.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QListWidget>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setEnabled(false);

    menu = new QMenu(ui->pushButton);
    menu->setProperty("fillIconSymbolicColor", true);
    menu->addAction(QIcon::fromTheme("edit-find-symbolic"), "edit-find-symbolic");
    menu->addAction(QIcon::fromTheme("edit-cut-symbolic"), "edit-cut-symbolic");
    menu->addAction(QIcon::fromTheme("user-trash"), "user-trash");
    menu->addAction(QIcon::fromTheme("open-menu-symbolic"), "open-menu-symbolic");
    menu->addAction(QIcon::fromTheme("pane-hide-symbolic"), "pane-hide-symbolic");
    ui->pushButton->setMenu(menu);

    view = new QListWidget(this);
    view->resize(300, 200);
    view->move(100, 200);

    auto item = new QListWidgetItem(QIcon::fromTheme("window-close"), "window-close", view);
    item = new QListWidgetItem(QIcon::fromTheme("window-close-symbolic"), "window-close-symoblic", view);
    item = new QListWidgetItem(QIcon::fromTheme("user-trash"), "user-trash", view);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onCheckBoxToggled(bool checked)
{
    ui->pushButton->setProperty("useIconHighlightEffect", checked);
    ui->pushButton->update();
    ui->toolButton->setProperty("useIconHighlightEffect", checked);
    ui->toolButton->update();
    view->setProperty("useIconHighlightEffect", checked);
    view->viewport()->update();
    menu->setProperty("useIconHighlightEffect", checked);
    ui->comboBox->setEnabled(checked);

    int mode = ui->comboBox->currentIndex();
    ui->pushButton->setProperty("iconHighlightEffectMode", mode);
    ui->pushButton->update();
    ui->toolButton->setProperty("iconHighlightEffectMode", mode);
    ui->toolButton->update();
    view->setProperty("iconHighlightEffectMode", mode);
    view->viewport()->update();
    menu->setProperty("iconHighlightEffectMode", mode);
}

void MainWindow::onComboBoxCurrentIndexChanged(int index)
{
    int mode = index;
    ui->pushButton->setProperty("iconHighlightEffectMode", mode);
    ui->pushButton->update();
    ui->toolButton->setProperty("iconHighlightEffectMode", mode);
    ui->toolButton->update();
    view->setProperty("iconHighlightEffectMode", mode);
    view->viewport()->update();
}
