#include "pacjentmedicinerepository.h"
#include <QDebug>
PacjentMedicineRepository* PacjentMedicineRepository::singleton=0;
PacjentMedicineRepository* PacjentMedicineRepository::getRepository()
{
    if(!singleton){
        singleton = new PacjentMedicineRepository;
    }
    return singleton;
}

void PacjentMedicineRepository::initTableFields()
{
    qDebug()<<"Initialize PacejntMedicine repository";
    currentValue.init();
}

PacjentMedicine PacjentMedicineRepository::getPacjentMedicine(int id){

}



