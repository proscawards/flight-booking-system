#include "flightnumgenerator.h"
#include "ui_flightnumgenerator.h"
#include "mainwindow.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QtSql>
#include <QTimer>

FlightNumGenerator::FlightNumGenerator(QWidget *parent) : QMainWindow(parent), ui(new Ui::FlightNumGenerator)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime()));
    timer->start();
    QTime time = QTime::currentTime();
    QString currenttime = time.toString("hhmmss");
    mainmenu *menu;
    menu = new mainmenu(this);
    int currenttimeint = currenttime.split(" ")[0].toInt();
    if ((currenttimeint >= 000000 && currenttimeint < 060000) ||
        (currenttimeint >= 220000 && currenttimeint <= 235959)){
        menu->ui->btn_newbook->setEnabled(false);
        menu->ui->btn_checkin->setEnabled(false);
        menu->ui->standbymodelbl->show();
        MainWindow m;
        m.dbopened();
        QSqlQueryModel readflightdata;
        QSqlQuery randomgenerator;
        readflightdata.setQuery("select * from flight");
        for (int i = 0; i< readflightdata.rowCount(); i++){
            QString no = readflightdata.record(i).value("no").toString();
            qsrand(QDateTime::currentMSecsSinceEpoch()%UINT_MAX);
            int randomnum = qrand() % (9999 - 1000 + 1) + 1000;
            QString randomnumstr = QString::number(randomnum);
            flightnum = airlineiata[i] + randomnumstr;
            randomgenerator.exec("update flight set flightnum = '"+flightnum+"' where no = '"+no+"'");}
        m.dbclosed();}
    else{
        menu->ui->btn_newbook->setEnabled(true);
        menu->ui->btn_checkin->setEnabled(true);
        menu->ui->standbymodelbl->hide();}
}

FlightNumGenerator::~FlightNumGenerator()
{
    delete ui;
}
