#include "flight.h"
#include "ui_flight.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qglobal.h>
#include <QTime>
#include <QtSql>
#include <QDebug>

Flight::Flight(QWidget *parent) :QMainWindow(parent), ui(new Ui::Flight)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime()));
    timer->start();
    QTime time = QTime::currentTime();
    timecompare = time.toString("hhmm");
    MainWindow m;
    m.dbopened();
    if (!m.dbopened()){ui->db_lbl->setText("Failed to connect to PABFS...");}
    else{ui->db_lbl->setText("Connected to PABFS!");}
    QSqlQueryModel qry;
    qry.setQuery("select * from flight order by time");
    for (int i = 0; i < qry.rowCount();i++){
        flighttime[i] = qry.record(i).value("time").toString();
        flightnum[i] = qry.record(i).value("flightnum").toString();
        flightdestination[i] = qry.record(i).value("destination").toString();
        flightairport[i] = qry.record(i).value("airport").toString();
        flightairline[i] = qry.record(i).value("airline").toString();
        int flightgatenum = qry.record(i).value("gate").toInt();
        flightgate[i] = QString::number(flightgatenum);
        flightstatus[i] = qry.record(i).value("status").toString();
        }
    m.dbclosed();
    displayflight();

}
void Flight::displaytime(){
    QTime time = QTime::currentTime();
    QString timeLabel = time.toString("hh : mm : ss");
    ui->timedisplay->setText(timeLabel);
}

