#include "idbcell.h"

IDBCell::IDBCell(const DBCellParameters parameters)
{
    this->parameters=parameters;
}

IDBCell::IDBCell(const std::string &table, const std::string &column)
{
    parameters.column=column;
    parameters.table=table;
}

