#ifndef NEW_PASS_WINDOW_H
#define NEW_PASS_WINDOW_H

#include <QDialog>

namespace Ui {
class New_Pass_window;
}

class New_Pass_window : public QDialog
{
    Q_OBJECT

public:
    explicit New_Pass_window(QWidget *parent = nullptr);
    ~New_Pass_window();

private:
    Ui::New_Pass_window *ui;
};

#endif // NEW_PASS_WINDOW_H
