#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <linkedlist.h>
#include <motorcycle.h>
#include <motorcycle_ext.h>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <istream>
//#include <QListWidget>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int * tact = new int;
    ui->pushAddBottomButton->setEnabled(false);
    ui->pushAddTopButton->setEnabled(false);

    ui->comboBox->addItem("Motorcycles");
    ui->comboBox->addItem("Exotic");

    ui->spinBox->setRange(1,6);
    ui->pushAddBottomButton->setVisible(false);

//    List = new LinkedList();
//    List = new LinkedList<Motorcycle*>();
    List = new motolist();


    *tact = 0;
//    *str = "";
    ui->lineEdit_Year->setText("1996");
    ui->lineEdit_Year->setVisible(false);
    ui->label_3->setVisible(false);

    connect(ui->lineEdit_Type,   SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Company,SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Model,  SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Year,   SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Volume, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Power,  SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Mileage,SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Price,  SIGNAL(textChanged(QString)),this,SLOT(activateButton()));

    connect(ui->pushButton_2,       SIGNAL(clicked()),this,SLOT(SaveToFile()));
    connect(ui->pushAddTopButton,   SIGNAL(clicked()),this,SLOT(AddTopButton()));
    connect(ui->pushAddBottomButton,SIGNAL(clicked()),this,SLOT(AddBottomButton()));

    connect(ui->pushFindButton,SIGNAL(clicked()),this,SLOT(Searching()));
    connect(ui->pushDeleteButton,SIGNAL(clicked()),this,SLOT(Delete()));
    connect(ui->pushClearButton,SIGNAL(clicked()),this,SLOT(Clear()));


    QRegExp stringexp("[a-zA-Z ]{1,10}");
    ui->lineEdit_Type->setValidator(new QRegExpValidator(stringexp,this));
    ui->lineEdit_Company->setValidator(new QRegExpValidator(stringexp, this));
    ui->lineEdit_6->setValidator(new QRegExpValidator(stringexp, this));

    QRegExp modelexp ("[a-zA-Z0-9]{2,10}");
    ui->lineEdit_Model->setValidator(new QRegExpValidator(modelexp,this));

    QRegExp yearexp("[1-9]([0-9]{1,4})");
    ui->lineEdit_Year->setValidator(new QRegExpValidator(yearexp,this));

    QRegExp volumeexp("[1-9]([0-9]{1,4})");
    ui->lineEdit_Volume->setValidator(new QRegExpValidator(volumeexp,this));

    QRegExp powerexp("[0-9]{1,3}");
    ui->lineEdit_Power->setValidator(new QRegExpValidator(powerexp,this));

    QRegExp mileageexp("[0-9]{1,7}");
    ui->lineEdit_Mileage->setValidator(new QRegExpValidator(mileageexp,this));

    QRegExp priceexp("[0-9]{1,7}");
    ui->lineEdit_Price->setValidator(new QRegExpValidator(priceexp,this));

//    ui->readfromfile->setVisible(false);
//    ui->pushAddBottomButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::activateButton()
{
    if(!(ui->lineEdit_Type->text().isEmpty())
            &&!(ui->lineEdit_Company->text().isEmpty())
            &&!(ui->lineEdit_Model->text().isEmpty())
            &&!(ui->lineEdit_Year->text().isEmpty())
            &&!(ui->lineEdit_Volume->text().isEmpty())
            &&!(ui->lineEdit_Power->text().isEmpty())
            &&!(ui->lineEdit_Mileage->text().isEmpty())
            &&!(ui->lineEdit_Price->text().isEmpty()))
    {
        ui->pushAddTopButton->setEnabled(true);
        ui->pushAddBottomButton->setEnabled(true);
    }
    else
    {
        ui->pushAddBottomButton->setEnabled(false);
        ui->pushAddTopButton->setEnabled(false);
    }
}


