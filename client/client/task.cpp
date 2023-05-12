#include "task.h"
#include "ui_task.h"
#include "socket.h"
#include <QErrorMessage>
#include <QMessageBox>

Task::Task(QWidget *parent) : // Вызов окна с заданием
    QDialog(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    Socket::GetInstance()->sk.write("ctrl:names"); // Возможность вывода задания через поля ввода текста
    Socket::GetInstance()->sk.waitForReadyRead(3000);
    QString buf = Socket::GetInstance()->sk.readAll();
    QStringList categories = buf.split("&");
    ui->comboBoxCategories->addItems(categories);
}

Task::~Task() // Диструктор, активирующийся при закрытии окна задания
{
    delete ui;
}

QString GetTaskTemplate(QString name) // Выбор шаблона задания из базы данных
{
    QString cmd = "ctrl:task_template&" + name;
    Socket::GetInstance()->sk.write(cmd.toUtf8());
    Socket::GetInstance()->sk.waitForReadyRead(3000);
    QString buf = Socket::GetInstance()->sk.readAll();

    return buf;
}

void Task::on_pushButtonGetTask_clicked() // Выводит выбранный вариант задания при нажатии кнопки "Получить задание"
{
    QString name = ui->comboBoxCategories->currentText();

    ui->labelTask->setText(GetTaskTemplate(name));

    QString cmd = "ctrl:task&" + name;
    Socket::GetInstance()->sk.write(cmd.toUtf8());
    Socket::GetInstance()->sk.waitForReadyRead(3000);
    QString buf = Socket::GetInstance()->sk.readAll();
    ui->label_Variant->setText(buf);
}

void Task::on_buttonBox_accepted() // Принимает данные из поля ввода текста
{
    QString cmd = "ctrl:answer&" + ui->lineEditAnswer->text();
    Socket::GetInstance()->sk.write(cmd.toUtf8());
    Socket::GetInstance()->sk.waitForReadyRead(3000);
    QString buf = Socket::GetInstance()->sk.readAll(); // Сравнение с правильным ответом

    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok);

    if (buf == "true")
    {
        msgBox.setInformativeText("Ответ правильный");
    }
    else
    {
        msgBox.setInformativeText("Ответ неправильный");
    }

    msgBox.exec();
}

