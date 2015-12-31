#include "pacjentmedicine.h"

PacjentMedicine::PacjentMedicine(){
    name = new DBCell<QString>("PacjentMedicine","name");
    from = new DBCell<QDate>("PacjentMedicine","from");
}

PacjentMedicine::PacjentMedicine(const PacjentMedicine &old)
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
