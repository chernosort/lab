#include "motorcycle_ext.h"

extMotorcycle::extMotorcycle()//:Motorcycle()
{
    type = ' ';
    company = ' ';
    model = ' ';
    cm3 = 0;
    hp =  0;
    year = 0;
    kilometrage = 0;
    price = 0;
    NumberOfWheels = 0;
}

extMotorcycle::extMotorcycle(string Type, string Company, string Model,int ReleaseYear, int Cm3, int HP,  long Kilometrage, long Price, int Number)
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
    if (a>0 && a<7 && a!=5){
        NumberOfWheels = a;
        return 0;}
    else
        return 1;
}

string extMotorcycle :: toStream()
{
//    int f = year;
//    string str = QString::number(year).toLocal8Bit().constData();
    string s = type + " "+ company +" "+ model +" "+ + QString::number(cm3).toLocal8Bit().constData()
            +" "+ QString::number(hp).toLocal8Bit().constData()
            +" "+ QString::number(kilometrage).toLocal8Bit().constData() +" "+ QString::number(price).toLocal8Bit().constData() +" "+ QString::number(NumberOfWheels).toLocal8Bit().constData();
    return s;
}

string extMotorcycle :: toFileStream()
{
//    int f = year;
    string str = QString::number(year).toLocal8Bit().constData();
    string s = "<<> "+type + " "+ company +" "+ model +" "+ + QString::number(cm3).toLocal8Bit().constData()
            +" "+ QString::number(hp).toLocal8Bit().constData()
            +" "+ QString::number(kilometrage).toLocal8Bit().constData() +" "+ QString::number(price).toLocal8Bit().constData() +" "+ QString::number(NumberOfWheels).toLocal8Bit().constData();
    return s;
}

void extMotorcycle :: setData(string Type, string Company, string Model,int ReleaseYear, int Cm3, int HP,  long Kilometrage,  long Price, int number)
{
    type = Type;
    company = Company;
    model = Model;
    year = ReleaseYear;
    cm3 = Cm3;
    hp = HP;
    kilometrage = Kilometrage;
    price = Price;
    NumberOfWheels = number;
}
