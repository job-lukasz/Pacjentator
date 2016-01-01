#ifndef IDBCELL_H
#define IDBCELL_H
#include "dbcellparameters.h"

class IDBCell
{
public:
    IDBCell(const DBCellParameters parameters);
    IDBCell(const std::string &table,const std::string &column);
    DBCellParameters parameters;
};

#endif // IDBCELL_H
