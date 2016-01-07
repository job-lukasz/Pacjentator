#ifndef PACJENTMEDICINE_H
#define PACJENTMEDICINE_H
#include <QString>
#include <QDate>
#include <QColor>
#include <ORM/dbcell.hpp>
#include <ORM/idbtable.h>
#include <string>
#include "ORM/dbdatatypes.h"
class PacjentMedicine:public IDBTable
{
public:
    enum dateKnowlege{wellKnown=1, dayNotKnown=2, mounthNotKnow=3, onGoing=4};
    PacjentMedicine();
    PacjentMedicine(const PacjentMedicine &old);
    DBCell<QDBString>* name;
    DBCell<QDBDate>* from;
    DBCell<QDBDate>* to;
    DBCell<QDBColor>* color;
    DBCell<QDBString>* dose;
    DBCell<QDBString>* freguency;
    DBCell<QDBEnum<dateKnowlege>>* fromKnownDate;
    DBCell<QDBEnum<dateKnowlege>>* toKnownDate;
    virtual ~PacjentMedicine();
};

#endif // PACJENTMEDICINE_H
