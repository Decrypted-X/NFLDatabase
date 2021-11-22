#ifndef CONTACTUSWINDOW_H
#define CONTACTUSWINDOW_H

#include <QDialog>

namespace Ui {
class ContactUsWindow;
}

class ContactUsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContactUsWindow(QWidget *parent = nullptr);

    ~ContactUsWindow();

private:
    Ui::ContactUsWindow *ui;
};

#endif // CONTACTUSWINDOW_H
