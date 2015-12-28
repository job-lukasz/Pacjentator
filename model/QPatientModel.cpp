#include "QPatientModel.h"

PatientModel::PatientModel(QDate startDate, QDate endDate,QObject *parent):QStandardItemModel(parent)
{
    colorer = new RowColorer();
    this->startDate = startDate;
    this->endDate = endDate;
    generateHeader();
}


void PatientModel::generateHeader()
{
    int currentColumn=0;
    for(int year=startDate.year();year<=endDate.year();year++){
        setItem(0,currentColumn,new QStandardItem(QString::number(year)));
        int maxMounth = year==endDate.year()?endDate.month():12;
        for(int mounth=1;mounth<=maxMounth;mounth++){
            setItem(1,currentColumn,new QStandardItem(mounthNames[mounth-1]));
            int maxDay = (year==endDate.year()&&mounth==endDate.month())?endDate.day():Calendar::getMounthLength(mounth,year);
            for(int day=1;day<=maxDay;day++){
                setItem(2,currentColumn++,new QStandardItem(QString::number(day)));
            }
        }
    }
}

void PatientModel::addMedicine(PacjentMedicine medicine){
    QMedicineItem* tmp = new QMedicineItem(medicine);
    tmp->setBackground(colorer->getBrush(medicine));

    int startDateColumn = getColumnNumber(medicine.from);
    int endDateColumn = getColumnNumber(medicine.to);

    tmp->setToolTip(QString("Dawka: %1\nCzęstotliwość: %2").arg(medicine.dose,medicine.freguency));
    int row = rowCount();
    setItem(row,0,new QStandardItem(QString("")));
    setItem(row,startDateColumn,tmp);
    setItem(row,endDateColumn+1,new QStandardItem(QString("")));
}

void PatientModel::fillVerticalHeaders(int value){
    for(int i=0; i<rowCount();i++){
        setRowHeader(value,i);
    }
}

void PatientModel::setRowHeader(int value, int row){
    while(item(row,value)==0&&value>-2){
        --value;
    }
    if(value>-1){
        setVerticalHeaderItem(row,item(row,value)->clone());
    }
}

QModelIndex PatientModel::getModelIndex(QDate date){
    return index(1,getColumnNumber(date));
}

int PatientModel::getColumnNumber(QDate date){
    int value = date.toJulianDay()-startDate.toJulianDay();
    return value;
}

PatientModel::~PatientModel(){
    if(colorer){
        delete colorer;
    }
}
