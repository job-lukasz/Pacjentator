#include "pacjentatorcontroller.h"
#include "ORM/idbtable.h"
#define DATABASE_FILE "database.sqlite"

PacjentatorController::PacjentatorController(QObject *parent)
{
    model = new PatientModel(QDate(1990,1,1),QDate(2017,2,10), this);
    pacjentator = new Pacjentator(model,this);
    std::list<IDBRepositories*> repos = {
        PacjentMedicineRepository::getRepository()
    };
    DBConfig* config = new DBConfig(repos);
    DatabaseConnector::getConnector().conntect(DATABASE_FILE);
    DBModel dbModel(config);
    dbModel.init();
    std::list<PacjentMedicine*> a = PacjentMedicineRepository::getRepository()->getAllRows();
    for(PacjentMedicine* value: a){
        addMedicine(value);
    }

}

void PacjentatorController::openAddMedicineForm(){
    addMedicineForm = QSharedPointer<AddPatientForm>(new AddPatientForm(new PacjentMedicine));
    addMedicineForm->show();
    addMedicineForm->setWindowModality(Qt::WindowModal);
    connect(addMedicineForm.data(),SIGNAL(save(PacjentMedicine*)),this, SLOT(closeAddMedicineForm(PacjentMedicine*)));
}

void PacjentatorController::closeAddMedicineForm(PacjentMedicine* value)
{
    disconnect(addMedicineForm.data(),SIGNAL(save(PacjentMedicine*)),this, SLOT(closeAddMedicineForm(PacjentMedicine*)));
    if(value->name->getValue().getRawaValue()!=""){
        value->save();
        addMedicine(value);
        addMedicineForm->close();
    }
}

void PacjentatorController::addMedicine(PacjentMedicine* value){
    model->addMedicine(value);
    model->fillVerticalHeaders(pacjentator->getCurrentColumn());
    pacjentator->tableDecorer->spanCells(model->rowCount()-1);
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
    DatabaseConnector::getConnector().disconnect();
    delete model;
    delete pacjentator;
}
