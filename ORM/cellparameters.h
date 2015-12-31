#ifndef CELLPARAMETERS_H
#define CELLPARAMETERS_H
#include <string>


struct CellParameters{
public:
    std::string table;
    std::string name;
    CellParameters(std::string table,std::string name);
    CellParameters();
    CellParameters(const CellParameters &old);
    void operator=(const CellParameters &assigned);
    bool operator!=(const CellParameters &parameters);
    bool operator==(const CellParameters &parameters);
};

#endif // CELLPARAMETERS_H
