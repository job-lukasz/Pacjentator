#include "databaseconnector.h"


bool DatabaseConnector::isConnected = false;
QSqlDatabase DatabaseConnector::db = QSqlDatabase();

DatabaseConnector::DatabaseConnector(){}

void DatabaseConnector::conntect(const QString &dbPath){
    qDebug()<<"Try to connect to database";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    db.open();
}

bool DatabaseConnector::executeQuerry(const QString &sqlQuery){
    QSqlQuery query(db);
    return query.exec(sqlQuery);
}

DatabaseResult DatabaseConnector::executeQueryGetResults(QString sqlQuery){
    QSqlQuery query(db);
    query.exec(sqlQuery);
    QSqlRecord record = query.record();
    int columnsNumber = record.count();

    DatabaseResult result(columnsNumber);

    for(int i=0; i<columnsNumber; i++){
        result.AddColumnName(record.fieldName(i));
    }
    while (query.next()) {
        for(int i=0; i<columnsNumber; i++){
            result.AddResult(query.value(i));
        }
    }
    return result;
}

std::map<std::string, std::string> DatabaseConnector::executeQueryAndGetSingleResult(std::string sqlQuery){
    QSqlQuery query(db);
    query.exec(sqlQuery.c_str());
    QSqlRecord record = query.record();
    std::map<std::string, std::string> result;
    for(int i=0; i<record.count(); i++){
        result[record.fieldName(i).toStdString()]=query.value(i).toString().toStdString();
    }
    return result;
}

