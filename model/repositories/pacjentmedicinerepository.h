#ifndef PACJENTMEDICINEREPOSITORY_H
#define PACJENTMEDICINEREPOSITORY_H
#include "ORM/idbrepositories.h"
#include "model/pacjentmedicine.h"
#include <list>

class PacjentMedicineRepository:public IDBRepositories
{
private:
    PacjentMedicineRepository() = default;
    PacjentMedicineRepository(PacjentMedicineRepository const &) = delete;
    void operator=(PacjentMedicineRepository const&)  = delete;
    PacjentMedicine currentValue;

public:
    static PacjentMedicineRepository* getRepository();
    virtual void initTableFields();
    PacjentMedicine getPacjentMedicine(int id);
    std::list<PacjentMedicine*> getAllRows();
    ~PacjentMedicineRepository();
};

#endif // PACJENTMEDICINEREPOSITORY_H