void MainWindow::AddTopButton()
{


    if (ui->comboBox->currentText() == "Motorcycles")
    {//changed . to ->
        Motorcycle* mot = new Motorcycle;
        mot->setType(ui->lineEdit_Type->text().toStdString());
        mot->setCompany(ui->lineEdit_Company->text().toStdString());
        mot->setKilometrage(ui->lineEdit_Mileage->text().toLong());
        mot->setModel(ui->lineEdit_Model->text().toStdString());
        mot->setPower(ui->lineEdit_Power->text().toInt());
        mot->setPrice(ui->lineEdit_Price->text().toLong());
        mot->setReleaseYear(ui->lineEdit_Year->text().toInt());
        mot->setVolume(ui->lineEdit_Volume->text().toInt());

        if ( !(mot->setKilometrage(ui->lineEdit_Mileage->text().toLong()))&&
             !(mot->setPower(ui->lineEdit_Power->text().toInt()))&&
             !(mot->setPrice(ui->lineEdit_Price->text().toLong())) &&
             !(mot->setReleaseYear(ui->lineEdit_Year->text().toInt())) &&
             !(mot->setVolume(ui->lineEdit_Volume->text().toInt()))
           )
        {
            List->AddTop(mot);
            ui->textBrowser->clear();
            ui->textBrowser->append(QString::fromStdString(List->PrintList()));
            *tact += 1;
        }
        else {
            QMessageBox::question(this,"", "Incorrect data!!"); //QMessageBox::StandardButton reply =

        }
    }

    if (ui->comboBox->currentText() == "Exotic")
    {
        extMotorcycle* mot1 = new extMotorcycle;
        mot1->setNumberOfWheels(ui->spinBox->value());
        mot1->setType(ui->lineEdit_Type->text().toStdString());
        mot1->setCompany(ui->lineEdit_Company->text().toStdString());
        mot1->setKilometrage(ui->lineEdit_Mileage->text().toLong());
        mot1->setModel(ui->lineEdit_Model->text().toStdString());
        mot1->setPower(ui->lineEdit_Power->text().toInt());
        mot1->setPrice(ui->lineEdit_Price->text().toLong());
        mot1->setReleaseYear(ui->lineEdit_Year->text().toInt());
        mot1->setVolume(ui->lineEdit_Volume->text().toInt());

        if ( !(mot1->setKilometrage(ui->lineEdit_Mileage->text().toLong()))&&
             !(mot1->setPower(ui->lineEdit_Power->text().toInt()))&&
             !(mot1->setPrice(ui->lineEdit_Price->text().toLong())) &&
             !(mot1->setReleaseYear(ui->lineEdit_Year->text().toInt())) &&
             !(mot1->setVolume(ui->lineEdit_Volume->text().toInt())) &&
             !(mot1->setNumberOfWheels(ui->spinBox->value()))
           )
        {
            List->AddTop(mot1);
            ui->textBrowser->clear();
            ui->textBrowser->append(QString::fromStdString(List->PrintList()));
            *tact += 1;
        }
        else {
             QMessageBox::question(this,"", "Incorrect data!!");

        }
    }
}

void MainWindow::AddBottomButton()
{

    if (ui->comboBox->currentText() == "Motorcycles")
    {
        Motorcycle* mot;
        mot->setType(ui->lineEdit_Type->text().toStdString());
        mot->setCompany(ui->lineEdit_Company->text().toStdString());
        mot->setKilometrage(ui->lineEdit_Mileage->text().toLong());
        mot->setModel(ui->lineEdit_Model->text().toStdString());
        mot->setPower(ui->lineEdit_Power->text().toInt());
        mot->setPrice(ui->lineEdit_Price->text().toLong());
        mot->setReleaseYear(ui->lineEdit_Year->text().toInt());
        mot->setVolume(ui->lineEdit_Volume->text().toInt());

        if ( !(mot->setKilometrage(ui->lineEdit_Mileage->text().toLong()))&&
             !(mot->setPower(ui->lineEdit_Power->text().toInt()))&&
             !(mot->setPrice(ui->lineEdit_Price->text().toLong())) &&
             !(mot->setReleaseYear(ui->lineEdit_Year->text().toInt())) &&
             !(mot->setVolume(ui->lineEdit_Volume->text().toInt()))
           )
        {
            List->AddBot(mot);
            ui->textBrowser->clear();
            ui->textBrowser->append(QString::fromStdString(List->PrintList()));
            *tact += 1;
        }
        else {
             QMessageBox::question(this,"", "Incorrect data!!");

        }
    }

    if (ui->comboBox->currentText() == "Exotic")
    {
        extMotorcycle* mot1;
        mot1->setNumberOfWheels(ui->spinBox->value());
        mot1->setType(ui->lineEdit_Type->text().toStdString());
        mot1->setCompany(ui->lineEdit_Company->text().toStdString());
        mot1->setKilometrage(ui->lineEdit_Mileage->text().toLong());
        mot1->setModel(ui->lineEdit_Model->text().toStdString());
        mot1->setPower(ui->lineEdit_Power->text().toInt());
        mot1->setPrice(ui->lineEdit_Price->text().toLong());
        mot1->setReleaseYear(ui->lineEdit_Year->text().toInt());
        mot1->setVolume(ui->lineEdit_Volume->text().toInt());

        if ( !(mot1->setKilometrage(ui->lineEdit_Mileage->text().toLong()))&&
             !(mot1->setPower(ui->lineEdit_Power->text().toInt()))&&
             !(mot1->setPrice(ui->lineEdit_Price->text().toLong())) &&
             !(mot1->setReleaseYear(ui->lineEdit_Year->text().toInt())) &&
             !(mot1->setVolume(ui->lineEdit_Volume->text().toInt())) &&
             !(mot1->setNumberOfWheels(ui->spinBox->value()))
           )
        {
            List->AddBot(mot1);
            ui->textBrowser->clear();
            ui->textBrowser->append(QString::fromStdString(List->PrintList()));
            *tact += 1;
        }
        else {
             QMessageBox::question(this,"", "Incorrect data!!");

        }
    }
}


