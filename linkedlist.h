#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//#include<QString>
#include "motorcycle.h"
#include "motorcycle_ext.h"
using namespace std;

template <class T> class LinkedList
{
private:
    struct Node
     {
         T data;
         Node *next,*prev;
     };
    Node *head, *tail;

public:
    //конструкторы
    LinkedList();
    LinkedList (T a, T b, T c);
    LinkedList(const LinkedList<T> & a);
    ~LinkedList();
    void AddNew(string Type, string Company, string Model,int Cm3, int HP,int ReleaseYear, long Kilometrage, long Price, int Number);
    void AddBot(T x);//добавить в начало
    void AddTop(T x);// добавить в конец
//    void AddBot1(extMotorcycle x);
//    void AddTop1(extMotorcycle mot1);
    void AddBot1(T x);


    void AddTop1(T mot1)
    {

         Node *temp=new Node;
         temp->prev=NULL;
    //     int i = mot1.getReleaseYear();
         temp->data = mot1;//new T(mot1.getType(), mot1.getCompany(), mot1.getModel(),mot1.getReleaseYear(), mot1.getVolume(), mot1.getPower(),  mot1.getKilometrage(), mot1.getPrice(), mot1.getNumberOfWheels());
    //     *(temp->data)=x;
         if (tail!=NULL)
         {
             temp->next=head;
             head->prev=temp;
             head=temp;
         }
         else
         {
             temp->next=NULL; //Предыдущий элемент указывает в пустоту
             tail=head=temp; //Голова=Хвост=тот элемент, что сейчас добавили
         }
    }

    string Get(string a);
    void Delete(string a);
    void DeleteList();
    string PrintList();
    string PrintListForFile();
    void Change(string a, string b);
//    int ReadFromFile(const char filename[]);
    bool SaveToFile (const char filename[]);

   T operator[](int i)
    {
        Node *temp = this->head;
        int count = 0;
        while (temp)
        {
            if (count == i)
            {
                return temp->data;
                break;
            }
            count++;
            temp = temp->next;
        }
        return this->head->data;

    }


//    friend LinkedList<T>& operator >> (T b2); //Добавление
//    friend LinkedList<T>& operator << (string str); //удаление

};

//#include <linkedlist.h>
//#include <sstream>
//#include <fstream>
//#include <iostream>
//#include <QDebug>
//using namespace std;

//void SHR(string &s,const int pos)
//{
//    for(int i=0;i<s.length();i++)
//    {
//        s[i]=s[i+pos];
//    }
//}

//template <class T>
//LinkedList<T>& LinkedList::operator >>(T b2)
//{
//    this->AddTop(b2);
//    return *this;
//}

//template <class T>
//LinkedList<T> & LinkedList::operator <<(string str)
//{
//    this->Delete(str);
//    return *this;
//}

//bool LinkedList::operator ==(const LinkedList &a) const
//{
//    if(amount==b2.amount)
//    {
//        int i;
//        for(i=0;list[i]==b2.list[i] || i<amount;i++);
//        if(i==amount) return true;
//    }
//    return false;
//}

