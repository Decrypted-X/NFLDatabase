/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The main window class handles functions that change data or elements that are
 * displayed to the user interface and the ability to open other windows. The main
 * window class also holds the data that is needed to be displayed on the screen in
 * private data members.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TeamsInputFile.h"
#include "helpwindow.h"
#include "contactuswindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Constructor that sets private data members according to parameters, fetches data from the
     * NFL Database Input file, and configures default values for the main window user interface.
     *
     * @param parent is the parent of the main window object that will delete the object if the
     *        parent is deleted.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * Destructor that deletes all teams objects, teams input file object, data being
     * displayed on the data display table, and other user interface components and windows
     * that are children of the main window object.
     */
    ~MainWindow();

    /**
     * Display the teams in the National Football Conference or American Football Conference
     * on the data display table depending on which conference is selected in the drop down.
     */
    void displayTeams();

    /**
     * Update the teams lists with teams from the NFL Database Input file.
     */
    void updateTeams();

private slots:
    /**
     * When the user changes the conference they want to be displayed, the function is called to
     * display the list of teams the user wants and changes sorting options depending on which
     * conference they want to see.
     */
    void on_conferenceSelect_currentTextChanged();

    /**
     * When the user clicks the help button in the menu bar, the function is called to open the
     * help window and display it to the user.
     */
    void on_actionHelp_triggered();

    /**
     * When the user clicks the contact us button in the menu bar, the function is called to open
     * the contact us window and display it to the user.
     */
    void on_actionContact_Us_triggered();

private:
    /**
     * Display the data of one team in a row in the data display table that is given by the
     * parameters.
     *
     * @param row is a row in the data display table in which a team's data will be displayed.
     * @param team is the team that holds data that will be displayed in a row in the data display
     *        table.
     */
    void displayTeam(int row, Team* team);

    /// A pointer that handles all user interface components for the main window class.
    Ui::MainWindow *ui;

    /// A pointer to a help window object that is created and displayed when the user clicks the
    /// help button.
    HelpWindow* helpWindow;

    /// A pointer to a contact us window object that is created and displayed when the user clicks
    /// the contact us button.
    ContactUsWindow* contactUsWindow;

    /// A pointer to a teams input file object that is used to get data from the NFL Database Input
    /// file and store it in a teams object.
    TeamsInputFile* inputFile;

    /// A pointer to a teams object that stores all the National Football Conference teams from the
    /// NFL Database Input file.
    Teams* nfcTeams;

    /// A pointer to a teams object that stores all the American Football Conference teams from the
    /// NFL Databse Input file.
    Teams* afcTeams;
};
#endif // MAINWINDOW_H
