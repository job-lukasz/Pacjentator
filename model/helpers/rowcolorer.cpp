#include "rowcolorer.h"

RowColorer::RowColorer(){

}

QGradient RowColorer::getGradient(const PacjentMedicine *medicine)
{
    QLinearGradient grandient(25,25,100,100);
    if(medicine->fromKnownDate->getValue()!=PacjentMedicine::wellKnown){
        grandient.setColorAt(0,Qt::white);
    }

    grandient.setColorAt(0.5,medicine->color->getValue());

    if(medicine->toKnownDate->getValue()!=PacjentMedicine::wellKnown){
        grandient.setColorAt(1,Qt::white);
    }
    return grandient;
}

QBrush RowColorer::getBrush(const PacjentMedicine* medicine)
{
    if(medicine->fromKnownDate->getValue()==PacjentMedicine::wellKnown && medicine->toKnownDate->getValue()==PacjentMedicine::wellKnown){
        return QBrush(medicine->color->getValue());
    }
    else{
        return QBrush(getGradient(medicine));
    }
}