template <typename T>
LinkedList<T> ::LinkedList(const LinkedList<T> &a)
{
    new LinkedList<T>;
    Node *temp = a.head;
    while (temp)
    {
        AddBot(temp->data);
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T>::LinkedList()
{
     head = NULL;
     tail = NULL;
}

template <typename T>
LinkedList<T> :: LinkedList(T a, T b, T c)
{
    head->data = a;
    tail->data = c;
    tail->prev->data = head->next->data = b;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
     while (head) //Пока по адресу на начало списка что-то есть
     {
         tail=head->next; //Резервная копия адреса следующего звена списка
         delete head; //Очистка памяти от первого звена
         head=tail; //Смена адреса начала на адрес следующего элемента
     }
}

template <typename T>
void LinkedList<T>::Delete(string x)
{
    Node *temp=head;

    int flag = 0;
    while (temp)
    {
        flag = 0;
//        Motorcycle* k = temp->data;
        if (temp->data->getCompany() == x)
        {
            if (temp == head)
            {
                flag = 1;
                head = head->next;
                if (head)
                {
                    head->prev = NULL;
                }
                if (head == NULL)
                    tail = NULL;
            }

            if (temp == tail)
            {
                flag = 1;
                tail = tail->prev;
                if (tail)
                    tail->next = NULL;
                if (tail == NULL)
                    head = NULL;
            }

            if (flag == 0)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

        }
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::DeleteList()
{
     while (head) //Пока по адресу на начало списка что-то есть
     {
         tail=head->next; //Резервная копия адреса следующего звена списка
         delete head; //Очистка памяти от первого звена
         head=tail; //Смена адреса начала на адрес следующего элемента
     }
}

template <typename T>
void LinkedList<T>::AddBot(T x)
{


//     Node *temp=new Node; //Выделение памяти под новый элемент структуры
    Node *temp=new Node; //Выделение памяти под новый элемент структуры
    temp->next=NULL;  //Указываем, что изначально по следующему адресу пусто
//    T mot = x;
    temp->data = x; //new T(x->getType(), x->getCompany(), x->getModel(), x->getVolume(), x->.getPower(), x->getReleaseYear(), x->getKilometrage(), x->getPrice());
     if (head!=NULL) //Если список не пуст
     {
         temp->prev=tail; //Указываем адрес на предыдущий элемент в соотв. поле
         tail->next=temp; //Указываем адрес следующего за хвостом элемента
         tail=temp; //Меняем адрес хвоста
     }
     else //Если список пустой
     {
         temp->prev=NULL; //Предыдущий элемент указывает в пустоту
         head=tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
     }
}

template <typename T>
void LinkedList<T>::AddBot1(T x)
{
     Node *temp=new Node; //Выделение памяти под новый элемент структуры
     temp->next=NULL;  //Указываем, что изначально по следующему адресу пусто
     temp->data = new T(x.getType(), x.getCompany(), x.getModel(), x.getReleaseYear(),x.getVolume(), x.getPower(),  x.getKilometrage(), x.getPrice(), x.getNumberOfWheels());//Записываем значение в структуру
     if (head!=NULL) //Если список не пуст
     {
         temp->prev=tail; //Указываем адрес на предыдущий элемент в соотв. поле
         tail->next=temp; //Указываем адрес следующего за хвостом элемента
         tail=temp; //Меняем адрес хвоста
     }
     else //Если список пустой
     {
         temp->prev=NULL; //Предыдущий элемент указывает в пустоту
         head=tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
     }
}

template <typename T>
void LinkedList<T>::AddTop(T x)
{
     Node *temp=new Node;
     temp->prev=NULL;
     T mot = x;
     temp->data = mot;//new T(x.getType(), x.getCompany(), x.getModel(), x.getReleaseYear(), x.getVolume(), x.getPower(), x.getKilometrage(), x.getPrice());
     if (tail!=NULL)
     {
         temp->next=head;
         head->prev=temp;
         head=temp;
     }
     else
     {
         temp->next=NULL; //Предыдущий элемент указывает в пустоту
         tail=head=temp; //Голова=Хвост=тот элемент, что сейчас добавили
     }
}

//template <class T>
//void LinkedList<T>::AddTop1(T mot1)
//{
//     Node *temp=new Node;
//     temp->prev=NULL;
////     int i = mot1.getReleaseYear();
//     temp->data = new T(mot1.getType(), mot1.getCompany(), mot1.getModel(),mot1.getReleaseYear(), mot1.getVolume(), mot1.getPower(),  mot1.getKilometrage(), mot1.getPrice(), mot1.getNumberOfWheels());
////     *(temp->data)=x;
//     if (tail!=NULL)
//     {
//         temp->next=head;
//         head->prev=temp;
//         head=temp;
//     }
//     else
//     {
//         temp->next=NULL; //Предыдущий элемент указывает в пустоту
//         tail=head=temp; //Голова=Хвост=тот элемент, что сейчас добавили
//     }
//}

template <typename T>
string LinkedList<T>::Get(string x)
{
//     LinkedList TempList;
//     Node *temp=tail;
//     int i= 0;
//     while (temp!=NULL)
//     {
//         Motorcycle* k = temp->data;
//         if (k->getCompany() == x)

//             TempList.AddTop(*(temp->data));

//         temp=temp->prev; //Указываем, что нужен адрес предыдущего элемента
//     }
//        return TempList.PrintList();
//    LinkedList TempList;
    Node *temp=head;
    string str= "";
    int a =1;
    while (temp!=NULL)
    {
        if (temp->data->getCompany() == x)
            str+="#" +QString::number(a).toStdString()+ " "+ temp->data->toStream() + "\n";
        temp=temp->next; //Указываем, что нужен адрес предыдущего элемента
    }
       return str;
}

template <typename T>
string LinkedList<T>::PrintList()
{
//    Node *temp=tail;
//    temp=head;
    Node *temp=head;
//    temp=head;
    int a = 0;
    string st = "";
    while (temp!=NULL)
    {
        QString str;
//        Motorcycle* k = temp->data;
        str = "#"+QString::number(a+1)+" " + QString::fromStdString(temp->data->toStream()) + "\n";//+ QString::fromStdString(k->getType())+" "+QString::fromStdString(k->getCompany()) + " " + QString::fromStdString(k->getModel()) +" " +  QString::number(k->getPrice()) + "\n" ;
        temp=temp->next;
        a++;
        st+= str.toLocal8Bit().constData();
    }
    return st;
}

template <typename T>
string LinkedList<T>::PrintListForFile()
{
//    Node *temp=tail;
//    temp=head;
    Node *temp=head;
//    temp=head;
    int a = 0;
    string st = "";
    while (temp!=NULL)
    {
        QString str;
//        Motorcycle* k = temp->data;
        str =QString::fromStdString(temp->data->toFileStream()) + "\n";//+ QString::fromStdString(k->getType())+" "+QString::fromStdString(k->getCompany()) + " " + QString::fromStdString(k->getModel()) +" " +  QString::number(k->getPrice()) + "\n" ;
        temp=temp->next;
        a++;
        st+= str.toLocal8Bit().constData();
    }
    return st;
}

template <typename T>
void LinkedList<T>::Change(string a, string b)
{
    Node *temp=head;
    while (temp)
    {
        if (temp->data->getCompany() == b)
        {
            temp->data->setCompany(a);
        }
        temp = temp->next;
    }
}


#endif // LINKEDLIST_H
