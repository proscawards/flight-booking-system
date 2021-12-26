#include "mainwindow.h"
#include "map.h"
#include "ui_map.h"
#include "flight.h"
#include "ui_flight.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QTimer>
#include <QTime>
#include <QDialog>
#include <QDebug>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime()));
    timer->start();
    QTime time = QTime::currentTime();
    currenttime = time.toString("hhmmss");
    currenttimeint = currenttime.split(" ")[0].toInt();
    ui->Lpasspword_cin->setEchoMode(QLineEdit::Password);
    QIcon pic;
    pic.addPixmap(QPixmap(":/images/eyeview.png"));
    ui->passhideview_btn->setIcon(pic);
    QPixmap logo;
    logo.load(":/images/logo.png");
    ui->logo->setPixmap(logo);
    passwordecho = 2;
    if (!dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to PABFS!");
        QDateTime date = QDateTime::currentDateTime();
        QString datetdy = date.toString("yyyy-MM-dd");
        QString datefromdb;
        QSqlQueryModel checkdate;
        QSqlQuery updatestatus;
        checkdate.setQuery("select * from bookingdata order by booking_id asc");
        for (int i = 0; i< checkdate.rowCount();i++){
            datefromdb = checkdate.record(i).value("date").toString();
            if (datefromdb <= datetdy){
                updatestatus.exec("update bookingdata set status = 'MISSED FLIGHT' where dateofbooked = '"+datefromdb+"'");}
            else{}}
        dbclosed();
    }
}

bool MainWindow::dbopened(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/pafbs.db");
    if (!db.open()){return false;}
    else{return true;}
}

void MainWindow::dbclosed(){
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

void MainWindow::displaytime(){
    QTime time = QTime::currentTime();
    QString timeLabel = time.toString("hh : mm : ss");
    currenttime = time.toString("hhmmss");
    currenttimeint = currenttime.split(" ")[0].toInt();
    ui->timedisplay->setText(timeLabel);
}

void MainWindow::on_registerbtn_clicked()
{
    Register *r;
    hide();
    r = new Register(this);
    r->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginbtn_clicked()
{
    usernameinput = ui->Lpassusername_cin->text();
    passwordinput = ui->Lpasspword_cin->text();
    dbopened();
    QSqlQueryModel qry;
    qry.setQuery("select * from passengerdata order by acc_id");
    for (int i = 0; i < qry.rowCount();i++){
        accid = qry.record(i).value("acc_id").toString();
        Lpassusername = qry.record(i).value("username").toString();
        Lpasspword = qry.record(i).value("password").toString();
        if ((usernameinput != Lpassusername && passwordinput == Lpasspword) ||
            (usernameinput == Lpassusername && passwordinput != Lpasspword) ||
            (usernameinput != Lpassusername && passwordinput != Lpasspword)){qDebug()<<"sama username ke pass";}
        if (usernameinput == Lpassusername && passwordinput == Lpasspword){
            QMessageBox::information(this, "Success", "Login Success!");
            QFile currentuser("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/currentuser.txt");
            currentuser.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream stream(&currentuser);
            stream << usernameinput << " " <<accid;
            dbclosed();
            hide();
            mainmenu *m;
            m = new mainmenu(this);
            QTime timenow = QTime::currentTime();
            QString currenttime = timenow.toString("hhmmss");
            int currenttimeint = currenttime.split(" ")[0].toInt();
            if ((currenttimeint >= 000000 && currenttimeint < 060000) ||
                (currenttimeint >= 220000 && currenttimeint <= 235959)){
                m->ui->btn_newbook->setEnabled(false);
                m->ui->standbymodelbl->show();}
            else{
                m->ui->btn_newbook->setEnabled(true);
                m->ui->standbymodelbl->hide();}
            m->show();
            break;}
        else{}}
}

void MainWindow::on_passhideview_btn_clicked()
{
    while(passwordecho != 0 || 2){
        if(passwordecho == 2){
            ui->Lpasspword_cin->setEchoMode(QLineEdit::Normal);
            QIcon pic;
            pic.addPixmap(QPixmap(":/images/eyehide.png"), QIcon::Normal, QIcon::On);
            ui->passhideview_btn->setIcon(pic);
            passwordecho = 0;
            break;}
        if(passwordecho == 0){
            ui->Lpasspword_cin->setEchoMode(QLineEdit::Password);
            QIcon pic;
            pic.addPixmap(QPixmap(":/images/eyeview.png"), QIcon::Normal, QIcon::On);
            ui->passhideview_btn->setIcon(pic);
            passwordecho = 2;
            break;}
    }
}

void MainWindow::on_viewflightbtn_clicked()
{
    hide();
    Flight *f;
    f = new Flight(this);
    f->show();
}

