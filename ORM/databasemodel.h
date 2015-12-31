#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
#include <string>
#include <QMap>
#include "cellparameters.h"
#include "repositories.h"
#include <list>

class DatabaseModel{
public:
    DatabaseModel();
    static std::map<std::string,CellParameters> DatabaseMap;
    static void initTables(const std::list<Repositories*> &list);
};
#endif // DATABASEMODEL_H
