// Teams.cpp  -  Class Implementation

#include "Teams.h"

// teams constructor that sets private data memebers according to parameters
Teams::Teams(int teamAmount)
{

}

// teams destructor
Teams::~Teams()
{

}

// sets the team amount and adjusts the size of the teams list
void Teams::setTeamAmount(int teamAmount)
{

}

// returns the team amount
int Teams::getTeamAmount() const
{

}

// sets a team at the specific index
void Teams::setTeam(int index, Team* team)
{

}

// increases the size of thie list and adds a team to the end of the teams list
void Teams::addTeam(Team* team)
{

}

// returns the team at the index in the teams list
Team* Teams::getTeam(int index) const
{
    if (index >= teamAmount || index < 0)
    {
        throw std::out_of_range("Out of range of the teams array.");
    }

    return teams[index];
}

// returns the list of teams
Team** Teams::getTeams() const
{
    return teams;
}
