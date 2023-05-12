#include "database_u.h"

#include <QSqlError>
#include <QSqlRecord>

Database_u *Database_u::instance;

Database_u::Database_u()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); // Добавление базы данных
    db.setDatabaseName("data.db"); // Перезапись имени базы данных для корректной работы кода
    if(db.open())
    {
        qDebug("open db"); // Выводится при корректной работе кода
    }
    else
    {
        qDebug("not open db"); // Выводится при некорректной работе кода
    }

    QSqlQuery *query = new QSqlQuery(db); // Создание полей таблицы, в случае их отсутствия
    query->exec("CREATE TABLE users(id integer not null primary key, Login TEXT, Password TEXT);");
    query->exec("CREATE TABLE tasks(id integer not null primary key, Name TEXT, Template TEXT);");
    query->exec("CREATE TABLE answers(id integer not null primary key, Answer TEXT, TaskId INTEGER, UserId INTEGER, IsCorrect BOOLEAN);");

    /*
     * Добавления таблицы заданий, в случае ее отсутствия (делается в ручную, через браузер SQLite)
     * INSERT INTO "main"."tasks" ("id", "Name", "Template") VALUES ('1', 'Task 1', 'По матрице инцедентности построить матрицу смежности');
     */
    AddUser("admin", "admin"); // Ручное добавление пользователя
}

Database_u* Database_u::GetInstance() // Если база данных не запущена
{
    if (Database_u::instance == NULL)
    {
        Database_u::instance = new Database_u();
    }

    return Database_u::instance;
}

bool Database_u::AddUser(QString login, QString password) // Добавление пользователя в базу данных (сохраняются логин и пароль)
{
    QSqlQuery *query = new QSqlQuery(db);

    if (!CheckUser(login, password)) { // Если соблюдены все условия для регистрации, то данные сохраняются
        query->prepare("INSERT INTO users (Login, Password) VALUES(:Login, :Password)");
        query->bindValue(":Login", login);
        query->bindValue(":Password", password);
        return query->exec();
    }

    return false;
}

bool Database_u::CheckUser(QString login, QString password) // Проверка наличия логина и пароля пользователя в базе данных
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT * FROM users WHERE Login=:Login AND Password=:Password LIMIT 1");
    query->bindValue(":Login", login);
    query->bindValue(":Password", password);
    query->exec();
    return query->next();
}

QString Database_u::GetTaskNames() // Получаем тип задания
{
    QString result = "";

    QSqlQuery *query = new QSqlQuery(db);
    query->exec("SELECT tasks.Name FROM tasks");

    while (query->next())
    {
        QString name = query->value(0).toString();
        result += name;
        result += "\t";
    }

    return result;
}

int Database_u::GetUserId(QString login) // Получаем ID пользователя для ведения статистики
{
    int result = -1;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT users.id FROM users WHERE Login=:Login LIMIT 1");
    query->bindValue(":Login", login);
    query->exec();

    if (query->next())
    {
        result = query->value(0).toInt();
    }

    return result;
}

int Database_u::GetTaskId(QString name) // Получаем ID задания для сохранения в статистику
{
    int result = -1;
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT tasks.id FROM tasks WHERE Name=:Name LIMIT 1");
    query->bindValue(":Name", name);
    query->exec();

    if (query->next())
    {
        result = query->value(0).toInt();
    }

    return result;
}

QString Database_u::GetTaskTemplate(QString name) // Получаем шаблон задания
{
    QString result = "";
    QSqlQuery *query = new QSqlQuery(db);

    query->prepare("SELECT tasks.Template FROM tasks WHERE Name=:Name LIMIT 1");
    query->bindValue(":Name", name);
    query->exec();

    if (query->next())
    {
        result = query->value(0).toString();
    }

    return result;
}

void Database_u::AddAnswer(QString login, QString name, QString answer, bool isCorrect) // Добавляем ответы в таблицу базы данных для ведения статистики и последующего использования
{
    QSqlQuery *query = new QSqlQuery(db);

    query->prepare("INSERT INTO answers (Answer, TaskId, UserId, IsCorrect) VALUES(:Answer, :Task, :User, :IsCorrect)");
    query->bindValue(":Answer", answer);
    query->bindValue(":Task", GetTaskId(name));
    query->bindValue(":User", GetUserId(login));
    query->bindValue(":IsCorrect", isCorrect);
    query->exec();
}

QString Database_u::GetStat(QString login) // Получение статистики из базы данных
{
    QSqlQuery *query = new QSqlQuery(db);
    int total = 0, correct = 0;

    query->prepare("SELECT answers.IsCorrect FROM answers WHERE UserId=:UserId");
    query->bindValue(":UserId", GetUserId(login)); // Используется UserID для выборочного получения данных
    query->exec();

    while (query->next())
    {
        if (query->value(0).toBool()) {
            correct++;
        }
        total++;
    }

    QString result = "Total:" + QString::number(total); // Вывод общего количества ответов
    result += ", Correct:" + QString::number(correct); // Вывод количества правильных ответов

    return result;
}
