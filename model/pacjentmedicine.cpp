#include "pacjentmedicine.h"
#define TABLENAME "PacjentMedicine"

PacjentMedicine::PacjentMedicine():IDBTable(TABLENAME){
    name = new DBCell<QDBString>(this,"name");
    from = new DBCell<QDBDate>(this,"from");
    to = new DBCell<QDBDate>(this,"to");
    color = new DBCell<QDBColor>(this,"color");
    dose = new DBCell<QDBString>(this,"dose");
    freguency = new DBCell<QDBString>(this,"frequency");
    fromKnownDate = new DBCell<QDBEnum<dateKnowlege>>(this, "fromKnownDate");
    toKnownDate = new DBCell<QDBEnum<dateKnowlege>>(this,"toKnownDate");
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
