#include "calendar.h"
#include "ui_calendar.h"
#include "flight.h"
#include "ui_flight.h"
#include "map.h"
#include "ui_map.h"
#include "seats.h"
#include "ui_seats.h"
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QPushButton>
#include <QMessageBox>
#include <QPalette>
#include <QCalendarWidget>
#include <QApplication>
#include <QDebug>

Calendar::Calendar(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calendar)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    connect(timer, SIGNAL(timeout()), this, SLOT(selectedloc()));
    timer->start();
    QTime time = QTime::currentTime();
    timecompare = time.toString("hhmm");
    QString dateLabel = datetdy.toString(":  dd/MM/yyyy");
    daytdy = datetdy.toString("dd"); monthtdy = datetdy.toString("MM"); yeartdy = datetdy.toString("yyyy");
    ui->datedisplay->setText(dateLabel);
    ui->calendarWidget->setGridVisible(true);
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
    ui->groupBox->hide();
    MainWindow m;
    m.dbopened();
    QSqlQueryModel qry;
    qry.setQuery("select * from flight order by no");
    for (int i = 0; i < qry.rowCount();i++){
        departure[i] = qry.record(i).value("departure").toString();
        arrival[i] = qry.record(i).value("arrival").toString();
        flighttime[i] = qry.record(i).value("time").toString();
        flightdestination[i] = qry.record(i).value("destination").toString();
        flightairport[i] = qry.record(i).value("airport").toString();
        flightairline[i] = qry.record(i).value("airline").toString();
        flightnum[i] = qry.record(i).value("flightnum").toString();
        flightstatus[i] = qry.record(i).value("status").toString();
        int flightgatenum = qry.record(i).value("gate").toInt();
        flightgate[i] = QString::number(flightgatenum);}
    m.dbclosed();
    displayflightonbtn();
}

void Calendar::displaytime(){
    QTime time = QTime::currentTime();
    QString timeLabel = time.toString("hh : mm : ss");
    ui->timedisplay->setText(timeLabel);}

void Calendar::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}

void Calendar::selectedloc(){
    QFile destination("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/destination.txt");
    destination.open(QFile::ReadOnly | QFile::Text);
    QTextStream get(&destination);
    get>>departloc>>arrivalloc>>distance>>ticketprice;
    destination.flush();
    destination.close();
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    dateselectLabel = date.toString("dd/MM/yyyy");
    day = date.toString("dd"); month = date.toString("MM"); year = date.toString("yyyy");
    qDebug() << day << month << year;
    ui->groupBox->show();
    ui->dateselectedLabel->setText((dateselectLabel));
    displayflightonbtn();
}

void Calendar::displayflightonbtn(){
    for (int i = 0; i< 90;i++){
        if (departure[i] == departloc && arrival[i] == arrivalloc){selected = i; i=90;}
        else{}
    }
    if (year==yeartdy && month==monthtdy && day==daytdy){
        if(flighttime[selected] <= timecompare){ui->status->setText("EXPIRED"); ui->groupBox->setEnabled(false);}
        else{ui->status->setText(flightstatus[selected]); ui->groupBox->setEnabled(true);}}
    else{ui->status->setText(flightstatus[selected]); ui->groupBox->setEnabled(true);}
    timeselected = flighttime[selected];
    ui->timelbl->setText(timeselected);
    ui->regionlbl->setText(flightdestination[selected]);
    ui->airlinelbl->setText(flightairline[selected]);
    ui->flighticon->setPixmap(flighticon[selected]);
    ui->airportlbl->setText(flightairport[selected]);
    flightselected = flightnum[selected];
    ui->flightnumlbl->setText(flightselected);
    gatenum = flightgate[selected];
    ui->gatenum->setText(gatenum);
    ui->datelbl->setText(dateselectLabel);
    flightcurstatus = flightstatus[selected];

}

void Calendar::on_buttonmainmenu_clicked()
{
    hide();
    mainmenu *menu;
    menu = new mainmenu(this);
    menu->show();
}

void Calendar::on_pushButton_clicked()
{
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
}

Calendar::~Calendar()
{
    delete ui;
}


void Calendar::on_buttonconfirm_clicked()
{
    if ((ui->dateselectedLabel->text() == "-" /*&& ui->timeselectedLabel->text() == "-"*/) ||
        (ui->dateselectedLabel->text() != "-" /*&& ui->timeselectedLabel->text() == "-"*/) ||
        (ui->dateselectedLabel->text() == "-" /*&& ui->timeselectedLabel->text() != "-"*/)){QMessageBox::information(this,"Warning!","Selection cannnot be EMPTY!");}
    if (ui->dateselectedLabel->text() != "-" /*&& ui->timeselectedLabel->text() != "-"*/){
        QString finalconfirm = "Date Selected : " + dateselectLabel + "\nTime Selected: " + timeselectedLabel;
        QMessageBox::StandardButton selection = QMessageBox::question(this,"Confirmation",finalconfirm , QMessageBox::Yes | QMessageBox::No);
        if (selection == QMessageBox::Yes){}
        else{}}

}





void Calendar::on_buttonreturn_clicked()
{
    hide();
    Map *map;
    map = new Map(this);
    map->show();
}

void Calendar::on_btnflight_clicked()
{
    QFile selectseat("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/b4selectseat.txt");
    selectseat.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream stream(&selectseat);
    stream <<departloc<<" "<<arrivalloc<<" "<<distance<<" "<<ticketprice<<" "<<flightselected<<" "<<gatenum<<" "<<dateselectLabel<<" "<<timeselected<<" "<<flightcurstatus;
    hide();
    Seats *s;
    s = new Seats(this);
    s->show();
}
