#ifndef IDBCELL_H
#define IDBCELL_H
#include "dbcellparameters.h"
#include <string>

class IDBCell
{
public:
    IDBCell(const DBCellParameters parameters);
    IDBCell(const std::string &table,const std::string &column, const std::string &sqlDataType);
    DBCellParameters parameters;
    virtual void setValue(const std::string &value)=0;
    virtual std::string getString()=0;
};

#endif // IDBCELL_H
