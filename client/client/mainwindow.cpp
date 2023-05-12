#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extrafunction.h"
#include "task.h"
#include "socket.h"

MainWindow::MainWindow(QWidget *parent) // Создание основного оконного интерфейса
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&Socket::GetInstance()->sk, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead); // Ожидание ввода данных
    connect(&Socket::GetInstance()->sk, &QTcpSocket::disconnected, this, &MainWindow::ClientDisconnected); // клиент отключился (закрыл UI)

    this->Connect();
}

MainWindow::~MainWindow() // Диструктор срабатывающий при закрытии окна клиента
{
    delete ui;
}

void MainWindow::Connect() // Подключение UI к серверу
{
    if (Socket::GetInstance()->sk.state() != QAbstractSocket::ConnectedState) {
        Socket::GetInstance()->sk.connectToHost("127.0.0.1", 33333);
        if (!Socket::GetInstance()->sk.waitForConnected(5))
        {
           ui->textinfo->append("Failed server connection"); // Выводится при попытке подключиться к отключенному серверу
           return;
        }
    }
// Пропуск уже прочитанного сокета
    skip_read = true;
    ExtraFunction authorisation;
    authorisation.setModal(true);
    authorisation.exec();
    skip_read = false;
}


void MainWindow::on_pushButton_clicked() // Подключение при нажатии кнопки "Connect"
{
    ui->textinfo->clear();
    Connect();
}

void MainWindow::SendToServer(QString str) // Отправка сообщений на сервер
{
    if (Socket::GetInstance()->sk.state() == QAbstractSocket::ConnectedState) // Проверка подключения
    {
        Socket::GetInstance()->sk.write(str.toUtf8()); // Вывод сообщения в UI
    }
}

void MainWindow::slotReadyRead() // Чтение отправленных сообщений
{
    if (skip_read)
    {
        return;
    }

    QString str;
    str.append(Socket::GetInstance()->sk.readAll());
    ui->textinfo->append("Client: " + str.trimmed()); // Вывод сообщения в виде "Client:<Отправленный текст>
}


void MainWindow::on_pushButton_2_clicked() // Отправляет текст из поля ввода при нажатии кнопки "--->"
{
    SendToServer(ui->lineEdit->text());
}


void MainWindow::on_lineEdit_returnPressed() // Ввод текста для отправки
{
    SendToServer(ui->lineEdit->text());
}

void MainWindow::ClientDisconnected() // Выводится сообщение об отключении сервера
{
    Socket::GetInstance()->sk.close();
    ui->textinfo->append("Server closed!");
}

void MainWindow::on_pushButton_3_clicked() // При нажатии кнопки перебрасывает на окно с заданием
{
    skip_read = true;
    Task task;
    task.setModal(true);
    task.exec();
    skip_read = false;
}


void MainWindow::on_pushButton_4_clicked() // Вывод статистики
{
    QString cmd = "ctrl:stat";
    Socket::GetInstance()->sk.write(cmd.toUtf8());
}

