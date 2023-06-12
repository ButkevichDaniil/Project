#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "socket.h"

Registration::Registration(QWidget *parent) : // Вызов окна регистрации
    QDialog(parent),
    ui(new Ui::Registration)
{

    ui->setupUi(this);
    ui->reg_pas->setEchoMode(QLineEdit::Password);
    ui->reg_pas_repeat->setEchoMode(QLineEdit::Password);
}

Registration::~Registration() // Диструктор, срабатывающий при закрытии UI регистрации
{
    delete ui;
}

void Registration::on_pushButton_clicked() // Проверка соответствия полей login password1 password2 при нажатии кнопки "Подтвердить"
{
    QString reg_login = ui -> mail ->text();
    QString reg_pas_1 = ui -> reg_pas ->text();
    QString reg_pas_2 = ui -> reg_pas_repeat ->text();
    if (reg_pas_1 == reg_pas_2) { // Сравнение полей password1 и password2
        qDebug("Пароли совпадают! Ожидание отправки");

        QString ctrl_msg = "ctrl:reg&" + reg_login + "&" + reg_pas_1; // Возможность регистрации через поле ввода текста
        Socket::GetInstance()->sk.write(ctrl_msg.toUtf8());
        Socket::GetInstance()->sk.waitForReadyRead();
        QString buf = Socket::GetInstance()->sk.readAll();
// Добавление аккаунта при успешной регистрации
        if (buf == "true") {
            QMessageBox::information(this, "Успешная регистрация", "вы успешно зарегистрировались!");
            hide();
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Фатальная ошибка"); // Ошибка регистрации
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают"); // Выводится при ошибке в воде логина/пароля
    }
}

