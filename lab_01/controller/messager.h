#ifndef MESSAGER_H
#define MESSAGER_H

#include <QMessageBox>

void message_task();
void message_about();
void message_author();

void message_warning(QString title, QString text);
void message_info(QString title, QString text);
int message_ask(QString title, QString text);

#endif // MESSAGER_H
