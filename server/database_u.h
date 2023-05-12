#ifndef DATABASE_U_H
#define DATABASE_U_H


#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QString>


class Database_u
{
public:
    static Database_u* GetInstance();

    bool AddUser(QString login, QString password);
    bool CheckUser(QString login, QString password);
    QString GetTaskNames();
    QString GetTaskTemplate(QString name);
    void AddAnswer(QString login, QString name, QString answer, bool isCorrect);
    QString GetStat(QString login);

private:
    static Database_u *instance;
    QSqlDatabase db;

    Database_u();
    int GetUserId(QString login);
    int GetTaskId(QString name);
};

#endif // DATABASE_U_H
