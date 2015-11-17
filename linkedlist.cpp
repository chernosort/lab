#include <linkedlist.h>
#include <sstream>
#include <fstream>
#include <iostream>
//#include <QString>
using namespace std;

void SHR(string &s,const int pos)
{
    for(int i=0;i<s.length();i++)
    {
        s[i]=s[i+pos];
    }
}

LinkedList ::LinkedList(const LinkedList &a)
{
    new LinkedList;
    Node *temp = a.head;
    while (temp)
    {
        AddBot(temp->data);
        temp = temp->next;
    }
}

LinkedList::LinkedList()
{
     head = NULL;
     tail = NULL;
}

LinkedList :: LinkedList(Motorcycle a, Motorcycle b, Motorcycle c)
{
    head->data = a;
    tail->data = c;
    tail->prev->data = head->next->data = b;
}

LinkedList::~LinkedList()
{
     while (head) //Пока по адресу на начало списка что-то есть
     {
         tail=head->next; //Резервная копия адреса следующего звена списка
         delete head; //Очистка памяти от первого звена
         head=tail; //Смена адреса начала на адрес следующего элемента
     }
}


void LinkedList::Delete(string x)
{
    Node *temp=head;
    int flag = 0;
    while (temp)
    {
        flag = 0;
        if (temp->data.getCompany() == x)
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

void LinkedList::DeleteList()
{
     while (head) //Пока по адресу на начало списка что-то есть
     {
         tail=head->next; //Резервная копия адреса следующего звена списка
         delete head; //Очистка памяти от первого звена
         head=tail; //Смена адреса начала на адрес следующего элемента
     }
}

//string LinkedList::Delete(string x)
//{
//     LinkedList TempList;
//     Node *temp=tail;
//     int i= 0;
//     while (temp!=NULL)
//     {
//         if (temp->data.getCompany() != x)

//             TempList.AddTop(temp->data);

//         temp=temp->prev; //Указываем, что нужен адрес предыдущего элемента
//     }
//        return TempList.PrintList();
//}

void LinkedList::AddBot(Motorcycle x)
{
     Node *temp=new Node; //Выделение памяти под новый элемент структуры
     temp->next=NULL;  //Указываем, что изначально по следующему адресу пусто
     temp->data=x;//Записываем значение в структуру
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

void LinkedList::AddBot(extMotorcycle x)
{
     Node *temp=new Node; //Выделение памяти под новый элемент структуры
     temp->next=NULL;  //Указываем, что изначально по следующему адресу пусто
     temp->data=x;//Записываем значение в структуру
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


void LinkedList::AddTop(Motorcycle x)
{
     Node *temp=new Node;
     temp->prev=NULL;
     temp->data=x;
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

void LinkedList::AddTop(extMotorcycle x)
{
     Node *temp=new Node;
     temp->prev=NULL;
     temp->data=x;
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

string LinkedList::Get(string x)
{
     LinkedList TempList;
     Node *temp=tail;
     int i= 0;
     while (temp!=NULL)
     {
         if (temp->data.getCompany() == x)

             TempList.AddTop(temp->data);

         temp=temp->prev; //Указываем, что нужен адрес предыдущего элемента
     }
        return TempList.PrintList();
}

string LinkedList::PrintList()
{
//    Node *temp=tail;
//    temp=head;
    Node *temp=head;
//    temp=head;
    int a = 0;
    string st = "";
    while (temp!=NULL)
    {
        string str;
        //а-ля to_string
        int i = temp->data.getPrice();

        string s;
        stringstream out;
        out << i;
        s = out.str();

        str = temp->data.getCompany() + " " + temp->data.getModel() +" " +  s + "\n" ; //" "  + temp->data.setReleaseYear() + " " + temp->data.getPrice() +
        st += str;
        temp=temp->next;
        a++;
    }
    return st;
}

int LinkedList::ReadFromFile(const char filename[])
{
    /*Формат хранения информации в файле:
    type = ' ';
    company = ' ';
    model = ' ';
    cm3 = 0;
    hp =  0;
    year = 0;
    kilometrage = 0;
    price = 0;
     */
    //пустые строки не допускаются и могут приводить к сохранению пустых записей

    string type, company, model ;//sender, recipient,bank;
    char t[90], c[90],m[90];
    int cm3,hp,year,NumberOfWheels;//income, expense, year, month, day,ID;
    long kilometrage, price;
    int num=0;

    ifstream fin; //Файловый поток вывода
    fin.open(filename, ios::in); //Открытие потока на запись

    if(fin)
    {
        while(!fin.eof())//пока не дошли до конца файла
        {
            type=company=model="";
            cm3=hp=year=kilometrage=price=NumberOfWheels=0;


            t[0]=c[0]=m[0]='\0';

            fin >> t; type =t; 
            if (t[0]=='<' && t[1]=='<' && t[2]=='>') 
            {
                SHR(type,3);
                fin >> c;  company=c;
                fin >> m;  model=m;
                fin >>cm3>>hp>>year>>kilometrage>>price>>NumberOfWheels;
            }
            else  //если нет идентификатора - запись обычная
            {

                fin >> t; type = t;
                fin >> c; company=c;
                fin >> m; model=m;
                fin >>cm3>>hp>>year>>kilometrage>>price; 
                NumberOfWheels=0;
            }
            
//            if(cm3 > 0 && cm3<=6000 ) //если получили нормальные данные - записываем их
//            {
//                
//            }
        }
    }
    return num;
}
