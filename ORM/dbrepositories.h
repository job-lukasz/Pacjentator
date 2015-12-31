#ifndef REPOSITORIES_H
#define REPOSITORIES_H

class DBRepositories
{
protected:
    DBRepositories();
public:
    virtual void initTableFields() = 0;
};

#endif // REPOSITORIES_H
