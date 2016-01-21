#include "QPatientModel.h"

PatientModel::PatientModel(QDate startDate, QDate endDate,QObject *parent):QStandardItemModel(parent)
{
    colorer = new RowColorer();
    this->startDate = startDate;
    this->endDate = endDate;
}


void PatientModel::generateHeader()
{
    insertRows(0,3);
    int startMounth = startDate.month();
    int startDay = startDate.day();
    int currentColumn=0;
    for(int year=startDate.year();year<=endDate.year();year++){
        setItem(0,currentColumn,new QStandardItem(QString::number(year)));
        int maxMounth = year==endDate.year()?endDate.month():12;
        for(int mounth=startMounth;mounth<=maxMounth;mounth++){
            setItem(1,currentColumn,new QStandardItem(mounthNames[mounth-1]));
            int maxDay = Calendar::getMounthLength(mounth,year);
            if(year==endDate.year()&&mounth==endDate.month()){
                maxDay = endDate.day();
            }
            for(int day=startDay;day<=maxDay;day++){
                setItem(2,currentColumn++,new QStandardItem(QString::number(day)));
            }
            startDay=1;
        }
        startMounth=1;
    }

}

void PatientModel::addMedicine(PacjentMedicine* medicine){
    QMedicineItem* tmp = new QMedicineItem(medicine);
    tmp->setBackground(colorer->getBrush(medicine));
    tmp->setToolTip(QString("Dawka: %1\nCzęstotliwość: %2").arg(medicine->dose->getValue().getRawaValue(),medicine->freguency->getValue().getRawaValue()));
    tryChangeModelDates(medicine->from->getValue().getRawaValue(),medicine->to->getValue().getRawaValue());
    addItem(tmp);
}

bool PatientModel::tryChangeModelDates(QDate startDate, QDate endDate)
{
    bool valuesChanged = false;
    if(this->startDate>startDate){
        valuesChanged=true;
        insertColumns(0,this->startDate.toJulianDay()-startDate.toJulianDay());
        this->startDate=startDate;
    }
    if(this->endDate<endDate){
        valuesChanged=true;
        insertColumns(columnCount(),endDate.toJulianDay()-this->endDate.toJulianDay());
        this->endDate=endDate;
    }
    if(valuesChanged){
        removeRows(0,3);
        generateHeader();
        emit headerChange();
    }

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

void PatientModel::addItem(QMedicineItem* tmp)
{
    int startDateColumn = getColumnNumber(tmp->medicine->from->getValue().getRawaValue());
    int endDateColumn = getColumnNumber(tmp->medicine->to->getValue().getRawaValue());
    int row = rowCount();
    setItem(row,0,new QStandardItem(QString("")));
    setItem(row,startDateColumn,tmp);
    setItem(row,endDateColumn+1,new QStandardItem(QString("")));
    emit itemAdded(rowCount()-1);
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
