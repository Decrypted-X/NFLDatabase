/**
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * The help window class displays help to the user.
 */

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructor that sets private data members according to parameters.
     *
     * @param parent is the parent of the help dialog object that will
     *        delete the object if the parent is deleted.
     */
    explicit HelpWindow(QWidget *parent = nullptr);

    /**
     * Destructor that deletes user interface components.
     */
    ~HelpWindow();

private:
    /// A pointer that handles all user interface components for the help
    /// window class.
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
