/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The add team window class allows an authorized user to add a team to the
 * database.
 */

#ifndef ADDTEAMWINDOW_H
#define ADDTEAMWINDOW_H

#include "TeamsInputFile.h"
#include <QLineEdit>
#include <QDialog>
#include <string>

namespace Ui {
class AddTeamWindow;
}

class AddTeamWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructor that sets private data members according to parameters, sets UI
     * components to default values, and initializes the teams input file object.
     *
     * @param parent is the parent of the add team dialog object that will
     *        delete the object if the parent is deleted.
     */
    explicit AddTeamWindow(QWidget *parent = nullptr);

    /**
     * Destructor that deletes the teams input file private data member and user
     * interface components.
     */
    ~AddTeamWindow();

    /**
     * An overriden function that is called when the dialog object is closed. The
     * function clears team property input, the status message, and hides the add team
     * window dialog.
     */
    void reject();

private slots:
    /**
     * When the user clicks the add team button, the function is called to add a team to the
     * database if the input is valid. The input is invalid if it is empty, or integer only
     * values have other characters in the input. If input is invalid, the window will display
     * a invalid input status message along with invalid input boxes highlighted in red. If input
     * is valid, the window will display a team added status message and the team is added to the
     * additional maintenance input file.
     */
    void on_addTeamButton_clicked();

private:
    /**
     * Clear all input from the user, remove any highlights, and hide the status message.
     */
    void resetInput();

    /**
     * Check the validity of the string property passed. If the input is empty and invalid, then display
     * the invalid input status message and highlight the input box in red. Returns the string property.
     *
     * @param input is the input box of the property that is being checked for validity and returned.
     * @return A string that represents a string property of a team object.
     */
    string getValidStringProperty(QLineEdit* input);

    /**
     * Check the validity of the integer property passed. If the input is empty, or is not a valid integer,
     * then display the invalid input status message and highlight the input box in red. Returns the integer
     * property.
     *
     * @param input is the input box of the property that is being checked for validity and returned.
     * @return An integer that represents an integer property of a team object.
     */
    int getValidIntProperty(QLineEdit* input);

    /// A pointer that handles all user interface components for the add team window class.
    Ui::AddTeamWindow *ui;

    /// A pointer to a teams input file object that is used to write data to the NFL Database Maintenance
    /// Input file.
    TeamsInputFile* inputFile;
};

#endif // ADDTEAMWINDOW_H
