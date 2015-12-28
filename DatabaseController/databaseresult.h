#ifndef DATABASERESULT_H
#define DATABASERESULT_H
#include <QString>
#include <QList>
#include <QVariant>
#include "databaserow.h"

class DatabaseResult
{
public:
    DatabaseResult(int columnNumber);
    virtual ~DatabaseResult();
    bool AddColumnName(const QString &columnName);
    void AddNewRow();
    void AddResult(const QVariant value);
private:
    int columnNumber;
    QList<QString> columnNames;
    QList<DatabaseRow*> rows;
};

#endif // DATABASERESULT_H
