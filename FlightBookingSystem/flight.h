#ifndef FLIGHT_H
#define FLIGHT_H

#include <QMainWindow>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "ui_calendar.h"

namespace Ui {
class Flight;
}

class Flight : public QMainWindow
{
    Q_OBJECT

public:
    explicit Flight(QWidget *parent = nullptr);
    int flightcode, gate;
    QString airlinecode, newflightcode, gatenum, destination;
    QString airportregion[10] = {"Kuala Lumpur(MY)",
                                "Changi(SG)",
                                "Hong Kong(HK)",
                                "Osaka(JP)",
                                "New Delhi(IN)",
                                "San Francisco(US)",
                                "Incheon(KR)",
                                "Mexico City(MX)",
                                "London City(UK)",
                                "Moscow(RU)"};
    QString airportname[10] = {"Kuala Lumpur International Airport (KLIA)",
                              "Singapore Changi Airport",
                              "Hong Kong International Airport",
                              "Kansai International Airport",
                              "Indira Gandhi International Airport",
                              "San Francisco International Airport",
                              "Incheon International Airport (IIA)",
                              "Mexico City International Airport",
                              "London City Airport",
                              "Moscow Domodedovo Airport"};
    QString airlinename[10] = {"Malaysia Airlines",
                              "Singapore Airlines",
                              "Hong Kong Airlines",
                              "Japan Airlines",
                              "Air India",
                              "American Eagle",
                              "Korean Air Lines",
                              "Aeroméxico",
                              "British Airways",
                              "Aeroflot Russian Airlines"};
    QString flighttime[90]; QString flightnum[90], flightdestination[90], flightairport[90], flightairline[90], flightgate[90], flightstatus[90];
    QPixmap flighticon[90] =
    {QPixmap(":/images/ru.png"), QPixmap(":/images/hk.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"), QPixmap(":/images/jp.png"), QPixmap(":/images/in.png"),QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"), QPixmap(":/images/me.png"), QPixmap(":/images/uk.png"),
     QPixmap(":/images/me.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/my.png"), QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"), QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"),
     QPixmap(":/images/uk.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"), QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"),QPixmap(":/images/us.png"), QPixmap(":/images/kr.png"),
     QPixmap(":/images/me.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"), QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"),QPixmap(":/images/us.png"),
     QPixmap(":/images/kr.png"), QPixmap(":/images/me.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"), QPixmap(":/images/in.png"),
     QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"), QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"), QPixmap(":/images/sg.png"),QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),
     QPixmap(":/images/in.png"), QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"), QPixmap(":/images/uk.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/me.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"), QPixmap(":/images/hk.png"),
     QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"), QPixmap(":/images/us.png"),QPixmap(":/images/kr.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/ru.png"),QPixmap(":/images/my.png"),QPixmap(":/images/sg.png"),
     QPixmap(":/images/sg.png"), QPixmap(":/images/hk.png"),QPixmap(":/images/jp.png"),QPixmap(":/images/in.png"),QPixmap(":/images/us.png"), QPixmap(":/images/kr.png"),QPixmap(":/images/me.png"),QPixmap(":/images/uk.png"),QPixmap(":/images/ru.png"), QPixmap(":/images/my.png")};
    QString timecompare;
    int newtime;
    void displayflight();
    ~Flight();

private slots:
    void displaytime();
    void on_buttonreturn_clicked();

private:
    Ui::Flight *ui;
};

#endif // FLIGHT_H
