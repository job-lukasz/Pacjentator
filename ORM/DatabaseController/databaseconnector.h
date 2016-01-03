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
    static bool isConnected;
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
    bool executeQuerry(const QString &query);
    DatabaseResult executeQueryGetResults(QString sqlQuery);
    std::map<std::string,std::string> executeQueryAndGetSingleResult(std::string sqlQuery);
};
#endif // DATABASECONNECTOR_H
