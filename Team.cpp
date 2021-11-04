// Team.cpp  -  Class Implementation

#include "Team.h"

// Team Data Members:
//     string teamName;
//     string stadiumName;
//     int seatingCapacity;
//     string location;
//     string conference;
//     string division;
//     string surfaceType;
//     string stadiumRoofType;
//     int dateOpened;


// The team constructor that sets private data memebers to default
// values.
Team::Team()
{
    teamName        = "";
    stadiumName     = "";
    seatingCapacity = 0;
    location        = "";
    conference      = "";
    division        = "";
    surfaceType     = "";
    stadiumRoofType = "";
    dateOpened      = 0;
}


// The team destructor.
Team::~Team() {};


// The function sets the private data members according to parameters.
void Team::setTeam(string teamName, string stadiumName, int seatingCapacity,
             string location, string conference, string division,
             string surfaceType, string stadiumRoofType, int dateOpened)
{
    this->teamName        = teamName;
    this->stadiumName     = stadiumName;
    this->seatingCapacity = seatingCapacity;
    this->location        = location;
    this->conference      = conference;
    this->division        = division;
    this->surfaceType     = surfaceType;
    this->stadiumRoofType = stadiumRoofType;
    this->dateOpened      = dateOpened;
}


// The function returns the name of the team.
string Team::getTeamName() const
{
    return teamName;
}


// The function returns the name of the stadium.
string Team::getStadiumName() const
{
    return stadiumName;
}


// The function returns the seating capacity of the stadium.
int Team::getSeatingCapacity() const
{
    return seatingCapacity;
}


// The function returns the location of the stadium.
string Team::getLocation() const
{
    return location;
}


// The function returns the conference of the team
string Team::getConference() const
{
    return conference;
}


// The function returns the division of the team
string Team::getDivision() const
{
    return division;
}


// The function returns the surface type of the stadium.
string Team::getSurfaceType() const
{
    return surfaceType;
}


// The function returns the roof type of the stadium.
string Team::getStadiumRoofType() const
{
    return stadiumRoofType;
}


// The function returns the date the stadium opened.
int Team::getDateOpened() const
{
    return dateOpened;
}
