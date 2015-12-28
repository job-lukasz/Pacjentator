#include "spanholder.h"
#include <QDebug>

SpanHolder::SpanHolder(int rowNumber, int columnNumber, int rowSpan, int columnSpan){
    this->rowNumber=rowNumber;
    this->columnNumber=columnNumber;
    this->rowSpan=rowSpan;
    this->columnSpan=columnSpan;
}

SpanHolder::SpanHolder(const SpanHolder &span):SpanHolder(span.rowNumber, span.columnNumber, span.rowSpan, span.columnSpan){}

SpanHolder::~SpanHolder(){}
