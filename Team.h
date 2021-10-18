// Team.h  -  Class Specification

#include <string>
using namespace std;

#ifndef TEAM_H
#define TEAM_H

class Team
{
public:
    // team constructor that sets private data memebers according to parameters
    Team(string teamName, string stadiumName, int seatingCapacity,
         string location, string conference, string division,
         string surfaceType, string stadiumRoofType, int dateOpened);

    // team destructor
    ~Team();

    // returns the name of the team
    string getTeamName() const;

    // returns the name of the stadium
    string getStadiumName() const;

    // returns the seating capacity of the stadium
    int getSeatingCapacity() const;

    // returns the location of the stadium
    string getLocation() const;

    // returns the conference of the team
    string getConference() const;

    // returns the division of the team
    string getDivision() const;

    // returns the surface type of the stadium
    string getSurfaceType() const;

    // returns the roof type of the stadium
    string getStadiumRoofType() const;

    // returns the date the stadium opened
    int getDateOpened() const;
private:
    string teamName;
    string stadiumName;
    int    seatingCapacity;
    string location;
    string conference;
    string division;
    string surfaceType;
    string stadiumRoofType;
    int    dateOpened;
};

#endif
