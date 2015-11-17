#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
using namespace std;
#include <QString>
//#include <string>


class Motorcycle
{
protected:
    int year, hp, cm3;
    long price, kilometrage;
    string type, company, model;
public:
    //конструкторы
    Motorcycle();
    Motorcycle(string Type, string Company, string Model, int Cm3, int HP, int ReleaseYear, long Kilometrage, long Price);
    Motorcycle (const Motorcycle & a);
    ~Motorcycle();

    //селекторы
    int setPrice(long a);
    int setVolume(int a);
    int setReleaseYear(int a);
    void setType(string a) {type = a;}
    void setCompany(string a) {company = a;}
    void setModel(string a) {model = a;}
    int setPower(int a);
    int setKilometrage (long a);

    //модификаторы
    long getPrice() {return price;}
    int getVolume() {return cm3;}
    int getReleaseYear() {return year;}
    string getType() {return type;}
    string getCompany() {return company;}
    string getModel() {return model;}
    int getPower() {return hp;}
    long getKilometrage() {return kilometrage;}
};

#endif // MOTORCYCLE_H
