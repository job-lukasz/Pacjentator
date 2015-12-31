#include "databasemodel.h"
#include <QDebug>

std::map<std::string,CellParameters> DatabaseModel::DatabaseMap;

DatabaseModel::DatabaseModel()
{
}

void DatabaseModel::initTables(const std::list<Repositories*> &list)
{
   for(Repositories* repository:list){
       repository->initTableFields();
   }
}

