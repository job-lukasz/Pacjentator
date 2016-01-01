#ifndef DBCELL_H
#define DBCELL_H
#include <string>
#include <map>
#include <QDebug>
#include "dbmodel.h"
#include "dbcellparameters.h"
#include "idbtable.h"
#include "idbcell.h"

template <typename CellType>
class DBCell:public IDBCell
{
private:
    CellType value;
public:
    DBCell(const DBCell & copied){
        (*this)=copied;
    }

    DBCell(IDBTable *table,const std::string &columnName):IDBCell(table->getName(),columnName){
        table->addToTable(this);
        if(DBModel::DatabaseMap.find(parameters.table+"#"+parameters.column) == DBModel::DatabaseMap.end()){
            DBModel::DatabaseMap[parameters.table+"#"+parameters.column]=parameters;
            qDebug()<<"Add: "<< parameters.table.c_str() << "/" << parameters.column.c_str() << "to DatabaseMap";
        }
    }

    DBCell(IDBTable *table,const DBCellParameters &cellParameters):IDBCell(cellParameters){
        table->addToTable(this);
        if(DBModel::DatabaseMap.find(parameters.table+"#"+parameters.column) == DBModel::DatabaseMap.end()){
            DBModel::DatabaseMap[parameters.table+"#"+parameters.column]=parameters;
            qDebug()<<"Add:"<< parameters.table.c_str() << "/" << parameters.column.c_str() << "to DatabaseMap";
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
