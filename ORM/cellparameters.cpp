#include "dbcellparameters.h"

DBCellParameters::DBCellParameters(std::string table,std::string name){
    this->column=name;
    this->table=table;
}

DBCellParameters::DBCellParameters(){
    this->column="";
    this->table="";
}

DBCellParameters::DBCellParameters(const DBCellParameters &old){
    (*this)=old;
}

void DBCellParameters::operator=(const DBCellParameters &assigned){
    column=assigned.column;
    table=assigned.table;
}

bool DBCellParameters::operator==(const DBCellParameters &parameters)
{
    return parameters.column==column&&parameters.table==table;
}
bool DBCellParameters::operator!=(const DBCellParameters &parameters)
{
    return !((*this)==parameters);
}
