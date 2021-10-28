/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The teams input file class handles input taken from the NFL Database Input
 * file.
 */

#include "Teams.h"
#include "QFile"
#include <iostream>

#ifndef TEAMSINPUTFILE_H
#define TEAMSINPUTFILE_H

class TeamsInputFile
{
public:
    /**
     * Constructor that sets private data members according to parameters.
     *
     * @param source is the path to the NFL Database Input file that will be
     *        used by the TeamsInputFile class.
     */
    TeamsInputFile(QString source);

    /**
     * Get a pointer to a Teams object that holds all the teams that are
     * in the conference specified by the parameter and stored in the NFL
     * Database Input file.
     *
     * @param conference is the conference of the teams that will be retrieved
     *        by the function.
     * @return A pointer to a Teams object that holds all the teams in a
     *         conference stored in the database file.
     */
    Teams* getTeams(string conference);
private:
    /**
     * Get an input value from the input file that is at the source path. Input
     * stops when a delimiter or a newline character is found, or the function
     * has reached the end of the file.
     *
     * @param inputFile is an open input file that input will be extracted from.
     * @return A string object that holds input that was taken from the inputFile
     *         passed.
     */
    string getInputFromFile(QFile& inputFile);

    /// A QString object that holds the path to the NFL Database Input file that
    /// is used in member functions.
    QString source;

    /// A delimiter that is used in functions to determine where to stop reading
    /// when taking in input.
    const char DELIMITER = '|';
};

#endif
