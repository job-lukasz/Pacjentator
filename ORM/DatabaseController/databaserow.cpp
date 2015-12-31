#include "databaserow.h"

DatabaseRow::DatabaseRow()
{

}

DatabaseRow::~DatabaseRow()
{
    for(DatabaseCell* cell: cells){
        delete cell;
    }
}

QList<DatabaseCell *> DatabaseRow::getCells()
{
    return cells;
}

int DatabaseRow::getCellsNumber()
{
    return cells.size();
}

void DatabaseRow::addCell(DatabaseCell *cell)
{
    cells.append(cell);
}

