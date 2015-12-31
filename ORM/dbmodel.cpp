#include "dbmodel.h"

std::map<std::string,CellParameters> DBModel::DatabaseMap;

DBModel::DBModel(DBConfig *config)
{
    this->config=config;
}

void DBModel::init()
{
    qDebug()<<"Database table map content:";
    for(std::map<std::string,CellParameters>::iterator it = DBModel::DatabaseMap.begin(); it != DBModel::DatabaseMap.end(); ++it) {
        qDebug()<< it->first.c_str() << " "<<it->second.table.c_str() <<" "<< it->second.name.c_str() ;
    }
    for(DBRepositories* repository:config->repoList){
        repository->initTableFields();
    }
}

DBModel::~DBModel()
{
    delete config;
}

