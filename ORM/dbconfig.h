#ifndef DBCONFIG_H
#define DBCONFIG_H
#include <string>
#include <list>
#include "ORM/dbrepositories.h"

class DBConfig
{
public:
    DBConfig(const std::list<DBRepositories*> &repositoryList);
    std::list<DBRepositories*> repoList;

};

#endif // DBCONFIG_H
