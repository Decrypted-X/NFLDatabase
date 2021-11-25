// mainwindow.cpp  -  Class Implementation

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Main Window Data Members:
//     Ui::MainWindow *ui;
//     HelpWindow* helpWindow;
//     ContactUsWindow* contactUsWindow;
//     LoginWindow* loginWindow;
//     TeamsInputFile* inputFile;
//     Teams* nfcTeams;
//     Teams* afcTeams;


// The main window constructor that sets private data memebrs according to parameters,
// fetches data from the input file, and configures default values for the user interface.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // creates a teams input file object with a path to the input file and maintenance input file
    inputFile = new TeamsInputFile(":/input/NFLDatabaseInput.dat",
                                   "C:/ProgramData/NFLDatabase/NFLAdditionalInput.dat");

    // gets teams objects for the nfc and the afc and stores them in the nfcTeams and afcTeams
    // pointers respectively
    nfcTeams = inputFile->getTeams("National Football Conference");
    afcTeams = inputFile->getTeams("American Football Conference");

    // hides the capacity labels until the user decides to view the total capacity
    ui->totalLabel->setVisible(false);
    ui->totalAmountLabel->setVisible(false);

    // initializes the helpWindow, contactUsWindow, and loginWindow pointers to null
    helpWindow = NULL;
    contactUsWindow = NULL;
    loginWindow = NULL;

    displayTeams();

    // sorts teams by team name
    ui->displayTable->sortItems(0, Qt::AscendingOrder);
}


// The main window destructor that deletes items in the data display table, windows opened by the
// main window, the input file object, teams objects, and all ui components relying on the main
// window object.
MainWindow::~MainWindow()
{
    // deletes each item displayed in the data display table
    for (int r = 0; r < ui->displayTable->rowCount(); r++)
    {
        for (int c = 0; c < ui->displayTable->columnCount(); c++)
        {
            delete ui->displayTable->item(r, c);
        }
    }

    delete helpWindow;
    delete contactUsWindow;
    delete loginWindow;
    delete inputFile;
    delete nfcTeams;
    delete afcTeams;
    delete ui;
}


// The function displays the team passed on the data display table at the row passed to the
// function.
void MainWindow::displayTeam(int row, Team* team)
{
    // temporarily holds data that is going to be displayed on the data display table
    QTableWidgetItem* tempItem;

    // displays the name of the team
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getTeamName()));
    ui->displayTable->setItem(row, 0, tempItem);

    // displays the stadium name
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getStadiumName()));
    ui->displayTable->setItem(row, 1, tempItem);

    // holds an unformatted seating capacity
    QString seatingCapacity = QString::number(team->getSeatingCapacity());

    // used to hold a formatted seating capacity in the format of #,###
    QString formattedSeatingCapacity;

    // holds the amount of digits in the seating capacity
    int digitCount = 1;

    // creates the formatted seating capacity and assigns it to formattedSeatingCapcity by
    // adding commas after every 3 digits
    for (int i = seatingCapacity.length() - 1; i >= 0; i--, digitCount++)
    {
        // adds another digit to the front of the formatted seating capacity text
        formattedSeatingCapacity.prepend(seatingCapacity[i]);

        // if there has been 3 digits and there are still more digits remaining, add a comma
        // to the front of the formatted seating capacity text
        if (digitCount % 3 == 0 && i - 1 >= 0)
        {
            formattedSeatingCapacity.prepend(',');
        }
    }

    // displays the formatted seating capacity
    tempItem = new QTableWidgetItem(formattedSeatingCapacity);
    tempItem->setTextAlignment(Qt::AlignCenter);
    ui->displayTable->setItem(row, 2, tempItem);

    // displays the location of the stadium
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getLocation()));
    ui->displayTable->setItem(row, 3, tempItem);

    // displays the conference of the team
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getConference()));
    ui->displayTable->setItem(row, 4, tempItem);

    // displays the division of the team
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getDivision()));
    ui->displayTable->setItem(row, 5, tempItem);

    // displays the surface type of the field of the stadium
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getSurfaceType()));
    ui->displayTable->setItem(row, 6, tempItem);

    // displays the roof type of the stadium
    tempItem = new QTableWidgetItem(QString::fromStdString(team->getStadiumRoofType()));
    ui->displayTable->setItem(row, 7, tempItem);

    // displays the date the stadium opened
    tempItem = new QTableWidgetItem(QString::number(team->getDateOpened()));
    tempItem->setTextAlignment(Qt::AlignCenter);
    ui->displayTable->setItem(row, 8, tempItem);
}


