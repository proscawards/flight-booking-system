#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"
#include "ui_map.h"
#include <QTime>
#include <QTimer>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QVarLengthArray>
#include <QFormLayout>
#include <QHBoxLayout>

mainmenu::mainmenu(QWidget *parent) :QMainWindow(parent),ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    connect(timer, SIGNAL(timeout()), this, SLOT(initarrayval())); 
    timer->start();
    ui->frame1->hide();
    ui->frame3->hide();
    ui->frame4->hide();
    ui->frame5->hide();
}

void mainmenu::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username>>accid;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}

void mainmenu::initarrayval(){
    QTime timenow = QTime::currentTime();
    QString currenttime = timenow.toString("hhmmss");
    time4digit = timenow.toString("hhmm");
    int currenttimeint = currenttime.split(" ")[0].toInt();
    if ((currenttimeint >= 000000 && currenttimeint < 060000) ||
        (currenttimeint >= 220000 && currenttimeint <= 235959)){
        ui->btn_newbook->setEnabled(false);
        ui->standbymodelbl->show();
    }
    else{
        ui->btn_newbook->setEnabled(true);
        ui->standbymodelbl->hide();
    }
    MainWindow m;
    m.dbopened();
    QSqlQuery count;
    count.exec("select SUM(acc_id) from bookingdata where acc_id = '"+accid+"'    ");
    if (count.next()) {
        totalaccid = count.value(0).toInt();
    }
    seatselected = new QString[totalaccid];
    gatenum = new QString[totalaccid];
    departure = new QString[totalaccid];
    arrival = new QString[totalaccid];
    flightnum = new QString[totalaccid];
    date = new QString[totalaccid];
    time = new QString[totalaccid];
    flightname = new QString[totalaccid];
    ficon = new QPixmap[totalaccid];
    flightlbl = new QLabel[totalaccid];
    seatlbl = new QLabel[totalaccid];
    departlbl = new QLabel[totalaccid];
    arrivelbl = new QLabel[totalaccid];
    gatelbl = new QLabel[totalaccid];
    datelbl = new QLabel[totalaccid];
    timelbl = new QLabel[totalaccid];
    iconlbl = new QLabel[totalaccid];
    namelbl = new QLabel[totalaccid];


    QSqlQueryModel qry;
    qry.setQuery("select * from bookingdata where acc_id = '"+accid+"'");
    for (int i = 0; i < qry.rowCount();i++){
        flightnum[i] = qry.record(i).value("flightnum").toString();
        gatenum[i] = qry.record(i).value("gate").toString();
        date[i] = qry.record(i).value("date").toString();
        time[i] = qry.record(i).value("time").toString();
        seatselected[i] = qry.record(i).value("seat").toString();
        departure[i] = qry.record(i).value("departure").toString();
        arrival[i] = qry.record(i).value("arrival").toString();
        if (arrival[i] == region[0]){flightname[i] = airlinename[0]; ficon[i] = flighticon[0];}
        if (arrival[i] == region[1]){flightname[i] = airlinename[1]; ficon[i] = flighticon[1];}
        if (arrival[i] == region[2]){flightname[i] = airlinename[2]; ficon[i] = flighticon[2];}
        if (arrival[i] == region[3]){flightname[i] = airlinename[3]; ficon[i] = flighticon[3];}
        if (arrival[i] == region[4]){flightname[i] = airlinename[4]; ficon[i] = flighticon[4];}
        if (arrival[i] == region[5]){flightname[i] = airlinename[5]; ficon[i] = flighticon[5];}
        if (arrival[i] == region[6]){flightname[i] = airlinename[6]; ficon[i] = flighticon[6];}
        if (arrival[i] == region[7]){flightname[i] = airlinename[7]; ficon[i] = flighticon[7];}
        if (arrival[i] == region[8]){flightname[i] = airlinename[8]; ficon[i] = flighticon[8];}
        if (arrival[i] == region[9]){flightname[i] = airlinename[9]; ficon[i] = flighticon[9];}
        value = i;
    }
    m.dbclosed();
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_buttonlogout_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Logout Confirmation","Are you sure you want to logout?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();}
    else{}
}

void mainmenu::on_buttonreturn_clicked()
{
    ui->frame1->hide();
    ui->frame0->show();
}

void mainmenu::on_btn_newbook_clicked()
{
    hide();
    Map *m;
    m = new Map(this);
    m->show();
}

