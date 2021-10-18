// Team.h  -  Class Implementation

#include "Team.h"

// TODO Add data members here

// team constructor that sets private data memebers according to parameters
Team::Team(string teamName, string stadiumName, int seatingCapacity,
     string location, string conference, string division,
     string surfaceType, string stadiumRoofType, int dateOpened)
{
    this->teamName = teamName;
    this->stadiumName = stadiumName;
    this->seatingCapacity = seatingCapacity;
    this->location = location;
    this->conference = conference;
    this->division = division;
    this->surfaceType = surfaceType;
    this->stadiumRoofType = stadiumRoofType;
    this->dateOpened = dateOpened;
}

// team destructor
Team::~Team() {}

// returns the name of the team
string Team::getTeamName() const
{
    return teamName;
}

// returns the name of the stadium
string Team::getStadiumName() const
{
    return stadiumName;
}

// returns the seating capacity of the stadium
int Team::getSeatingCapacity() const
{
    return seatingCapacity;
}

// returns the location of the stadium
string Team::getLocation() const
{
    return location;
}

// returns the conference of the team
string Team::getConference() const
{
    return conference;
}

// returns the division of the team
string Team::getDivision() const
{
    return division;
}

// returns the surface type of the stadium
string Team::getSurfaceType() const
{
    return surfaceType;
}

// returns the roof type of the stadium
string Team::getStadiumRoofType() const
{
    return stadiumRoofType;
}

// returns the date the stadium opened
int Team::getDateOpened() const
{
    return dateOpened;
}
