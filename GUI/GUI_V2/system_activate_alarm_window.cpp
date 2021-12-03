#include "system_activate_alarm_window.h"
#include "ui_system_activate_alarm_window.h"
#include<QTimer>

System_Activate_Alarm_Window::System_Activate_Alarm_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::System_Activate_Alarm_Window)
{
    ui->setupUi(this);

}

System_Activate_Alarm_Window::~System_Activate_Alarm_Window()
{
    delete ui;
}
