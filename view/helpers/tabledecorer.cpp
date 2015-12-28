#include "tabledecorer.h"

void TableDecorer::spanCells(int rowNumber)
{
    std::shared_ptr<QVector<std::shared_ptr<SpanHolder>>> spanVector = generateSpanVector(rowNumber);
    QVectorIterator<std::shared_ptr<SpanHolder>> iterator(*spanVector);
    while(iterator.hasNext()){
        std::shared_ptr<SpanHolder> span = iterator.next();
        table->setSpan(span->rowNumber,span->columnNumber,span->rowSpan,span->columnSpan);
    }
}

std::shared_ptr<QVector<std::shared_ptr<SpanHolder>>> TableDecorer::generateSpanVector(int rowNumber){
    int value=0;
    int lastColumnWithValue = 0;
    int columnsNumbers = model->columnCount();
    std::shared_ptr<QVector<std::shared_ptr<SpanHolder>>> spanVector(new QVector<std::shared_ptr<SpanHolder>>);
    while(value<columnsNumbers){
        while(model->item(rowNumber,value)==0&&value<columnsNumbers){
            ++value;
        }
        int length = value-lastColumnWithValue;
        if (length>1){
            std::shared_ptr<SpanHolder> pointer(new SpanHolder(rowNumber,lastColumnWithValue,1, length));
            spanVector->append(pointer);
        }
        lastColumnWithValue=value;
        ++value;
    }
    return spanVector;
}

void TableDecorer::setCellWidth(){
    int tmp = table->horizontalScrollBar()->value();
    table->verticalHeader()->setDefaultSectionSize(15);
    for(int i=0;i<model->columnCount();i++){
        table->setColumnWidth(i,cellWidth);
    }
    table->horizontalScrollBar()->setValue(tmp+1);
    table->horizontalScrollBar()->setValue(tmp);
}

void TableDecorer::setCellWidth(const int cellWidth){
    this->cellWidth = cellWidth;
    setCellWidth();
}

void TableDecorer::incCellWidth(){
    cellWidth=cellWidth+5;
    setCellWidth();
}

void TableDecorer::decCellWidth(){
    cellWidth=cellWidth>5?cellWidth-5:1;
    setCellWidth();
}

void TableDecorer::spanAllCells(){
    for(int i=0;i<model->rowCount();i++)
    {
        spanCells(i);
    }
}


