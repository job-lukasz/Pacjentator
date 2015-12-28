#include "rowcolorer.h"

RowColorer::RowColorer(){

}

QGradient RowColorer::getGradient(PacjentMedicine medicine)
{
    QLinearGradient grandient(25,25,100,100);
    if(medicine.fromKnownDate!=PacjentMedicine::wellKnown){
        grandient.setColorAt(0,Qt::white);
    }

    grandient.setColorAt(0.5,medicine.color);

    if(medicine.toKnownDate!=PacjentMedicine::wellKnown){
        grandient.setColorAt(1,Qt::white);
    }
    return grandient;
}

QBrush RowColorer::getBrush(PacjentMedicine medicine)
{
    if(medicine.fromKnownDate==PacjentMedicine::wellKnown && medicine.toKnownDate==PacjentMedicine::wellKnown){
        return QBrush(medicine.color);
    }
    else{
        return QBrush(getGradient(medicine));
    }
}
