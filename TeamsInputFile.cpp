// TeamsInputFile.cpp  -  Class Implementation

#include "TeamsInputFile.h"

// TeamsInputFile Data Members:
//     QString source;
//     QString additionalSource;
//     const char DELIMITER = '|';


// The TeamsInputFile constructor that sets private data memebers according to parameters.
TeamsInputFile::TeamsInputFile(QString source, QString additionalSource)
{
    inputFile.setFileName(source);
    additionalInputFile.setFileName(additionalSource);
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
    // declares a teams object
    Teams* teams;

    // opens the input file and if successful continue to get input from the file
    // otherwise, display input file could not be opened and close the application
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Input file is unable to open.\n";
        exit(1);
    }

    // if the additional input file exists, open the file
    // otherwise, make the file
    if (additionalInputFile.exists())
    {
        // opens the additional input file and if successful continue to get input from the file
        // otherwise, display additional input file could not be opened and close the application
        if (!additionalInputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            cout << "Additional input file is unable to open.\n";
            exit(1);
        }
    }
    else
    {
        // creates a NFLDatabase directory to store the additional database file if not created
        QDir dir;
        dir.mkdir("C:/ProgramData/NFLDatabase");

        // attempts to create and open a file
        // if unsuccessful, the application will close
        if (!additionalInputFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            cout << "Additional maintenance input file was not found and was unable to be created.\n";
            exit(1);
        }
    }

    // declares a teamAmount that will hold how many teams are in the input file
    int teamAmount = 0;

    // holds the index of the current team being put into the teams object
    int currentTeam = 0;

    // gets the amount of teams held in the input file that have the conference passed
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

    // gets the amount of teams held in the additional input file that have the conference passed
    while (!additionalInputFile.atEnd())
    {
        // skips input for team name, stadium name, seating capacity, and location
        getInputFromFile(additionalInputFile);
        getInputFromFile(additionalInputFile);
        getInputFromFile(additionalInputFile);
        getInputFromFile(additionalInputFile);

        // gets the conference of the team
        string teamConference = getInputFromFile(additionalInputFile);

        // if the team conference from the input file matches the conference passed
        // as a parameter, then increment the amount of teams
        if (teamConference == conference)
        {
            teamAmount++;
        }

        // skips remaining input for the team
        additionalInputFile.readLine();
    }

    // creates a new teams object with the number of teams in the input file and
    // assigns it to the teams pointer
    teams = new Teams(teamAmount);

    // sets the input pointer back to the beginning of the file
    inputFile.seek(0);

    // sets the additional input pointer back to the beginning of the file
    additionalInputFile.seek(0);

    // continues to get input from the input file until the end of the file has been reached or the
    // current team index has gone over the size of the teams dynamic array
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

    // continues to get input from the additional input file until the end of the file has been
    // reached or the current team index has gone over the size of the teams dynamic array
    while (!additionalInputFile.atEnd() && currentTeam < teamAmount)
    {
        string teamName = getInputFromFile(additionalInputFile);

        string stadiumName = getInputFromFile(additionalInputFile);

        int seatingCapacity = stoi(getInputFromFile(additionalInputFile));

        string location = getInputFromFile(additionalInputFile);

        string teamConference = getInputFromFile(additionalInputFile);

        // if the team conference from the input file matches the conference passed as a parameter,
        // then continue to get input for the team and put the team into a team object in the teams
        // object
        // otherwise, skip the rest of the input for this team and go to the next team in the input
        // file
        if (teamConference == conference)
        {
            string division = getInputFromFile(additionalInputFile);

            string surfaceType = getInputFromFile(additionalInputFile);

            string stadiumRoofType = getInputFromFile(additionalInputFile);

            int dateOpened = stoi(getInputFromFile(additionalInputFile));

            // sets the private data members of a team object in the dynamic array of teams
            // using data from the input file
            teams->setTeam(currentTeam++, teamName, stadiumName, seatingCapacity, location,
                           teamConference, division, surfaceType, stadiumRoofType, dateOpened);
        }
        else
        {
            // skips remaining input for the team
            additionalInputFile.readLine();
        }
    }

    // closes the input file and additional input file after getting input and putting it in the teams
    // object
    inputFile.close();
    additionalInputFile.close();

    return teams;
}


// Function that writes a string property of a team object to the input file passed by using the
// QTextStream object passed.
void TeamsInputFile::addTeamProperty(QFile& inputFile, QTextStream& output, string property, bool isLast)
{
    // writes the property to the file
    // writes a newline character if it is the last property of a team; otherwise, writes the delimiter
    output << property.c_str() << (isLast ? '\n' : DELIMITER);

    // flushes the output stream after writing to the file
    output.flush();
    inputFile.flush();
}


// Function that writes an integer property of a team object to the input file passed by using the
// QTextStream object passed.
void TeamsInputFile::addTeamProperty(QFile& inputFile, QTextStream& output, int property, bool isLast)
{
    // writes the property to the file
    // writes a newline character if it is the last property of a team; otherwise, writes the delimiter
    output << property << (isLast ? '\n' : DELIMITER);

    // flushes the output stream after writing to the file
    output.flush();
    inputFile.flush();
}


// Function that adds a new team object that is passed to the function to the end of the additional
// maintenance input file.
void TeamsInputFile::addTeam(Team& team)
{
    // open the additional input file to write
    // if fails, display that the file was unable to open and close the application
    if (additionalInputFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        // creates a QTextStream object that is used to write text to the end of the file
        QTextStream output(&additionalInputFile);
        // sets the encoding of the QTextStream object to UTF-8
        output.setEncoding(QStringConverter::Encoding::Utf8);

        // calls the addTeamProperty function for each property in the team object to write each team
        // property to the file
        addTeamProperty(additionalInputFile, output, team.getTeamName(), false);
        addTeamProperty(additionalInputFile, output, team.getStadiumName(), false);
        addTeamProperty(additionalInputFile, output, team.getSeatingCapacity(), false);
        addTeamProperty(additionalInputFile, output, team.getLocation(), false);
        addTeamProperty(additionalInputFile, output, team.getConference(), false);
        addTeamProperty(additionalInputFile, output, team.getDivision(), false);
        addTeamProperty(additionalInputFile, output, team.getSurfaceType(), false);
        addTeamProperty(additionalInputFile, output, team.getStadiumRoofType(), false);
        addTeamProperty(additionalInputFile, output, team.getDateOpened(), true);

        // closes the additional maintence input file after finished writing
        additionalInputFile.close();
    }
    else
    {
        cout << "The maintenance input file is unable to open.\n";
        exit(1);
    }
}
