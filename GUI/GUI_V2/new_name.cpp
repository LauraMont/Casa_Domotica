#include "new_name.h"
#include "ui_new_name.h"

extern  QSqlDatabase db;

//Funcionamiento :
//Cambia el nombre del usuario en el label y la base de datos
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

void New_name::on_buttonBox_accepted()
{


}
