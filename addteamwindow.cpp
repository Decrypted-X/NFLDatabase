#include "addteamwindow.h"
#include "ui_addteamwindow.h"

AddTeamWindow::AddTeamWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTeamWindow)
{
    ui->setupUi(this);

    ui->statusMessage->setVisible(false);

    inputFile = new TeamsInputFile("C:/ProgramData/NFLDatabase/NFLDatabaseInput.dat");
}


AddTeamWindow::~AddTeamWindow()
{
    delete inputFile;
    delete ui;
}


void AddTeamWindow::resetInput()
{
    ui->teamNameInput->setStyleSheet("border-style: none;");
    ui->stadiumNameInput->setStyleSheet("border-style: none;");
    ui->seatingCapacityInput->setStyleSheet("border-style: none;");
    ui->locationInput->setStyleSheet("border-style: none;");
    ui->conferenceInput->setStyleSheet("border-style: none;");
    ui->divisionInput->setStyleSheet("border-style: none;");
    ui->surfaceTypeInput->setStyleSheet("border-style: none;");
    ui->stadiumRoofTypeInput->setStyleSheet("border-style: none;");
    ui->dateOpenedInput->setStyleSheet("border-style: none;");

    ui->teamNameInput->setText("");
    ui->stadiumNameInput->setText("");
    ui->seatingCapacityInput->setText("");
    ui->locationInput->setText("");
    ui->conferenceInput->setText("");
    ui->divisionInput->setText("");
    ui->surfaceTypeInput->setText("");
    ui->stadiumRoofTypeInput->setText("");
    ui->dateOpenedInput->setText("");

    ui->statusMessage->setVisible(false);
}


void AddTeamWindow::reject()
{
    resetInput();
    hide();
}


string AddTeamWindow::getValidStringProperty(QLineEdit* input)
{
    string property = input->text().toStdString();

    if (property.size() < 1)
    {
        if (!ui->statusMessage->isVisible())
        {
            ui->statusMessage->setText("Invalid input.");
            ui->statusMessage->setStyleSheet("color: red;");
            ui->statusMessage->setVisible(true);
        }

        input->setStyleSheet("border-style: solid; border-width: 1px; border-color: red;");
    }
    else
    {
        input->setStyleSheet("border-style: none;");
    }

    return property;
}


int AddTeamWindow::getValidIntProperty(QLineEdit* input)
{
    bool* isValidInput = new bool(true);
    int property = input->text().toInt(isValidInput);

    if (!*isValidInput)
    {
        if (!ui->statusMessage->isVisible())
        {
            ui->statusMessage->setText("Invalid input.");
            ui->statusMessage->setStyleSheet("color: red;");
            ui->statusMessage->setVisible(true);
        }

        input->setStyleSheet("border-style: solid; border-width: 1px; border-color: red;");
    }
    else
    {
        input->setStyleSheet("border-style: none;");
    }

    return property;
}


void AddTeamWindow::on_addTeamButton_clicked()
{
    ui->statusMessage->setVisible(false);
    ui->addTeamButton->setEnabled(false);

    string teamName        = getValidStringProperty(ui->teamNameInput);
    string stadiumName     = getValidStringProperty(ui->stadiumNameInput);
    int seatingCapacity    = getValidIntProperty(ui->seatingCapacityInput);
    string location        = getValidStringProperty(ui->locationInput);
    string conference      = getValidStringProperty(ui->conferenceInput);
    string division        = getValidStringProperty(ui->divisionInput);
    string surfaceType     = getValidStringProperty(ui->surfaceTypeInput);
    string stadiumRoofType = getValidStringProperty(ui->stadiumRoofTypeInput);
    int dateOpened         = getValidIntProperty(ui->dateOpenedInput);

    if (!ui->statusMessage->isVisible())
    {
        resetInput();

        ui->statusMessage->setText("Team added.");
        ui->statusMessage->setStyleSheet("color: green;");
        ui->statusMessage->setVisible(true);

        Team newTeam;
        newTeam.setTeam(teamName, stadiumName, seatingCapacity, location, conference,
                         division, surfaceType, stadiumRoofType, dateOpened);

        inputFile->addTeam(newTeam);
    }

    ui->addTeamButton->setEnabled(true);
}