void Flight::displayflight(){
    for (int i = 0; i < 90;i++){
        if(flighttime[i] > timecompare){newtime = i;i=90;
            ui->timelbl->setText(flighttime[newtime]);
            ui->regionlbl->setText(flightdestination[newtime]);
            ui->flightnumlbl->setText(flightnum[newtime]);
            ui->airlinelbl->setText(flightairline[newtime]);
            ui->flighticon->setPixmap(flighticon[newtime]);
            ui->airportlbl->setText(flightairport[newtime]);
            ui->status->setText(flightstatus[newtime]);
            ui->gatenum->setText(flightgate[newtime]);

            ui->timelbl_2->setText(flighttime[newtime+1]);
            ui->regionlbl_2->setText(flightdestination[newtime+1]);
            ui->flightnumlbl_2->setText(flightnum[newtime+1]);
            ui->airlinelbl_2->setText(flightairline[newtime+1]);
            ui->flighticon_2->setPixmap(flighticon[newtime+1]);
            ui->airportlbl_2->setText(flightairport[newtime+1]);
            ui->status_2->setText(flightstatus[newtime+1]);
            ui->gatenum_2->setText(flightgate[newtime+1]);

            ui->timelbl_3->setText(flighttime[newtime+2]);
            ui->regionlbl_3->setText(flightdestination[newtime+2]);
            ui->flightnumlbl_3->setText(flightnum[newtime+2]);
            ui->airlinelbl_3->setText(flightairline[newtime+2]);
            ui->flighticon_3->setPixmap(flighticon[newtime+2]);
            ui->airportlbl_3->setText(flightairport[newtime+2]);
            ui->status_3->setText(flightstatus[newtime+2]);
            ui->gatenum_3->setText(flightgate[newtime+2]);

            ui->timelbl_4->setText(flighttime[newtime+3]);
            ui->regionlbl_4->setText(flightdestination[newtime+3]);
            ui->flightnumlbl_4->setText(flightnum[newtime+3]);
            ui->airlinelbl_4->setText(flightairline[newtime+3]);
            ui->flighticon_4->setPixmap(flighticon[newtime+3]);
            ui->airportlbl_4->setText(flightairport[newtime+3]);
            ui->status_4->setText(flightstatus[newtime+3]);
            ui->gatenum_4->setText(flightgate[newtime+3]);

            ui->timelbl_5->setText(flighttime[newtime+4]);
            ui->regionlbl_5->setText(flightdestination[newtime+4]);
            ui->flightnumlbl_5->setText(flightnum[newtime+4]);
            ui->airlinelbl_5->setText(flightairline[newtime+4]);
            ui->flighticon_5->setPixmap(flighticon[newtime+4]);
            ui->airportlbl_5->setText(flightairport[newtime+4]);
            ui->status_5->setText(flightstatus[newtime+4]);
            ui->gatenum_5->setText(flightgate[newtime+4]);

            ui->timelbl_6->setText(flighttime[newtime+5]);
            ui->regionlbl_6->setText(flightdestination[newtime+5]);
            ui->flightnumlbl_6->setText(flightnum[newtime+5]);
            ui->airlinelbl_6->setText(flightairline[newtime+5]);
            ui->flighticon_6->setPixmap(flighticon[newtime+5]);
            ui->airportlbl_6->setText(flightairport[newtime+5]);
            ui->status_6->setText(flightstatus[newtime+5]);
            ui->gatenum_6->setText(flightgate[newtime+5]);

            ui->timelbl_7->setText(flighttime[newtime+6]);
            ui->regionlbl_7->setText(flightdestination[newtime+6]);
            ui->flightnumlbl_7->setText(flightnum[newtime+6]);
            ui->airlinelbl_7->setText(flightairline[newtime+6]);
            ui->flighticon_7->setPixmap(flighticon[newtime+6]);
            ui->airportlbl_7->setText(flightairport[newtime+6]);
            ui->status_7->setText(flightstatus[newtime+6]);
            ui->gatenum_7->setText(flightgate[newtime+6]);

            ui->timelbl_8->setText(flighttime[newtime+7]);
            ui->regionlbl_8->setText(flightdestination[newtime+7]);
            ui->flightnumlbl_8->setText(flightnum[newtime+7]);
            ui->airlinelbl_8->setText(flightairline[newtime+7]);
            ui->flighticon_8->setPixmap(flighticon[newtime+7]);
            ui->airportlbl_8->setText(flightairport[newtime+7]);
            ui->status_8->setText(flightstatus[newtime+7]);
            ui->gatenum_8->setText(flightgate[newtime+7]);

            ui->timelbl_9->setText(flighttime[newtime+8]);
            ui->regionlbl_9->setText(flightdestination[newtime+8]);
            ui->flightnumlbl_9->setText(flightnum[newtime+8]);
            ui->airlinelbl_9->setText(flightairline[newtime+8]);
            ui->flighticon_9->setPixmap(flighticon[newtime+8]);
            ui->airportlbl_9->setText(flightairport[newtime+8]);
            ui->status_9->setText(flightstatus[newtime+8]);
            ui->gatenum_9->setText(flightgate[newtime+8]);

            ui->timelbl_10->setText(flighttime[newtime+9]);
            ui->regionlbl_10->setText(flightdestination[newtime+9]);
            ui->flightnumlbl_10->setText(flightnum[newtime+9]);
            ui->airlinelbl_10->setText(flightairline[newtime+9]);
            ui->flighticon_10->setPixmap(flighticon[newtime+9]);
            ui->airportlbl_10->setText(flightairport[newtime+9]);
            ui->status_10->setText(flightstatus[newtime+9]);
            ui->gatenum_10->setText(flightgate[newtime+9]);
            break;}
        if(flighttime[i] >= 2035 && flighttime[i] >= 2055){newtime = i; i = 90;
            ui->timelbl->setText(flighttime[newtime]);
            ui->regionlbl->setText(flightdestination[newtime]);
            ui->flightnumlbl->setText(flightnum[newtime]);
            ui->airlinelbl->setText(flightairline[newtime]);
            ui->flighticon->setPixmap(flighticon[newtime]);
            ui->airportlbl->setText(flightairport[newtime]);
            ui->status->setText(flightstatus[newtime]);
            ui->gatenum->setText(flightgate[newtime]);

            ui->timelbl_2->setText(flighttime[newtime+1]);
            ui->regionlbl_2->setText(flightdestination[newtime+1]);
            ui->flightnumlbl_2->setText(flightnum[newtime+1]);
            ui->airlinelbl_2->setText(flightairline[newtime+1]);
            ui->flighticon_2->setPixmap(flighticon[newtime+1]);
            ui->airportlbl_2->setText(flightairport[newtime+1]);
            ui->status_2->setText(flightstatus[newtime+1]);
            ui->gatenum_2->setText(flightgate[newtime+1]);

            ui->timelbl_3->setText(flighttime[newtime+2]);
            ui->regionlbl_3->setText(flightdestination[newtime+2]);
            ui->flightnumlbl_3->setText(flightnum[newtime+2]);
            ui->airlinelbl_3->setText(flightairline[newtime+2]);
            ui->flighticon_3->setPixmap(flighticon[newtime+2]);
            ui->airportlbl_3->setText(flightairport[newtime+2]);
            ui->status_3->setText(flightstatus[newtime+2]);
            ui->gatenum_3->setText(flightgate[newtime+2]);

            ui->timelbl_4->setText(flighttime[newtime+3]);
            ui->regionlbl_4->setText(flightdestination[newtime+3]);
            ui->flightnumlbl_4->setText(flightnum[newtime+3]);
            ui->airlinelbl_4->setText(flightairline[newtime+3]);
            ui->flighticon_4->setPixmap(flighticon[newtime+3]);
            ui->airportlbl_4->setText(flightairport[newtime+3]);
            ui->status_4->setText(flightstatus[newtime+3]);
            ui->gatenum_4->setText(flightgate[newtime+3]);

            ui->timelbl_5->setText(flighttime[newtime+4]);
            ui->regionlbl_5->setText(flightdestination[newtime+4]);
            ui->flightnumlbl_5->setText(flightnum[newtime+4]);
            ui->airlinelbl_5->setText(flightairline[newtime+4]);
            ui->flighticon_5->setPixmap(flighticon[newtime+4]);
            ui->airportlbl_5->setText(flightairport[newtime+4]);
            ui->status_5->setText(flightstatus[newtime+4]);
            ui->gatenum_5->setText(flightgate[newtime+4]);

            ui->timelbl_6->setText(flighttime[newtime+5]);
            ui->regionlbl_6->setText(flightdestination[newtime+5]);
            ui->flightnumlbl_6->setText(flightnum[newtime+5]);
            ui->airlinelbl_6->setText(flightairline[newtime+5]);
            ui->flighticon_6->setPixmap(flighticon[newtime+5]);
            ui->airportlbl_6->setText(flightairport[newtime+5]);
            ui->status_6->setText(flightstatus[newtime+5]);
            ui->gatenum_6->setText(flightgate[newtime+5]);

            ui->timelbl_7->setText(flighttime[newtime+6]);
            ui->regionlbl_7->setText(flightdestination[newtime+6]);
            ui->flightnumlbl_7->setText(flightnum[newtime+6]);
            ui->airlinelbl_7->setText(flightairline[newtime+6]);
            ui->flighticon_7->setPixmap(flighticon[newtime+6]);
            ui->airportlbl_7->setText(flightairport[newtime+6]);
            ui->status_7->setText(flightstatus[newtime+6]);
            ui->gatenum_7->setText(flightgate[newtime+6]);

            ui->timelbl_8->setText(flighttime[newtime+7]);
            ui->regionlbl_8->setText(flightdestination[newtime+7]);
            ui->flightnumlbl_8->setText(flightnum[newtime+7]);
            ui->airlinelbl_8->setText(flightairline[newtime+7]);
            ui->flighticon_8->setPixmap(flighticon[newtime+7]);
            ui->airportlbl_8->setText(flightairport[newtime+7]);
            ui->status_8->setText(flightstatus[newtime+7]);
            ui->gatenum_8->setText(flightgate[newtime+7]);

            ui->timelbl_9->setText(flighttime[newtime+8]);
            ui->regionlbl_9->setText(flightdestination[newtime+8]);
            ui->flightnumlbl_9->setText(flightnum[newtime+8]);
            ui->airlinelbl_9->setText(flightairline[newtime+8]);
            ui->flighticon_9->setPixmap(flighticon[newtime+8]);
            ui->airportlbl_9->setText(flightairport[newtime+8]);
            ui->status_9->setText(flightstatus[newtime+8]);
            ui->gatenum_9->setText(flightgate[newtime+8]);

            ui->timelbl_10->setText(flighttime[newtime-i]);
            ui->regionlbl_10->setText(flightdestination[newtime-i]);
            ui->flightnumlbl_10->setText(flightnum[newtime-i]);
            ui->airlinelbl_10->setText(flightairline[newtime-i]);
            ui->flighticon_10->setPixmap(flighticon[newtime-i]);
            ui->airportlbl_10->setText(flightairport[newtime-i]);
            ui->status_10->setText(flightstatus[newtime-i]);
            ui->gatenum_10->setText(flightgate[newtime-i]);
            break;
        }
        else{}
    }

}
Flight::~Flight()
{
    delete ui;
}



void Flight::on_buttonreturn_clicked()
{
    hide();
    MainWindow *m;
    m = new MainWindow(this);
    m->show();
}
