#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sort_items_clicked()
{

   ui->tableWidget->selectColumn(3);
}


void MainWindow::on_ImportButton_clicked()
{

    QString filePath = QFileDialog::getOpenFileName(this, "Import CSV Files", QDir::rootPath(), "CSV Files (*csv)");
    QFile inputFile(filePath);
    qDebug() << filePath << " here is the path to your file for easy copy pasting when editing.";

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

