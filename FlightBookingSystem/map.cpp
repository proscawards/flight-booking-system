#include "map.h"
#include "ui_map.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "ui_calendar.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QMovie>
#include <QtSql>
#include <QTime>
#include <QTimer>
#include <QDateTime>

Map::Map(QWidget *parent) :QMainWindow(parent), ui(new Ui::Map)
{
    ui->setupUi(this);
    QPixmap pic;
    pic.load(":/images/MAP.png");
    QIcon locicon;
    locicon.addPixmap(QPixmap(":/images/iconr.png"));
    QMovie *weather0 = new QMovie(":/images/raining.gif");
    QMovie *weather1 = new QMovie(":/images/lightning.gif");
    QDateTime datetdy = QDateTime::currentDateTime();
    QString datecheck = datetdy.toString("dd");
    datecheckint = datecheck.split(" ")[0].toInt();
    if (datecheckint % 2 == 0){
        MainWindow m;
        m.dbopened();
        QSqlQueryModel readstatus;
        QSqlQuery delayedstatus, ontimestatus;
        readstatus.setQuery("select * from flight");
        for (int i = 0; i < readstatus.rowCount();i++){
            QString arrival = readstatus.record(i).value("arrival").toString();
            delayedstatus.exec("update flight set status = 'DELAYED' where arrival = 'US' OR arrival = 'MY' OR arrival = 'RU' OR arrival = 'HK' OR arrival = 'JP'");
            ontimestatus.exec("update flight set status = 'ON TIME' where arrival = 'KR' OR arrival = 'ME' OR arrival = 'IN' OR arrival = 'SG' OR arrival = 'UK'");
        }
        m.dbclosed();
        ui->weather_us->setMovie(weather0);
        ui->weather_my->setMovie(weather1);
        ui->weather_ru->setMovie(weather0);
        ui->weather_hk->setMovie(weather1);
        ui->weather_jp->setMovie(weather0);

    }
    if (datecheckint % 2 == 1){
        MainWindow m;
        m.dbopened();
        QSqlQueryModel readstatus1;
        QSqlQuery delayedstatus1, ontimestatus1;
        readstatus1.setQuery("select * from flight");
        for (int i = 0; i<readstatus1.rowCount();i++){
            QString arrival = readstatus1.record(i).value("arrival").toString();
            qDebug()<<arrival;
            delayedstatus1.exec("update flight set status = 'DELAYED' where arrival = 'KR' OR arrival = 'ME' OR arrival = 'IN' OR arrival = 'SG' OR arrival = 'UK'");
            ontimestatus1.exec("update flight set status = 'ON TIME' where arrival = 'US' OR arrival = 'MY' OR arrival = 'RU' OR arrival = 'HK' OR arrival = 'JP'");
        }
        m.dbclosed();
        ui->weather_kr->setMovie(weather0);
        ui->weather_me->setMovie(weather1);
        ui->weather_sg->setMovie(weather0);
        ui->weather_in->setMovie(weather1);
        ui->weather_uk->setMovie(weather0);
    }
    weather0->start(); weather1->start();
    ui->my_btn->setIcon(locicon);
    ui->sg_btn->setIcon(locicon);
    ui->hk_btn->setIcon(locicon);
    ui->jp_btn->setIcon(locicon);
    ui->in_btn->setIcon(locicon);
    ui->kr_btn->setIcon(locicon);
    ui->us_btn->setIcon(locicon);
    ui->me_btn->setIcon(locicon);
    ui->uk_btn->setIcon(locicon);
    ui->ru_btn->setIcon(locicon);
    ui->worldmap_lbl->setPixmap(pic);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    timer->start();

}

Map::~Map()
{
    delete ui;
}

void Map::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}

void Map::on_jp_btn_clicked()
{
   QString jploc = "Kansai International Airport, Osaka, Japan";
   if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = jploc; arrival = "JP"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
   if (ui->departloc_lbl->text() == ""){departloc_lbl = jploc; departure = "JP"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->jp_btn->setEnabled(false);}
}

void Map::on_us_btn_clicked()
{
   QString usloc = "San Francisco International Airport, San Francisco, U.S.A.";
   if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = usloc; arrival = "US"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
   if (ui->departloc_lbl->text() == ""){departloc_lbl = usloc; departure = "US"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->us_btn->setEnabled(false);}

}

void Map::on_me_btn_clicked()
{
    QString meloc = "Mexico City International Airport, Mexico";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = meloc; arrival = "ME"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = meloc; departure = "ME"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->me_btn->setEnabled(false);}
}

void Map::on_ru_btn_clicked()
{
    QString ruloc = "Moscow Domodedovo Airport, Moscow, Russia";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = ruloc; arrival = "RU"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = ruloc; departure = "RU"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->ru_btn->setEnabled(false);}
}

void Map::on_uk_btn_clicked()
{
    QString ukloc = "London City Airport, London, United Kingdom";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = ukloc; arrival = "UK"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = ukloc; departure = "UK"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->uk_btn->setEnabled(false);}
}

