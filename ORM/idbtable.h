#ifndef DBTABLE_H
#define DBTABLE_H
#include <QDebug>
#include <map>
#include <string>
#include <list>
#include "idbcell.h"
#include "DatabaseController/databaseconnector.h"
#include "dbmodel.h"

class IDBTable
{
private:
    std::map<std::string,IDBCell*> cells;
    std::string tableName;
    static void init(std::string tableName);

    std::string generateInsertQuery();
    std::string generateUpdateQuery();
    static std::string genereteSelectAllQuery(const std::string &tableName);
    static std::string generateCreateTableQuerry(std::string tableName);

    static void fillRow(IDBTable* mainTable, std::map<std::string, std::string> result);



protected:
    int ID;

public:
    IDBTable(const std::string &tableName);
    IDBTable(const IDBTable &old);
    IDBTable* getRow(const int &id);
    std::string getTableName();
    void addCellToTable(IDBCell* cell);
    bool save();
    void init();
    void setID(const int &id){ID=id;}
    static void initAll();

    template<typename IDBTableType>
    static std::list<IDBTableType*> getAllRows(const std::string &tableName){
        std::string query = genereteSelectAllQuery(tableName);
        std::list<std::map<std::string, std::string>> queryResult = DatabaseConnector::getConnector().executeQueryGetResults(query);
        std::list<IDBTableType*> resultObjectList;

        for(std::map<std::string, std::string> row : queryResult) {
            IDBTableType* temp = new IDBTableType();
            temp->setID(std::stoi(row.at("ID")));
            row.erase("ID");
            fillRow(temp,row);
            resultObjectList.push_back(temp);
        }
        return resultObjectList;
    }
    std::string generateSelectRowQuery(const int &id);
};

#endif // DBTABLE_H
