#include "messager.h"

void message_task()
{
    QMessageBox msgBox;
    msgBox.setText("Компьютетная графика\nЛабоаторная работа №2");
    msgBox.setInformativeText("Вариант №12\n"
                              "Нарисовать исходный рисунок, затем его переместить, промасштабировать, повернуть.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void message_about()
{
    QMessageBox msgBox;
    msgBox.setText("Дорогой пользователь!");
    msgBox.setInformativeText("Предлагаю ознакомиться со справкой о программе\n"
                              "Программа позволяет просматривать рисунок и выполнять операции масштабирования, поворота, перемещения над ним\n"
                              "Прежде чем выполнять операции требуется выбрать рисунок, чтобы это сделать воспользуйся верхним меню или сочетанием клавиш «Ctrl+O» («Cmd+O»).\n"
                              "После ты можешь выполнять перемещение, масштабирование и поворот исходного рисунка. Дополнительно ты можешь задать опорную точку масштабирования и поворота.\n"
                              "Программа позволяет отменять выполненные действия сочетанием клавиш «Ctrl+Z» («Cmd+Z»)  или с помощью меню «Правка» -> «Отменить»\n"
                              "Отмененные действия можно повторить сочетанием клавиш «Ctrl+Shift+Z» («Cmd+Shift+Z»)  или с помощью меню «Правка» -> «Повторить»\n"
                              "Данную информацию можно повторно просмотреть в меню «Справка» -> «О программе» или просмотреть подсказки при наведении на действия в левом боковом меню\n"
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
