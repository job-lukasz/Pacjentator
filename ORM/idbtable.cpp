#include "idbtable.h"



IDBTable::IDBTable(const std::string &tableName)
{
    this->tableName = tableName;
}


IDBTable::IDBTable(const IDBTable &old)
{
    this->tableName = old.tableName;
}

std::string IDBTable::getName()
{
    return tableName;
}

void IDBTable::addToTable(IDBCell *cell)
{
    qDebug()<<"add cel:"<<cell->parameters.column.c_str() << "to table:"<<tableName.c_str();
    cells[cell->parameters.column]=cell;
}

IDBTable* IDBTable::getRow(const int &id){
    return nullptr;
}
