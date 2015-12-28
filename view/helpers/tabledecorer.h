#ifndef TABLEDECORER_H
#define TABLEDECORER_H
#include <QTableView>
#include <memory>
#include <view/helpers/spanholder.h>
#include "model/QPatientModel.h"
#include <QScrollBar>
#include <QHeaderView>

class TableDecorer
{
private:
    QTableView* table;
    PatientModel* model;
    int cellWidth = 15;
private:
    std::shared_ptr<QVector<std::shared_ptr<SpanHolder>>> generateSpanVector(int rowNumber);

public:
    TableDecorer(QTableView* tableView):table(tableView){
         model = dynamic_cast<PatientModel*>(tableView->model());
    }
    void spanCells(int rowNumber);
    void spanAllCells();
    void setCellWidth(int cellWidth);
    void decCellWidth();
    void incCellWidth();
    void setCellWidth();
};

#endif // TABLEDECORER_H
