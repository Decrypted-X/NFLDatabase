/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The contact us window class displays contact information to the user if they
 * have further questions about the application, found a bug, or want to contact
 * the creators of the application.
 */

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
    /**
     * Constructor that sets private data members according to parameters.
     *
     * @param parent is the parent of the contact us dialog object that will
     *        delete the object if the parent is deleted.
     */
    explicit ContactUsWindow(QWidget *parent = nullptr);

    /**
     * Destructor that deletes user interface components.
     */
    ~ContactUsWindow();

private:
    /// A pointer that handles all user interface components for the contact us
    /// window class.
    Ui::ContactUsWindow *ui;
};

#endif // CONTACTUSWINDOW_H
