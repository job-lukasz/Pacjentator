#ifndef DATABASECELL_H
#define DATABASECELL_H
#include <QVariant>

class DatabaseCell
{
public:
    DatabaseCell(QVariant value);
    QVariant getValue();
private:
    QVariant value;
};

#endif // DATABASECELL_H
