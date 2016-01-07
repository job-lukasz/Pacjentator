#include "databaseconnector.h"


QSqlDatabase DatabaseConnector::db = QSqlDatabase();

DatabaseConnector::DatabaseConnector(){}

void DatabaseConnector::conntect(const QString &dbPath){
    qDebug()<<"Try to connect to database";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    db.open();
}

bool DatabaseConnector::executeQuerry(const std::string &sqlQuery){
    QSqlQuery query(db);
    return query.exec(sqlQuery.c_str());
}

int DatabaseConnector::executeInsertQuerry(const std::string &insertQuerry){
    QSqlQuery query(db);
    if(query.exec(insertQuerry.c_str())){
        return query.lastInsertId().toInt();
    }
    return -1;
}

std::list<std::map<std::string, std::string>> DatabaseConnector::executeQueryGetResults(std::string sqlQuery){
    QSqlQuery query(db);
    query.exec(sqlQuery.c_str());
    QSqlRecord record = query.record();
    int columnsNumber = record.count();

    std::list<std::map<std::string, std::string>> result;
    //TODO add read all
    //    for(int i=0; i<columnsNumber; i++){
    //        result.AddColumnName(record.fieldName(i));
    //    }
    //    while (query.next()) {
    //        for(int i=0; i<columnsNumber; i++){
    //            result.AddResult(query.value(i));
    //        }
    //    }
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

