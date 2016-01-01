#include "dbconfig.h"

#define DBPATH "./database.sqlite"

DBConfig::DBConfig(const std::list<IDBRepositories *> &repositoryList){
    repoList = repositoryList;
}

