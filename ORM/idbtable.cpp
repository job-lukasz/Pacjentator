#include "idbtable.h"

IDBTable::IDBTable(const std::string &tableName)
{
    this->tableName = tableName;
    ID=-1;
}


IDBTable::IDBTable(const IDBTable &old)
{
    this->tableName = old.tableName;
    this->ID = old.ID;
}

std::string IDBTable::getTableName()
{
    return tableName;
}

void IDBTable::addToTable(IDBCell *cell)
{
    cells[cell->parameters.column]=cell;
}

std::string IDBTable::generateInsertQuery()
{
    std::string query;
    query.append("INSERT INTO ");
    query.append(tableName).append(" (");
    for(std::map<std::string,IDBCell*>::iterator it = cells.begin(); it != cells.end(); ++it){
        query.append("\"").append(it->first).append("\", ");
    }
    query=query.substr(0,query.size()-2).append(" ) values (");
    for(std::map<std::string,IDBCell*>::iterator it = cells.begin(); it != cells.end(); ++it){
        query.append("\"").append(it->second->getString()).append("\", ");
    }
    return query.substr(0,query.size()-2).append(" );");
}

std::string IDBTable::generateUpdateQuery()
{
    std::string query;
    query.append("UPDATE ");
    query.append(tableName).append(" SET ");
    for(std::map<std::string,IDBCell*>::iterator it = cells.begin(); it != cells.end(); ++it){
        query.append("\"").append(it->first).append("\"=\"").append(it->second->getString()).append("\", ");
    }
    query=query.substr(0,query.size()-2);
    return query.append("WHERE id = ").append(std::to_string(ID)).append(";");
}

std::string IDBTable::genereteSelectAllQuery(const std::string &tableName)
{
    std::string query = "select \"id\", ";
    std::map<std::string, DBCellParameters> cellList = DBModel::DatabaseMap[tableName];
    for(std::map<std::string, DBCellParameters>::iterator it = cellList.begin(); it != cellList.end(); ++it){
        query.append("\"").append(it->first).append("\", ");
    }
    query=query.substr(0,query.size()-2);
    query.append(" from ").append(tableName).append(";");
    return query;
}

bool IDBTable::save(){
    std::string query;
    if(ID<1){
        query = generateInsertQuery();
        ID = DatabaseConnector::getConnector().executeInsertQuerry(query);
        if(ID>0){
            return true;
        }
    }
    else{
        query = generateUpdateQuery();
        return DatabaseConnector::getConnector().executeQuerry(query);
    }
    return false;
}

void IDBTable::init()
{
    init(tableName);
}

IDBTable* IDBTable::getRow(const int &id){
    ID=id;
    std::string query = "select \"id\", ";
    for(std::map<std::string,IDBCell*>::iterator it = cells.begin(); it != cells.end(); ++it){
        query.append(it->first).append(", ");
    }
    query=query.substr(0,query.size()-2);
    query.append(" from ").append(tableName).append(" where id = ").append(std::to_string(id));
    std::map<std::string, std::string> result = DatabaseConnector::getConnector().executeQueryAndGetSingleResult(query);
    for(std::map<std::string,std::string>::iterator it = result.begin(); it != result.end(); ++it){
        cells.at(it->first)->setValue(it->second);
    }
    return this;
}

//template<typename IDBTableType>
//std::list<IDBTableType> IDBTable::getAllRows(const std::string &tableName){

//}

void IDBTable::init(std::string tableName){
    std::string query = "CREATE TABLE IF NOT EXISTS ";
    query.append(tableName).append("(ID INTEGER PRIMARY KEY AUTOINCREMENT,");
    for(std::map<std::string,DBCellParameters>::iterator it = DBModel::DatabaseMap[tableName].begin(); it != DBModel::DatabaseMap[tableName].end(); ++it){
        query.append("\"").append(it->second.column).append("\" ").append(it->second.dbDataType).append(", ");
    }
    query=query.substr(0,query.size()-2).append(");");
    return;
}

void IDBTable::initAll(){
    for(std::map<std::string,std::map<std::string,DBCellParameters>>::iterator it = DBModel::DatabaseMap.begin(); it != DBModel::DatabaseMap.end(); ++it){
        init(it->first);
    }
}