void MainWindow::Searching()
{
    ui->textBrowser_2->clear();
    if (*tact != 0 && (str.find(ui->lineEdit_6->text().toStdString()) > 0)){
        ui->textBrowser_2->clear();
        ui->textBrowser_2->append(QString::fromStdString(List->Get(ui->lineEdit_6->text().toStdString())));
    }

}

void MainWindow::Clear()
{
    if ((*tact != 0) )
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"", "now the'll delete");
        if (reply == QMessageBox::Ok)
        {
            List->DeleteList();
            ui->textBrowser->clear();
            ui->textBrowser_2->clear();
            *tact = 0;
        }
    }

}


void MainWindow::Delete()
{
    List->Delete(ui->lineEdit_6->text().toStdString());
        ui->textBrowser->clear();
        ui->textBrowser->append(QString::fromStdString(List->PrintList()));
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->spinBox->setValue(2);
    if (ui->comboBox->currentText() == "Motorcycles")
    {
        ui->spinBox->setVisible(false);
        ui->label_10->setVisible(false);
    }
    if (ui->comboBox->currentText() == "Exotic")
    {
        ui->spinBox->setVisible(true);
        ui->label_10->setVisible(true);
    }
}

void MainWindow::on_readfromfile_clicked()
{

        int amount_readed;
        QString fileName = QFileDialog::getOpenFileName(this,"Open file","C:\\","Motorcycles(*.mot)");
        if (fileName!="")
        {
            amount_readed=ReadFromFile(fileName.toStdString().c_str()); //чтение файла

            //вывод сообщения, что файл прочитан
            QString s = "<a style=color:#007900>File opened " +QString::number(amount_readed);
            QMessageBox::information(this,"Success",s+" notes!</a>",QMessageBox::Ok);
//            Refresh();
        }
        else QMessageBox::information(this,"Failure","Empty filename",QMessageBox::Ok);
}


void MainWindow::SaveToFile()
{
    //Запрашивает имя сохраняемого файла у пользователя
    QString fileName = QFileDialog::getSaveFileName(this,"Save to file","C:\\","Motorcycles(*.mot)");
    if (fileName=="")
    {
        //Сообщение при пустом имени файла
        QMessageBox::information(this,"Failure","File was not saved",QMessageBox::Ok);
    }
    else
    {
        //сохранение в файл
        bool flag = SaveListToFile(fileName.toStdString().c_str());
        if(flag)
        {
            //Вывод сообщения, что файл успешно сохранён
            QString s = "<a style=color:#007900>file \""+fileName+"\" Success!";
            QMessageBox::information(this,"Success",s,QMessageBox::Ok);
        }
        else QMessageBox::critical(this,"Failure","An error acquired",QMessageBox::Ok);
    }
}


bool MainWindow::SaveListToFile(const char filename[])
{
    ofstream fout; //Файловый поток вывода
    fout.open(filename, ios::out | ios::trunc); //открытие файла на чтение + перезапись файла, если уже существует
    if(fout)
    {
//        for(int i = 0; i < amount; i++)
//        {
            fout << List->PrintListForFile();
        //}
        fout.close();
        return true;
    }
    else
        return false;
}


