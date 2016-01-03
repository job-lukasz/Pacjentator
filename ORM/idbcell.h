#ifndef IDBCELL_H
#define IDBCELL_H
#include "dbcellparameters.h"
#include <string>

class IDBCell
{
public:
    IDBCell(const DBCellParameters parameters);
    IDBCell(const std::string &table,const std::string &column);
    DBCellParameters parameters;
    virtual void setValue(const std::string &value)=0;
};

#endif // IDBCELL_H
