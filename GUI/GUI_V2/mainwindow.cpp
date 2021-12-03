#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"new_name.h"
#include"new_pass_window.h"
#include"system_activate_alarm_window.h"
#include"system_activate_window.h"
#include <QFileDialog>            //  Para poder usar el QFileDialog
#include <iostream>
#include <QDebug>
#include<istream>
using namespace std;

//  Funcionamiento:
//Al iniciar se cambiaran todos los nombres (habitaciones, usuario y datos) por los que se almacenaron en la base de datos
//ILUM:Si se cambian los line edit de las habitaciones o del usuario se guardara en la base de datos
//AMB: se generara el grafico con las temperaturas de la base de datos y se mostrara la temperatura actual .
//SEG:
//CONF: Se muestra la temperatura estandar(con un rango de +/- 2 grados) ,esta se podra modificar lo que se guarda en la base de datos .Los pb emergeran ventanas

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Creacion de la base de datos...
    qDebug()<<"Aplicacion iniciada...";
    QString  nombre;
     QSqlQuery crear_t1 , crear_t2;

    nombre.append("badeDeDatos.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    if(db.open())  {
        qDebug()<<"Se ha conectado a la base de datos.";
    }
    else{
        qDebug()<<"ERROR! No se ha conectado a la base de datos.";
    }

    CrearTablaUsuarios();

   ConfigurarDatosInterfaz();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Pendiente : ver como inicializar la tabla con datos por default si la tabla de nombre esta vacia
// Lo mismo con user_data (no inicializo la temp_data)
void MainWindow::CrearTablaUsuarios()
{
    QSqlQuery crear_t1(db) ,  crear_t3(db);
    //Creacion de tabla...
    QString User_data("CREATE TABLE IF NOT EXISTS datos("
                            "usuario VARCHAR(50)NOT NULL PRIMARY KEY,"
                            "Habitacion1 VARCHAR(50) ,"
                            "Habitacion2 VARCHAR(50),"
                            "Habitacion3 VARCHAR(50),"
                           "psw VARCHAR(50),"
                           "temp INTEGER,"
                           "Hora_sis_seg INTEGER"
                            ");");
    QString Temp_data("CREATE TABLE IF NOT EXISTS temperaturas("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT ,"
                          "Temperatura INTEGER"
                          ");");
    crear_t1.prepare(User_data);
    crear_t3.prepare(Temp_data);
    crear_t1.exec();
    crear_t3.exec();
    //Solo se ejecuta cuando la lista esta vacia .
    QString Consulta ;
    QSqlQuery datos(db);
    QVariant aux;
    Consulta.append("SELECT * FROM datos" );

    datos.prepare(Consulta);
    datos.exec();
    if(!datos.next())
    DatosPorDefecto();
}

//Datos por defecto la primera vez que el usuario ingresa.
void MainWindow::DatosPorDefecto()
{
    QSqlQuery datos(db);
    QString consulta1,consulta2;
    consulta1.append("INSERT INTO datos(usuario,Habitacion1,Habitacion2,Habitacion3,psw,temp,Hora_sis_seg) "
                    "VALUES ('CASA USUARIO', 'Sala', 'Comedor', 'Habitacion ','1234', 30, -1 );");
    datos.prepare(consulta1);
    datos.exec();

}
//Cambia todos los nombres con los de la base de datos al iniciar
void MainWindow::ConfigurarDatosInterfaz()
{
    QString Consulta ;
    QSqlQuery datos(db);
    QVariant aux;
    Consulta.append("SELECT * FROM datos" );

    datos.prepare(Consulta);
    datos.exec();
    datos.next();

    aux= datos.value(0);
    ui->Nombre_usuario_l->setText(aux.toString());

    aux= datos.value(1);
    ui->Habitacion_1_l->setText(aux.toString());

    aux= datos.value(2);
     ui->Habitacion_2_l->setText(aux.toString());

    aux= datos.value(3);
    ui->Habitacion_3_l->setText(aux.toString());

    aux= datos.value(5);
    ui->Temp_sb->setValue(aux.toInt());

}


void MainWindow::on_change_pass_pb_clicked()
{
   New_Pass_window new_pass_wd;
   new_pass_wd.setModal(true);
   new_pass_wd.exec();
}

void MainWindow::on_change_name_pb_clicked()
{
    New_name new_name_wd;
    new_name_wd.setModal(true);
    new_name_wd.exec();
}

#define     ON          1
#define     OFF         0
void MainWindow::on_Sala_pushButton_clicked()
{
    static bool status = ON;
    if (status)
    {
        ui->Sala_pushButton->setText("OFF");
        ui->Sala_pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                              "QPushButton:enabled { background-color: rgb(200,0,0); }\n");
        status = OFF;
    }
    else
    {
        ui->Sala_pushButton->setText("ON");
                ui->Sala_pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                                      "QPushButton:enabled { background-color: rgb(34, 102, 19); }\n");
                status = ON;
    }
}

void MainWindow::on_habitacion1_pushButton_clicked()
{
    static bool status = ON;
    if (status)
    {
        ui->habitacion1_pushButton->setText("OFF");
        ui->habitacion1_pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                              "QPushButton:enabled { background-color: rgb(200,0,0); }\n");
        status = OFF;
    }
    else
    {
        ui->habitacion1_pushButton->setText("ON");
                ui->habitacion1_pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                                      "QPushButton:enabled { background-color: rgb(34, 102, 19); }\n");
                status = ON;
    }
}

void MainWindow::on_habitacion2_pushButton_clicked()
{
    static bool status = ON;
    if (status)
    {
        ui->habitacion2_pushButton->setText("OFF");
        ui->habitacion2_pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                              "QPushButton:enabled { background-color: rgb(200,0,0); }\n");
        status = OFF;
    }
    else
    {
        ui->habitacion2_pushButton->setText("ON");
                ui->habitacion2_pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                                      "QPushButton:enabled { background-color: rgb(34, 102, 19); }\n");
                status = ON;
    }
}
