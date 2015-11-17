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

private:
    Ui::MainWindow *ui;
    LinkedList *List;
    int *tact;
    string str;
};

#endif // MAINWINDOW_H
