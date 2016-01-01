#ifndef PACJENTMEDICINE_H
#define PACJENTMEDICINE_H
#include <QString>
#include <QDate>
#include <QColor>
#include <ORM/dbcell.hpp>
#include <ORM/idbtable.h>
#include <string>

class PacjentMedicine:public IDBTable
{
public:
    enum dateKnowlege{wellKnown=1, dayNotKnown=2, mounthNotKnow=3, onGoing=4};
    PacjentMedicine();
    PacjentMedicine(const PacjentMedicine &old);
    DBCell<QString>* name;
    DBCell<QDate>* from;
    DBCell<QDate>* to;
    DBCell<QColor>* color;
    DBCell<QString>* dose;
    DBCell<QString>* freguency;
    DBCell<dateKnowlege>* fromKnownDate;
    DBCell<dateKnowlege>* toKnownDate;
    virtual void init();
    virtual ~PacjentMedicine();
};

#endif // PACJENTMEDICINE_H
