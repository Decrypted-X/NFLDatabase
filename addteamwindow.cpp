// addteamwindow.cpp  -  Class Implementation

#include "addteamwindow.h"
#include "ui_addteamwindow.h"

// Add Team Window Data Members:
//     Ui::AddTeamWindow *ui;
//     TeamsInputFile* inputFile;


// The add team window constructor sets private data memebrs according to parameters, sets up
// the user interface, and initalizes the teams input file object.
AddTeamWindow::AddTeamWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTeamWindow)
{
    ui->setupUi(this);

    // hides the status message label until the user enters invalid input or adds a team
    ui->statusMessage->setVisible(false);

    // creates a teams input file object with a path to the input file and maintenance input file
    inputFile = new TeamsInputFile(":/input/NFLDatabaseInput.dat",
                                   "C:/ProgramData/NFLDatabase/NFLAdditionalInput.dat");
}


// The add team window destructor deletes the teams input file private data member and all ui
// components relying on the add team window object.
AddTeamWindow::~AddTeamWindow()
{
    delete inputFile;
    delete ui;
}


// The function clears all input by the user, removes any highlighted red borders, and hides the
// status message label.
void AddTeamWindow::resetInput()
{
    // hides all highlighted red borders
    ui->teamNameInput->setStyleSheet("border-style: none;");
    ui->stadiumNameInput->setStyleSheet("border-style: none;");
    ui->seatingCapacityInput->setStyleSheet("border-style: none;");
    ui->locationInput->setStyleSheet("border-style: none;");
    ui->conferenceInput->setStyleSheet("border-style: none;");
    ui->divisionInput->setStyleSheet("border-style: none;");
    ui->surfaceTypeInput->setStyleSheet("border-style: none;");
    ui->stadiumRoofTypeInput->setStyleSheet("border-style: none;");
    ui->dateOpenedInput->setStyleSheet("border-style: none;");

    // clears all input from user
    ui->teamNameInput->setText("");
    ui->stadiumNameInput->setText("");
    ui->seatingCapacityInput->setText("");
    ui->locationInput->setText("");
    ui->conferenceInput->setText("");
    ui->divisionInput->setText("");
    ui->surfaceTypeInput->setText("");
    ui->stadiumRoofTypeInput->setText("");
    ui->dateOpenedInput->setText("");

    // hides status message label
    ui->statusMessage->setVisible(false);
}


// The function clears user input, highlighted red borders, the status message, and hides the
// dialog window.
void AddTeamWindow::reject()
{
    resetInput();
    hide();
}


// The function checks if a string property of a team is valid and returns the property. If invalid,
// the property input box is highlighted red and the status message displays invalid input.
string AddTeamWindow::getValidStringProperty(QLineEdit* input)
{
    // gets the string from the input box
    string property = input->text().toStdString();

    // if the string is empty, show that it is invalid; otherwise, hide the highlighted red box if it
    // is being shown
    if (property.size() < 1)
    {
        // displays the invalid status message if it is not already visible
        if (!ui->statusMessage->isVisible())
        {
            ui->statusMessage->setText("Invalid input.");
            ui->statusMessage->setStyleSheet("color: red;");
            ui->statusMessage->setVisible(true);
        }

        // highlights the border of the input box red
        input->setStyleSheet("border-style: solid; border-width: 1px; border-color: red;");
    }
    else
    {
        // removes the highlighted red border of the input box if it is visible
        input->setStyleSheet("border-style: none;");
    }

    return property;
}


// The function checks if an integer property of a team is valid and returns the property. If invalid,
// the property input box is highlighted red and the status message displays invalid input.
int AddTeamWindow::getValidIntProperty(QLineEdit* input)
{
    // initializes a boolean that holds whether the integer input is valid
    bool* isValidInput = new bool(true);

    // gets the integer from the input box
    int property = input->text().toInt(isValidInput);

    // if the integer is invalid, show that it is invalid; otherwise, hide the highlighted red box if it
    // is being shown
    if (!*isValidInput)
    {
        // displays the invalid status message if it is not already visible
        if (!ui->statusMessage->isVisible())
        {
            ui->statusMessage->setText("Invalid input.");
            ui->statusMessage->setStyleSheet("color: red;");
            ui->statusMessage->setVisible(true);
        }

        // highlights the border of the input box red
        input->setStyleSheet("border-style: solid; border-width: 1px; border-color: red;");
    }
    else
    {
        // removes the highlighted red border of the input box if it is visible
        input->setStyleSheet("border-style: none;");
    }

    return property;
}


// The function gathers all input from the user, checks if it is valid, and adds a team object
// to the database if the input is valid.
void AddTeamWindow::on_addTeamButton_clicked()
{
    // resets the status message and disables the add team button before getting input and
    // checking its validity
    ui->statusMessage->setVisible(false);
    ui->addTeamButton->setEnabled(false);

    // gets each property of the team object input by the user
    string teamName        = getValidStringProperty(ui->teamNameInput);
    string stadiumName     = getValidStringProperty(ui->stadiumNameInput);
    int seatingCapacity    = getValidIntProperty(ui->seatingCapacityInput);
    string location        = getValidStringProperty(ui->locationInput);
    string conference      = getValidStringProperty(ui->conferenceInput);
    string division        = getValidStringProperty(ui->divisionInput);
    string surfaceType     = getValidStringProperty(ui->surfaceTypeInput);
    string stadiumRoofType = getValidStringProperty(ui->stadiumRoofTypeInput);
    int dateOpened         = getValidIntProperty(ui->dateOpenedInput);

    // if the status message is not visible, then input is valid and the team can be added to
    // the database
    if (!ui->statusMessage->isVisible())
    {
        // resets the input given by the user, any highlighted red boxes, and the status message
        resetInput();

        // sets the status message to display that a team has been added to the database
        ui->statusMessage->setText("Team added.");
        ui->statusMessage->setStyleSheet("color: green;");
        ui->statusMessage->setVisible(true);

        // creates a new team with the properties that were input by the user
        Team newTeam;
        newTeam.setTeam(teamName, stadiumName, seatingCapacity, location, conference,
                         division, surfaceType, stadiumRoofType, dateOpened);

        // calls the add team function of the teams input file object to add the team to the
        // database
        inputFile->addTeam(newTeam);
    }

    // re-enables the add team button after processing the input
    ui->addTeamButton->setEnabled(true);
}
