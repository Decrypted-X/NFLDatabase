#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TeamsInputFile.h"
#include "helpwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayTeams();

    void updateTeams();

private slots:
    void on_conferenceSelect_currentTextChanged();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;

    HelpWindow* helpWindow;

    void displayTeam(int row, Team* team);

    TeamsInputFile* inputFile;
    Teams* nfcTeams;
    Teams* afcTeams;
};
#endif // MAINWINDOW_H