// The function displays all the teams in the nfc or afc depending on which is selected on the
// drop down by the user.
void MainWindow::displayTeams()
{
    int teamAmount;

    // deletes all data currently displayed on the data display table
    for (int r = 0; r < ui->displayTable->rowCount(); r++)
    {
        for (int c = 0; c < ui->displayTable->columnCount(); c++)
        {
            delete ui->displayTable->item(r, c);
        }
    }

    // Index 0 - National Football Conference
    // Index 1 - American Football Conference
    // if the nfc is selected on the conferenceSelect object, then display all the teams in the nfc
    // otherwise display all the teams in the afc
    if (ui->conferenceSelect->currentIndex() == 0)
    {
        // get the amount of teams in the nfc
        teamAmount = nfcTeams->getTeamAmount();

        // set the number of rows to the amount of teams in the nfc
        ui->displayTable->setRowCount(teamAmount);

        // display all the teams in the nfc teams
        for (int i = 0; i < teamAmount; i++)
        {
            displayTeam(i, nfcTeams->getTeam(i));
        }
    }
    else
    {
        // get the amount of teams in the afc
        teamAmount = afcTeams->getTeamAmount();

        // set the number of rows to the amount of teams in the afc
        ui->displayTable->setRowCount(teamAmount);

        // display all the teams in the afc teams
        for (int i = 0; i < teamAmount; i++)
        {
            displayTeam(i, afcTeams->getTeam(i));
        }
    }

    // resize all the columns to fit to the data displayed in them
    ui->displayTable->resizeColumnsToContents();
}


// The function gets input from the inputFile object and resets the data stored in the nfcTeams
// object and afcTeams object.
void MainWindow::updateTeams()
{
    // deletes the old nfcTeams and afcTeams
    delete nfcTeams;
    delete afcTeams;

    // gets updated nfcTeams and afcTeams objects from data in the input file
    nfcTeams = inputFile->getTeams("National Football Conference");
    afcTeams = inputFile->getTeams("American Football Conference");
}


// The function is called when the user selects a new conference. It updates the sort drop down based
// on the conference selected, and calls the displayTeams function.
void MainWindow::on_conferenceSelect_currentTextChanged()
{
    // Index 0 - National Football Conference
    // Index 1 - American Football Conference
    // if the nfc is selected on the conferenceSelect object, then show the options to sort by team
    //     name, stadium name, seating capacity, or location
    // otherwise show the options to sort by team name
    if (ui->conferenceSelect->currentIndex() == 0)
    {
        ui->sortSelect->setMaxCount(4);
        ui->sortSelect->addItem("Stadium Name");
        ui->sortSelect->addItem("Seating Capacity");
        ui->sortSelect->addItem("Location");
    }
    else
    {
        ui->sortSelect->setMaxCount(1);
    }

    displayTeams();

    // sorts teams by team name
    ui->displayTable->sortItems(0, Qt::AscendingOrder);
}

// The function is called when the user selects sorting method. It updates the sort drop down based
// on the conference selected, and calls the displayTeams function.
void MainWindow::on_sortSelect_currentTextChanged()
{
    // Index 0 - Team Name
    // Index 1 - Stadium Name
    // Index 2 - Seating Capacity
    // Index 3 - Location
    switch (ui->sortSelect->currentIndex())
    {
    case 0:
        ui->displayTable->sortItems(0, Qt::AscendingOrder);
        break;
    case 1:
         ui->displayTable->sortItems(1, Qt::AscendingOrder);
         break;
    case 2:
        ui->displayTable->sortItems(2, Qt::DescendingOrder);
        break;
    case 3:
        ui->displayTable->sortItems(3, Qt::AscendingOrder);
        break;
    }
}


// The function is called when the user clicks the help button. It creates and displays a help window to
// the user.
void MainWindow::on_actionHelp_triggered()
{
    // if the help window is not initialized, then create a new help window
    if (!helpWindow)
    {
        helpWindow = new HelpWindow(this);
    }

    // if the help window is not visible, then show the help window
    if (!helpWindow->isVisible())
    {
        helpWindow->show();
    }
}


// The function is called when the user clicks the contact us button. It creates and displays a contact us
// window to the user.
void MainWindow::on_actionContact_Us_triggered()
{
    // if the contact us window is not initialized, then create a new contact us window
    if (!contactUsWindow)
    {
        contactUsWindow = new ContactUsWindow(this);
    }

    // if the contact us window is not visible, then show the contact us window
    if (!contactUsWindow->isVisible())
    {
        contactUsWindow->show();
    }
}


// The function is called when the user clicks the maintenance button. It creates and displays a log in
// page to the user that is used to get to the maintenance page.
void MainWindow::on_actionLoginWin_triggered()
{
    // if the login window is not initialized, then create a new login window
    if (!loginWindow)
    {
        loginWindow = new LoginWindow(this);
    }

    // if the login window is not visible, then show the login window
    if (!loginWindow->isVisible())
    {
        loginWindow->show();
    }
}


