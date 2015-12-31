#include "QMedicineItem.h"

QMedicineItem::QMedicineItem(PacjentMedicine* medicine):QStandardItem(medicine->name->getValue())
{
    this->medicine=medicine;
}

