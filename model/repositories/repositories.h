#ifndef REPOSITORIES_H
#define REPOSITORIES_H
#include "model/helpers/databaseconnector.h"

class Repositories
{
public:
    Repositories();

protected:
    DatabaseConnector* database = &(DatabaseConnector::getConnector());

};

#endif // REPOSITORIES_H
