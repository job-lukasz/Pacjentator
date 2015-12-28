#ifndef CALENDAR_H
#define CALENDAR_H
#include <QDate>

class Calendar
{
public:
    Calendar();
    static int getMounthLength(int mounth,int year);
};

#endif // CALENDAR_H