int MainWindow::ReadFromFile(const char filename[])
{

    /*Формат хранения информации в файле:
    type
    company
    model
    cm3
    hp
    year
    kilometrage
    price
     */
    //пустые строки не допускаются и могут приводить к сохранению пустых записей

    string type, company, model ;
    char sign[900], t[900], c[900],m[900];
    int cm3,hp,year,NumberOfWheels;
    long kilometrage, price;
    int num=0;
    ifstream fin; //Файловый поток вывода
    fin.open(filename, ios::in); //Открытие потока на запись
    if(fin)
    {
        int k = 0;
        while(!fin.eof() )//&& k<100 )//пока не дошли до конца файла
        {
            type=company=model="";
            cm3=hp=kilometrage=price=NumberOfWheels=0;
            year=1990;
            sign[0]=t[0]=c[0]=m[0]='\0';
            fin >> sign;
//            fin >> t; type =t;  //type = t; //читаем первую строку записи
            if (sign[0]=='<' && sign[1]=='<' && sign[2]=='>') //если это есть идентификатор "<<>" то читаем как расширенную запись
            {
//                SHR(type, 3);
                fin >> t; type = t;
                fin >> c;  company=c;
                fin >> m;  model=m;
//                fin >> year;
                fin >> cm3;
                fin >> hp;
                fin >>kilometrage;
                fin >>price;
                fin >>NumberOfWheels;
            }
            else  //если нет идентификатора - запись обычная
            {

                fin >> t; type = t;
                fin >> c; company=c;
                fin >> m; model=m;
//                fin >>year
                fin >>cm3>>hp>>kilometrage>>price;
                NumberOfWheels=0;

            }
            AddNew(type, company, model,year, cm3, hp, kilometrage, price, NumberOfWheels);
            k++;
            num++;
            *tact++;
        }
    }
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(List->PrintList()));
    return num-1;
}


void MainWindow::AddNew(string Type, string Company, string Model, int ReleaseYear, int Cm3, int HP, long Kilometrage, long Price, int Number)
{
    if(Number == 0 && Price!=0)
    {
        //записываем полученные данные
        Motorcycle *temp = new Motorcycle( Type, Company, Model,ReleaseYear, Cm3, HP,  Kilometrage, Price);
        List->AddBot(temp);//add to list

    }
    if (Price != 0 && Number != 0)
    {
        extMotorcycle *temp1 = new extMotorcycle( Type, Company, Model,ReleaseYear, Cm3, HP,  Kilometrage, Price,Number);
//        List->AddBot(*temp);//add to list
        List->AddBot(temp1);//add to list
//        ui->textBrowser->append(QString::fromStdString(List->PrintList()));

    }
}

//template <typename T1, typename T2>
//T2 MainWindow::Summarize(T1 a, T2 b)
//{
//    T2 mot1 = new T2;
//    mot1->setNumberOfWheels(2);
//    mot1->setType(a.getType() + b.getType());
//    mot1->setCompany(a.getCompany() + b.getCompany());
//    mot1->setKilometrage(a.getKilometrage()+ b.getKilometrage());
//    mot1->setModel(a.getModel() + b.getModel());
//    mot1->setPower(a.getPower()+b.getPower());
//    mot1->setPrice(a.getPrice()+b.getPrice());
//    mot1->setReleaseYear(a.getReleaseYear());
//    mot1->setVolume(a.getVolume()+b.getVolume());
//    return mot1;
//}

extMotorcycle MainWindow::Summarize(Motorcycle a, extMotorcycle b)
{
    extMotorcycle mot1;
    mot1.setNumberOfWheels(2);
    mot1.setType(a.getType() + b.getType());
    mot1.setCompany(a.getCompany() + b.getCompany());
    mot1.setKilometrage(a.getKilometrage()+ b.getKilometrage());
    mot1.setModel(a.getModel() + b.getModel());
    mot1.setPower(a.getPower()+b.getPower());
    mot1.setPrice(a.getPrice()+b.getPrice());
    mot1.setReleaseYear(a.getReleaseYear());
    mot1.setVolume(a.getVolume()+b.getVolume());
    return mot1;
}

void MainWindow::SHR(string &s,const int pos)
{
    for(unsigned int i=0;i<s.length();i++)
    {
        s[i]=s[i+pos];
    }
}



void MainWindow::on_pushButton_clicked()
{
    List->Change(ui->lineEdit_6->text().toStdString(), ui->lineEdit_Company->text().toStdString());
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(List->PrintList()));
}

