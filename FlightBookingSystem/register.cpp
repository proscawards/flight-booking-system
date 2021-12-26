#include "register.h"
#include "ui_register.h"
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QIODevice>


Register::Register(QWidget *parent) : QMainWindow(parent), ui(new Ui::Register)
{
    ui->setupUi(this);
    //QPixmap pic;
    //pic.load("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/logo.png");
    //int w = ui->logo_lbl->width();
    //int h = ui->logo_lbl->height();
    //ui->logo_lbl->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    MainWindow m;
    if (!m.dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to PABFS!");}


}

Register::~Register()
{
    delete ui;
}

void Register::on_back2login_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Returning to Login Page...","Are you sure you want to terminate the current registration?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        m = new MainWindow(this);
        m->show();
    }
    else{}
}

void Register::on_registerbtn_clicked()
{
    rpassFname = ui->passFname_cin->text();
    rpassLname = ui->passLname_cin->text();
    rpassphone = ui->passphone_cin->text();
    rpassusername = ui->passusername_cin->text();
    rpasspword = ui->passpword_cin->text();
    rpasstitle = ui->comboBox->currentText();
    MainWindow m;
    m.dbopened();
    QSqlQuery qry;
    qry.prepare("insert into passengerdata (firstname,lastname,title,phonenum,username,password)" "values ('"+rpassFname+"','"+rpassLname+"','"+rpasstitle+"','"+rpassphone+"','"+rpassusername+"', '"+rpasspword+"')");
    if(qry.exec()){
           QMessageBox::information(this,"Redirecting...","Registered Sucessfully!");
           m.dbclosed();
           hide();
           MainWindow *m;
           m = new MainWindow(this);
           m->show();
    }
    else{QMessageBox::information(this,"Redirecting...","ERROR!");}




}
