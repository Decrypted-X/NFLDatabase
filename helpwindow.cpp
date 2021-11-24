// helpwindow.cpp  -  Class Implementation

#include "helpwindow.h"
#include "ui_helpwindow.h"

// Help Window Data Members:
//     Ui::HelpWindow *ui;


// The help window constructor sets private data memebrs according to
// parameters and sets up the user interface.
HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
}


// The help window destructor deletes all ui components relying on the
// help window object.
HelpWindow::~HelpWindow()
{
    delete ui;
}
