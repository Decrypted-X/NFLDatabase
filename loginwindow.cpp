#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    addTeamWindow = NULL;
}


LoginWindow::~LoginWindow()
{
    delete addTeamWindow;
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{
    QString enteredPassword = ui->lineEdit_pass->text();

    if (enteredPassword == "test")
    {
        if (!addTeamWindow)
        {
            addTeamWindow = new AddTeamWindow(this);
        }

        if (!addTeamWindow->isVisible())
        {
            addTeamWindow->show();
        }
    }
    else
    {
        QMessageBox::warning (this, "Login", "Password was not correct");
    }
}

