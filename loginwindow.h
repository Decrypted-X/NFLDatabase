/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The log in window class handles maintenance log in interactions with
 * the user and only gives maintenance access to authorized users.
 */

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "addteamwindow.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructor that sets private data members according to parameters
     * and configures default values.
     *
     * @param parent is the parent of the log in dialog object that will
     *        delete the object if the parent is deleted.
     */
    explicit LoginWindow(QWidget *parent = nullptr);

    /**
     * Destructor that deletes user interface components and windows that
     * are children of the log in window object.
     */
    ~LoginWindow();

    /**
     * An overriden function that is called when the dialog object is closed. The
     * function clears password input and hides the log in window dialog.
     */
    void reject();

private slots:
    /**
     * When the user clicks the log in button, the function is called to open
     * the maintenance add team window and display it to the user if the corret
     * password is entered.
     */
    void on_loginButton_clicked();

private:
    /// A pointer that handles all user interface components for the log in
    /// window class.
    Ui::LoginWindow *ui;

    /// A pointer to a add team window object that is created and displayed when
    /// the user clicks the log in button after entering the correct password.
    AddTeamWindow* addTeamWindow;

    /// A QString object that holds the correct password to the maintenance window.
    const QString KEY = "test";
};

#endif // LOGINWINDOW_H
