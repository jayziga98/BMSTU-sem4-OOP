#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qaction.h>
#include <QFileDialog>
#include <stdio.h>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    this->pool = pool;

    this->ui->graphicsView->scale(1, -1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите фигуру"), "../../../../lab_02/data", tr("TXT Files (*.txt)"));

    FILE *f = freopen(filename.toLocal8Bit().data(), "r", stdin);
    if (f == NULL)
    {
        warningMessage("Что-то пошло не так", "Не удалось открыть выбранный файл.\nПопробуйте еще раз или выберите другой файл");
        return;
    }
}

void MainWindow::on_pushButton_rotate_clicked()
{
    if (this->item == nullptr)
    {
        warningMessage("Ошибка! Выберите фигуру", "Прежде чем выполнить поворот требуется выбрать фигуру. \n Для этого можно воспользоваться сочетанием клавиш «Ctrl+O» («Cmd+O»)");
        return;
    }

    double ax = -ui->doubleSpinBox_ax->value();
    double ay = -ui->doubleSpinBox_ay->value();
    double az = -ui->doubleSpinBox_az->value();

    this->pool->allocAndSend(ROTATE, this->item, ax, ay, az);
}


void MainWindow::on_pushButton_move_clicked()
{
    if (this->item == nullptr)
    {
        warningMessage("Ошибка! Выберите фигуру", "Прежде чем выполнить перемещение требуется выбрать фигуру. \n Для этого можно воспользоваться сочетанием клавиш «Ctrl+O» («Cmd+O»)");
        return;
    }

    double dx = ui->doubleSpinBox_dx->value();
    double dy = ui->doubleSpinBox_dy->value();
    double dz = ui->doubleSpinBox_dz->value();

    this->pool->allocAndSend(MOVE, this->item, dx, dy, dz);
}

void MainWindow::on_pushButton_scale_clicked()
{
    if (this->item == nullptr)
    {
        warningMessage("Ошибка! Выберите фигуру", "Прежде чем выполнить масштабирование требуется выбрать фигуру. \n Для этого можно воспользоваться сочетанием клавиш «Ctrl+O» («Cmd+O»)");
        return;
    }

    double kx = ui->doubleSpinBox_kx->value();
    double ky = ui->doubleSpinBox_ky->value();
    double kz = ui->doubleSpinBox_kz->value();

    this->pool->allocAndSend(SCALE, this->item, kx, ky, kz);
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
        event->accept();
}
