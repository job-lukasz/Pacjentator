#include "rowcolorer.h"

RowColorer::RowColorer(){

}

QGradient RowColorer::getGradient(const PacjentMedicine *medicine)
{
    QLinearGradient grandient(25,25,100,100);
    if(medicine->fromKnownDate->getValue().getRawaValue()!=PacjentMedicine::wellKnown){
        grandient.setColorAt(0,Qt::white);
    }

    grandient.setColorAt(0.5,medicine->color->getValue().getRawaValue());

    if(medicine->toKnownDate->getValue().getRawaValue()!=PacjentMedicine::wellKnown){
        grandient.setColorAt(1,Qt::white);
    }
    return grandient;
}

QBrush RowColorer::getBrush(const PacjentMedicine* medicine)
{
    if(medicine->fromKnownDate->getValue().getRawaValue()==PacjentMedicine::wellKnown && medicine->toKnownDate->getValue().getRawaValue()==PacjentMedicine::wellKnown){
        return QBrush(medicine->color->getValue().getRawaValue());
    }
    else{
        return QBrush(getGradient(medicine));
    }
}
