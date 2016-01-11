#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QSqlRecord>
#include <map>

class DatabaseConnector
{
private:
    QSqlDatabase* db;

private:
    DatabaseConnector();
    DatabaseConnector(DatabaseConnector const &) = delete;
    void operator=(DatabaseConnector const&)  = delete;


    std::map<std::string, std::string> fillRow(const QSqlQuery &query);

public:
    static DatabaseConnector& getConnector(){
        static DatabaseConnector singleton;
        return singleton;
    }

    void conntect(const QString &dbPath);
    void disconnect();
    bool executeQuerry(const std::string &query);
    int executeInsertQuerry(const std::string &insertQuerry);
    std::map<std::string,std::string> executeQueryAndGetSingleResult(const std::string &sqlQuery);
    std::list<std::map<std::string, std::string>> executeQueryGetResults(const std::string &sqlQuery);
    ~DatabaseConnector();
};
#endif // DATABASECONNECTOR_H
