#include "TeamsInputFile.h"

// TeamsInputFile constructor that sets private data memebers according to parameters
TeamsInputFile::TeamsInputFile(QString source)
{
    this->source = source;
}

// gets an input from the file
string TeamsInputFile::getInputFromFile(QFile& inputFile)
{
    string input = "";
    char* inputChar = new char;

    while(inputFile.getChar(inputChar) && !inputFile.atEnd() && *inputChar != DELIMITER
          && *inputChar != '\n')
    {
        input += *inputChar;
    }

    delete inputChar;

    return input;
}

// getTeams function that assigns a dynamic array of teams with teams in the input file
Teams* TeamsInputFile::getTeams()
{
    Teams* teams;
    QFile inputFile(source);

    if (inputFile.open(QIODevice::ReadOnly))
    {
        int teamAmount = 0;
        int currentTeam = 0;

        while (!inputFile.atEnd())
        {
            inputFile.readLine();
            teamAmount++;
        }

        teams = new Teams(teamAmount);

        inputFile.seek(0);

        while (!inputFile.atEnd() && currentTeam < teamAmount)
        {
            string teamName = getInputFromFile(inputFile);

            string stadiumName = getInputFromFile(inputFile);

            int seatingCapacity = stoi(getInputFromFile(inputFile));

            string location = getInputFromFile(inputFile);

            string conference = getInputFromFile(inputFile);

            string division = getInputFromFile(inputFile);

            string surfaceType = getInputFromFile(inputFile);

            string stadiumRoofType = getInputFromFile(inputFile);

            int dateOpened = stoi(getInputFromFile(inputFile));

            teams->setTeam(currentTeam++, teamName, stadiumName, seatingCapacity, location,
                           conference, division, surfaceType, stadiumRoofType, dateOpened);
        }

        inputFile.close();

        // testing input
        for (int i = 0; i < teams->getTeamAmount(); i++)
        {
            Team* team = teams->getTeam(i);

            cout << team->getTeamName()        << " | "
                 << team->getStadiumName()     << " | "
                 << team->getSeatingCapacity() << " | "
                 << team->getLocation()        << " | "
                 << team->getConference()      << " | "
                 << team->getDivision()        << " | "
                 << team->getSurfaceType()     << " | "
                 << team->getStadiumRoofType() << " | "
                 << team->getDateOpened()      << endl;
        }
    }
    else
    {
        cout << "Input file is unable to open.\n";
        exit(1);
    }

    return teams;
}
