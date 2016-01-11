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
    name = new DBCell<QDBString>(this,"name");
    from = new DBCell<QDBDate>(this,"from");
    to = new DBCell<QDBDate>(this,"to");
    color = new DBCell<QDBColor>(this,"color");
    dose = new DBCell<QDBString>(this,"dose");
    freguency = new DBCell<QDBString>(this,"frequency");
    fromKnownDate = new DBCell<QDBEnum<dateKnowlege>>(this, "fromKnownDate");
    toKnownDate = new DBCell<QDBEnum<dateKnowlege>>(this,"toKnownDate");
    *name = old.name->getValue();
    *from=old.from->getValue();
    *to=old.to->getValue();
    *freguency=old.freguency->getValue();
    *fromKnownDate= old.fromKnownDate->getValue();
    *toKnownDate=old.toKnownDate->getValue();
    *color=old.color->getValue();
    *dose=old.dose->getValue();
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
