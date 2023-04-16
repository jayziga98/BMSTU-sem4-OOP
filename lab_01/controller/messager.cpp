#include "messager.h"

void message_task()
{
    QMessageBox msgBox;
    msgBox.setText("Объектно-ориентированное программирование\nЛабоаторная работа №1");
    msgBox.setInformativeText("3D-viewer");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void message_about()
{
    QMessageBox msgBox;
    msgBox.setText("Дорогой пользователь!");
    msgBox.setInformativeText("Предлагаю ознакомиться со справкой о программе\n"
                              "Программа позволяет просматривать фигуру и выполнять операции масштабирования, поворота, перемещения над ним\n"
                              "Прежде чем выполнять операции требуется выбрать фигуру, чтобы это сделать воспользуйся верхним меню или сочетанием клавиш «Ctrl+O» («Cmd+O»).\n"
                              "После ты можешь выполнять перемещение, масштабирование и поворот исходного рисунка.\n"
                              "Приятного использования!");

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void message_author()
{
    QMessageBox msgBox;
    msgBox.setText("Козлитин Максим ИУ7-44Б");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void message_warning(QString title, QString text)
{
    QMessageBox msgBox = QMessageBox();
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.addButton(QString("Закрыть"), QMessageBox::AcceptRole);

    msgBox.exec();
}

void message_info(QString title, QString text)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.addButton(QString("Закрыть"), QMessageBox::AcceptRole);

    msgBox.exec();
}

int message_ask(QString title, QString text)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.addButton(QString("Нет"), QMessageBox::RejectRole);
    msgBox.addButton(QString("Да"), QMessageBox::AcceptRole);

    return msgBox.exec();
}
