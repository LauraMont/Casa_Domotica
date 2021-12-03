#ifndef NEW_PASS_WINDOW_H
#define NEW_PASS_WINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class New_Pass_window;
}

class New_Pass_window : public QDialog
{
    Q_OBJECT

public:
    explicit New_Pass_window(QWidget *parent = nullptr);
    ~New_Pass_window();
    int contador = 0;
    int status =1;

private:
    Ui::New_Pass_window *ui;
private slots:
    void funcionActivacionTimer();


    void on_buttonBox_accepted();
};

#endif // NEW_PASS_WINDOW_H
