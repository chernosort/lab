#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <linkedlist.h>
#include <motorcycle.h>
#include <motorcycle_ext.h>
#include <QString>
#include <QMessageBox>
//#include <QListWidget>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushAddBottomButton->setEnabled(false);
    ui->pushAddTopButton->setEnabled(false);

    ui->comboBox->addItem("Motorcycles");
    ui->comboBox->addItem("Exotic");

    ui->spinBox->setRange(1,6);



    List = new LinkedList();
    *tact = 0;
//    *str = "";

    connect(ui->lineEdit_Type,   SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Company,SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Model,  SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Year,   SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Volume, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Power,  SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Mileage,SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Price,  SIGNAL(textChanged(QString)),this,SLOT(activateButton()));

    connect(ui->pushAddTopButton,SIGNAL(clicked()),this,SLOT(AddTopButton()));
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
    Motorcycle mot;

    mot.setType(ui->lineEdit_Type->text().toStdString());
    mot.setCompany(ui->lineEdit_Company->text().toStdString());
    mot.setKilometrage(ui->lineEdit_Mileage->text().toLong());
    mot.setModel(ui->lineEdit_Model->text().toStdString());
    mot.setPower(ui->lineEdit_Power->text().toInt());
    mot.setPrice(ui->lineEdit_Price->text().toLong());
    mot.setReleaseYear(ui->lineEdit_Year->text().toInt());
    mot.setVolume(ui->lineEdit_Volume->text().toInt());
    if (
                 //!(mot.setType(ui->lineEdit_Type->text().toStdString())) &&  !(mot.setCompany(ui->lineEdit_Company->text().toStdString())) && !(mot.setModel(ui->lineEdit_Model->text().toStdString()))&&
            !(mot.setKilometrage(ui->lineEdit_Mileage->text().toLong()))&&

            !(mot.setPower(ui->lineEdit_Power->text().toInt()))&&
            !(mot.setPrice(ui->lineEdit_Price->text().toLong())) &&
            !(mot.setReleaseYear(ui->lineEdit_Year->text().toInt())) &&
            !(mot.setVolume(ui->lineEdit_Volume->text().toInt()))
            )
    {
    List->AddTop(mot);
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(List->PrintList()));
    *tact += 1;
    }
    else {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"", "Something wrong, I can feel it!!");

    }
////    ui->textBrowser->append(QString::fromStdString(mot.getCompany())+"\n "
////                            + QString::fromStdString(mot.getModel())+" "
////                            + QString::number(mot.getReleaseYear()) +" "
////                            + QString::number(mot.getPrice()));
//    List->AddTop(mot);
//    ui->textBrowser->clear();
//    ui->textBrowser->append(QString::fromStdString(List->PrintList()));
//    *tact += 1;
////    ui->textBrowser->append(QString::number(*tact));
}

void MainWindow::AddBottomButton()
{

    Motorcycle mot;
    mot.setType(ui->lineEdit_Type->text().toStdString());
    mot.setCompany(ui->lineEdit_Company->text().toStdString());
    mot.setKilometrage(ui->lineEdit_Mileage->text().toLong());
    mot.setModel(ui->lineEdit_Model->text().toStdString());
    mot.setPower(ui->lineEdit_Power->text().toInt());
    mot.setPrice(ui->lineEdit_Price->text().toLong());
    mot.setReleaseYear(ui->lineEdit_Year->text().toInt());
    mot.setVolume(ui->lineEdit_Volume->text().toInt());
    if (
                 //!(mot.setType(ui->lineEdit_Type->text().toStdString())) &&  !(mot.setCompany(ui->lineEdit_Company->text().toStdString())) && !(mot.setModel(ui->lineEdit_Model->text().toStdString()))&&
            !(mot.setKilometrage(ui->lineEdit_Mileage->text().toLong()))&&

            !(mot.setPower(ui->lineEdit_Power->text().toInt()))&&
            !(mot.setPrice(ui->lineEdit_Price->text().toLong())) &&
            !(mot.setReleaseYear(ui->lineEdit_Year->text().toInt())) &&
            !(mot.setVolume(ui->lineEdit_Volume->text().toInt()))
            )
    {
    List->AddBot(mot);
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(List->PrintList()));
    *tact += 1;
    }
    else {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"", "Something is wrong");

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
    if ((*tact != 0) ){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"", "now the'll delete");
    if (reply == QMessageBox::Ok)
    {
        ui->textBrowser->clear();
        ui->textBrowser_2->clear();
        *tact = 0;
    }
    }

}


void MainWindow::Delete()
{
//    if ((*tact != 0) )
//    {
        List->Delete(ui->lineEdit_6->text().toStdString());
        ui->textBrowser->clear();
        ui->textBrowser->append(QString::fromStdString(List->PrintList()));
//        str += ui->lineEdit_6->text().toStdString();

//    }
}

//void MainWindow::on_pushAddTopButton_clicked()
//{

//}

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
