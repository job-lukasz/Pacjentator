#include "databasecell.h"

DatabaseCell::DatabaseCell(QVariant value)
{
    this->value=value;
}

QVariant DatabaseCell::getValue()
{
    return value;
}
