#ifndef PACJENTMEDICINE_H
#define PACJENTMEDICINE_H
#include <QString>
#include <QDate>
#include <QColor>
#include <ORM/dbcell.hpp>
#include <ORM/dbtable.h>
#include <string>

class PacjentMedicine:public DBTable
{
public:
    enum dateKnowlege{wellKnown=1, dayNotKnown=2, mounthNotKnow=3, onGoing=4};
    PacjentMedicine();
    PacjentMedicine(const PacjentMedicine &old);
    DBCell<QString>* name;
    DBCell<QDate>* from;
    QDate to;
    QColor color;
    QString dose;
    QString freguency;
    dateKnowlege fromKnownDate = static_cast<dateKnowlege>(1);
    dateKnowlege toKnownDate =  static_cast<dateKnowlege>(1);
    virtual void init();
};

#endif // PACJENTMEDICINE_H