void Map::on_sg_btn_clicked()
{
    QString sgloc = "Singapore Changi Airport, Singapore";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = sgloc; arrival = "SG"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = sgloc; departure = "SG"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->sg_btn->setEnabled(false);}
}

void Map::on_in_btn_clicked()
{
    QString inloc = "Indira Gandhi International Airport, New Delhi, India";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = inloc; arrival = "IN"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = inloc; departure = "IN"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->in_btn->setEnabled(false);}
}

void Map::on_hk_btn_clicked()
{
    QString hkloc = "Hong Kong International Airport, Hong Kong";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = hkloc; arrival = "HK";ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = hkloc; departure = "HK"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->hk_btn->setEnabled(false);}
}

void Map::on_my_btn_clicked()
{
    QString myloc = "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = myloc; arrival = "MY"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = myloc; departure = "MY"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->my_btn->setEnabled(false);}
}

void Map::on_kr_btn_clicked()
{
    QString krloc = "Incheon International Airport(IIA), Incheon, South Korea";
    if (ui->departloc_lbl->text() != "" && departselected == true){arrivalloc_lbl = krloc; arrival = "KR"; ui->arrivalloc_lbl->setText(arrivalloc_lbl); displayestimateddistance();}
    if (ui->departloc_lbl->text() == ""){departloc_lbl = krloc; departure = "KR"; ui->departloc_lbl->setText(departloc_lbl); departselected = true; ui->kr_btn->setEnabled(false);}
}

void Map::on_reset_btn_clicked()
{
    ui->departloc_lbl->clear();
    ui->arrivalloc_lbl->clear();
    ui->estimatedis_lbl->clear();
    ui->kr_btn->setEnabled(true);
    ui->my_btn->setEnabled(true);
    ui->sg_btn->setEnabled(true);
    ui->jp_btn->setEnabled(true);
    ui->me_btn->setEnabled(true);
    ui->uk_btn->setEnabled(true);
    ui->us_btn->setEnabled(true);
    ui->in_btn->setEnabled(true);
    ui->hk_btn->setEnabled(true);
    ui->ru_btn->setEnabled(true);
}

void Map::on_confirm_btn_clicked()
{
    if (ui->departloc_lbl->text() != "" && ui->arrivalloc_lbl->text() != ""){
        QString finalconfirm = "Departure Location Selected : " + departloc_lbl + "\nArrival Location Selected: " + arrivalloc_lbl + "\nEstimated Distance       :" + estimatedis_lbl;
        QMessageBox::StandardButton selection = QMessageBox::question(this,"Confirmation",finalconfirm , QMessageBox::Yes | QMessageBox::No);
        if (selection == QMessageBox::Yes){
            QFile destination("G:/Degree/Sem3(1910)/TCP1201 - OOPDS/Assignment/FlightBookingSystem/destination.txt");
            destination.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream stream(&destination);
            stream<<departure<<" "<<arrival<<" "<<estimatedis_lbl<<" "<<estimatedprice;
            hide();
            Calendar *c;
            c = new Calendar(this);
            c->show();}
        else{}
    }
}

