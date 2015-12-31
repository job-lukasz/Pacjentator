#ifndef PACJENTATORCONTROLLER_H
#define PACJENTATORCONTROLLER_H
#include <QSharedPointer>
#include <QDebug>
#include <map>
#include <string>

#include "../model/helpers/QMedicineItem.h"
#include "../view/addpatientform.h"
#include "../model/QPatientModel.h"
#include "../view/pacjentator.h"

#include "model/repositories/pacjentmedicinerepository.h"

class Pacjentator;

class PacjentatorController: public QObject
{
    Q_OBJECT

private:
    PatientModel* model;
    Pacjentator* pacjentator;

public:
    PacjentatorController(QObject *parent=0);
    ~PacjentatorController();
    void openAddMedicineForm();
    void showMainForm();
    QMedicineItem* getModelItem(QModelIndex index);
    QModelIndex getModelIndex(QDate date);
    void fillVerticalHeaders(int currentColumn);

private:
    QSharedPointer<AddPatientForm> addMedicineForm;

private slots:
    void addMedicine(PacjentMedicine* value);
};

#endif // PACJENTATORCONTROLLER_H
