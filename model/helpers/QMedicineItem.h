#ifndef QMEDICINEITEM_H
#define QMEDICINEITEM_H
#include "model/pacjentmedicine.h"
#include <QStandardItem>

class QMedicineItem : public QStandardItem
{
public:
    QMedicineItem(PacjentMedicine* medicine);
    PacjentMedicine* medicine;
    virtual ~QMedicineItem();
};

#endif // QMEDICINEITEM_H
