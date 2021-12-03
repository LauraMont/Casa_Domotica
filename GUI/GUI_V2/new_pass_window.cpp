#include "new_pass_window.h"
#include "ui_new_pass_window.h"
#include <QTimer>
extern  QSqlDatabase db;

//Funcionamiento:
//cuando se presiona aceptar primero se comprueba si las constraseña actual es igual a la de la base de datos
//Si coinciden se procede a guardar la nueva contraseña y emerge una pestaña donde avisa al usuario que se cambio la contraseña
//Por ultimo se cierran ambas ventanas y se vuelve a la ventana principal
//Solo se prodra intentar 3 veces la comprobacion de la contraseña actual
//cada vez que suceda aparecera una ventana emergente donde se notifique al usuario
//Luego de las 3 veces se cierra la ventana y se vuelve a la ventana principal

void New_Pass_window::funcionActivacionTimer(){
    ui->lcdNumber->display(contador);
    contador++;
    if(contador>10)
        status=0;

}
New_Pass_window::New_Pass_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Pass_window)
{
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(1000);
    if(contador>=2)
    {
        cronometro->stop();

    }
}
New_Pass_window::~New_Pass_window()
{
    delete ui;
}

void New_Pass_window::on_buttonBox_accepted()
{

}
