#ifndef DBCELL_H
#define DBCELL_H
#include <string>
#include <map>
#include "databasemodel.h"
#include "cellparameters.h"
#include <QDebug>

template <typename CellType>
class DBCell
{
private:
    CellType value;
public:
    CellParameters parameters;

public:
    DBCell(const DBCell & copied){
        (*this)=copied;
    }

    DBCell(const std::string &tableName,const std::string &columnName){
        CellParameters newParameters = {tableName,columnName};
        parameters=newParameters;
        if(DatabaseModel::DatabaseMap.find(parameters.table+"#"+parameters.name) == DatabaseModel::DatabaseMap.end()){
            DatabaseModel::DatabaseMap[parameters.table+"#"+parameters.name]=parameters;
            qDebug()<<"Add: "<< parameters.table.c_str() << "/" << parameters.name.c_str() << "to DatabaseMap";
        }
    }

    DBCell(const CellParameters &cellParameters){
        parameters=cellParameters;
        if(DatabaseModel::DatabaseMap.find(parameters.table+"#"+parameters.name) == DatabaseModel::DatabaseMap.end()){
            DatabaseModel::DatabaseMap[parameters.table+"#"+parameters.name]=parameters;
            qDebug()<<"Add:"<< parameters.table.c_str() << "/" << parameters.name.c_str() << "to DatabaseMap";
        }
    }

    void operator=(const CellType &assigned){
        value = assigned;
    }

    void operator=(const DBCell<CellType> &assigned){
        value = assigned.value;
    }

    bool operator!=(const CellType &compared) const{
        return value!=compared;
    }

    CellType getValue() const{
        return value;
    }

    void setValue(const CellType &value){
        this->value = value;
    }

};

#endif // DBCELL_H
