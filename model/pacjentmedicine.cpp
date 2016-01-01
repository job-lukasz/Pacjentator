#include "pacjentmedicine.h"
#define TABLENAME "PacjentMedicine"

PacjentMedicine::PacjentMedicine():IDBTable(TABLENAME){
    name = new DBCell<QString>(this,"name");
    from = new DBCell<QDate>(this,"from");
    to = new DBCell<QDate>(this,"to");
    color = new DBCell<QColor>(this,"color");
    dose = new DBCell<QString>(this,"dose");
    freguency = new DBCell<QString>(this,"frequency");
    fromKnownDate = new DBCell<dateKnowlege>(this, "fromKnownDate");
    toKnownDate = new DBCell<dateKnowlege>(this,"toKnownDate");
}

PacjentMedicine::PacjentMedicine(const PacjentMedicine &old):IDBTable(old)
{
    name=old.name;
    from=old.from;
    to=old.to;
    freguency=old.freguency;
    fromKnownDate=old.fromKnownDate;
    toKnownDate=old.toKnownDate;
    color=old.color;
    dose=old.dose;
}

void PacjentMedicine::init(){}

PacjentMedicine::~PacjentMedicine()
{
    delete name;
    delete from;
    delete to;
    delete color;
    delete dose;
    delete freguency;
    delete fromKnownDate;
    delete toKnownDate;
}
