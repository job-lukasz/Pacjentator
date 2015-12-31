#ifndef ROWCOLORER_H
#define ROWCOLORER_H
#include <QBrush>
#include <QGradient>
#include "model/pacjentmedicine.h"
class RowColorer
{
public:
    RowColorer();
    QGradient getGradient(const PacjentMedicine* medicine);
    QBrush getBrush(const PacjentMedicine *medicine);
};

#endif // ROWCOLORER_H
