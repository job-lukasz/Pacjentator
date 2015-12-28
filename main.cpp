#include "view/pacjentator.h"
#include <QApplication>
#include "controller/pacjentatorcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PacjentatorController* controller = new PacjentatorController();
    controller->showMainForm();
    return a.exec();
}
