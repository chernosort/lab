#include "motorcycle.h"
#include<string.h>
//#include<QString>
using namespace std;

Motorcycle :: Motorcycle()
{
    type = ' ';
    company = ' ';
    model = ' ';
    cm3 = 0;
    hp =  0;
    year = 0;
    kilometrage = 0;
    price = 0;
}

//конструктор с параметрами
Motorcycle :: Motorcycle(string Type, string Company, string Model, int Cm3, int HP, int ReleaseYear, long Kilometrage,  long Price)
{
    type = Type;
    company = Company;
    model = Model;
    cm3 = Cm3;
    hp = HP;
    year = ReleaseYear;
    kilometrage = Kilometrage;
    price = Price;
}

//Деструктор
Motorcycle :: ~Motorcycle()
{

}

Motorcycle :: Motorcycle(const Motorcycle & a)
{
    this->type = a.type;
    this->company = a.company;
    this->cm3 = a.cm3;
    this->hp = a.hp;
    this->kilometrage = a.kilometrage;
    this->model = a.model;
    this->price = a.price;
}

//проверки параметров мотоцикла
int Motorcycle::setPrice( long a)
{
    if (a < 0 || a > 30000000)
        return 1;
    else
    {
        price = a;
        return 0;
    }
}

int Motorcycle::setVolume(int a)
{
    if (a < 0 || a > 10000)
        return 1;
    else
    {
        cm3 = a;
        return 0;
    }
}

int Motorcycle::setKilometrage(long a)
{
    if (a < 0 || a > 10000000)
        return 1;
    else
    {
        kilometrage = a;
        return 0;
    }
}

int Motorcycle::setReleaseYear(int a)
{
    if (a < 1885 || a > 2016)
        return 1;
    else
    {
        year = a;
        return 0;
    }
}

int Motorcycle ::setPower(int a)
{
     if (a<1 || a> 320)
        return 1;
     else
     {
         hp = a;
         return 0;
     }
}
