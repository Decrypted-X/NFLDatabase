// loginwindow.cpp  -  Class Implementation

#include "loginwindow.h"
#include "ui_loginwindow.h"

// Log In Window Data Members:
//     Ui::LoginWindow *ui;
//     AddTeamWindow* addTeamWindow;
//     const QString KEY = "test";


// The log in window constructor sets private data memebrs according to
// parameters and configures default values for the user interface.
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // initializes the addTeamWindow pointer to null
    addTeamWindow = NULL;
}


// The log in window destructor deletes windows opened by the log in window
// and all ui components relying on the log in window object.
LoginWindow::~LoginWindow()
{
    delete addTeamWindow;
    delete ui;
}


// The function clears the password input and hides the dialog window.
void LoginWindow::reject()
{
    ui->lineEdit_pass->setText("");

    hide();
}


// The function opens the maintenance add team window if the password is entered
// correctly, and displays that the password was not correct if input is incorrect.
void LoginWindow::on_loginButton_clicked()
{
    // get the password input by the user
    QString enteredPassword = ui->lineEdit_pass->text();

    // clears password input
    ui->lineEdit_pass->setText("");

    // if the password entered by the user is the correct password in the KEY object,
    // then display the maintenance add team window and close this window
    if (enteredPassword == KEY)
    {
        if (!addTeamWindow)
        {
            addTeamWindow = new AddTeamWindow(this);
        }

        if (!addTeamWindow->isVisible())
        {
            addTeamWindow->show();
        }

        // calls the reject function as if the user was closing the window
        reject();
    }
    else
    {
        // displays that the user entered an incorrect password
        QMessageBox::warning(this, "Login", "Password was not correct");
    }
}

