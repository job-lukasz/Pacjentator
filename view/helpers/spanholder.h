#ifndef SPANHOLDER_H
#define SPANHOLDER_H


class SpanHolder
{
public:
    SpanHolder();
    int rowNumber, columnNumber, rowSpan, columnSpan;

    SpanHolder(int rowNumber, int columnNumber, int rowSpan, int columnSpan);
    SpanHolder(const SpanHolder &span);
    ~SpanHolder();
};

#endif // SPANHOLDER_H
