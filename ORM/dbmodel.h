#ifndef DBMODEL_H
#define DBMODEL_H
#include <string>
#include <map>
#include <list>
#include <QDebug>
#include "cellparameters.h"
#include "dbrepositories.h"
#include "dbconfig.h"

class DBModel{
public:
    DBModel(DBConfig* config);
    DBConfig* config;
    static std::map<std::string,CellParameters> DatabaseMap;
    void init();

    virtual ~DBModel();
};
#endif // DATABASEMODEL_H
