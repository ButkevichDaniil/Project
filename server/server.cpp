#include "server.h"
#include <QDebug>
#include <QCoreApplication>
#include <QDataStream>
#include <functions.h>

Server::Server()
{
    if (this->listen(QHostAddress::Any, 33333))
    {
        server_status = 1;
        qDebug()<<"Server started!";
    }
    else
    {
        qDebug()<<"Lost connection!";
    }
}

Server::~Server()
{
    server_status = 0;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    if(server_status == 1)
    {
        socket = new QTcpSocket;
        socket->setSocketDescriptor(socketDescriptor);
        connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &Server::clientDisconnected);
        Sockets.push_back(socket);
        qDebug()<<"Client connected!"<<socketDescriptor;
    }
    if (server_status == 0)
        socket->close();
}

void Server::clientDisconnected()
{
    QTcpSocket* client = (QTcpSocket *)sender();
    if (client) {
        client->deleteLater();
        for (int i = 0; i < Sockets.size(); i++) {
            if (Sockets[i] == client) {
                Sockets.remove(i);
                break;
            }
        }
    }
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in (socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok) {
        qDebug() << "read...";
        QString str;

        while (socket->bytesAvailable() > 0) {
            str.append(socket->readAll());
        }

        if (str.startsWith("ctrl:")) {
            str.remove(0, 5);
            if(str.right(2) == "\r\n")
                str = str.left(str.length()-2);
            socket->write(parse(str).toUtf8());
        } else {
            SendToClient(str);
        }
    }
    else {
        qDebug() << "error!";
    }
}

void Server::SendToClient(QString str)
{
    for (int i = 0; i < Sockets.size(); i++)
    {
       Sockets[i]->write(str.toUtf8() + "\r\n");
    }
}
