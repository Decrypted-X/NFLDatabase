// InputFile.h  -  Class Specification

#include "Teams.h"
#include <iostream>
#include <fstream>

#ifndef TEAMSINPUTFILE_H
#define TEAMSINPUTFILE_H

class TeamsInputFile
{
public:
    // TeamsInputFile constructor that sets private data memebers according to parameters
    TeamsInputFile(string source);

    // assigns a dynamic array of teams with teams in the input file
    Teams* getTeams();
private:
    // the source of the input file
    string source;

    // the amount of characters that can be taken in input
    const int INPUT_SIZE = 10000;

    // the separator between each input column
    const char SEPARATOR = '|';
};

#endif
