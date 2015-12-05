#ifndef MAINWINDOW_H
#define MAINWINDOW_H
using namespace std;
#include <QMainWindow>
#include "linkedlist.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    typedef Motorcycle T1;
//    typedef extMotorcycle T2;


    
private slots:
    void activateButton();
    void AddTopButton();
    void AddBottomButton();
    void Searching();
    void Delete();
    void Clear();

//    void pushAddBottomButton(LinkedList);
//    void on_pushAddTopButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);
    bool SaveListToFile(const char filename[]);
    void SaveToFile();
    void on_readfromfile_clicked();
    void AddNew(string Type, string Company, string Model,int Cm3, int HP,int ReleaseYear, long Kilometrage, long Price, int Number);
    extMotorcycle Summarize(Motorcycle a, extMotorcycle b);

//    T2 Summarize(T1 a, T2 b);

    int ReadFromFile(const char filename[]);
    void SHR(string &s, const int pos);
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
//    LinkedList *List;
    typedef LinkedList<Motorcycle*> motolist;
    motolist *List;


    int *tact;
    string str;

};

#endif // MAINWINDOW_H
