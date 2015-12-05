#ifndef MOTORCYCLE_EXT_H
#define MOTORCYCLE_EXT_H
#include "motorcycle.h"

class extMotorcycle : public Motorcycle
{
private:
    int NumberOfWheels;
public:
    extMotorcycle();
    extMotorcycle(string Type, string Company, string Model,int ReleaseYear,int Cm3, int HP, long Kilometrage, long Price, int Number);
    int setNumberOfWheels(int a);
    int getNumberOfWheels(){return NumberOfWheels;}
    string toStream();
    string toFileStream();
    void setData(string Type, string Company, string Model, int ReleaseYear, int Cm3, int HP, long Kilometrage, long Price, int Number);

};


#endif // MOTORCYCLE_EXT_H
