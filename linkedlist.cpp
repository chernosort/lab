#include <linkedlist.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <QDebug>
using namespace std;

//void SHR(string &s,const int pos)
//{
//    for(int i=0;i<s.length();i++)
//    {
//        s[i]=s[i+pos];
//    }
//}

LinkedList ::LinkedList(const LinkedList &a)
{
    new LinkedList;
    Node *temp = a.head;
    while (temp)
    {
        AddBot(*(temp->data));
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
    *(head->data) = a;
    *(tail->data) = c;
    *(tail->prev->data) = *(head->next->data) = b;
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
        Motorcycle* k = temp->data;
        if (k->getCompany() == x)
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


void LinkedList::AddBot(Motorcycle x)
{
    qDebug() << "1";
//     Node *temp=new Node; //Выделение памяти под новый элемент структуры
    Node *temp=new Node; //Выделение памяти под новый элемент структуры
    qDebug() << "2";
    temp->next=NULL;  //Указываем, что изначально по следующему адресу пусто
    qDebug() << "3";
    temp->data = new Motorcycle(x.getType(), x.getCompany(), x.getModel(), x.getVolume(), x.getPower(), x.getReleaseYear(), x.getKilometrage(), x.getPrice());
    qDebug() << "31";
    qDebug() << "4";

     if (head!=NULL) //Если список не пуст
     {
         qDebug() << "5";
         temp->prev=tail; //Указываем адрес на предыдущий элемент в соотв. поле
         qDebug() << "6";
         tail->next=temp; //Указываем адрес следующего за хвостом элемента
         qDebug() << "7";
         tail=temp; //Меняем адрес хвоста
         qDebug() << "8";
     }
     else //Если список пустой
     {
         qDebug() << "9";
         temp->prev=NULL; //Предыдущий элемент указывает в пустоту
         qDebug() << "10";
         head=tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
     }
}

void LinkedList::AddBot(extMotorcycle x)
{
     Node *temp=new Node; //Выделение памяти под новый элемент структуры
     temp->next=NULL;  //Указываем, что изначально по следующему адресу пусто
     temp->data = new extMotorcycle(x.getType(), x.getCompany(), x.getModel(), x.getVolume(), x.getPower(), x.getReleaseYear(), x.getKilometrage(), x.getPrice(), x.getNumberOfWheels());//Записываем значение в структуру
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
     qDebug() << "1";
     temp->prev=NULL;
     qDebug() << "1";
     temp->data = new Motorcycle(x.getType(), x.getCompany(), x.getModel(), x.getVolume(), x.getPower(), x.getReleaseYear(), x.getKilometrage(), x.getPrice());
//     *(temp->data)=x;
     qDebug() << "1";
     if (tail!=NULL)
     {
         qDebug() << "1";
         temp->next=head;
         qDebug() << "1";
         head->prev=temp;
         qDebug() << "1";
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
     temp->data = new extMotorcycle(x.getType(), x.getCompany(), x.getModel(), x.getVolume(), x.getPower(), x.getReleaseYear(), x.getKilometrage(), x.getPrice(), x.getNumberOfWheels());
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

string LinkedList::Get(string x)
{
     LinkedList TempList;
     Node *temp=tail;
     int i= 0;
     while (temp!=NULL)
     {
         Motorcycle* k = temp->data;
         if (k->getCompany() == x)

             TempList.AddTop(*(temp->data));

         temp=temp->prev; //Указываем, что нужен адрес предыдущего элемента
     }
        return TempList.PrintList();
}

string LinkedList::PrintList()
{
//    Node *temp=tail;
//    temp=head;
    qDebug() << "1";
    Node *temp=head;
    qDebug() << "2";
//    temp=head;
    int a = 0;
    string st = "";
    while (temp!=NULL)
    {
        qDebug() << "3";
        QString str;
        Motorcycle* k = temp->data;
        qDebug() << "4";
        str = "#"+QString::number(a+1)+" " + QString::fromStdString(k->getType())+" "+QString::fromStdString(k->getCompany()) + " " + QString::fromStdString(k->getModel()) +" " +  QString::number(k->getPrice()) + "\n" ;
        qDebug() << "5";
        temp=temp->next;
        a++;
        st+= str.toLocal8Bit().constData();
        qDebug() << "6";
    }
    return st;
}

//int LinkedList::ReadFromFile(const char filename[])
//{
//    /*Формат хранения информации в файле:
//    type
//    company
//    model
//    cm3
//    hp
//    year
//    kilometrage
//    price
//     */
//    //пустые строки не допускаются и могут приводить к сохранению пустых записей

//    string type, company, model ;//sender, recipient,bank;
//    char t[90], c[90],m[90];
//    int cm3,hp,year,NumberOfWheels;//income, expense, year, month, day,ID;
//    long kilometrage, price;
//    int num=0;


//    ifstream fin; //Файловый поток вывода
//    fin.open(filename, ios::in); //Открытие потока на запись

//    if(fin)
//    {
//        while(!fin.eof())//пока не дошли до конца файла
//        {
//            type=company=model="";
//            cm3=hp=year=kilometrage=price=NumberOfWheels=0;

////            day=month=year=income=expense=ID=0; //Инициализация переменных
////            bank=sender=recipient="";
//            t[0]=c[0]=m[0]='\0';

//            fin >> t; type =t;  //sender=s; //читаем первую строку записи
//            if (t[0]=='<' && t[1]=='<' && t[2]=='>') //если это есть идентификатор "<<>" то читаем как расширенную запись
//            {
//                SHR(type,3);
//                fin >> c;  company=c;
//                fin >> m;  model=m;
//                fin >>cm3>>hp>>year>>kilometrage>>price>>NumberOfWheels;//income>>expense>>day>>month>>year>>ID;

//            }
//            else  //если нет идентификатора - запись обычная
//            {

//                fin >> t; type = t;
//                fin >> c; company=c;
//                fin >> m; model=m;
//                fin >>cm3>>hp>>year>>kilometrage>>price; //fin >>income>>expense>>day>>month>>year;
//                NumberOfWheels=0;
//            }
//            AddNew(type, company, model, cm3, hp, year,kilometrage, price, NumberOfWheels);
//        }
//    }
//    return num;
//}


//void LinkedList::AddNew(string Type, string Company, string Model,int Cm3, int HP,int ReleaseYear, long Kilometrage, long Price, int Number)
//{
//    if(Number == 0)
//    {
//        //записываем полученные данные
//        Motorcycle *temp = new Motorcycle( Type, Company, Model, Cm3, HP, ReleaseYear, Kilometrage, Price);
//        //add to list

//    }
//    else
//    {
//        extMotorcycle *temp = new extMotorcycle( Type, Company, Model, Cm3, HP, ReleaseYear, Kilometrage, Price,Number);
//        //add to list
//    }
//}


//bool LinkedList::SaveToFile(const char filename[])
//{
//    ofstream fout; //Файловый поток вывода
//    fout.open(filename, ios::out | ios::trunc); //открытие файла на чтение + перезапись файла, если уже существует
//    if(fout)
//    {
//        for(int i = 0; i < amount; i++)
//        {
//            fout << ();
//        }
//        fout.close();
//        return true;
//    }
//    else
//        return false;
//}



//        string str;
//        //а-ля to_string
//        Motorcycle* k =temp->data;
//        long i = *k->getPrice();
//        string s;
//        stringstream out;
//        out << i;
//        s = out.str();
//        str = temp->data->getCompany() + " " + temp->data->getModel() +" " +  s + "\n" ; //" "  + temp->data.setReleaseYear() + " " + temp->data.getPrice() +
//        st += str;

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
