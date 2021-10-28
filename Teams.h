/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The teams class stores a list of team objects that represents all the teams
 * in the NFL Database.
 */

#include <stdexcept>
#include "Team.h"

#ifndef TEAMS_H
#define TEAMS_H

class Teams
{
public:
    /**
     * Constructor that sets private data members according to parameters and
     * initializes a team dynamic array with a size of teamAmount.
     *
     * @param teamAmount is the amount of teams that will be stored in the Teams
     *        object and represents the amount of teams in the database.
     */
    Teams(int teamAmount);

    /**
     * Destructor that deletes all team objects in the teams dynamic array and
     * the teams dynamic array.
     */
    ~Teams();

    /**
     * Get the amount of teams stored in the Teams object.
     *
     * @return An integer that represents the amount of teams stored in the
     *         Teams object.
     */
    int getTeamAmount() const;

    /**
     * Set the private data memebers of a team object at the index in the teams
     * dynamic array according to the parameters passed.
     *
     * @param index is the index of the team object in the teams dynamic array.
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
    void setTeam(int index, string teamName, string stadiumName,
                int seatingCapacity, string location, string conference,
                string division, string surfaceType, string stadiumRoofType,
                int dateOpened);

    /**
     * Get the Team object stored at the index in the teams dynamic array.
     *
     * @param index is the index of the team object in the teams dynamic array.
     * @return A pointer to a Team object that is stored in the teams dynamic
     *         array.
     */
    Team* getTeam(int index) const;
private:
    /// An integer that holds the amount of teams stored in the teams dynamic
    /// array.
    int teamAmount;

    /// A dynamic array of Team objects that represents the teams stored in the
    /// NFL Database.
    Team** teams;
};

#endif
