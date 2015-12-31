#include "cellparameters.h"

CellParameters::CellParameters(std::string table,std::string name){
    this->name=name;
    this->table=table;
}

CellParameters::CellParameters(){
    this->name="";
    this->table="";
}

CellParameters::CellParameters(const CellParameters &old){
    (*this)=old;
}

void CellParameters::operator=(const CellParameters &assigned){
    name=assigned.name;
    table=assigned.table;
}

bool CellParameters::operator==(const CellParameters &parameters)
{
    return parameters.name==name&&parameters.table==table;
}
bool CellParameters::operator!=(const CellParameters &parameters)
{
    return !((*this)==parameters);
}
