#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
using namespace std;
#include <QString>
#include <istream>

//#include <string>


class Motorcycle
{
protected:
    int year, hp, cm3;
    long price, kilometrage;
    string  company, model;
    mutable string type;
public:
    //конструкторы
    Motorcycle();
    Motorcycle(string Type, string Company, string Model,int ReleaseYear, int Cm3, int HP,  long Kilometrage, long Price);
    Motorcycle (const Motorcycle & a);
    ~Motorcycle();

    //селекторы
    int setPrice(long a);
    int setVolume(int a);
    int setReleaseYear(int a);
    void setType(string a)const {type = a;}
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
    virtual string toStream();
    virtual string toFileStream();
    virtual void setData (string Type, string Company, string Model,int ReleaseYear, int Cm3, int HP,  long Kilometrage, long Price);

    bool operator  >(const Motorcycle & a) {return price > a.price;}
    bool operator  <(const Motorcycle & a) {return price < a.price;}
    bool operator ==(const Motorcycle & a) {return price == a.price;}
    bool operator >=(const Motorcycle & a) {return !(price<a.price);}
    //арифметические
//    long operator+(const Motorcycle & a) {return price + a.price;}
    Motorcycle operator+(const Motorcycle & a)
    {
        Motorcycle tmp;
//        tmp=*this;
        tmp.cm3 = cm3;
        tmp.company = company;
        tmp.hp = hp;
        tmp.model = model;
        tmp.type = type;
        tmp.year = year;
        tmp.price=this->price+a.price;
        tmp.kilometrage=this->kilometrage+a.kilometrage;
        return tmp;
    }
//    long operator-(const Motorcycle & a) {return price - a.price;}
    Motorcycle operator-(const Motorcycle & a)
    {
        Motorcycle tmp;
        tmp=*this;
        tmp.price=this->price-a.price;
        tmp.kilometrage=this->kilometrage-a.kilometrage;
        return tmp;
    }
//    int operator *(const Motorcycle & a) {return cm3   * a.cm3;}
    Motorcycle operator *(const Motorcycle & a)
    {
        Motorcycle tmp;
        tmp=*this;
        tmp.price=this->cm3*a.cm3;
        return tmp;
    }


    Motorcycle & operator=(const Motorcycle & value)
    {
        //проверка на самоприсваивание
        if (this == &value) {
            return *this;
        }
        type = value.type;
        company = value.company;
        model = value.model;
        year = value.year;
        cm3 = value.cm3;
        hp = value.hp;
        price = value.price;
        kilometrage = value.kilometrage;
        return *this;
    }
    //префиксный/постфиксный инкремент и декремент
    //префиксный
    Motorcycle& operator++()
    {
        price++;
        return *this;
    }
    //постфиксный
    Motorcycle operator++(int)
    {
        Motorcycle temp = *this;
        ++this->price;
        return temp;
    }

    friend string &operator<<(string &os, Motorcycle* &n)
    {
        os="Motorcycle " + n->toStream();
        return os;
    }

    friend string &operator >>( string &input, Motorcycle* &value )
    {
        value->company = input;
        string str = value->toStream();
        return str;
    }
//changed
    Motorcycle & operator()(int n)
    {
        price = n;
        return *this;
    }
};

#endif // MOTORCYCLE_H