void MainWindow::on_pushButton_3_clicked()
{
//    mot1 = new Motorcycle
    Motorcycle* mot1 = new Motorcycle;
    mot1->setData("scuter", "honda", "dio", 1990, 50, 15, 70000, 20000);
    Motorcycle* mot2 = new Motorcycle;
    mot2->setData("racing", "yamaha", "r1", 2010, 990, 200, 300000, 5000);
    ui->operatorstext->append("first two motos");
    ui->operatorstext->append(QString::fromStdString(mot1->toStream()));
    ui->operatorstext->append(QString::fromStdString(mot2->toStream()));
    Motorcycle mot3;
    ui->operatorstext->append("third moto default");
    ui->operatorstext->append(QString::fromStdString(mot3.toStream()));
    mot3 = *mot2;
    ui->operatorstext->append("mot3 = mot2");
    ui->operatorstext->append(QString::fromStdString(mot3.toStream()));
//    LinkedList List;
//    LinkedList<Motorcycle*> List;
    motolist List;
    List.AddBot(mot1);
    List.AddBot(mot2);

    ui->operatorstext->append("mot1 > mot2");
    if (mot1 > mot2)
        ui->operatorstext->append("true");
    else
        ui->operatorstext->append("false");

    ui->operatorstext->append("mot1 < mot2");
    if (mot1 < mot2)
        ui->operatorstext->append("true");
    else
        ui->operatorstext->append("false");

    ui->operatorstext->append("mot1 >= mot2");
    if (mot1 >= mot2)
        ui->operatorstext->append("true");
    else
        ui->operatorstext->append("false");

    ui->operatorstext->append("mot2+mot1");

    Motorcycle mot8= ((*mot1)+(*mot2));
    ui->operatorstext->append(QString::fromStdString(mot8.toStream()));
//    ui->operatorstext->append(QString::number((*mot2)+(*mot1)));
    ui->operatorstext->append("mot2-mot1");
    mot8 = *mot2 - *mot1;
    ui->operatorstext->append(QString::fromStdString(mot8.toStream()));
    mot8 = (*mot2)*(*mot1);
    ui->operatorstext->append("mot2*mot1");
    ui->operatorstext->append(QString::fromStdString(mot8.toStream()));

    for(int l = 0; l < 5; l++)
         (*mot1)++;
    ui->operatorstext->append(QString::fromStdString(mot1->toStream()));

    for(int l; l<7; l++)
        ++(*mot1);
    ui->operatorstext->append(QString::fromStdString(mot1->toStream()));

    ui->operatorstext->append("set price 25");
    Motorcycle mot7 = *mot1;
    mot7(25);
    ui->operatorstext->append(QString::fromStdString(mot1->toStream()));

    Motorcycle* mot4 = List[1];
    ui->operatorstext->append("mot 4 = list 1");
    ui->operatorstext->append(QString::fromStdString(mot4->toStream()));

//    List >> mot4;
//    ui->operatorstext->append("List append mot 4");
//    ui->operatorstext->append(QString::fromStdString(List.PrintList()));
//    List << "honda";
//    ui->operatorstext->append("List delete honda");
//    ui->operatorstext->append(QString::fromStdString(List.PrintList()));

    ui->operatorstext->append("mot operator <<");
    string str = "";
    str<<mot4;
    ui->operatorstext->append(QString::fromStdString(str));
    ui->operatorstext->append("mot operator >>");
//    string str1 = "scuterbiatch honda dio 50 10 1985 70000 20000";
//    istringstream str2(str1);
    string str2 ="hell";
    str2 >> mot4;
    ui->operatorstext->append(QString::fromStdString(mot4->toStream()));
    ui->operatorstext->append("mot4: ");
    ui->operatorstext->append(QString::fromStdString(mot4->toStream()));
    extMotorcycle mot5("scooter", "suzuki", "jog", 1980, 125, 12, 1234, 12345, 2);
    ui->operatorstext->append("mot5: ");
    ui->operatorstext->append(QString::fromStdString(mot5.toStream()));

    mot8 =(* mot1)+(*mot2);
    ui->operatorstext->append("mot1 + mot2: ");
    ui->operatorstext->append(QString::fromStdString(mot8.toStream()));

//    extMotorcycle mot6 = Summarize(*mot4, mot5);
//    ui->operatorstext->append("mot4 + mot5: ");
//    ui->operatorstext->append(QString::fromStdString(mot6.toStream()));

}
