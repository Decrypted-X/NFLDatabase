#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TeamsInputFile inputFile(":/input/NFLDatabaseInput.dat");
    nfcTeams = inputFile.getTeams("National Football Conference");
    afcTeams = inputFile.getTeams("American Football Conference");

    displayTeams();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayTeams()
{

}


void MainWindow::updateTeams()
{
    delete nfcTeams;
    delete afcTeams;

    TeamsInputFile inputFile(":/input/NFLDatabaseInput.dat");
    nfcTeams = inputFile.getTeams("National Football Conference");
    afcTeams = inputFile.getTeams("American Football Conference");
}
