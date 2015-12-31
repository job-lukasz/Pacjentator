#ifndef DBCELL_H
#define DBCELL_H
#include <string>
#include <map>
#include <QDebug>
#include "dbmodel.h"
#include "cellparameters.h"


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
        if(DBModel::DatabaseMap.find(parameters.table+"#"+parameters.name) == DBModel::DatabaseMap.end()){
            DBModel::DatabaseMap[parameters.table+"#"+parameters.name]=parameters;
            qDebug()<<"Add: "<< parameters.table.c_str() << "/" << parameters.name.c_str() << "to DatabaseMap";
        }
    }

    DBCell(const CellParameters &cellParameters){
        parameters=cellParameters;
        if(DBModel::DatabaseMap.find(parameters.table+"#"+parameters.name) == DBModel::DatabaseMap.end()){
            DBModel::DatabaseMap[parameters.table+"#"+parameters.name]=parameters;
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
