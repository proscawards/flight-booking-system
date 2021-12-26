#ifndef REGISTER_H
#define REGISTER_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QString>
#include <QKeyEvent>


namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    QString accid, newaccid, mileage;
    QString rpassFname, rpassLname, rpassusername, rpasspword, rpasstitle, rpassphone;
    ~Register();

private slots:
    void on_back2login_clicked();
    void on_registerbtn_clicked();

private:
    Ui::Register *ui;
    QKeyEvent *event;
    QMainWindow *m;

};

#endif // REGISTER_H
