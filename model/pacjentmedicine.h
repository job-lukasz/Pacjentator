#ifndef PACJENTMEDICINE_H
#define PACJENTMEDICINE_H
#include <QString>
#include <QDate>
#include <QColor>

class PacjentMedicine
{
public:
    enum dateKnowlege{wellKnown=1, dayNotKnown=2, mounthNotKnow=3, onGoing=4};
    PacjentMedicine();
    QString name;
    QDate from;
    QDate to;
    QColor color;
    QString dose;
    QString freguency;
    dateKnowlege fromKnownDate = static_cast<dateKnowlege>(1);
    dateKnowlege toKnownDate =  static_cast<dateKnowlege>(1);
};

#endif // PACJENTMEDICINE_H
