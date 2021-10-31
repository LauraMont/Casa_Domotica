#include "new_pass_window.h"
#include "ui_new_pass_window.h"

New_Pass_window::New_Pass_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Pass_window)
{
    ui->setupUi(this);
}

New_Pass_window::~New_Pass_window()
{
    delete ui;
}
