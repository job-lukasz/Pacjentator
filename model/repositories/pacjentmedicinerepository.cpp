#include "pacjentmedicinerepository.h"
#include <QDebug>

PacjentMedicineRepository* PacjentMedicineRepository::getRepository()
{
    static PacjentMedicineRepository singleton;
    return &singleton;
}

void PacjentMedicineRepository::initTableFields()
{
    qDebug()<<"Initialize pacjentMedicine repositories";
    currentValue.init();
}

PacjentMedicine PacjentMedicineRepository::getPacjentMedicine(int id){

}

std::list<PacjentMedicine*> PacjentMedicineRepository::getAllRows()
{
    return IDBTable::getAllRows<PacjentMedicine>("PacjentMedicine");
}

PacjentMedicineRepository::~PacjentMedicineRepository()
{}



