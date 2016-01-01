#include "addpatientform.h"

AddPatientForm::AddPatientForm(PacjentMedicine *form, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addPatientForm)
{
    saveValue=form;
    ui->setupUi(this);

    setRandomColor();
    ui->FromCombo->addItem("Znane",PacjentMedicine::wellKnown);
    ui->FromCombo->addItem("Miesiąc nie znany",PacjentMedicine::mounthNotKnow);
    ui->FromCombo->addItem("Dzień nie znany",PacjentMedicine::dayNotKnown);

    ui->ToCombo->addItem("Znane",PacjentMedicine::wellKnown);
    ui->ToCombo->addItem("Miesiąc nie znany",PacjentMedicine::mounthNotKnow);
    ui->ToCombo->addItem("Dzień nie znany",PacjentMedicine::dayNotKnown);
    ui->ToCombo->addItem("Nadal",PacjentMedicine::onGoing);

    connect(colorPicker,SIGNAL(colorChanged(QColor)),this,SLOT(setColor(QColor)));
}

AddPatientForm::~AddPatientForm()
{
    if(colorPicker) delete colorPicker;
    delete ui;
}

void AddPatientForm::on_cancel_clicked()
{
    this->close();
}

void AddPatientForm::setColor(QColor color){
    saveValue->color->setValue(color);
}

void AddPatientForm::on_Save_clicked()
{
    saveValue->from->setValue(ui->medicineFrom->date());
    saveValue->to->setValue(ui->medicineTo->date());
    saveValue->name->setValue(ui->medicineName->text());
    saveValue->dose->setValue(ui->dose->text());
    saveValue->freguency->setValue(ui->frequency->text());
    saveValue->fromKnownDate->setValue(static_cast<PacjentMedicine::dateKnowlege>(ui->FromCombo->currentData().toInt()));
    saveValue->toKnownDate->setValue(static_cast<PacjentMedicine::dateKnowlege>(ui->ToCombo->currentData().toInt()));
    emit save(saveValue);
    this->close();
}


void AddPatientForm::setRandomColor()
{
    colorPicker = new ColorPickerWidget(this);
    auto rnd = []() -> int {return qrand() % 256;};
    QColor color = QColor(rnd(),rnd(),rnd());
    colorPicker->setColor(color);
    saveValue->color->setValue(color);
    ui->colorPickerLayout->addWidget(colorPicker);
}