void mainmenu::on_btn_viewbook_clicked()
{
    ui->frame0->hide();
    ui->frame1->show();
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modal = new QSqlQueryModel;
    QSqlQuery *qry = new QSqlQuery(m.db);
    qry->prepare("select flightnum,seat,date,time,ticketstatus,price from bookingdata where acc_id = '"+accid+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    m.dbclosed();


    }
    /*
    if (value == 0){
        ui->groupBox_2->hide();
        ui->groupBox_3->hide();
        ui->groupBox_4->hide();
        ui->groupBox_5->hide();
        ui->label->setText(flightnum[value]);
        ui->timelbl->setText(time[value]);
        ui->departlbl->setText(departure[value]);
        ui->arrivelbl->setText(arrival[value]);
        ui->gatenum->setText(gatenum[value]);
        ui->datelbl->setText(date[value]);
        ui->seat->setText(seatselected[value]);
        ui->flighticon->setPixmap(ficon[value]);
        ui->airlinelbl->setText(flightname[value]);}
    if (value == 1){
        ui->groupBox_3->hide();
        ui->groupBox_4->hide();
        ui->groupBox_5->hide();
        ui->label->setText(flightnum[value-1]);
        ui->timelbl->setText(time[value-1]);
        ui->departlbl->setText(departure[value-1]);
        ui->arrivelbl->setText(arrival[value-1]);
        ui->gatenum->setText(gatenum[value-1]);
        ui->datelbl->setText(date[value-1]);
        ui->seat->setText(seatselected[value-1]);
        ui->flighticon->setPixmap(ficon[value-1]);
        ui->airlinelbl->setText(flightname[value-1]);

        ui->label_2->setText(flightnum[value]);
        ui->timelbl_2->setText(time[value]);
        ui->departlbl_2->setText(departure[value]);
        ui->arrivelbl_2->setText(arrival[value]);
        ui->gatenum_2->setText(gatenum[value]);
        ui->datelbl_2->setText(date[value]);
        ui->seat_2->setText(seatselected[value]);
        ui->flighticon_2->setPixmap(ficon[value]);
        ui->airlinelbl_2->setText(flightname[value]);}
    if (value == 2){
        ui->groupBox_4->hide();
        ui->groupBox_5->hide();
        ui->label->setText(flightnum[value-2]);
        ui->timelbl->setText(time[value-2]);
        ui->departlbl->setText(departure[value-2]);
        ui->arrivelbl->setText(arrival[value-2]);
        ui->gatenum->setText(gatenum[value-2]);
        ui->datelbl->setText(date[value-2]);
        ui->seat->setText(seatselected[value-2]);
        ui->flighticon->setPixmap(ficon[value-2]);
        ui->airlinelbl->setText(flightname[value-2]);

        ui->label_2->setText(flightnum[value-1]);
        ui->timelbl_2->setText(time[value-1]);
        ui->departlbl_2->setText(departure[value-1]);
        ui->arrivelbl_2->setText(arrival[value-1]);
        ui->gatenum_2->setText(gatenum[value-1]);
        ui->datelbl_2->setText(date[value-1]);
        ui->seat_2->setText(seatselected[value-1]);
        ui->flighticon_2->setPixmap(ficon[value-1]);
        ui->airlinelbl_2->setText(flightname[value-1]);

        ui->label_3->setText(flightnum[value]);
        ui->timelbl_3->setText(time[value]);
        ui->departlbl_3->setText(departure[value]);
        ui->arrivelbl_3->setText(arrival[value]);
        ui->gatenum_3->setText(gatenum[value]);
        ui->datelbl_3->setText(date[value]);
        ui->seat_3->setText(seatselected[value]);
        ui->flighticon_3->setPixmap(ficon[value]);
        ui->airlinelbl_3->setText(flightname[value]);
    }*/


void mainmenu::on_btn_info_clicked()
{
    ui->frame0->hide();
    ui->frame3->show();
    QString Fname,Lname,title,phone,password,mileage;
    MainWindow m;
    m.dbopened();
    QSqlQueryModel qry;
    qry.setQuery("select * from passengerdata where acc_id = '"+accid+"'");
    for (int i = 0; i < qry.rowCount();i++){
        Fname = qry.record(i).value("firstname").toString();
        Lname = qry.record(i).value("lastname").toString();
        title = qry.record(i).value("title").toString();
        phone = qry.record(i).value("phonenum").toString();
        password = qry.record(i).value("password").toString();
        mileage = qry.record(i).value("mileage").toString();
    }
    int mileageval, newmileageval = 0;
    QSqlQueryModel totalmileage;
    totalmileage.setQuery("select * from bookingdata where acc_id = '"+accid+"' AND ticketstatus = 'CHECKED IN'");
    for (int i = 0; i < totalmileage.rowCount();i++){
         mileage = totalmileage.record(i).value("distance").toString();
         mileageval = mileage.split(" ")[0].toInt();
         newmileageval = newmileageval + mileageval;}
    QString newmileage = QString::number(newmileageval);
    QSqlQuery updatemileage;
    updatemileage.exec("update passengerdata set mileage = '"+newmileage+"' where acc_id = '"+accid+"'");
    ui->distitle->setText(title);
    ui->disFname->setText(Fname);
    ui->disLname->setText(Lname);
    ui->disphone->setText("(+60)" + phone);
    ui->dispass->setText(password);
    ui->disusername->setText(username);
    ui->disdeal->setNum(totalaccid);
    ui->dismileage->setText(newmileage + " km");
}

void mainmenu::on_buttonmainmenu_2_clicked()
{
    ui->frame3->hide();
    ui->frame0->show();
}

void mainmenu::on_buttonmainmenu_clicked()
{
    ui->frame1->hide();
    ui->frame0->show();
}

void mainmenu::on_btn_cancelbook_clicked()
{
    ui->frame0->hide();
    ui->frame4->show();
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modal1 = new QSqlQueryModel;
    QSqlQuery *qry1 = new QSqlQuery(m.db);
    qry1->prepare("select booking_id,flightnum,seat,date,ticketstatus from bookingdata where acc_id = '"+accid+"'");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->tablecancel->setModel(modal1);
    QSqlQueryModel *modal2 = new QSqlQueryModel();
    QSqlQuery *qry2 = new QSqlQuery(m.db);
    qry2->exec("Select booking_id from bookingdata where acc_id = '"+accid+"' AND ticketstatus = 'PENDING'");
    modal2->setQuery(*qry2);
    ui->listView->setModel(modal2);
    m.dbclosed();
}

void mainmenu::on_buttonmainmenu_3_clicked()
{
    ui->frame4->hide();
    ui->frame0->show();
}

void mainmenu::on_listView_clicked(const QModelIndex &index)
{
    selectedbookid = ui->listView->model()->data(index).toString();
    ui->labelselectedstatus->setText(selectedbookid);
}

void mainmenu::on_btn_cancel_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Confirmation", "Are you sure you want to cancel the current selected booking?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        MainWindow m;
        m.dbopened();
        QSqlQuery updateticket;
        updateticket.exec("update bookingdata set ticketstatus = 'CANCELLED' where booking_id = '"+selectedbookid+"'");
        m.dbclosed();
    }
    else{}
}

