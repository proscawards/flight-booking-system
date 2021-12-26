#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "register.h"
#include "map.h"
#include "ui_map.h"
#include "flight.h"
#include "ui_flight.h"
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int currenttimeint;
    QString username, accid, currenttime;
    QString flightnum;
    int passwordecho;
    QString Lpassusername, Lpasspword, LpassFname, LpassLname, Lpassphone, Lpasstitle;
    QString usernameinput, passwordinput;
    QSqlDatabase db;
    void dbclosed();
    bool dbopened();
    ~MainWindow();

private slots:
    void displaytime();
    void on_registerbtn_clicked();
    void on_loginbtn_clicked();
    void on_passhideview_btn_clicked();
    void on_viewflightbtn_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
