#ifndef PACJENTATOR_H
#define PACJENTATOR_H

#include <QMainWindow>
#include <memory>
#include "ui_pacjentator.h"
#include "QScrollBar"
#include "model/pacjentmedicine.h"
#include "model/helpers/QMedicineItem.h"
#include "helpers/tabledecorer.h"
#include "../controller/pacjentatorcontroller.h"

namespace Ui {
    class Pacjentator;
}

class PacjentatorController;

class Pacjentator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pacjentator(QWidget *parent = 0);
    Pacjentator(PatientModel* model,PacjentatorController *controller, QWidget *parent = 0);
    ~Pacjentator();
    int getCurrentColumn();
    void setInitValues();
    TableDecorer* tableDecorer;

public slots:
    void setVericalHeader(int value);

private slots:
    void on_actionPowi_ksz_triggered();
    void on_actionPomniejsz_triggered();
    void on_actionDodaj_Lek_triggered();
    void setMedicinePanelValue(QModelIndex);

private:
    Ui::Pacjentator *ui;
    PacjentatorController* controller;
};

#endif // PACJENTATOR_H
