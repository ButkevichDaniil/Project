#include "database.h"
#include "ui_database.h"

DataBase::DataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLLITE");
    db.setDatabaseName("./db/users.db");

    if(db.open())
    {
        qDebug("open db");
    }
    else qDebug("not open db");

}

DataBase::~DataBase()
{
    delete ui;
}
