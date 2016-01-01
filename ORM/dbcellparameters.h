#ifndef CELLPARAMETERS_H
#define CELLPARAMETERS_H
#include <string>


struct DBCellParameters{
public:
    std::string table;
    std::string column;
    DBCellParameters(std::string table,std::string column);
    DBCellParameters();
    DBCellParameters(const DBCellParameters &old);
    void operator=(const DBCellParameters &assigned);
    bool operator!=(const DBCellParameters &parameters);
    bool operator==(const DBCellParameters &parameters);
};

#endif // CELLPARAMETERS_H
