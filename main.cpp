#include "mainwindow.h"

// Testing
#include "TeamsInputFile.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Testing
    TeamsInputFile input(":/input/NFLDatabaseInput.dat");
    Teams* teams = input.getTeams();

    delete teams;


    return a.exec();
}
