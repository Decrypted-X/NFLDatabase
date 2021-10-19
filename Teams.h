// Teams.h  -  Class Specification

#include <stdexcept>
#include "Team.h"

#ifndef TEAMS_H
#define TEAMS_H

class Teams
{
public:
    // teams constructor that sets private data memebers according to parameters
    Teams(int teamAmount);

    // teams destructor
    ~Teams();

    // returns the team amount
    int getTeamAmount() const;

    // sets a team at the specific index according to parameters
    void setTeam(int index, string teamName, string stadiumName,
                int seatingCapacity, string location, string conference,
                string division, string surfaceType, string stadiumRoofType,
                int dateOpened);

    // returns the team at the index in the teams dynamic array
    Team* getTeam(int index) const;
private:
    int teamAmount;

    // teams dynamic array that holds all the teams in the database
    Team** teams;
};

#endif
