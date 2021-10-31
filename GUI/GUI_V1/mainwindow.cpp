#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"new_name.h"
#include"new_pass_window.h"
#include"system_activate_alarm_window.h"
#include"system_activate_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
