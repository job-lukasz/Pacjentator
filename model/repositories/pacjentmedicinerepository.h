#ifndef PACJENTMEDICINEREPOSITORY_H
#define PACJENTMEDICINEREPOSITORY_H
#include "ORM/idbrepositories.h"
#include "model/pacjentmedicine.h"

class PacjentMedicineRepository:public IDBRepositories
{
private:
    static PacjentMedicineRepository* singleton;
    PacjentMedicineRepository() = default;
    PacjentMedicineRepository(PacjentMedicineRepository const &) = delete;
    void operator=(PacjentMedicineRepository const&)  = delete;
    PacjentMedicine currentValue;

public:
    static PacjentMedicineRepository* getRepository();
    virtual void initTableFields();
    PacjentMedicine getPacjentMedicine(int id);
};

#endif // PACJENTMEDICINEREPOSITORY_H
