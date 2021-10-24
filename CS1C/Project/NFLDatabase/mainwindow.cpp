#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    openFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile()
{
    QFile inputFile("C:/Users/Connor/Desktop/College Classes/CS1C/Project/NFLDatabase/NFLInformation.csv.csv");
    if (!inputFile.open(QFile::Text | QFile::ReadOnly))
    {
        return;
    }

    QTextStream inFile(&inputFile);


    int cter = 0;
    QString readLine = inFile.readLine();
    QStringList listValue = readLine.split(",");
    ui->tableWidget->setColumnCount(listValue.size());
    ui->tableWidget->setHorizontalHeaderLabels(listValue);

    while (!inFile.atEnd())
    {
           QString readLine = inFile.readLine();
           QStringList listValue = readLine.split(",");

           cter += 1;
           ui->tableWidget->setRowCount(cter);
            for (int i = 0; i < listValue.size(); i++)
            {
                ui -> tableWidget -> setItem(cter-1, i, new QTableWidgetItem(listValue[i]));
            }
           inputFile.flush();
           inputFile.close();
}
}

void MainWindow::on_sort_items_clicked()
{

   ui->tableWidget->selectColumn(3);
}

