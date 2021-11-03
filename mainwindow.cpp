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

    ui->totalLabel->setVisible(false);
    ui->totalAmountLabel->setVisible(false);

    helpWindow = NULL;
    contactUsWindow = NULL;

    // TODO Sort by team name here for the nfc teams

    displayTeams();
}


MainWindow::~MainWindow()
{
    for (int r = 0; r < ui->displayTable->rowCount(); r++)
    {
        for (int c = 0; c < ui->displayTable->columnCount(); c++)
        {
            delete ui->displayTable->item(r, c);
        }
    }

    delete helpWindow;
    delete contactUsWindow;
    delete inputFile;
    delete nfcTeams;
    delete afcTeams;
    delete ui;
}


void MainWindow::displayTeam(int row, Team* team)
{
    QTableWidgetItem* tempItem;

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getTeamName()));
    ui->displayTable->setItem(row, 0, tempItem);

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getStadiumName()));
    ui->displayTable->setItem(row, 1, tempItem);

    QString seatingCapacity = QString::number(team->getSeatingCapacity());
    QString formattedSeatingCapacity;
    int digitCount = 1;

    for (int i = seatingCapacity.length() - 1; i >= 0; i--, digitCount++)
    {
        formattedSeatingCapacity.prepend(seatingCapacity[i]);

        if (digitCount % 3 == 0 && i - 1 >= 0)
        {
            formattedSeatingCapacity.prepend(',');
        }
    }

    tempItem = new QTableWidgetItem(formattedSeatingCapacity);
    tempItem->setTextAlignment(Qt::AlignCenter);
    ui->displayTable->setItem(row, 2, tempItem);

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getLocation()));
    ui->displayTable->setItem(row, 3, tempItem);

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getConference()));
    ui->displayTable->setItem(row, 4, tempItem);

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getDivision()));
    ui->displayTable->setItem(row, 5, tempItem);

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getSurfaceType()));
    ui->displayTable->setItem(row, 6, tempItem);

    tempItem = new QTableWidgetItem(QString::fromStdString(team->getStadiumRoofType()));
    ui->displayTable->setItem(row, 7, tempItem);

    tempItem = new QTableWidgetItem(QString::number(team->getDateOpened()));
    tempItem->setTextAlignment(Qt::AlignCenter);
    ui->displayTable->setItem(row, 8, tempItem);
}


void MainWindow::displayTeams()
{
    int teamAmount;

    for (int r = 0; r < ui->displayTable->rowCount(); r++)
    {
        for (int c = 0; c < ui->displayTable->columnCount(); c++)
        {
            delete ui->displayTable->item(r, c);
        }
    }

    // Index 0 - National Football Conference
    // Index 1 - American Football Conference
    if (ui->conferenceSelect->currentIndex() == 0)
    {
        teamAmount = nfcTeams->getTeamAmount();

        ui->displayTable->setRowCount(teamAmount);

        for (int i = 0; i < teamAmount; i++)
        {
            displayTeam(i, nfcTeams->getTeam(i));
        }
    }
    else
    {
        teamAmount = afcTeams->getTeamAmount();

        ui->displayTable->setRowCount(teamAmount);

        for (int i = 0; i < teamAmount; i++)
        {
            displayTeam(i, afcTeams->getTeam(i));
        }
    }

    ui->displayTable->resizeColumnsToContents();
}


void MainWindow::updateTeams()
{
    delete nfcTeams;
    delete afcTeams;

    nfcTeams = inputFile->getTeams("National Football Conference");
    afcTeams = inputFile->getTeams("American Football Conference");
}


void MainWindow::on_conferenceSelect_currentTextChanged()
{
    // Index 0 - National Football Conference
    // Index 1 - American Football Conference
    if (ui->conferenceSelect->currentIndex() == 0)
    {
        ui->sortSelect->setMaxCount(4);
        ui->sortSelect->addItem("Stadium Name");
        ui->sortSelect->addItem("Seating Capacity");
        ui->sortSelect->addItem("Location");

        ui->displayTotalSelect->setVisible(true);

        // TODO Sort by team name here for the nfc teams
    }
    else
    {
        ui->sortSelect->setMaxCount(1);

        ui->displayTotalSelect->setChecked(false);
        ui->displayTotalSelect->setVisible(false);

        // TODO Sort by team name here for the afc teams
    }

    displayTeams();
}


void MainWindow::on_actionHelp_triggered()
{
    if (!helpWindow)
    {
        helpWindow = new HelpWindow(this);
    }

    if (!helpWindow->isVisible())
    {
        helpWindow->show();
    }
}


void MainWindow::on_actionContact_Us_triggered()
{
    if (!contactUsWindow)
    {
        contactUsWindow = new ContactUsWindow(this);
    }

    if (!contactUsWindow->isVisible())
    {
        contactUsWindow->show();
    }
}

