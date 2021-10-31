#include "new_name.h"
#include "ui_new_name.h"

New_name::New_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_name)
{
    ui->setupUi(this);
}

New_name::~New_name()
{
    delete ui;
}
