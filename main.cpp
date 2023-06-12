#include <QCoreApplication>
#include "server.h"
#include "database_u.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server MyServer;

    return a.exec();
}
