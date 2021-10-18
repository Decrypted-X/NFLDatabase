// Team.h  -  Class Implementation

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

// Team Constructor
// The team constructor that sets private data memebers according to
// parameters.
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

// Team Destructor
Team::~Team() {}

// getTeamName Function
// The function returns the name of the team.
string Team::getTeamName() const
{
    return teamName;
}

// getStadiumName Function
// The function returns the name of the stadium.
string Team::getStadiumName() const
{
    return stadiumName;
}

// getSeatingCapacity Function
// The function returns the seating capacity of the stadium.
int Team::getSeatingCapacity() const
{
    return seatingCapacity;
}

// getLocation Function
// The function returns the location of the stadium.
string Team::getLocation() const
{
    return location;
}

// getConference Function
// The function returns the conference of the team
string Team::getConference() const
{
    return conference;
}

// getDivision Function
// The function returns the division of the team
string Team::getDivision() const
{
    return division;
}

// getSurfaceType Function
// The function returns the surface type of the stadium.
string Team::getSurfaceType() const
{
    return surfaceType;
}

// getStadiumRoofType Function
// The function returns the roof type of the stadium.
string Team::getStadiumRoofType() const
{
    return stadiumRoofType;
}

// getDateOpened Function
// The function returns the date the stadium opened.
int Team::getDateOpened() const
{
    return dateOpened;
}
