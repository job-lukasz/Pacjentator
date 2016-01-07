#include "dbcellparameters.h"

DBCellParameters::DBCellParameters(const std::string &table, const std::string &name, const std::string &dbDataType){
    this->column=name;
    this->table=table;
    this->dbDataType=dbDataType;
}

DBCellParameters::DBCellParameters(){
    this->column="";
    this->table="";
    this->dbDataType="";
}

DBCellParameters::DBCellParameters(const DBCellParameters &old){
    (*this)=old;
}

void DBCellParameters::operator=(const DBCellParameters &assigned){
    column=assigned.column;
    table=assigned.table;
    dbDataType=assigned.dbDataType;
}

bool DBCellParameters::operator==(const DBCellParameters &parameters)
{
    return parameters.column==column&&parameters.table==table;
}
bool DBCellParameters::operator!=(const DBCellParameters &parameters)
{
    return !((*this)==parameters);
}
