#include "TeamsInputFile.h"

// TeamsInputFile constructor that sets private data memebers according to parameters
TeamsInputFile::TeamsInputFile(string source)
{
    this->source = source;
}

// getTeams function that assigns a dynamic array of teams with teams in the input file
Teams* TeamsInputFile::getTeams()
{
    Teams* teams;
    ifstream inputFile;

    inputFile.open(source);

    if (inputFile.is_open())
    {
        char* input = new char[INPUT_SIZE];
        int teamAmount = 0;
        int currentTeam = 0;

        while (!inputFile.eof())
        {
            inputFile.ignore(INPUT_SIZE, '\n');
            teamAmount++;
        }

        teams = new Teams(teamAmount);

        inputFile.seekg(inputFile.beg);

        while (!inputFile.eof() && currentTeam < teamAmount)
        {
            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string teamName = input;

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string stadiumName = input;

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            int seatingCapacity = atoi(input);

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string location = input;

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string conference = input;

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string division = input;

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string surfaceType = input;

            inputFile.getline(input, INPUT_SIZE, SEPARATOR);
            string stadiumRoofType = input;

            inputFile.getline(input, INPUT_SIZE, '\n');
            int dateOpened = atoi(input);

            teams->setTeam(currentTeam++, teamName, stadiumName, seatingCapacity, location,
                           conference, division, surfaceType, stadiumRoofType, dateOpened);
        }

        delete [] input;
        inputFile.close();
    }
    else
    {
        cout << "Input file is unable to open.\n";
        exit(1);
    }

    return teams;
}
