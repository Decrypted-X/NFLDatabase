// Teams.cpp  -  Class Implementation

#include "Teams.h"

// Teams Data Members:
//     int    teamAmount;
//     Team** teams;


// The teams constructor that sets team amount according to parameters and
// initializes the dynamic teams array with default teams.
Teams::Teams(int teamAmount)
{
    this->teamAmount = teamAmount;

    teams = new Team*[teamAmount];

    // fills the teams dynamic array with default teams
    for (int i = 0; i < teamAmount; i++)
    {
        teams[i] = new Team();
    }
}


// The team destructor eletes each team in the teams dynamic array and then
// deletes the teams dynamic array.
Teams::~Teams()
{
    // deletes all the teams in the teams dynamic array
    for (int i = 0; i < teamAmount; i++)
    {
        delete teams[i];
    }

    delete [] teams;
}


// The function returns the amount of teams in the teams dynamic array.
int Teams::getTeamAmount() const
{
    return teamAmount;
}


// The function sets a team's private data members at the specific index according
// to parameters.
void Teams::setTeam(int index, string teamName, string stadiumName,
                    int seatingCapacity, string location, string conference,
                    string division, string surfaceType, string stadiumRoofType,
                    int dateOpened)
{
    teams[index]->setTeam(teamName, stadiumName, seatingCapacity, location,
                          conference, division, surfaceType, stadiumRoofType,
                          dateOpened);
}


// The function returns the team at the index in the teams dynamic array or throws
// an exception if the index is out of bounds.
Team* Teams::getTeam(int index) const
{
    if (index >= teamAmount || index < 0)
    {
        throw std::out_of_range("Out of range of the teams array.");
    }

    return teams[index];
}
