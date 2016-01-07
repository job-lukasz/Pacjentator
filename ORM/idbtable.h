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

protected:
    int ID;

public:
    IDBTable(const std::string &tableName);
    IDBTable(const IDBTable &old);
    IDBTable* getRow(const int &id);
    std::string getTableName();
    void addToTable(IDBCell* cell);
    bool save();
    void init();

    static void initAll();
    static std::list<IDBTable*> getAllRows(const std::string &tableName);
};

#endif // DBTABLE_H
