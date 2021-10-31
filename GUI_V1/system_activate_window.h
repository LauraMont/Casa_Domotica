#ifndef SYSTEM_ACTIVATE_WINDOW_H
#define SYSTEM_ACTIVATE_WINDOW_H

#include <QDialog>

namespace Ui {
class System_Activate_Window;
}

class System_Activate_Window : public QDialog
{
    Q_OBJECT

public:
    explicit System_Activate_Window(QWidget *parent = nullptr);
    ~System_Activate_Window();

private:
    Ui::System_Activate_Window *ui;
};

#endif // SYSTEM_ACTIVATE_WINDOW_H
