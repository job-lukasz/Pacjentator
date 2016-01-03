#include "pacjentator.h"

Pacjentator::Pacjentator(PatientModel *model, PacjentatorController *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pacjentator)
{
    ui->setupUi(this);
    connect(ui->tableView->horizontalScrollBar(), SIGNAL(valueChanged(int)),this, SLOT(setVericalHeader(int)));
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)),this,SLOT(setMedicinePanelValue(QModelIndex)));
    this->controller = controller;
    ui->tableView->setModel(model);
}

void Pacjentator::setInitValues(){
    tableDecorer = std::shared_ptr<TableDecorer>(new TableDecorer(ui->tableView));
    tableDecorer->setCellWidth();
    tableDecorer->spanAllCells();
    ui->tableView->scrollTo(controller->getModelIndex(QDate::currentDate()));
}

int Pacjentator::getCurrentColumn(){
   return ui->tableView->horizontalScrollBar()->value();
}

void Pacjentator::setMedicinePanelValue(QModelIndex index){
    if(QMedicineItem* item = controller->getModelItem(index)){
        ui->From->setText(item->medicine->from->getValue().getRawaValue().toString("dd.MM.yyyy"));
        ui->To->setText(item->medicine->to->getValue().getRawaValue().toString("dd.MM.yyyy"));
        ui->Medicine->setText(item->medicine->name->getValue().getRawaValue());
        ui->Dose->setText(item->medicine->dose->getValue().getRawaValue());
        ui->Frequency->setText(item->medicine->freguency->getValue().getRawaValue());
    }
}

void Pacjentator::setVericalHeader(int value){
    controller->fillVerticalHeaders(value);
}

void Pacjentator::on_actionPowi_ksz_triggered()
{
    tableDecorer->incCellWidth();

}
void Pacjentator::on_actionPomniejsz_triggered()
{
    tableDecorer->decCellWidth();
}

void Pacjentator::on_actionDodaj_Lek_triggered()
{
   controller->openAddMedicineForm();
}

Pacjentator::~Pacjentator()
{
    delete ui;
}
