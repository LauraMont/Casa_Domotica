#ifndef NEW_NAME_H
#define NEW_NAME_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class New_name;
}

class New_name : public QDialog
{
    Q_OBJECT

public:
    explicit New_name(QWidget *parent = nullptr);
    ~New_name();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::New_name *ui;
};

#endif // NEW_NAME_H
