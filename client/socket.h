#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

class Socket {
public:
    QTcpSocket sk;

    static Socket* GetInstance()
    {
        if (instance == NULL) {
            instance = new Socket();
        }

        return instance;
    }

private:
    Socket()
    {
    }

    static Socket *instance;
};

#endif // SOCKET_H
