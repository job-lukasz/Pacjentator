#ifndef PACJENTMEDICINEREPOSITORY_H
#define PACJENTMEDICINEREPOSITORY_H
#include "repositories.h"
#include "../../model/pacjentmedicine.h"
class PacjentMedicineRepository:public Repositories
{
private:
    PacjentMedicineRepository() = default;
    PacjentMedicineRepository(PacjentMedicineRepository const &) = delete;
    void operator=(PacjentMedicineRepository const&)  = delete;

public:
    static PacjentMedicineRepository& getRepository(){
        static PacjentMedicineRepository singleton;
        return singleton;
    }

    PacjentMedicine getPacjentMedicine(int id);
};

#endif // PACJENTMEDICINEREPOSITORY_H
