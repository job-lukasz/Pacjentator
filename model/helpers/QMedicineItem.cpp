#include "QMedicineItem.h"

QMedicineItem::QMedicineItem(PacjentMedicine medicine):QStandardItem(medicine.name)
{
    this->medicine=medicine;
}

