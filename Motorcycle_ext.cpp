#include "motorcycle_ext.h"

extMotorcycle::extMotorcycle():Motorcycle()
{
    NumberOfWheels = 2;
}

extMotorcycle::extMotorcycle(string Type, string Company, string Model, int Cm3, int HP, int ReleaseYear, long Kilometrage, long Price, int Number)
{
    type = Type;
    company = Company;
    model = Model;
    cm3 = Cm3;
    hp = HP;
    year = ReleaseYear;
    kilometrage = Kilometrage;
    price = Price;
    NumberOfWheels = Number;
}

int extMotorcycle::setNumberOfWheels(int a)
{
    if (a>0 && a<7 && a!=5)
        return 0;
    else
        return 1;
}
