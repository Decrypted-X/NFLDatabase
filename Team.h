/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The team class represents one team that is stored in the NFL Database.
 */

#include <string>
using namespace std;

#ifndef TEAM_H
#define TEAM_H

class Team
{
public:
    /**
     * Default constructor that sets private data members to default values.
     */
    Team();

    /**
     * Set the private data members of the team according to parameters.
     *
     * @param teamName is the name of the team.
     * @param stadiumName is the name of the stadium.
     * @param seatingCapacity is the amount of people that can sit at the
     *        stadium.
     * @param location is the location of the stadium.
     * @param conference is the conference that the team is in.
     * @param division is the division that the team is in.
     * @param surfaceType is the type of surface on the field of the stadium.
     * @param stadiumRoofType is the type of roof of the stadium.
     * @param dateOpened is the date that the stadium opened.
     */
    void setTeam(string teamName, string stadiumName, int seatingCapacity,
                 string location, string conference, string division,
                 string surfaceType, string stadiumRoofType, int dateOpened);

    /**
     * Get the name of the team.
     *
     * @return A string object that holds the name of the team.
     */
    string getTeamName() const;

    /**
     * Get the name of the stadium.
     *
     * @return A string object that holds the name of the stadium.
     */
    string getStadiumName() const;

    /**
     * Get the amount of people that can sit at the stadium.
     *
     * @return An integer that holds the seating capacity of the stadium.
     */
    int getSeatingCapacity() const;

    /**
     * Get the location of the stadium.
     *
     * @return A string object that holds the location of the stadium.
     */
    string getLocation() const;

    /**
     * Get the conference of the team.
     *
     * @return A string object that holds the conference of the team.
     */
    string getConference() const;

    /**
     * Get the divison of the team.
     *
     * @return A string object that holds the division of the team.
     */
    string getDivision() const;

    /**
     * Get the type of surface on the field of the stadium.
     *
     * @return A string object that holds the surface type of the field in
     *         the stadium.
     */
    string getSurfaceType() const;

    /**
     * Get the type of roof of the stadium.
     *
     * @return A string object that holds the type of roof of the stadium.
     */
    string getStadiumRoofType() const;

    /**
     * Get the year that the stadium opened.
     *
     * @return A string object that holds the date the stadium opened.
     */
    int getDateOpened() const;
private:
    /// A string that holds the name of the team.
    string teamName;

    /// A string that holds the name of the stadium.
    string stadiumName;

    /// An integer that holds the amount of people that can sit at the stadium.
    int seatingCapacity;

    /// A string that holds the location of the stadium.
    string location;

    /// A string that holds the conference that the team is in.
    string conference;

    /// A string that holds the division that the team is in.
    string division;

    /// A string that holds the type of surface on the field of the stadium.
    string surfaceType;

    /// A string that holds the type of roof of the stadium.
    string stadiumRoofType;

    /// An integer that holds the date that the stadium opened.
    int dateOpened;
};

#endif
