#ifndef MOTORCYCLE_EXT_H
#define MOTORCYCLE_EXT_H
#include "motorcycle.h"

class extMotorcycle : public Motorcycle
{
private:
    int NumberOfWheels;
public:
    extMotorcycle();
    extMotorcycle(string Type, string Company, string Model,int Cm3, int HP,int ReleaseYear, long Kilometrage, long Price, int Number);
    int setNumberOfWheels(int a);

};


#endif // MOTORCYCLE_EXT_H
