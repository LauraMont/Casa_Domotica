#ifndef SYSTEM_ACTIVATE_ALARM_WINDOW_H
#define SYSTEM_ACTIVATE_ALARM_WINDOW_H

#include <QDialog>

namespace Ui {
class System_Activate_Alarm_Window;
}

class System_Activate_Alarm_Window : public QDialog
{
    Q_OBJECT

public:
    explicit System_Activate_Alarm_Window(QWidget *parent = nullptr);
    ~System_Activate_Alarm_Window();

private:
    Ui::System_Activate_Alarm_Window *ui;
};

#endif // SYSTEM_ACTIVATE_ALARM_WINDOW_H
