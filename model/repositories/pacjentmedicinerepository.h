#ifndef PACJENTMEDICINEREPOSITORY_H
#define PACJENTMEDICINEREPOSITORY_H
#include "ORM/repositories.h"
#include "../pacjentmedicine.h"
class PacjentMedicineRepository:public Repositories
{
private:
    PacjentMedicineRepository() = default;
    PacjentMedicineRepository(PacjentMedicineRepository const &) = delete;
    void operator=(PacjentMedicineRepository const&)  = delete;
    PacjentMedicine currentValue;


public:
    static PacjentMedicineRepository& getRepository(){
        static PacjentMedicineRepository singleton;
        return singleton;
    }
    virtual void initTableFields();
    PacjentMedicine getPacjentMedicine(int id);
};

#endif // PACJENTMEDICINEREPOSITORY_H
