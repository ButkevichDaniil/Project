#include "functions.h"
#include <QObject>
#include <QByteArray>
#include <QString>
#include <QCoreApplication>
#include <QRandomGenerator>

static QString cLogin = "";
static QString cTask = "";
static QString cAnswer = "";

QString authorization(QString login, QString password)
{
    if (Database_u::GetInstance()->CheckUser(login, password))
    {
        cLogin = login;
        return "true";
    }

    return "false";
}

QString registration(QString login, QString password)
{
    if (Database_u::GetInstance()->AddUser(login, password))
        return "true";

    return "false";
}

QString GetTask1()
{
    const int size = 5;
    QString result = "";
    int matrix[size][size] = { 0 };


    for (int i = 0; i < size; i++)
    {
        int i0, i1;

        do
        {
            i0 = QRandomGenerator::global()->bounded(0, size - 1);
            i1 = QRandomGenerator::global()->bounded(0, size - 1);
        } while (i0 == i1);

        matrix[i0][i] = 1;
        matrix[i1][i] = 1;
    }

    int adjacency_matrix[size][size] = { 0 };

    for (int i = 0; i < size; i++) {
        int count = 0;
        int i0, i1;

        for (int j = 0; j < size; j++) {
            if (matrix[j][i] != 0)
            {
                count++;
                if (count == 1)
                {
                    i0 = j;
                }
                else
                {
                    i1 = j;
                    break;
                }
            }
        }

        if (count == 2)
        {
            adjacency_matrix[i0][i1] = 1;
            adjacency_matrix[i1][i0] = 1;
        }
    }

    cAnswer = "";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result += QString::number(matrix[i][j]) + "\t";
            cAnswer += QString::number(adjacency_matrix[i][j]);
        }

        result += "\n";
    }

    cTask = "Task 1";
    return result;
}

QString getTask(QString name)
{
    if (name == "Task 1")
    {
        return GetTask1();
    }

    return "";
}

QString CheckAnswer(QString answer)
{
    bool isCorrect = false;

    if (cTask.isEmpty())
    {
        return "false";
    }

    answer.replace(' ', "");
    answer.replace(',', "");
    answer.replace('.', "");
    answer.replace('\t', "");
    answer.replace('\n', "");

    if (answer == cAnswer)
    {
        isCorrect = true;
    }

    Database_u::GetInstance()->AddAnswer(cLogin, cTask, answer, isCorrect);

    if (isCorrect)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

QString parse(QString data)
{
    data = data.trimmed();

    QStringList parts = data.split("&"); //разбиваем строку на список параметров, (&) - разделитель для разделения параметров
    qDebug()<<data;
    if (parts[0] == "auth" && parts.size() == 3)
        return authorization(parts[1].trimmed(), parts[2].trimmed());
    else if (parts[0] == "reg" && parts.size() == 3)
        return registration(parts[1].trimmed(), parts[2].trimmed());
    else if (parts[0] == "names" && parts.size() == 1)
        return Database_u::GetInstance()->GetTaskNames();
    else if (parts[0] == "task" && parts.size() == 2)
        return getTask(parts[1].trimmed());
    else if (parts[0] == "task_template" && parts.size() == 2)
        return Database_u::GetInstance()->GetTaskTemplate(parts[1].trimmed());
    else if (parts[0] == "answer" && parts.size() == 2)
        return CheckAnswer(parts[1].trimmed());
    else if (parts[0] == "stat" && parts.size() == 1)
        return Database_u::GetInstance()->GetStat(cLogin);

    return "false";
}
