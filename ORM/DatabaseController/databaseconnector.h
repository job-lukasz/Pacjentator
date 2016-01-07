#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QSqlRecord>
#include "databaseresult.h"
#include <map>

class DatabaseConnector
{
private:
    static QSqlDatabase db;

private:
    DatabaseConnector();
    DatabaseConnector(DatabaseConnector const &) = delete;
    void operator=(DatabaseConnector const&)  = delete;


public: 
    static void conntect(const QString &dbPath);
    static void disconnect();
    static DatabaseConnector& getConnector(){
        static DatabaseConnector singleton;
        return singleton;
    }

    static bool executeQuerry(const std::string &query);
    static int executeInsertQuerry(const std::string &insertQuerry);
    static std::map<std::string,std::string> executeQueryAndGetSingleResult(std::string sqlQuery);
    static std::list<std::map<std::string, std::string>> executeQueryGetResults(std::string sqlQuery);

};
#endif // DATABASECONNECTOR_H
