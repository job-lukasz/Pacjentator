#include "QMedicineItem.h"

QMedicineItem::QMedicineItem(PacjentMedicine* medicine):QStandardItem(medicine->name->getValue().getRawaValue())
{
    this->medicine=medicine;
}

