#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "controller/action_handler.h"
#include "controller/messager.h"
#include <qaction.h>
#include <QFileDialog>
#include <stdio.h>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    item = figure_item_create();

    this->ui->graphicsView->scale(1, -1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите фигуру"), "../../../../lab_01/data", tr("TXT Files (*.txt)"));

    action_handler_t handler;
    action_handler_init(handler, OPEN, filename.toLocal8Bit().data());
    error_t rc = action_handler_handle(handler);
    if (rc)
        error_message(rc);
}

void MainWindow::on_pushButton_rotate_clicked()
{
    double ax = ui->doubleSpinBox_ax->value();
    double ay = ui->doubleSpinBox_ay->value();
    double az = ui->doubleSpinBox_az->value();
    point_t params = point_init(ax, ay, az);

    action_handler_t handler;
    action_handler_init(handler, ROTATE, params);
    error_t rc = action_handler_handle(handler);
    if (rc)
        error_message(rc);
}


void MainWindow::on_pushButton_move_clicked()
{
    double dx = ui->doubleSpinBox_dx->value();
    double dy = ui->doubleSpinBox_dy->value();
    double dz = ui->doubleSpinBox_dz->value();
    point_t params = point_init(dx, dy, dz);

    action_handler_t handler;
    action_handler_init(handler, MOVE, params);
    error_t rc = action_handler_handle(handler);
    if (rc)
        error_message(rc);
}

void MainWindow::on_pushButton_scale_clicked()
{
    double kx = ui->doubleSpinBox_kx->value();
    double ky = ui->doubleSpinBox_ky->value();
    double kz = ui->doubleSpinBox_kz->value();
    point_t params = point_init(kx, ky, kz);

    action_handler_t handler;
    action_handler_init(handler, SCALE, params);
    error_t rc = action_handler_handle(handler);
    if (rc)
        error_message(rc);
}

void MainWindow::on_actionAboutTask_triggered()
{
    message_task();
}

void MainWindow::on_actionAboutProgram_triggered()
{
    message_about();
}

void MainWindow::on_actionAboutAuthor_triggered()
{
    message_author();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    event->ignore();
    if (message_ask("Завершение работы", "Вы уверены что хотите выйти?"))
        event->ignore();
    else
    {
        action_handler_t handler;
        action_handler_init_quit(handler);
        event->accept();
    }
}

void MainWindow::on_action_save_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите фигуру"), "../../../../lab_01/data", tr("TXT Files (*.txt)"));

    action_handler_t handler;
    action_handler_init(handler, SAVE, filename.toLocal8Bit().data());
    error_t rc = action_handler_handle(handler);
    if (rc)
        error_message(rc);
}