void mainmenu::on_btn_checkin_clicked()
{
    ui->frame5->show();
    ui->frame0->hide();
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modal3 = new QSqlQueryModel;
    QSqlQuery *qry3 = new QSqlQuery(m.db);
    qry3->prepare("select booking_id,flightnum,seat,date,time,ticketstatus from bookingdata where acc_id = '"+accid+"' AND date = '"+datetdylbl+"' AND time > '"+time4digit+"' AND ticketstatus = 'PENDING'");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->tablecheckin->setModel(modal3);
    QSqlQueryModel loadstatus;
    QSqlQuery update;
    loadstatus.setQuery("select * from bookingdata where acc_id = '"+accid+"'");
    for (int i = 0; i <loadstatus.rowCount(); i++){
        bookingid = loadstatus.record(i).value("booking_id").toString();
        timeofbooked = loadstatus.record(i).value("time").toString();
        dateofbooked = loadstatus.record(i).value("date").toString();
        gatecheckin = loadstatus.record(i).value("gate").toString();
        int timeofbookedval = timeofbooked.split(" ")[0].toInt();
        int timecountdownval = timeLabel.split(" ")[0].toInt();
        int timeb4checkinval = timeofbookedval - 30;
        int timecdinterval = timeofbookedval - timecountdownval;
        timeb4checkin = QString::number(timeb4checkinval);
        timecountdownlbl = QString::number(timecdinterval);
        if (dateofbooked == datetdylbl){
            if(timeofbooked < timeb4checkin){
                ui->bookingidlbl->setText(bookingid);
                ui->timelbl->setText(timeb4checkin);
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(timecountdown()));
                timer->start();
            }
            else{
                update.exec("update bookingdata set ticketstatus = 'MISSED FLIGHT' where booking_id = '"+bookingid+"'");
            }

        }
        else{}
    }
    m.dbclosed();
}

void mainmenu::on_buttonmainmenu_4_clicked()
{
    ui->frame5->hide();
    ui->frame0->show();
}

void mainmenu::timecountdown(){
    QTime time = QTime::fromString(timecountdownlbl,"hm");
    time = time.addSecs(-1);
    QString timeLabel = time.toString("hh : mm : ss");
    ui->timerlbl->setText(timeLabel);
}

void mainmenu::on_btn_checkedin_clicked()
{
    MainWindow m;
    m.dbopened();
    QSqlQuery checkin;
    checkin.exec("update bookingdata set ticketstatus = 'CHECKED IN' where booking_id = '"+bookingid+"'");
    m.dbclosed();
    QString infocheckin = "Checked in successfully! Please head on to gate " + gatecheckin;
    QMessageBox::information(this,"Information", infocheckin);
    ui->frame5->hide();
    ui->frame0->show();
}
