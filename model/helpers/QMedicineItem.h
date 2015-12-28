#ifndef QMEDICINEITEM_H
#define QMEDICINEITEM_H
#include "model/pacjentmedicine.h"
#include <QStandardItem>

class QMedicineItem : public QStandardItem
{
public:
    QMedicineItem(PacjentMedicine medicine);
    PacjentMedicine medicine;
};

#endif // QMEDICINEITEM_H
