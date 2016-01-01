#ifndef DBMODEL_H
#define DBMODEL_H
#include <string>
#include <map>
#include <list>
#include <QDebug>
#include "dbcellparameters.h"
#include "idbrepositories.h"
#include "dbconfig.h"

class DBModel{
public:
    DBModel(DBConfig* config);
    DBConfig* config;
    static std::map<std::string,DBCellParameters> DatabaseMap;
    void init();

    virtual ~DBModel();
};
#endif // DATABASEMODEL_H
