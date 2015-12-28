#ifndef DATABASEROW_H
#define DATABASEROW_H
#include <QString>
#include <QList>
#include <QVariant>
#include "databasecell.h"

class DatabaseRow
{
public:
    DatabaseRow();
    virtual ~DatabaseRow();
    QList<DatabaseCell*> getCells();
    int getCellsNumber();
    void addCell(DatabaseCell * cell);
private:
    QList<DatabaseCell*> cells;
};

#endif // DATABASEROW_H
