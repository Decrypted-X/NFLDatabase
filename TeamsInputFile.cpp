// Teams.cpp  -  Class Implementation

#include "TeamsInputFile.h"

// TeamsInputFile Data Members:
//     QString source;
//     const char DELIMITER = '|';


// The TeamsInputFile constructor that sets private data memebers according to parameters.
TeamsInputFile::TeamsInputFile(QString source)
{
    this->source = source;
}


// The function gets input from the file and stops when it reaches a delimiter, new character,
// or the end of the file and returns the input in a string object.
string TeamsInputFile::getInputFromFile(QFile& inputFile)
{
    // sets input string to an empty string and initializes inputChar
    string input = "";
    char* inputChar = new char;

    // if getting a character input from the file is a success, the input is not at the
    // end of the file, and the inputChar is not equal to the delimiter or the newline character,
    // then append the input character to the end of the input string and repeat
    while(inputFile.getChar(inputChar) && !inputFile.atEnd() && *inputChar != DELIMITER
          && *inputChar != '\n')
    {
        input += *inputChar;
    }

    // deletes the inputChar before the end of the function
    delete inputChar;

    return input;
}


// Function that assigns a dynamic array of teams with teams in the input file that
// are in the conference passed.
Teams* TeamsInputFile::getTeams(string conference)
{
    // declares a teams object and the inputFile
    Teams* teams;
    QFile inputFile(source);

    // opens the input file and if successful continue to get input from the file
    // otherwise, display input file could not be opened and close the application
    if (inputFile.open(QIODevice::ReadOnly))
    {
        // declares a teamAmount that will hold how many teams are in the input file
        int teamAmount = 0;

        // holds the index of the current team being put into the teams object
        int currentTeam = 0;

        // gets the amount of teams held in the input file that have the conference
        // passed
        while (!inputFile.atEnd())
        {
            // skips input for team name, stadium name, seating capacity, and location
            getInputFromFile(inputFile);
            getInputFromFile(inputFile);
            getInputFromFile(inputFile);
            getInputFromFile(inputFile);

            // gets the conference of the team
            string teamConference = getInputFromFile(inputFile);

            // if the team conference from the input file matches the conference passed
            // as a parameter, then increment the amount of teams
            if (teamConference == conference)
            {
                teamAmount++;
            }

            // skips remaining input for the team
            inputFile.readLine();
        }

        // creates a new teams object with the number of teams in the input file and
        // assigns it to the teams pointer
        teams = new Teams(teamAmount);

        // sets the input pointer back to the beginning of the file
        inputFile.seek(0);

        // continues to get input from the file until the end of the file has been
        // reached or the current team index has gone over the size of the teams
        // dynamic array
        while (!inputFile.atEnd() && currentTeam < teamAmount)
        {
            string teamName = getInputFromFile(inputFile);

            string stadiumName = getInputFromFile(inputFile);

            int seatingCapacity = stoi(getInputFromFile(inputFile));

            string location = getInputFromFile(inputFile);

            string teamConference = getInputFromFile(inputFile);

            // if the team conference from the input file matches the conference passed as a parameter,
            // then continue to get input for the team and put the team into a team object in the teams
            // object
            // otherwise, skip the rest of the input for this team and go to the next team in the input
            // file
            if (teamConference == conference)
            {
                string division = getInputFromFile(inputFile);

                string surfaceType = getInputFromFile(inputFile);

                string stadiumRoofType = getInputFromFile(inputFile);

                int dateOpened = stoi(getInputFromFile(inputFile));

                // sets the private data members of a team object in the dynamic array of teams
                // using data from the input file
                teams->setTeam(currentTeam++, teamName, stadiumName, seatingCapacity, location,
                               teamConference, division, surfaceType, stadiumRoofType, dateOpened);
            }
            else
            {
                // skips remaining input for the team
                inputFile.readLine();
            }
        }

        // closes the input file after getting input and putting it in the teams object
        inputFile.close();
    }
    else
    {
        cout << "Input file is unable to open.\n";
        exit(1);
    }

    return teams;
}
