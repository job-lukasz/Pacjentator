#include "databaseresult.h"

DatabaseResult::DatabaseResult(int columnNumber)
{
    columnNames.reserve(columnNumber);
    this->columnNumber=columnNumber;
}

DatabaseResult::~DatabaseResult()
{
    for(DatabaseRow* row:rows){
        delete row;
    }
}

void DatabaseResult::AddNewRow()
{
    rows.append(new DatabaseRow());
}

bool DatabaseResult::AddColumnName(const QString& columnName){
    if(columnNames.size()==columnNumber){
        return false;
    }
    columnNames.append(columnName);
    return true;
}

/*Add values to next free cell, or create new row*/
void DatabaseResult::AddResult(const QVariant value)
{
    if(rows.last()->getCellsNumber()>=columnNumber){
        AddNewRow();
    }
    rows.last()->addCell(new DatabaseCell(value));
}
