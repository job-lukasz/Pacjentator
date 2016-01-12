#include "dbmodel.h"

std::map<std::string,std::map<std::string,DBCellParameters>> DBModel::DatabaseMap;

DBModel::DBModel(DBConfig *config)
{
    this->config=config;
}

void DBModel::init()
{
    for(IDBRepositories* repository:config->repoList){
        repository->initTableFields();
    }
}

DBModel::~DBModel()
{
    delete config;
}

