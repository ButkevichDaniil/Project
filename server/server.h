#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QObject>
#include <QByteArray>
#include <QtNetwork>
#include <QTextStream>
#include <QSqlDatabase>
#include <QDebug>

#include "database_u.h"

class Server: public QTcpServer
{
    Q_OBJECT
public:
    Server();
    ~Server();
    QTcpSocket* socket;

private:
    QVector <QTcpSocket*> Sockets;
    int server_status;
    QByteArray Data;
    void SendToClient(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void clientDisconnected();
};

#endif // SERVER_H
