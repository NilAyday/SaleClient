#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include<QTableWidget>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])

{
     QApplication a(argc, argv);
    QTableWidget tableWidget;
    tableWidget.setRowCount(50);
    tableWidget.setColumnCount(5);
    tableWidget.setAlternatingRowColors(true);
    tableWidget.setSortingEnabled(true);
    QStringList header;
    header << "Ürün Kayıtları";

    string line;
    QStringList hlabels;
    hlabels << "Ürün Adedi" << "Ürün Adı" << "Ürün Fiyatı" << "Ürün KDVsi" << "Ürün Barkodu";
    tableWidget.setHorizontalHeaderLabels(hlabels);
    tableWidget.setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget.setSelectionBehavior(QAbstractItemView::SelectRows);
    char data[500][100];
    ifstream myfile ("C:\\SaleClient\\serverLog.txt");




      if (myfile.is_open())
      {

for(int i=0;i<500;i++){
            myfile >> data[i];

          cout << data[i]<< '\n';
           QTableWidgetItem *item1= new QTableWidgetItem;
           tableWidget.setItem(0,i,item1);
           QString line2 = QString::fromStdString(data[i]);
           item1->setText(line2);
item1=NULL;
}
        myfile.close();

      }




      tableWidget.show();
    return a.exec();




}
