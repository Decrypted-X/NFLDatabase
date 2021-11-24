// contactuswindow.cpp  -  Class Implementation

#include "contactuswindow.h"
#include "ui_contactuswindow.h"

// Contact Us Window Data Members:
//     Ui::ContactUsWindow *ui;


// The contact us window constructor sets private data memebrs according to
// parameters and sets up the user interface.
ContactUsWindow::ContactUsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUsWindow)
{
    ui->setupUi(this);
}


// The contact us window destructor deletes all ui components relying on the
// contact us window object.
ContactUsWindow::~ContactUsWindow()
{
    delete ui;
}
