#ifndef DBCONFIG_H
#define DBCONFIG_H
#include <string>
#include <list>
#include "ORM/idbrepositories.h"

class DBConfig
{
public:
    DBConfig(const std::list<IDBRepositories*> &repositoryList);
    std::list<IDBRepositories*> repoList;

};

#endif // DBCONFIG_H
