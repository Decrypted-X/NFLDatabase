#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TeamsInputFile* inputFile = new TeamsInputFile(":/input/NFLDatabaseInput.dat");
    nfcTeams = inputFile->getTeams("National Football Conference");
    afcTeams = inputFile->getTeams("American Football Conference");

    displayTeams();
}


MainWindow::~MainWindow()
{
    delete inputFile;
    delete nfcTeams;
    delete afcTeams;
    delete ui;
}


void MainWindow::displayTeams()
{

}


void MainWindow::updateTeams()
{
    delete nfcTeams;
    delete afcTeams;

    nfcTeams = inputFile->getTeams("National Football Conference");
    afcTeams = inputFile->getTeams("American Football Conference");
}
