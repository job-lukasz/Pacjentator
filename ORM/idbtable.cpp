#include "idbtable.h"

IDBTable::IDBTable(const std::string &tableName)
{
    this->tableName = tableName;
}


IDBTable::IDBTable(const IDBTable &old)
{
    this->tableName = old.tableName;
}

std::string IDBTable::getTableName()
{
    return tableName;
}

void IDBTable::addToTable(IDBCell *cell)
{
    qDebug()<<"add cel:"<<cell->parameters.column.c_str() << "to table:"<<tableName.c_str();
    cells[cell->parameters.column]=cell;
}

IDBTable* IDBTable:: getRow(const int &id){
    std::string query = "select ";
    for(std::map<std::string,IDBCell*>::iterator it = cells.begin(); it != cells.end(); ++it){
        query.append(it->first).append(", ");
    }
    query=query.substr(0,query.size()-2);
    query.append(" from ").append(tableName).append(" where id = ").append(std::to_string(id));
    std::map<std::string, std::string> result = DatabaseConnector::getConnector().executeQueryAndGetSingleResult(query);
    for(std::map<std::string,std::string>::iterator it = result.begin(); it != result.end(); ++it){
        cells.at(it->first)->setValue(it->second);
    }

    return nullptr;
}
