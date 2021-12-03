#include "system_activate_window.h"
#include "ui_system_activate_window.h"

System_Activate_Window::System_Activate_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::System_Activate_Window)
{
    ui->setupUi(this);
}

System_Activate_Window::~System_Activate_Window()
{
    delete ui;
}
