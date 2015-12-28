#ifndef ADDPATIENTFORM_H
#define ADDPATIENTFORM_H

#include <QWidget>
#include "model/pacjentmedicine.h"
#include "ui_addpatientform.h"
#include "view/colorTriangle/colorpickerwidget.h"
#include <QColor>

namespace Ui {
class addPatientForm;
}

class AddPatientForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddPatientForm(QWidget *parent = 0);
    ~AddPatientForm();

signals:
    void save(PacjentMedicine);

private slots:
    void on_cancel_clicked();
    void on_Save_clicked();
    void setColor(QColor color);

private:
    PacjentMedicine saveValue;

    Ui::addPatientForm *ui;
    ColorPickerWidget* colorPicker;
    void setRandomColor();
};

#endif // ADDPATIENTFORM_H
