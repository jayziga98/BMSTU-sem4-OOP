#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure_item.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    figure_item_t *item = nullptr;

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
