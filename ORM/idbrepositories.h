#ifndef REPOSITORIES_H
#define REPOSITORIES_H

class IDBRepositories
{
protected:
    IDBRepositories(){}
public:
    virtual void initTableFields() = 0;
};

#endif // REPOSITORIES_H
