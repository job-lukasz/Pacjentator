#include "pacjentatorcontroller.h"

PacjentatorController::PacjentatorController(QObject *parent)
{
    std::list<IDBRepositories*> repos = {
        PacjentMedicineRepository::getRepository()
    };
    DBConfig* config = new DBConfig(repos);
    DBModel* dbModel = new DBModel(config);
    dbModel->init();
    model = new PatientModel(QDate(1990,1,1),QDate(2017,2,10), this);
    pacjentator = new Pacjentator(model,this);
}

void PacjentatorController::openAddMedicineForm(){
    addMedicineForm = QSharedPointer<AddPatientForm>(new AddPatientForm(new PacjentMedicine));
    addMedicineForm->show();
    addMedicineForm->setWindowModality(Qt::WindowModal);
    connect(addMedicineForm.data(),SIGNAL(save(PacjentMedicine*)),this, SLOT(addMedicine(PacjentMedicine*)));
}

void PacjentatorController::addMedicine(PacjentMedicine *value){
    disconnect(addMedicineForm.data(),SIGNAL(save(PacjentMedicine*)),this, SLOT(addMedicine(PacjentMedicine*)));
    if(value->name->getValue().getRawaValue()!=""){
        model->addMedicine(value);
        model->fillVerticalHeaders(pacjentator->getCurrentColumn());
        pacjentator->tableDecorer->spanCells(model->rowCount()-1);
    }
}

void PacjentatorController::showMainForm(){
    pacjentator->show();
    pacjentator->setInitValues();
}

void PacjentatorController::fillVerticalHeaders(int currentColumn){
    model->fillVerticalHeaders(currentColumn);
}

QMedicineItem* PacjentatorController::getModelItem(QModelIndex index){
    return dynamic_cast<QMedicineItem*>(model->itemFromIndex(index));
}

QModelIndex PacjentatorController::getModelIndex(QDate date){
    return model->getModelIndex(date);
}

PacjentatorController::~PacjentatorController(){
    delete model;
    delete pacjentator;
}
