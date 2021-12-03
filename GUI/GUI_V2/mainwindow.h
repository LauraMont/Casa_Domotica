#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QTableWidgetItem>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_change_pass_pb_clicked();

    void on_change_name_pb_clicked();

    void on_Sala_pushButton_clicked();

    void on_habitacion1_pushButton_clicked();

    void on_habitacion2_pushButton_clicked();

    void CrearTablaUsuarios();

    void DatosPorDefecto();

    void ConfigurarDatosInterfaz();
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
