#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//#include<QString>
#include "motorcycle.h"
#include "motorcycle_ext.h"
using namespace std;

class LinkedList
{
private:
    struct Node
     {
         Motorcycle data;
         Node *next,*prev;
     };
    Node *head, *tail;

public:
    //конструкторы
    LinkedList();
    LinkedList (Motorcycle a, Motorcycle b, Motorcycle c);
    LinkedList(const LinkedList & a);
    ~LinkedList();

    void AddBot(Motorcycle x);//добавить в начало
    void AddTop(Motorcycle x);// добавить в конец
    void AddBot(extMotorcycle x);
    void AddTop(extMotorcycle x);
    string Get(string a);
    void Delete(string a);
    void DeleteList();
    string PrintList();
    int ReadFromFile(const char filename[]);
};

#endif // LINKEDLIST_H
