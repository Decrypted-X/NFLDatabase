#include "contactuswindow.h"
#include "ui_contactuswindow.h"

ContactUsWindow::ContactUsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUsWindow)
{
    ui->setupUi(this);
}

ContactUsWindow::~ContactUsWindow()
{
    delete ui;
}
