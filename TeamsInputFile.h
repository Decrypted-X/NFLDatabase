// InputFile.h  -  Class Specification

#include "Teams.h"
#include <iostream>
#include "QFile"

#ifndef TEAMSINPUTFILE_H
#define TEAMSINPUTFILE_H

class TeamsInputFile
{
public:
    // TeamsInputFile constructor that sets private data memebers according to parameters
    TeamsInputFile(QString source);

    // assigns a dynamic array of teams with teams in the input file
    Teams* getTeams();
private:
    string getInputFromFile(QFile& inputFile);

    // the source of the input file
    QString source;

    // the separator between each input column
    const char DELIMITER = '|';
};

#endif