void Map::displayestimateddistance(){
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A.") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A.")   ){
        estimatedis_lbl = "8687"; estimatedprice = "5974";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Mexico City International Airport, Mexico") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Mexico City International Airport, Mexico")){
        estimatedis_lbl = "11714"; estimatedprice = "6048";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "7341"; estimatedprice = "5309";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "9502"; estimatedprice = "6565";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Singapore Changi Airport, Singapore") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Singapore Changi Airport, Singapore")){
        estimatedis_lbl = "4897"; estimatedprice = "1476";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India") ||
         (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Indira Gandhi International Airport, New Delhi, India")){
        estimatedis_lbl = "5473"; estimatedprice = "2344";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Hong Kong International Airport, Hong Kong") ||
         (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Hong Kong International Airport, Hong Kong")){
        estimatedis_lbl = "2473"; estimatedprice = "1147";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia")){
        estimatedis_lbl = "4939"; estimatedprice = "1471";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kansai International Airport, Osaka, Japan" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Kansai International Airport, Osaka, Japan" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "859"; estimatedprice = "488";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Mexico City International Airport, Mexico") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Mexico City International Airport, Mexico")){
        estimatedis_lbl = "3695"; estimatedprice = "2710";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "9496"; estimatedprice = "2821";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "8632"; estimatedprice = "2685";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Singapore Changi Airport, Singapore") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Singapore Changi Airport, Singapore")){
        estimatedis_lbl = "13572"; estimatedprice = "2703";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Indira Gandhi International Airport, New Delhi, India")){
        estimatedis_lbl = "12374"; estimatedprice = "6565";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Hong Kong International Airport, Hong Kong") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Hong Kong International Airport, Hong Kong")){
        estimatedis_lbl = "11121"; estimatedprice = "3240";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia")){
        estimatedis_lbl = "13626"; estimatedprice = "2760";
        ui->estimatedis_lbl->setText(estimatedis_lbl + "km");
    }
    if ((departloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "San Francisco International Airport, San Francisco, U.S.A." && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "9080"; estimatedprice = "2951";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "10751"; estimatedprice = "5803";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "8930"; estimatedprice = "5730";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "Singapore Changi Airport, Singapore") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "Singapore Changi Airport, Singapore")){
        estimatedis_lbl = "16586"; estimatedprice = "3629";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "Indira Gandhi International Airport, New Delhi, India")){
        estimatedis_lbl = "14654"; estimatedprice = "5271";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "Hong Kong International Airport, Hong Kong") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "Hong Kong International Airport, Hong Kong")){
        estimatedis_lbl = "14142"; estimatedprice = "4292";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia")){
        estimatedis_lbl = "16652"; estimatedprice = "4933";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Mexico City International Airport, Mexico" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Mexico City International Airport, Mexico" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "12090"; estimatedprice = "4845";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "4609"; estimatedprice = "1266";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && arrivalloc_lbl == "Singapore Changi Airport, Singapore") ||
        (arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && departloc_lbl == "Singapore Changi Airport, Singapore")){
        estimatedis_lbl = "356"; estimatedprice = "231";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && arrivalloc_lbl == "Hong Kong International Airport, Hong Kong") ||
        (arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && departloc_lbl == "Hong Kong International Airport, Hong Kong")){
        estimatedis_lbl = "2542"; estimatedprice = "550";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India") ||
        (arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && departloc_lbl == "Indira Gandhi International Airport, New Delhi, India")){
        estimatedis_lbl = "5789"; estimatedprice = "1103";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "10563"; estimatedprice = "3179";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "Kuala Lumpur International Airport(KLIA), Kuala Lumpur, Malaysia" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "8130"; estimatedprice = "2413";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Singapore Changi Airport, Singapore" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "Singapore Changi Airport, Singapore" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "8395"; estimatedprice = "3154";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Singapore Changi Airport, Singapore" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Singapore Changi Airport, Singapore" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "4622"; estimatedprice = "1283";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Singapore Changi Airport, Singapore" && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "Singapore Changi Airport, Singapore" && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "10840"; estimatedprice = "3296";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Singapore Changi Airport, Singapore" && arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India") ||
        (arrivalloc_lbl == "Singapore Changi Airport, Singapore" && departloc_lbl == "Indira Gandhi International Airport, New Delhi, India")){
        estimatedis_lbl = "6122"; estimatedprice = "1327";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Singapore Changi Airport, Singapore" && arrivalloc_lbl == "Hong Kong International Airport, Hong Kong") ||
        (arrivalloc_lbl == "Singapore Changi Airport, Singapore" && departloc_lbl == "Hong Kong International Airport, Hong Kong")){
        estimatedis_lbl = "2563"; estimatedprice = "644";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Hong Kong International Airport, Hong Kong" && arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India") ||
        (arrivalloc_lbl == "Hong Kong International Airport, Hong Kong" && departloc_lbl == "Indira Gandhi International Airport, New Delhi, India")){
        estimatedis_lbl = "3745"; estimatedprice = "1346";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Hong Kong International Airport, Hong Kong" && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "Hong Kong International Airport, Hong Kong" && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "9593"; estimatedprice = "2896";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Hong Kong International Airport, Hong Kong" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Hong Kong International Airport, Hong Kong" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "2067"; estimatedprice = "641";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Hong Kong International Airport, Hong Kong" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "Hong Kong International Airport, Hong Kong" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "7105"; estimatedprice = "2133";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Indira Gandhi International Airport, New Delhi, India" && arrivalloc_lbl == "London City Airport, London, United Kingdom") ||
        (arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India" && departloc_lbl == "London City Airport, London, United Kingdom")){
        estimatedis_lbl = "6692"; estimatedprice = "3566";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Indira Gandhi International Airport, New Delhi, India" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "4649"; estimatedprice = "2371";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Indira Gandhi International Airport, New Delhi, India" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "Indira Gandhi International Airport, New Delhi, India" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "4305"; estimatedprice = "2158";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "London City Airport, London, United Kingdom" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "London City Airport, London, United Kingdom" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "8830"; estimatedprice = "4836";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "London City Airport, London, United Kingdom" && arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia") ||
        (arrivalloc_lbl == "London City Airport, London, United Kingdom" && departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia")){
        estimatedis_lbl = "2912"; estimatedprice = "861";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
    if ((departloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia" && arrivalloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea") ||
        (arrivalloc_lbl == "Moscow Domodedovo Airport, Moscow, Russia" && departloc_lbl == "Incheon International Airport(IIA), Incheon, South Korea")){
        estimatedis_lbl = "6577"; estimatedprice = "2141";
        ui->estimatedis_lbl->setText(estimatedis_lbl+ "km");
    }
}


void Map::on_buttonmainmenu_clicked()
{
    hide();
    mainmenu *menu;
    menu = new mainmenu(this);
    menu->show();
}
