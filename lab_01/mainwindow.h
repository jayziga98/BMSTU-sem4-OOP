#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controller/drawer.h"
#include "controller/action_handler.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    drawer_t drawer;
    figure_item_t *item;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_pushButton_rotate_clicked();

    void on_pushButton_move_clicked();

    void on_pushButton_scale_clicked();

    void on_actionAboutTask_triggered();

    void on_actionAboutProgram_triggered();

    void on_actionAboutAuthor_triggered();

    void closeEvent(QCloseEvent* event);

    void on_action_save_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

void action_handler_init(action_handler_t &handler, actionType type, const char *filename);
void action_handler_init(action_handler_t &handler, actionType type, point_t &params);
void action_handler_init(action_handler_t &handler, actionType type, drawer_t &drawer);
void action_handler_init_quit(action_handler_t &handler);
