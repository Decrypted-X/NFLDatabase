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
    explicit AddTeamWindow(QWidget *parent = nullptr);

    ~AddTeamWindow();

private slots:
    void on_addTeamButton_clicked();

private:
    string getValidStringProperty(QLineEdit* input);

    int getValidIntProperty(QLineEdit* input);

    Ui::AddTeamWindow *ui;

    TeamsInputFile* inputFile;
};

#endif // ADDTEAMWINDOW_H
