// Teams.h  -  Class Specification

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

    // sets the team amount and adjusts the size of the teams list
    void setTeamAmount(int teamAmount);

    // returns the team amount
    int getTeamAmount() const;

    // sets a team at the specific index
    void setTeam(int index, Team* team);

    // increases the size of thie list and adds a team to the end of the teams list
    void addTeam(Team* team);

    // returns the team at the index in the teams list
    Team* getTeam(int index) const;

    // returns the list of teams
    Team** getTeams() const;
private:
    int    teamAmount;
    Team** teams;
};

#endif
