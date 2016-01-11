#include "databaseconnector.h"


DatabaseConnector::DatabaseConnector(){
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
}

//! connector.
/*!
  Method using to connnect to DataBase
*/
void DatabaseConnector::conntect(const QString &dbPath){
    qDebug()<<"Try to connect to database";
    db->setDatabaseName(dbPath);
    db->open();
}

void DatabaseConnector::disconnect()
{
    db->close();
    db->removeDatabase(QLatin1String(QSqlDatabase::defaultConnection));
}

bool DatabaseConnector::executeQuerry(const std::string &sqlQuery){
    QSqlQuery query(*db);
    qInfo()<<"executed query:"<<sqlQuery.c_str();
    return query.exec(sqlQuery.c_str());
}

int DatabaseConnector::executeInsertQuerry(const std::string &insertQuerry){
    QSqlQuery query(*db);
    qInfo()<<"executed query:"<<insertQuerry.c_str();
    if(query.exec(insertQuerry.c_str())){
        return query.lastInsertId().toInt();
    }
    return -1;
}

std::map<std::string, std::string> DatabaseConnector::fillRow(const QSqlQuery &query)
{
    int columnsNumber = query.record().count();
    std::map<std::string, std::string> temp;
    for(int i=0; i<columnsNumber; i++){
        temp[query.record().fieldName(i).toStdString()]=query.value(i).toString().toStdString();
    }
    return temp;
}

std::list<std::map<std::string, std::string>> DatabaseConnector::executeQueryGetResults(const std::string &sqlQuery){
    QSqlQuery query(*db);
    qInfo()<<"executed query:"<<sqlQuery.c_str();
    query.exec(sqlQuery.c_str());


    std::list<std::map<std::string, std::string>> result;
    while (query.next()){
        result.push_back(fillRow(query));
    }
    return result;
}

DatabaseConnector::~DatabaseConnector()
{
    db->removeDatabase(QLatin1String(db->defaultConnection));
    delete db;
}

std::map<std::string, std::string> DatabaseConnector::executeQueryAndGetSingleResult(const std::string &sqlQuery){
    QSqlQuery query(*db);
    qInfo()<<"executed query:"<<sqlQuery.c_str();
    query.exec(sqlQuery.c_str());
    QSqlRecord record = query.record();
    std::map<std::string, std::string> result;
    for(int i=0; i<record.count(); i++){
        result[record.fieldName(i).toStdString()]=query.value(i).toString().toStdString();
    }
    return result;
}

