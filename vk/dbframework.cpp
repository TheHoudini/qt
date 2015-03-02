#include "dbframework.h"

dbFramework::dbFramework(QObject *parent) :
    QObject(parent)
{
    // if db not exist,then create all table and default values
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("appDB");
    db.open();

    query = new QSqlQuery(db);
    query->prepare( "CREATE TABLE IF NOT EXISTS apiData ( "
    " name char primary key, "
    " token char, user_id char)");

    if(query->exec()){
    query->exec("INSERT INTO apiData(name) VALUES ('vk')");
    }


}


dbFramework::~dbFramework(){
    delete query;
}

// update token on table apiData,row vk
void dbFramework::updateVkData(QString* token)
{

    query->prepare("UPDATE apiData SET token = ? WHERE name='vk'");
    query->addBindValue(*token);
    if(query->exec())
            qDebug() << "token update";
}


// update token and user_id on table apiData,row vk
void dbFramework::updateVkData(QString *token, QString *user_id)
{
    query->prepare("UPDATE apiData SET token = ?,user_id=? WHERE name='vk'");
    query->addBindValue(*token);
    query->addBindValue(*user_id);
    if(query->exec())
        qDebug() << "token update";
}


// return vk token
QString dbFramework::getVkToken()
{
    query->prepare("SELECT * FROM apiData WHERE name='vk'");
    if(query->exec()){
        query->next();
        return query->value(1).toString();
    }else return 0;
}




