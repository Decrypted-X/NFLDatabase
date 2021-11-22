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
    explicit LoginWindow(QWidget *parent = nullptr);

    ~LoginWindow();

    void reject();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;

    AddTeamWindow* addTeamWindow;
};

#endif // LOGINWINDOW_H
