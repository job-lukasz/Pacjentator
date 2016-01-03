#ifndef DBTABLE_H
#define DBTABLE_H
#include <QDebug>
#include <map>
#include <string>
#include <list>
#include "idbcell.h"
#include "DatabaseController/databaseconnector.h"

class IDBTable
{
private:
    std::map<std::string,IDBCell*> cells;
    std::string tableName;
public:
    IDBTable(const std::string &tableName);
    IDBTable(const IDBTable &old);
    IDBTable* getRow(const int &id);
    std::list<IDBTable*> getAllRows();
    std::string getTableName();
    void addToTable(IDBCell* cell);
    virtual void init() = 0;
};

#endif // DBTABLE_H
