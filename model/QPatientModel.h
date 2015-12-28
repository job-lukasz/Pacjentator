#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H
#include <QStandardItemModel>
#include <QVector>
#include <QDebug>
#include <QDate>
#include <QStandardItem>
#include "model/pacjentmedicine.h"
#include "helpers/rowcolorer.h"
#include "helpers/calendar.h"
#include "model/helpers/QMedicineItem.h"

static const QString mounthNames[12] = {"Styczeń","Luty","Marzec","Kwiecień","Maj","Czerwiec","Lipiec","Sierpień","Wrzesień","Październik","Listopad","Grudzień"};

class PatientModel : public QStandardItemModel
{
    Q_OBJECT
public:
    PatientModel(QDate startDatet, QDate endDate,QObject *parent);

    ~PatientModel();
    void generateHeader();
    QModelIndex getModelIndex(QDate date);
    void fillVerticalHeaders(int value);
    void addMedicine(PacjentMedicine medicine);

private:
    QDate startDate;
    QDate endDate;
    RowColorer *colorer;

    QVector<int *> * spanVector;
    void generateValue(int *startDate, int lastSaveColumn, int *endDate, int &currentColumn, int level);
    int *setSpanTableValue(int row, int currentColumn, int columnSpan);
    int getColumnNumber(QDate date);
    void setRowHeader(int value, int row);
    void setBackgrounds();

    QBrush getBrush(PacjentMedicine medicine);
    QGradient getGradient(PacjentMedicine medicine);
};

#endif // PATIENTMODEL_H