// The function is called when the user toggles the display total select check
// box. It toggles whether or not to display the NFL total capacity.
void MainWindow::on_displayTotalSelect_stateChanged(int status)
{
    // 2 - display total is checked
    // 0 - display total is unchecked
    if (status == 2)
    {
        // integer used to store the total capacity of the nfl
        int total = 0;

        // loops through each spot in the nfc teams array and adds up the total capacity of
        // each stadium without including stadiums already accounted for
        for (int teamIndex = 0; teamIndex < nfcTeams->getTeamAmount(); teamIndex++)
        {
            // used to check if the stadium has been counted already
            bool isValidAddition = true;

            // loops through each previous spot in the nfc teams array to check if the stadium
            // of the current team has already been counted
            for (int i = teamIndex - 1; i >= 0; i--)
            {
                // checks if the stadium of the current team has already been counted for by a
                // previous team
                if (nfcTeams->getTeam(teamIndex)->getStadiumName().compare(
                            nfcTeams->getTeam(i)->getStadiumName()) == 0)
                {
                    // if stadium is already counted, make the addition invalid so it is not
                    // counted again
                    isValidAddition = false;
                    break;
                }
            }

            // if the stadium name has not been included already, then add the seating capacity
            // of the stadium to the total capacity of the nfl
            if (isValidAddition)
            {
                total += nfcTeams->getTeam(teamIndex)->getSeatingCapacity();
            }
        }

        // loops through each spot in the afc teams array and adds up the total capacity of
        // each stadium without including stadiums already accounted for
        for (int teamIndex = 0; teamIndex < afcTeams->getTeamAmount(); teamIndex++)
        {
            // used to check if the stadium has been counted already
            bool isValidAddition = true;

            // loops through each previous spot in the afc teams array to check if the stadium
            // of the current team has already been counted
            for (int i = teamIndex - 1; i >= 0; i--)
            {
                // checks if the stadium of the current team has already been counted for by a
                // previous team
                if (afcTeams->getTeam(teamIndex)->getStadiumName().compare(
                            afcTeams->getTeam(i)->getStadiumName()) == 0)
                {
                    // if stadium is already counted, make the addition invalid so it is not
                    // counted again
                    isValidAddition = false;
                    break;
                }
            }

            // if the stadium is valid, continue to check the nfc teams to ensure it has not been
            // counted for
            if (isValidAddition)
            {
                // checks the nfc teams compared to the current afc team to ensure the stadium has
                // not been counted already
                for (int i = 0; i < nfcTeams->getTeamAmount(); i++)
                {
                    // checks if the stadium of the current team has already been counted for
                    // by a team in the nfc
                    if (afcTeams->getTeam(teamIndex)->getStadiumName().compare(
                                nfcTeams->getTeam(i)->getStadiumName()) == 0)
                    {
                        // if stadium is already counted, make the addition invalid so it is not
                        // counted again
                        isValidAddition = false;
                        break;
                    }
                }

                // if the stadium name has not been included already, then add the seating capacity
                // of the stadium to the total capacity of the nfl
                if (isValidAddition)
                {
                    total += afcTeams->getTeam(teamIndex)->getSeatingCapacity();
                }
            }
        }

        // holds an unformatted total capacity
        QString totalCapacity = QString::number(total);

        // used to hold a formatted total capacity in the format of #,###
        QString formattedTotalCapacity;

        // holds the amount of digits in the total capacity
        int digitCount = 1;

        // creates the formatted total capacity and assigns it to formattedTotalCapcity by
        // adding commas after every 3 digits
        for (int i = totalCapacity.length() - 1; i >= 0; i--, digitCount++)
        {
            // adds another digit to the front of the formatted total capacity text
            formattedTotalCapacity.prepend(totalCapacity[i]);

            // if there has been 3 digits and there are still more digits remaining, add a comma
            // to the front of the formatted total capacity text
            if (digitCount % 3 == 0 && i - 1 >= 0)
            {
                formattedTotalCapacity.prepend(',');
            }
        }

        // sets total capacity to the label and makes it visible for the user to see
        ui->totalLabel->setVisible(true);
        ui->totalAmountLabel->setText(formattedTotalCapacity);
        ui->totalAmountLabel->setVisible(true);
    }
    else
    {
        // hides the total capacity of the nfl when the check box is unchecked
        ui->totalLabel->setVisible(false);
        ui->totalAmountLabel->setVisible(false);
    }
}


// The function is called when the user clicks the refresh table button. It refreshes the data stored in
// the private data member team objects, displays the updated teams, sorts the teams according to what
// option is selected, and updates the NFL total capacity.
void MainWindow::on_refreshTableButton_clicked()
{
    updateTeams();
    displayTeams();
    on_sortSelect_currentTextChanged();

    if (ui->displayTotalSelect->isChecked())
    {
        on_displayTotalSelect_stateChanged(2);
    }
    else
    {
        on_displayTotalSelect_stateChanged(0);
    }
}
